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
mlx_vector_SCTYPE mlx_vector_SCTYPE_new_data(CTYPE* data, size_t size);
mlx_vector_SCTYPE mlx_vector_SCTYPE_new_value(CTYPE val);
int mlx_vector_SCTYPE_set_data(mlx_vector_SCTYPE vec, CTYPE* data, size_t size);
int mlx_vector_SCTYPE_set_value(mlx_vector_SCTYPE vec, CTYPE val);
void mlx_vector_SCTYPE_add_data(mlx_vector_SCTYPE vec,  CTYPE* data, size_t size);
void mlx_vector_SCTYPE_add_value(mlx_vector_SCTYPE vec, CTYPE val);
size_t mlx_vector_SCTYPE_size(mlx_vector_SCTYPE vec);
int mlx_vector_SCTYPE_get(mlx_vector_SCTYPE vec, size_t idx, RETURN_CTYPE);
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

extern "C" mlx_vector_SCTYPE mlx_vector_SCTYPE_new_data(
    CTYPE* data,
    size_t size) {
  std::vector<CPPTYPE> cpp_arrs;
  for (size_t i = 0; i < size; i++) {
    cpp_arrs.push_back(C_TO_CPP(data[i]));
  }
  RETURN_MLX_C_PTR(new mlx_vector_SCTYPE_(cpp_arrs))
}

extern "C" mlx_vector_SCTYPE mlx_vector_SCTYPE_new_value(CTYPE val) {
  RETURN_MLX_C_PTR(new mlx_vector_SCTYPE_({C_TO_CPP(val)}))
}

extern "C" int mlx_vector_SCTYPE_set_data(
    mlx_vector_SCTYPE vec,
    CTYPE* data,
    size_t size) {
  try {
    std::vector<CPPTYPE> cpp_arrs;
    for (size_t i = 0; i < size; i++) {
      cpp_arrs.push_back(C_TO_CPP(data[i]));
    }
    vec->ctx = cpp_arrs;
  } catch (std::exception & e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_vector_SCTYPE_set_value(mlx_vector_SCTYPE vec, CTYPE val) {
  try {
    vec->ctx = std::vector<CPPTYPE>({C_TO_CPP(val)});
  } catch (std::exception & e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" void mlx_vector_SCTYPE_add_data(
    mlx_vector_SCTYPE vec,
    CTYPE* data,
    size_t size) {
  MLX_TRY_CATCH(
      for (size_t i = 0; i < size;
           i++) { vec->ctx.push_back(C_TO_CPP(data[i])); }, );
}

extern "C" void mlx_vector_SCTYPE_add_value(
    mlx_vector_SCTYPE vec,
    CTYPE value) {
  MLX_TRY_CATCH(vec->ctx.push_back(C_TO_CPP(value));, )
}

extern "C" int mlx_vector_SCTYPE_get(mlx_vector_SCTYPE vec, size_t index, RETURN_CTYPE res) {
  try {
    C_ASSIGN(res, vec->ctx.at(index));
  } catch (std::exception & e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
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
    rctype=None,
    c_to_cpp=lambda s: s + "->ctx",
    c_assign=lambda d, s: d + "->ctx = " + s,
):
    if rctype is None:
        rctype = ctype.replace("const ", "")

    def c_assign_wrap(s):
        d, s = s.split(",")
        return c_assign(d, s)

    code = replace_match_parenthesis(code, "C_ASSIGN", c_assign_wrap)
    code = replace_match_parenthesis(code, "C_TO_CPP", c_to_cpp)
    code = code.replace("RETURN_CTYPE", rctype)
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
        "const mlx_array",
        "array",
    )
)
print(
    generate(
        code,
        "std::vector<mlx::core::array>",
        "const mlx_vector_array",
        "vector_array",
    )
)
print(
    generate(
        code,
        "int",
        "int",
        "int",
        "int*",
        lambda s: s,
        lambda d, s: "*" + d + " = " + s,
    )
)
print(
    generate(
        code,
        "std::vector<int>",
        "const mlx_vector_int",
        "vector_int",
    )
)
print(
    generate(
        code,
        "std::string",
        "const char*",
        "string",
        "char**",
        lambda s: s,
        lambda d, s: "*" + d + " = " + s + ".data()",
    )
)
print(end)
