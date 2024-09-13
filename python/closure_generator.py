import argparse
import regex
import string
import mlxtypes as mt

parser = argparse.ArgumentParser("MLX C closure code generator", add_help=False)
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
typedef struct NAME_* NAME;
NAME NAME_new(RCARG (*fun)(CARGS));
NAME NAME_new_with_payload(
    RCARG (*fun)(CARGS, void*),
    void* payload,
    void (*dtor)(void*));
RCARG NAME_apply(NAME cls, CARGS_TYPE_NAME);
"""


def generate(code, name, rctype, ctypes):
    cargs_name = []
    cargs_type_name = []
    cppargs_type_name = []
    cppargs_to_cargs = []
    cargs_free = []
    cargs_ctx = []
    for i in range(len(ctypes)):
        ctype = mt.ctypes[ctypes[i]]
        cpparg = ctype["cpp"]
        suffix = "_" + str(i) if len(ctypes) > 1 else ""
        cargs_name.append("input" + suffix)
        cargs_type_name.append(ctype["c_arg"]("input" + suffix))
        cppargs_type_name.append(ctype["cpp_arg"]("cpp_input" + suffix))
        cppargs_to_cargs.append(
            "auto input"
            + suffix
            + " = "
            + ctype["cpp_to_c"]("cpp_input" + suffix)
            + ";"
        )
        cargs_free.append(ctype["free"]("input" + suffix) + ";")
        cargs_ctx.append(ctype["c_to_cpp"]("input" + suffix))

    cargs_name = ", ".join(cargs_name)
    cargs_type_name = ", ".join(cargs_type_name)
    cppargs_type_name = ", ".join(cppargs_type_name)
    cppargs_to_cargs = "\n".join(cppargs_to_cargs)
    cargs_free = "\n".join(cargs_free)
    cargs_ctx = ", ".join(cargs_ctx)
    cppargs = ", ".join([mt.ctypes[ctype]["cpp_arg"]("") for ctype in ctypes])
    cargs = " ".join([mt.ctypes[ctype]["c_arg"]("") for ctype in ctypes])

    code = replace_match_parenthesis(
        code,
        "RETURN_CPP_TO_C",
        lambda s: mt.ctypes[rctype]["return"](mt.ctypes[rctype]["cpp_to_c"](s)),
    )
    code = code.replace("CARGS_TYPE_NAME", cargs_type_name)
    code = code.replace("CPPARGS_TYPE_NAME", cppargs_type_name)
    code = code.replace("CPPARGS_TO_CARGS", cppargs_to_cargs)
    code = code.replace("CARGS_FREE", cargs_free)
    code = code.replace("CARGS_NAME", cargs_name)
    code = code.replace("CARGS_CTX", cargs_ctx)
    code = code.replace(
        "CARGS", ", ".join([mt.ctypes[ctype]["c_arg"]("") for ctype in ctypes])
    )
    code = code.replace("CPPARGS", cppargs)
    code = code.replace("NAME", name)
    code = code.replace("RCARG", mt.ctypes[rctype]["c"])
    code = code.replace("RCPPARG", mt.ctypes[rctype]["cpp"])

    return code


impl_code = """
mlx_string_* NAME_::tostring() {
  RETURN_MLX_C_STRING("RCARG mlx_closure(CARGS, void*)");
}

extern "C" NAME NAME_new(
    RCARG (*fun)(CARGS)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](CPPARGS_TYPE_NAME) {
            CPPARGS_TO_CARGS
            auto res = fun(CARGS_NAME);
            CARGS_FREE
            auto cpp_res = res->ctx;
            mlx_free(res);
            return cpp_res;
          };
      return new NAME_(cpp_closure), return nullptr);
}

extern "C" NAME NAME_new_with_payload(
    RCARG (*fun)(CARGS, void*),
    void* payload,
    void (*dtor)(void*)) {
  auto cpp_payload = std::shared_ptr<void>(payload, dtor);
  auto cpp_closure =
      [fun, cpp_payload, dtor](CPPARGS_TYPE_NAME) {
        CPPARGS_TO_CARGS
        auto res = fun(CARGS_NAME, cpp_payload.get());
        CARGS_FREE
        auto cpp_res = res->ctx;
        mlx_free(res);
        return cpp_res;
      };
  MLX_TRY_CATCH(return new NAME_(cpp_closure), return nullptr);
}

extern "C" RCARG NAME_apply(
    NAME cls,
    CARGS_TYPE_NAME) {
  RETURN_CPP_TO_C(cls->ctx(CARGS_CTX));
}
"""

priv_code = """
struct NAME_ : mlx_object_ {
  NAME_(std::function<RCPPARG(CPPARGS)> ctx)
      : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  std::function<RCPPARG(CPPARGS)> ctx;
};
"""

decl_begin = """/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_CLOSURE_H
#define MLX_CLOSURE_H

#include "mlx/c/array.h"
#include "mlx/c/optional.h"
#include "mlx/c/stream.h"
#include "mlx/c/tuple.h"
#include "mlx/c/vector.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_closure Closures
 * MLX closure objects.
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

#include "mlx/c/closure.h"
#include "mlx/c/object.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/stream.h"
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

#ifndef MLX_CLOSURE_PRIVATE_H
#define MLX_CLOSURE_PRIVATE_H

#include "mlx/c/closure.h"
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
        "mlx_closure",
        "mlx_vector_array",
        ["mlx_vector_array"],
    )
)
if args.implementation:
    print(
        """
extern "C" mlx_closure mlx_closure_new_unary(
    mlx_array (*fun)(const mlx_array)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](const std::vector<mlx::core::array>& cpp_input) {
            if (cpp_input.size() != 1) {
              throw std::runtime_error("closure: expected unary input");
            }
            auto input = new mlx_array_(cpp_input[0]);
            auto res = fun(input);
            mlx_free(input);
            std::vector<mlx::core::array> cpp_res = {res->ctx};
            mlx_free(res);
            return cpp_res;
          };
      return new mlx_closure_(cpp_closure), return nullptr);
}
"""
    )
elif args.private:
    pass
else:
    print(
        """
mlx_closure mlx_closure_new_unary(mlx_array (*fun)(const mlx_array));        
    """
    )
print(
    generate(
        code,
        "mlx_closure_value_and_grad",
        "mlx_tuple_vector_array_vector_array",
        ["mlx_vector_array"],
    )
)
print(
    generate(
        code,
        "mlx_closure_custom_function",
        "mlx_vector_array",
        ["mlx_vector_array"] * 3,
    )
)
print(
    generate(
        code,
        "mlx_closure_custom_function_jvp",
        "mlx_vector_array",
        ["mlx_vector_array", "mlx_vector_array", "mlx_vector_int"],
    )
)
print(
    generate(
        code,
        "mlx_closure_custom_function_vmap",
        "mlx_tuple_vector_array_vector_int",
        ["mlx_vector_array", "mlx_vector_int"],
    )
)
print(
    generate(
        code,
        "mlx_closure_metal_kernel_function",
        "mlx_vector_array",
        [
            "mlx_vector_array",
            "mlx_vector_vector_int",
            "mlx_vector_array_dtype",
            "mlx_tuple_int_int_int",
            "mlx_tuple_int_int_int",
            "mlx_vector_tuple_string_variant_int_bool_array_dtype",
            "mlx_optional_float",
            "bool",
            "mlx_stream",
        ],
    )
)
print(end)
