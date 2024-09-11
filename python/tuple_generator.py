import argparse
import re
import string

parser = argparse.ArgumentParser("MLX C tuple code generator", add_help=False)
parser.add_argument("--implementation", default=False, action="store_true")
parser.add_argument("--private", default=False, action="store_true")
args = parser.parse_args()

decl_code = """
/**
 * A tuple of (CARGS).
 */
typedef struct NAME_* NAME;
NAME NAME_new(CARGS_TYPE_NAME);
"""

decl_code_get = """
CARG NAME_get_IDX(NAME tuple);"""

impl_code = """
mlx_string NAME_::tostring() {
  RETURN_MLX_C_STRING("mlx_tuple(CARGS)");
}

extern "C" NAME
NAME_new(CARGS_TYPE_NAME) {
  RETURN_MLX_C_PTR(
      new NAME_(MAKE_TUPLE(CARGS_CTX)));
}
"""

impl_code_get = """
extern "C" CARG NAME_get_IDX(
    NAME tuple) {
  RETURN_MLX_C_PTR(new CARG_(std::get<IDX>(tuple->ctx)));
}
"""

priv_code = """
struct NAME_ : mlx_object_ {
  NAME_(
      TUPLE<CPPARGS>&& ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  NAME_(
      const TUPLE<CPPARGS>& ctx)
      : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  TUPLE<CPPARGS> ctx;
};
"""


def generate(code, code_get, cargs, cppargs):
    assert len(cargs) == len(cppargs)
    cargs_name = []
    cargs_type_name = []
    cargs_ctx = []
    name = ["mlx_tuple"]
    for i in range(len(cargs)):
        carg = cargs[i]
        cpparg = cppargs[i]
        suffix = "_" + str(i) if len(cargs) > 1 else ""
        cargs_name.append("input" + suffix)
        cargs_type_name.append("const " + carg + " input" + suffix)
        # cppargs_type_name.append("const " + cpparg + "& cpp_input" + suffix)
        cargs_ctx.append("input" + suffix + "->ctx")

        if code_get:
            code = code + code_get.replace("CARG", carg).replace("IDX", str(i))

        name.append(re.sub("^mlx_", "", carg))

    if len(cargs) == 2:
        tuple_type = "std::pair"
        make_tuple = "std::make_pair"
    else:
        tuple_type = "std::tuple"
        make_tuple = "std::make_tuple"

    cargs_name = ", ".join(cargs_name)
    cargs_type_name = ", ".join(cargs_type_name)
    # cppargs_type_name = ", ".join(cppargs_type_name)
    cargs_ctx = ", ".join(cargs_ctx)
    cargs = ", ".join(["const " + carg for carg in cargs])
    cppargs = ", ".join(cppargs)
    name = "_".join(name)

    code = code.replace("CARGS_TYPE_NAME", cargs_type_name)
    # code = code.replace("CPPARGS_TYPE_NAME", cppargs_type_name)
    code = code.replace("CARGS_NAME", cargs_name)
    code = code.replace("CARGS_CTX", cargs_ctx)
    code = code.replace("CARGS", cargs)
    code = code.replace("CPPARGS", cppargs)
    code = code.replace("NAME", name)
    code = code.replace("MAKE_TUPLE", make_tuple)
    code = code.replace("TUPLE", tuple_type)

    return code


decl_begin = """/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_TUPLE_H
#define MLX_TUPLE_H

#include "mlx/c/array.h"
#include "mlx/c/string.h"
#include "mlx/c/vector.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_tuple Tuples
 * MLX tuple objects.
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
#include "mlx/c/private/tuple.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

"""

impl_end = """
"""

priv_begin = """/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_TUPLE_PRIVATE_H
#define MLX_TUPLE_PRIVATE_H

#include "mlx/c/object.h"
#include "mlx/c/private/object.h"
#include "mlx/c/tuple.h"
#include "mlx/mlx.h"

#include <tuple>
#include <utility>

"""

priv_end = """
#endif
"""

if args.implementation:
    code = impl_code
    code_get = impl_code_get
    begin = impl_begin
    end = impl_end
elif args.private:
    code = priv_code
    code_get = None
    begin = priv_begin
    end = priv_end
else:
    code = decl_code
    code_get = decl_code_get
    begin = decl_begin
    end = decl_end


print(begin)
print(generate(code, code_get, ["mlx_array"] * 2, ["mlx::core::array"] * 2))
print(generate(code, code_get, ["mlx_array"] * 3, ["mlx::core::array"] * 3))
print(
    generate(
        code, code_get, ["mlx_vector_array"] * 2, ["std::vector<mlx::core::array>"] * 2
    )
)
print(
    generate(
        code,
        code_get,
        ["mlx_vector_array", "mlx_vector_int"],
        ["std::vector<mlx::core::array>", "std::vector<int>"],
    )
)
print(end)
