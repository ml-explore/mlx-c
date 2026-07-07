# Copyright © 2023-2024 Apple Inc.

import re
import sys

import mlxtypes as mt
import mlxhooks as hooks
import mlxvariants as variants

# Classifying catch ladder shared by every generated binding. Ordered most- to
# least-specific so the first matching handler wins. The trailing catch (...)
# closes the ABI hole: a non-std throw would otherwise unwind across extern "C".
# _mlx_error_with_code records classified thread-local state *and* invokes the
# legacy handler, so handler-based callers keep working unchanged. e.what() is
# passed through "%s" so messages containing '%' are not misread as formats.
CATCH_LADDER = [
    '  } catch (const std::invalid_argument& e) {',
    '    mlx_error_with_code(MLX_ERROR_INVALID_ARGUMENT, "%s", e.what());',
    "    return 1;",
    "  } catch (const std::out_of_range& e) {",
    '    mlx_error_with_code(MLX_ERROR_OUT_OF_RANGE, "%s", e.what());',
    "    return 1;",
    "  } catch (const std::bad_alloc& e) {",
    '    mlx_error_with_code(MLX_ERROR_OUT_OF_MEMORY, "%s", e.what());',
    "    return 1;",
    "  } catch (const std::exception& e) {",
    '    mlx_error_with_code(MLX_ERROR_RUNTIME, "%s", e.what());',
    "    return 1;",
    "  } catch (...) {",
    '    mlx_error_with_code(MLX_ERROR_UNKNOWN, "unknown (non-std) exception");',
    "    return 1;",
]


def to_snake_letters(name):
    name = re.sub(r"([A-Z]+)([A-Z][a-z])", r"\1_\2", name)
    name = re.sub(r"([a-z\d])([A-Z])", r"\1_\2", name)
    name = name.lower()
    return name


def c_namespace(namespace):
    c_prefix = namespace.split("::")
    if c_prefix[0] == "mlx" and c_prefix[1] == "core":
        c_prefix.pop(1)  # we pop core
        if len(c_prefix) == 2 and c_prefix[1] == "cu":
            c_prefix[1] = "cuda"
    return "_".join(c_prefix)


def uniq_defs(defs):
    uniq_defs = []
    variants = {}
    for d in defs:
        variant = d["variant"] if "variant" in d else ""
        if variant in variants:
            continue
        else:
            variants[variant] = True
            uniq_defs.append(d)
    return uniq_defs


def generate(funcs, enums, header, headername, implementation, docstring):
    sorted_funcs = []
    for name, defs in funcs.items():
        name_split = name.split("::")
        namespace = "_".join(name_split[:-1])
        name = name_split[-1]

        defs.sort(key=lambda x: len(x["params_name"]), reverse=True)

        # handle duplicates and other exceptions
        if hasattr(variants, namespace):
            defs = getattr(variants, namespace)(name, defs)

        sorted_funcs += uniq_defs(defs)

    sorted_funcs.sort(key=lambda x: x["name"])

    print(
        """/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */
"""
    )
    if implementation:
        print('#include "mlx/c/' + headername + '.h"')
        for include in header.split(";"):
            # Extract path from the last mlx/ onwards
            # This handles paths like ../mlx/mlx/backend/... -> mlx/backend/...
            parts = include.split("/")
            mlx_idx = None
            for i, part in enumerate(parts):
                if part == "mlx":
                    mlx_idx = i
            if mlx_idx is not None:
                print('#include "' + "/".join(parts[mlx_idx:]) + '"')
        print('#include "mlx/c/error.h"')
        print('#include "mlx/c/private/mlx.h"')
        print()
    else:
        print("#ifndef MLX_" + headername.upper() + "_H")
        print("#define MLX_" + headername.upper() + "_H")
        print(
            """
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "mlx/c/array.h"
#include "mlx/c/closure.h"
#include "mlx/c/distributed_group.h"
#include "mlx/c/io_types.h"
#include "mlx/c/map.h"
#include "mlx/c/stream.h"
#include "mlx/c/string.h"
#include "mlx/c/vector.h"

#ifdef __cplusplus
extern "C" {
#endif
"""
        )
        if docstring:
            docstring = docstring.replace("\n", "\n * ")
            print("/**")
            print(r" * \defgroup " + headername + " " + docstring)
            print(" */")
            print("/**@{*/")
            print()  # blank line after /**@{*/

    for _, enum in enums.items():
        c_typename = "mlx_" + to_snake_letters(enum["name"])
        c_vals = []
        for value in enum["values"]:
            c_vals.append(
                "MLX_" + to_snake_letters(enum["name"]).upper() + "_" + value.upper()
            )
        if implementation:
            pass
        else:
            decl = ["typedef enum "]
            decl.append(c_typename + "_")
            decl.append("{")
            decl.append(", ".join(c_vals))
            decl.append("}")
            decl.append(c_typename)
            decl.append(";")
            print(" ".join(decl))
            print()

    for f in sorted_funcs:
        if "variant" in f:
            func_name = (
                c_namespace(f["namespace"]) + "_" + f["name"] + "_" + f["variant"]
            )
        else:
            func_name = c_namespace(f["namespace"]) + "_" + f["name"]

        if hasattr(hooks, func_name):
            hook_result = getattr(hooks, func_name)(f, implementation)
            if not hook_result:
                print()  # blank line after hook output
                continue

        signature = []
        return_t = f["return_t"]
        if return_t in mt.cpptypes:
            return_t = mt.cpptypes[return_t]
        elif return_t in mt.alttypes:
            return_t = mt.alttypes[return_t]
        else:
            print("unsupported return type: " + return_t, file=sys.stderr)
            print("skipping", f, file=sys.stderr)
            continue

        signature.append("int")
        signature.append(func_name + "(")

        c_call = []
        cpp_call = []

        # return values as first arguments
        res_arg = return_t["c_return_arg"]("res")
        if res_arg:
            c_call.append(res_arg)

        pt = f["params_t"]
        pn = f["params_name"]
        pd = f["params_default"]
        use_defaults = "use_defaults" in f and f["use_defaults"]
        encountered_unsupported_type = False
        for i in range(len(pt)):
            if use_defaults and pd[i]:
                continue

            pti = pt[i]
            pni = pn[i]
            if pni is None:
                pni = "param"  # good luck

            if pti in mt.cpptypes:
                pti = mt.cpptypes[pti]
            elif pti in mt.alttypes:
                pti = mt.alttypes[pti]
            else:
                print("unsupported argument type: " + pti, file=sys.stderr)
                encountered_unsupported_type = True
                print("skipping", f, file=sys.stderr)
                break

            c_call.append(pti["c_arg"](pni))
            cpp_call.append(pti["c_to_cpp"](pni))

        if encountered_unsupported_type:
            print("skipping", f, file=sys.stderr)
            continue

        # print(f)
        c_call = ", ".join(c_call) if len(c_call) > 0 else "void"
        cpp_call = ", ".join(cpp_call)
        signature.append(c_call)
        signature.append(")")
        # Join signature parts, then clean up spaces around parens
        signature = " ".join(signature)
        signature = signature.replace("( ", "(").replace(" )", ")")

        c_code = signature + ";"
        if implementation:
            cpp_call = f["namespace"] + "::" + f["name"] + "(" + cpp_call + ")"
            cpp_code = [
                'extern "C" ' + signature + " {",
                "  try {",
                "    " + return_t["c_assign_from_cpp"]("res", cpp_call) + ";",
                *CATCH_LADDER,
                "  }",
                "  return 0;",
                "}",
            ]
            print("\n".join(cpp_code))
        else:
            print(c_code)

    if implementation:
        pass
    else:
        if docstring:
            print()  # blank line before /**@}*/
            print("/**@}*/")
        print(
            """\

#ifdef __cplusplus
}
#endif

#endif"""
        )  # no trailing newline
