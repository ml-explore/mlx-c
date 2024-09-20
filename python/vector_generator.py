import argparse
import regex
import string

parser = argparse.ArgumentParser("MLX C vector code generator", add_help=False)
parser.add_argument("--implementation", default=False, action="store_true")
parser.add_argument("--private", default=False, action="store_true")
args = parser.parse_args()


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


decl_code = """
/**
 * A vector of SCTYPE.
 */
typedef struct mlx_vector_SCTYPE_* mlx_vector_SCTYPE;
mlx_vector_SCTYPE mlx_vector_SCTYPE_new();
mlx_vector_SCTYPE mlx_vector_SCTYPE_from_data(const CTYPE* data, size_t size);
mlx_vector_SCTYPE mlx_vector_SCTYPE_from_value(const CTYPE val);
void mlx_vector_SCTYPE_add_data(mlx_vector_SCTYPE vec, const CTYPE* data, size_t size);
void mlx_vector_SCTYPE_add_value(mlx_vector_SCTYPE vec, const CTYPE val);
size_t mlx_vector_SCTYPE_size(mlx_vector_SCTYPE vec);
CTYPE mlx_vector_SCTYPE_get(mlx_vector_SCTYPE vec, size_t idx);
CTYPE* mlx_vector_SCTYPE_data(mlx_vector_SCTYPE vec);
"""

impl_code = """
mlx_string mlx_vector_SCTYPE_::tostring() {
  MLX_TRY_CATCH(std::ostringstream os;
                os << "vector of SCTYPEs (size=" << ctx.size() << ")";
                std::string str = os.str();
                return new mlx_string_(str);
                , return nullptr);
}

extern "C" mlx_vector_SCTYPE mlx_vector_SCTYPE_new() {
  RETURN_MLX_C_PTR(new mlx_vector_SCTYPE_())
}

extern "C" mlx_vector_SCTYPE mlx_vector_SCTYPE_from_data(
    const CTYPE* data,
    size_t size) {
  std::vector<CPPTYPE> cpp_arrs;
  for (size_t i = 0; i < size; i++) {
    cpp_arrs.push_back(C_TO_CPP(data[i]));
  }
  RETURN_MLX_C_PTR(new mlx_vector_SCTYPE_(cpp_arrs))
}

extern "C" mlx_vector_SCTYPE mlx_vector_SCTYPE_from_value(const CTYPE val) {
  RETURN_MLX_C_PTR(new mlx_vector_SCTYPE_({C_TO_CPP(val)}))
}

extern "C" void mlx_vector_SCTYPE_add_data(
    mlx_vector_SCTYPE vec,
    const CTYPE* data,
    size_t size) {
  MLX_TRY_CATCH(
      for (size_t i = 0; i < size;
           i++) { vec->ctx.push_back(C_TO_CPP(data[i])); }, );
}

extern "C" void mlx_vector_SCTYPE_add_value(
    mlx_vector_SCTYPE vec,
    const CTYPE value) {
  MLX_TRY_CATCH(vec->ctx.push_back(C_TO_CPP(value));, )
}

extern "C" CTYPE mlx_vector_SCTYPE_get(mlx_vector_SCTYPE vec, size_t index) {
   RETURN_CPP_TO_C(vec->ctx.at(index));
}

extern "C" size_t mlx_vector_SCTYPE_size(mlx_vector_SCTYPE vec) {
  return vec->ctx.size();
}
"""

priv_code = """
struct mlx_vector_SCTYPE_ : mlx_object_ {
  mlx_vector_SCTYPE_() : mlx_object_(){};
  mlx_vector_SCTYPE_(const std::vector<CPPTYPE>& ctx)
      : mlx_object_(), ctx(ctx){};
  mlx_vector_SCTYPE_(std::vector<CPPTYPE>&& ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  mlx_vector_SCTYPE_(const std::pair<CPPTYPE, CPPTYPE>& ctx)
      : mlx_object_(), ctx({ctx.first, ctx.second}){};
  mlx_vector_SCTYPE_(
      const std::tuple<CPPTYPE, CPPTYPE, CPPTYPE>&
          ctx)
      : mlx_object_(),
        ctx({std::get<0>(ctx), std::get<1>(ctx), std::get<2>(ctx)}){};
  virtual mlx_string_* tostring() override;
  std::vector<CPPTYPE> ctx;
};
"""


def generate(
    code,
    cpptype,
    ctype,
    sctype,
    c_to_cpp=lambda s: s + "->ctx",
    return_cpp_to_c=lambda s: "RETURN_MLX_C_PTR(new CTYPE_(" + s + "))",
):
    code = replace_match_parenthesis(code, "C_TO_CPP", c_to_cpp)
    code = replace_match_parenthesis(code, "RETURN_CPP_TO_C", return_cpp_to_c)
    code = code.replace("SCTYPE", sctype)
    code = code.replace("CPPTYPE", cpptype)
    code = code.replace("CTYPE", ctype)
    return code


decl_begin = """/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_VECTOR_H
#define MLX_VECTOR_H

#include "mlx/c/array.h"
#include "mlx/c/string.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_vector Vectors
 * MLX vector objects.
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
#include "mlx/c/vector.h"
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

#ifndef MLX_VECTOR_PRIVATE_H
#define MLX_VECTOR_PRIVATE_H

#include "mlx/c/object.h"
#include "mlx/c/vector.h"
#include "mlx/c/private/object.h"
#include "mlx/mlx.h"
"""

priv_end = """
#endif
"""

if args.implementation:
    code = impl_code
    begin = impl_begin
    end = impl_end
elif args.private:
    code = priv_code
    begin = priv_begin
    end = priv_end
else:
    code = decl_code
    begin = decl_begin
    end = decl_end

print(begin)
print(
    generate(
        code,
        "mlx::core::array",
        "mlx_array",
        "array",
    )
)
print(
    generate(
        code,
        "std::vector<mlx::core::array>",
        "mlx_vector_array",
        "vector_array",
    )
)
print(
    generate(
        code,
        "int",
        "int",
        "int",
        lambda s: s,
        lambda s: "return " + s,
    )
)
print(
    generate(
        code,
        "std::vector<int>",
        "mlx_vector_int",
        "vector_int",
    )
)
print(
    generate(
        code,
        "std::string",
        "mlx_string",
        "string",
    )
)
print(
    generate(
        code,
        "mlx::core::Dtype",
        "mlx_array_dtype",
        "array_dtype",
        lambda s: "MLX_CPP_ARRAY_DTYPE(" + s + ")",
        lambda s: "RETURN_MLX_C_ARRAY_DTYPE(" + s + ")",
    )
)
if not args.implementation and not args.private:
    # avoid circular dependencies
    print(
        """
typedef struct mlx_tuple_string_variant_int_bool_array_dtype_* mlx_tuple_string_variant_int_bool_array_dtype;
    """
    )
print(
    generate(
        code,
        "std::pair<std::string, std::variant<int, bool, mlx::core::Dtype>>",
        "mlx_tuple_string_variant_int_bool_array_dtype",
        "tuple_string_variant_int_bool_array_dtype",
    )
)
print(end)
