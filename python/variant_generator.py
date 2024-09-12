import argparse
import regex
import string


def replace_match_parenthesis(string, keyword, fun):
    pattern = regex.compile(keyword + r"(\((?:[^()]++|(?1))++\))")
    res = []
    pos = 0
    for m in pattern.finditer(string):
        res.append(string[pos : m.start()])
        res.append(fun(m[1][1:-1]))
        pos = m.end()
    res.append(string[pos:])
    return "".join(res)


parser = argparse.ArgumentParser("MLX C variant code generator", add_help=False)
parser.add_argument("--implementation", default=False, action="store_true")
parser.add_argument("--private", default=False, action="store_true")
args = parser.parse_args()

decl_code = """
/**
 * A variant of (CARGS).
 */
typedef struct NAME_* NAME;
"""

decl_code_new = """NAME NAME_new_with_SCARG(CARG val);"""
decl_code_get = """CARG NAME_get_SCARG(NAME var);"""
decl_code_holds = """bool NAME_holds_SCARG(NAME var);"""

impl_code = """
mlx_string NAME_::tostring() {
  RETURN_MLX_C_STRING("mlx_variant(CARGS)");
}"""

impl_code_new = """
extern "C" NAME NAME_new_with_SCARG(CARG val) {
  RETURN_MLX_C_PTR(new NAME_(C_TO_CPP(val)));
}"""

impl_code_get = """
extern "C" CARG NAME_get_SCARG(NAME var) {
  RETURN_CPP_TO_C(std::get<CPPARG>(var->ctx));
}"""

impl_code_holds = """
extern "C" bool NAME_holds_SCARG(NAME var) {
  return std::holds_alternative<CPPARG>(var->ctx);
}"""

priv_code = """
struct NAME_ : mlx_object_ {
  NAME_(const std::variant<CPPARGS>& ctx)
      : mlx_object_(), ctx(ctx){};
  NAME_(const std::variant<CPPARGS>&& ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  virtual mlx_string_* tostring() override;
  std::variant<CPPARGS> ctx;
};
"""


def generate(
    code,
    code_new,
    code_get,
    code_holds,
    cargs,
    cppargs,
    c_to_cpp=None,
    return_cpp_to_c=None,
):
    assert len(cargs) == len(cppargs)
    name = ["mlx_variant"]
    subcodes = [[], [], []]
    for i in range(len(cargs)):
        carg = cargs[i]
        scarg = regex.sub("^mlx_", "", carg)
        cpparg = cppargs[i]
        suffix = "_" + str(i) if len(cargs) > 1 else ""
        if return_cpp_to_c is None or return_cpp_to_c[i] is None:
            carg_cpp_to_c = lambda s: "RETURN_MLX_C_PTR(new CARG_(" + s + "))"
        else:
            carg_cpp_to_c = return_cpp_to_c[i]
        if c_to_cpp is None or c_to_cpp[i] is None:
            carg_c_to_cpp = lambda s: s + "->ctx"
        else:
            carg_c_to_cpp = c_to_cpp[i]

        for subidx, subcode in enumerate([code_new, code_get, code_holds]):
            if subcode:
                subcode = replace_match_parenthesis(
                    subcode, "RETURN_CPP_TO_C", carg_cpp_to_c
                )
                subcode = replace_match_parenthesis(subcode, "C_TO_CPP", carg_c_to_cpp)
                subcode = subcode.replace("SCARG", scarg)
                subcode = subcode.replace("CARG", carg)
                subcode = subcode.replace("CPPARG", cpparg)
                subcodes[subidx].append(subcode)

        name.append(scarg)

    subcodes = ["\n".join(subcode) for subcode in subcodes]
    subcodes = "\n".join(subcodes)
    code = "\n".join([code, subcodes])

    cargs = ", ".join(cargs)
    cppargs = ", ".join(cppargs)
    name = "_".join(name)

    code = code.replace("CARGS", cargs)
    code = code.replace("CPPARGS", cppargs)
    code = code.replace("NAME", name)

    return code


decl_begin = """/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_VARIANT_H
#define MLX_VARIANT_H

#include "mlx/c/array.h"
#include "mlx/c/string.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_variant Variants
 * MLX variant objects.
 */
/**@{*/
"""

decl_end = """
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
"""

impl_begin = """/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/object.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/variant.h"
"""

impl_end = """
"""

priv_begin = """/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_VARIANT_PRIVATE_H
#define MLX_VARIANT_PRIVATE_H

#include "mlx/c/object.h"
#include "mlx/c/private/object.h"
#include "mlx/c/variant.h"
#include "mlx/mlx.h"

#include <variant>
#include <utility>

"""

priv_end = """
#endif
"""

if args.implementation:
    code = impl_code
    code_new = impl_code_new
    code_get = impl_code_get
    code_holds = impl_code_holds
    begin = impl_begin
    end = impl_end
elif args.private:
    code = priv_code
    code_new = None
    code_get = None
    code_holds = None
    begin = priv_begin
    end = priv_end
else:
    code = decl_code
    code_new = decl_code_new
    code_get = decl_code_get
    code_holds = decl_code_holds
    begin = decl_begin
    end = decl_end


print(begin)
print(
    generate(
        code,
        code_new,
        code_get,
        code_holds,
        ["mlx_string", "size_t"],
        ["std::string", "size_t"],
        [None, lambda s: s],
        [None, lambda s: "return " + s],
    )
)
print(end)
