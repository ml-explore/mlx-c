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
typedef struct NAME_ { void* ctx; } NAME;
NAME NAME_new();
void NAME_free(NAME cls);
NAME NAME_new_func(void (*fun)(CARGS_UNNAMED, RCARGS_UNNAMED));
NAME NAME_new_func_payload(
    void (*fun)(CARGS_UNNAMED, void*, RCARGS_UNNAMED),
    void* payload,
    void (*dtor)(void*));
int NAME_apply(NAME cls, CARGS, RCARGS);
"""


def generate(code, name, rcpptype, cpptypes):
    cargs_untyped = []
    cargs = []
    cppargs_type_name = []
    cppargs_to_cargs = []
    cargs_free = []
    cargs_ctx = []
    for i in range(len(cpptypes)):
        cpptype = mt.cpptypes[cpptypes[i]]
        cpparg = cpptype["cpp"]
        suffix = "_" + str(i) if len(cpptypes) > 1 else ""
        cargs_untyped.append(cpptype["c_arg"]("input" + suffix, untyped=True))
        cargs.append(cpptype["c_arg"]("input" + suffix))
        cppargs_type_name.append(cpptype["cpp_arg"]("cpp_input" + suffix))
        cargs_free.append(cpptype["free"]("input" + suffix) + ";")
        cargs_ctx.append(cpptype["c_to_cpp"]("input" + suffix))
        cppargs_to_cargs.append(cpptype["c_new"]("input" + suffix) + ";")
        cppargs_to_cargs.append(
            cpptype["c_assign_from_cpp"](
                "input" + suffix, "cpp_input" + suffix, returned=False
            )
            + ";"
        )

    rcargs_new = mt.cpptypes[rcpptype]["c_new"]("res") + ";"
    rcargs_free = mt.cpptypes[rcpptype]["free"]("res") + ";"
    rcargs_to_cpp = "auto cpp_res = " + mt.cpptypes[rcpptype]["c_to_cpp"]("res") + ";"

    cargs_untyped = ", ".join(cargs_untyped)
    cargs = ", ".join(cargs)
    cppargs_type_name = ", ".join(cppargs_type_name)
    cppargs_to_cargs = "\n".join(cppargs_to_cargs)
    cargs_free = "\n".join(cargs_free)
    cargs_ctx = ", ".join(cargs_ctx)
    cppargs = ", ".join([mt.cpptypes[cpptype]["cpp_arg"]("") for cpptype in cpptypes])
    cargs_unnamed = " ".join(
        [mt.cpptypes[cpptype]["c_arg"]("") for cpptype in cpptypes]
    )
    rcargs_unnamed = mt.cpptypes[rcpptype]["c_return_arg"]("")
    rcargs = mt.cpptypes[rcpptype]["c_return_arg"]("res")
    rcargs_untyped = mt.cpptypes[rcpptype]["c_return_arg"]("res", untyped=True)

    code = code.replace("RCARGS_UNTYPED", rcargs_untyped)
    code = code.replace("RCARGS_UNNAMED", rcargs_unnamed)
    code = code.replace("CPPARGS_TYPE_NAME", cppargs_type_name)
    code = code.replace("CPPARGS_TO_CARGS", cppargs_to_cargs)
    code = code.replace("RCARGS_NEW", rcargs_new)
    code = code.replace("RCARGS_FREE", rcargs_free)
    code = code.replace("RCARGS_TO_CPP", rcargs_to_cpp)
    code = code.replace("CARGS_UNTYPED", cargs_untyped)
    code = code.replace("CARGS_CTX", cargs_ctx)
    code = code.replace("CARGS_FREE", cargs_free)
    code = code.replace("RCPPARG", mt.cpptypes[rcpptype]["cpp"].replace("@", ""))
    code = code.replace(
        "CARGS_UNNAMED",
        ", ".join([mt.cpptypes[cpptype]["c_arg"]("") for cpptype in cpptypes]),
    )

    code = code.replace(
        "ASSIGN_CLS_TO_RCARGS",
        mt.cpptypes[rcpptype]["c_assign_from_cpp"](
            "res", "NAME_get_(cls)(" + cargs_ctx + ")", returned=True
        )
        + ";",
    )

    code = code.replace("CPPARGS", cppargs)
    code = code.replace("NAME", name)
    code = code.replace("RCARGS", rcargs)
    code = code.replace("CARGS", cargs)

    return code


impl_code = """
extern "C" NAME NAME_new() {
  try {
    auto cpp_closure =
          [](CPPARGS_TYPE_NAME) {
              return RCPPARG();
          };
    return NAME_new_(cpp_closure);
  } catch (std::exception & e) {
    mlx_error(e.what());
    return {nullptr};
  }
}

extern "C" void NAME_free(NAME cls) {
  NAME_free_(cls);
}

extern "C" NAME NAME_new_func(
    void (*fun)(CARGS_UNNAMED, RCARGS_UNNAMED)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](CPPARGS_TYPE_NAME) {
            CPPARGS_TO_CARGS
            RCARGS_NEW
            fun(CARGS_UNTYPED, RCARGS_UNTYPED);
            CARGS_FREE
            RCARGS_TO_CPP
            RCARGS_FREE
            return cpp_res;
          };
      return NAME_new_(cpp_closure), return {nullptr});
}

extern "C" NAME NAME_new_func_payload(
    void (*fun)(CARGS_UNNAMED, void*, RCARGS_UNNAMED),
    void* payload,
    void (*dtor)(void*)) {
  auto cpp_payload = std::shared_ptr<void>(payload, dtor);
  auto cpp_closure =
      [fun, cpp_payload, dtor](CPPARGS_TYPE_NAME) {
        CPPARGS_TO_CARGS
        RCARGS_NEW
        fun(CARGS_UNTYPED, cpp_payload.get(), RCARGS_UNTYPED);
        CARGS_FREE
        RCARGS_TO_CPP
        RCARGS_FREE
        return cpp_res;
      };
  MLX_TRY_CATCH(return NAME_new_(cpp_closure), return {nullptr});
}

extern "C" int NAME_apply(
    NAME cls,
    CARGS, RCARGS) {
  try {
  ASSIGN_CLS_TO_RCARGS
  } catch (std::exception & e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
"""

priv_code = """
inline NAME NAME_new_(std::function<RCPPARG(CPPARGS)>&& s) {
  return NAME({new std::function<RCPPARG(CPPARGS)>(std::move(s))});
}

inline NAME& NAME_set_(NAME& d, std::function<RCPPARG(CPPARGS)> s) {
  if (d.ctx) {
    *static_cast<std::function<RCPPARG(CPPARGS)>*>(d.ctx) = s;
  } else {
    d.ctx = new std::function<RCPPARG(CPPARGS)>(s);
  }
  return d;
}

inline std::function<RCPPARG(CPPARGS)>& NAME_get_(NAME d) {
  return *static_cast<std::function<RCPPARG(CPPARGS)>*>(d.ctx);
}

inline void NAME_free_(NAME d) {
  if (d.ctx) {
    delete static_cast<std::function<RCPPARG(CPPARGS)>*>(d.ctx);
  }
}
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
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/stream.h"
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

#ifndef MLX_CLOSURE_PRIVATE_H
#define MLX_CLOSURE_PRIVATE_H

#include "mlx/c/closure.h"
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
        "std::vector<mlx::core::array>",
        ["std::vector<mlx::core::array>"],
    )
)
if args.implementation:
    print(
        """
extern "C" mlx_closure mlx_closure_new_unary(
    void (*fun)(const mlx_array, mlx_array*)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](const std::vector<mlx::core::array>& cpp_input) {
            if (cpp_input.size() != 1) {
              throw std::runtime_error("closure: expected unary input");
            }
            auto input = mlx_array_new_(cpp_input[0]);
            auto res = mlx_array_new_();
            fun(input, &res);
            mlx_array_free(input);
            std::vector<mlx::core::array> cpp_res = {mlx_array_get_(res)};
            mlx_array_free(res);
            return cpp_res;
          };
      return mlx_closure_new_(cpp_closure), return {nullptr});
}
"""
    )
elif args.private:
    pass
else:
    print(
        """
mlx_closure mlx_closure_new_unary(void (*fun)(const mlx_array, mlx_array*));
    """
    )
print(
    generate(
        code,
        "mlx_closure_value_and_grad",
        "std::pair<std::vector<mlx::core::array>, std::vector<mlx::core::array>>",
        ["std::vector<mlx::core::array>"],
    )
)
print(
    generate(
        code,
        "mlx_closure_custom",
        "std::vector<mlx::core::array>",
        ["std::vector<mlx::core::array>"] * 3,
    )
)
print(
    generate(
        code,
        "mlx_closure_custom_jvp",
        "std::vector<mlx::core::array>",
        [
            "std::vector<mlx::core::array>",
            "std::vector<mlx::core::array>",
            "std::vector<int>",
        ],
    )
)
print(
    generate(
        code,
        "mlx_closure_custom_vmap",
        "std::pair<std::vector<mlx::core::array>, @std::vector<int>>",
        ["std::vector<mlx::core::array>", "std::vector<int>"],
    )
)
if args.private:
    print(
        """
     """
    )

print(end)
