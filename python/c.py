# Copyright © 2023-2024 Apple Inc.

import re
import sys

import mlxtypes as mt
import mlxhooks as hooks


def to_snake_letters(name):
    name = re.sub(r"(?<!^)(?=[A-Z])", "_", name).lower()
    return name


def generate(funcs, enums, headername, namespace, implementation, docstring):
    namespace_prefix = namespace.split("::")
    if namespace_prefix[0] == "mlx" and namespace_prefix[1] == "core":
        namespace_prefix.pop(1)  # we pop core
    namespace_prefix = "_".join(namespace_prefix)

    sorted_funcs = []
    for name in funcs:
        variants = funcs[name]
        if len(variants) == 1:
            sorted_funcs.append(variants[0])
        else:
            variants.sort(key=lambda x: len(x["params_name"]), reverse=True)

            if name != "all" and name != "norm":
                idx = 0
                while idx < len(variants) - 1:
                    pidx = variants[idx]["params_name"]
                    pidxp1 = variants[idx + 1]["params_name"]
                    mpidx = [p if p != "axis" else "axes" for p in pidx]
                    mpidxp1 = [p if p != "axis" else "axes" for p in pidxp1]
                    if mpidx == mpidxp1:
                        if pidx == mpidx:
                            variants.pop(idx + 1)
                        else:
                            variants.pop(idx)
                    else:
                        idx = idx + 1

            if len(variants) == 1:
                sorted_funcs.append(variants[0])
            elif name == "tensordot":
                var0 = variants[0]
                var1 = variants[1]
                var1["variant"] = "along_axis"
                sorted_funcs.append(var0)
                sorted_funcs.append(var1)
            elif name == "split":
                var0 = variants[0]
                var1 = variants[1]
                var0["variant"] = "equal_parts"
                sorted_funcs.append(var0)
                sorted_funcs.append(var1)
            elif name == "pad":
                sorted_funcs.append(variants[0])
            elif name == "all":
                variants[0]["variant"] = "axes"
                variants[1]["variant"] = "axis"
                variants[2]["variant"] = "all"
                sorted_funcs.append(variants[0])
                sorted_funcs.append(variants[1])
                sorted_funcs.append(variants[2])
            elif name == "categorical":
                variants[0]["variant"] = "shape"
                variants[1]["variant"] = "num_samples"
                sorted_funcs.append(variants[0])
                sorted_funcs.append(variants[1])
                sorted_funcs.append(variants[2])
            elif name == "norm":
                variants[0]["variant"] = "p"
                variants[2]["variant"] = "ord"
                sorted_funcs.append(variants[0])
                sorted_funcs.append(variants[2])
                sorted_funcs.append(variants[4])
            elif (
                "axes" in variants[0]["params_name"]
                or "axis" in variants[0]["params_name"]
            ) and (
                "axes" not in variants[1]["params_name"]
                and "axis" not in variants[1]["params_name"]
            ):
                var0 = variants[0]
                var1 = variants[1]
                var1["variant"] = "all"
                sorted_funcs.append(var0)
                sorted_funcs.append(var1)
            elif (
                "std::shared_ptr<io::Reader>" in variants[0]["params_t"]
                or "std::shared_ptr<io::Reader>" in variants[1]["params_t"]
                or "std::shared_ptr<io::Writer>" in variants[0]["params_t"]
                or "std::shared_ptr<io::Writer>" in variants[1]["params_t"]
            ):
                if (
                    "std::shared_ptr<io::Reader>" in variants[0]["params_t"]
                    or "std::shared_ptr<io::Writer>" in variants[0]["params_t"]
                ):
                    variants[0]["variant"] = "file"
                else:
                    variants[1]["variant"] = "file"
                sorted_funcs.append(variants[0])
                sorted_funcs.append(variants[1])
            else:
                sorted_funcs.append(variants[0])  # abandon

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
        print(
            """
    #include "mlx/c/mlx.h"
    #include "mlx/c/private/array.h"
    #include "mlx/c/private/closure.h"
    #include "mlx/c/private/distributed_group.h"
    #include "mlx/c/private/io.h"
    #include "mlx/c/private/map.h"
    #include "mlx/c/private/stream.h"
    #include "mlx/c/private/string.h"
    #include "mlx/c/private/utils.h"
    #include "mlx/c/private/vector.h"

    """
        )
    else:
        print("#ifndef MLX_" + headername.upper() + "_H")
        print("#define MLX_" + headername.upper() + "_H")
        print(
            """
    #include <stdio.h>

    #include "mlx/c/array.h"
    #include "mlx/c/closure.h"
    #include "mlx/c/distributed_group.h"
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
            docstring = docstring.replace("\n", "\n* ")
            print("/**")
            print("* \defgroup " + headername + " " + docstring)
            print("*/")
            print("/**@{*/")

    for enum, values in enums.items():
        c_typename = "mlx_" + to_snake_letters(enum)
        c_vals = []
        for value in values:
            c_vals.append("MLX_" + to_snake_letters(enum).upper() + "_" + value.upper())
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

    for f in sorted_funcs:
        if "variant" in f:
            func_name = namespace_prefix + "_" + f["name"] + "_" + f["variant"]
        else:
            func_name = namespace_prefix + "_" + f["name"]
        if hasattr(hooks, func_name):
            getattr(hooks, func_name)(f, implementation)
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
        signature.append(func_name)
        signature.append("(")

        c_call = []
        cpp_call = []
        pt = f["params_t"]
        pn = f["params_name"]
        encountered_unsupported_type = False
        for i in range(len(pt)):
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

        res_arg = return_t["c_return_arg"]("res")
        if res_arg:
            c_call.append(res_arg)

        # print(f)
        c_call = ", ".join(c_call)
        cpp_call = ", ".join(cpp_call)
        signature.append(c_call)
        signature.append(")")
        signature = " ".join(signature)

        c_code = [signature, ";"]
        cpp_code = ['extern "C"', signature, "{"]
        cpp_code.append("try {")
        cpp_call = [namespace + "::" + f["name"], "(", cpp_call, ")"]
        cpp_call = "".join(cpp_call)
        cpp_code.append(return_t["c_assign_from_cpp"]("res", cpp_call))
        cpp_code.append(";")
        cpp_code.append("} catch (std::exception & e) {")
        cpp_code.append("mlx_error(e.what());")
        cpp_code.append("return 1;")
        cpp_code.append("}")
        cpp_code.append("return 0;")
        cpp_code.append("}")
        if implementation:
            print(" ".join(cpp_code))
        else:
            print(" ".join(c_code))

    if implementation:
        pass
    else:
        if docstring:
            print("/**@}*/")
        print(
            """
    #ifdef __cplusplus
    }
    #endif

    #endif
    """
        )
