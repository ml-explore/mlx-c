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
NAME NAME_new();
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
            cpptype["c_assign_from_cpp"]("input" + suffix, "cpp_input" + suffix) + ";"
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
        mt.cpptypes[rcpptype]["c_assign_from_cpp"]("res", "cls->ctx(" + cargs_ctx + ")")
        + ";",
    )

    code = code.replace("CPPARGS", cppargs)
    code = code.replace("NAME", name)
    code = code.replace("RCARGS", rcargs)
    code = code.replace("CARGS", cargs)

    return code


impl_code = """
mlx_string_* NAME_::tostring() {
  RETURN_MLX_C_STRING("void mlx_closure(CARGS_UNNAMED, void*, RCARGS_UNNAMED)");
}

extern "C" NAME NAME_new() {
  try {
    auto cpp_closure =
          [](CPPARGS_TYPE_NAME) {
              return RCPPARG();
          };
    return new NAME_(cpp_closure);
  } catch (std::exception & e) {
    mlx_error(e.what());
    return nullptr;
  }
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
      return new NAME_(cpp_closure), return nullptr);
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
  MLX_TRY_CATCH(return new NAME_(cpp_closure), return nullptr);
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
        "std::vector<mlx::core::array>",
        ["std::vector<mlx::core::array>"],
    )
)
if args.implementation:
    print(
        """
extern "C" mlx_closure mlx_closure_new_unary(
    void (*fun)(const mlx_array, mlx_array)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](const std::vector<mlx::core::array>& cpp_input) {
            if (cpp_input.size() != 1) {
              throw std::runtime_error("closure: expected unary input");
            }
            auto input = new mlx_array_(cpp_input[0]);
            auto res = new mlx_array_();
            fun(input, res);
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
mlx_closure mlx_closure_new_unary(void (*fun)(const mlx_array, mlx_array));
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
    struct mlx_closure_metal_kernel_desc_ : mlx_object_ {
    mlx_closure_metal_kernel_desc_()
      : mlx_object_() {};
  virtual mlx_string_* tostring() override;

    std::vector<std::vector<int>> output_shapes;
    std::vector<mlx::core::Dtype> output_dtypes;
    std::tuple<int, int, int> grid;
    std::tuple<int, int, int> thread_group;
    std::vector<std::pair<std::string, mlx::core::fast::TemplateArg>> template_args;
    std::optional<float> init_value;
    bool verbose;
};

struct mlx_closure_metal_kernel_ : mlx_object_ {
  mlx_closure_metal_kernel_() : mlx_object_() {
    ctx = [](const std::vector<mlx::core::array>&,
    const std::vector<std::vector<int>>&,
    const std::vector<mlx::core::Dtype>&,
    std::tuple<int, int, int>,
    std::tuple<int, int, int>,
    std::vector<std::pair<std::string, mlx::core::fast::TemplateArg>>,
    std::optional<float>,
    bool,
    mlx::core::StreamOrDevice) {
      return std::vector<mlx::core::array>();
    };
  };
  mlx_closure_metal_kernel_(mlx::core::fast::MetalKernelFunction ctx)
      : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  mlx::core::fast::MetalKernelFunction ctx;
};
    """
    )
elif args.implementation:
    print(
        """

mlx_string_* mlx_closure_metal_kernel_desc_::tostring() {
  RETURN_MLX_C_STRING(
      "mlx_closure_metal_kernel_desc");
}

extern "C" mlx_closure_metal_kernel_desc mlx_closure_metal_kernel_desc_new() {
  try {
    return new mlx_closure_metal_kernel_desc_();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return nullptr;
  }
}

extern "C" int mlx_closure_metal_kernel_desc_add_output_arg(mlx_closure_metal_kernel_desc desc, const int* shape, size_t size, mlx_dtype dtype) {
  try {
    desc->output_shapes.push_back(std::vector<int>(shape, shape+size));
    desc->output_dtypes.push_back(mlx_dtype_to_cpp(dtype));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_closure_metal_kernel_desc_set_grid(mlx_closure_metal_kernel_desc desc, int grid1, int grid2, int grid3) {
  try {
    desc->grid = std::make_tuple(grid1, grid2, grid3);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_closure_metal_kernel_desc_set_thread_group(mlx_closure_metal_kernel_desc desc, int thread1, int thread2, int thread3) {
  try {
    desc->thread_group = std::make_tuple(thread1, thread2, thread3);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_closure_metal_kernel_desc_set_init_value(mlx_closure_metal_kernel_desc desc, float value){
  try {
    desc->init_value = value;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_closure_metal_kernel_desc_set_verbose(mlx_closure_metal_kernel_desc desc, bool verbose) {
  try {
    desc->verbose = verbose;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_closure_metal_kernel_desc_add_template_arg_dtype(mlx_closure_metal_kernel_desc desc, const char* name, mlx_dtype dtype) {
  try {
    desc->template_args.push_back(std::make_pair(std::string(name), mlx_dtype_to_cpp(dtype)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_closure_metal_kernel_desc_add_template_arg_int(mlx_closure_metal_kernel_desc desc, const char *name, int value) {
  try {
    desc->template_args.push_back(std::make_pair(std::string(name), value));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_closure_metal_kernel_desc_add_template_arg_bool(mlx_closure_metal_kernel_desc desc, const char* name, bool value)  {
  try {
    desc->template_args.push_back(std::make_pair(std::string(name), value));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

mlx_string_* mlx_closure_metal_kernel_::tostring() {
  RETURN_MLX_C_STRING(
      "mlx_closure_metal_kernel_");
}

extern "C" mlx_closure_metal_kernel mlx_closure_metal_kernel_new() {
  try {
    return new mlx_closure_metal_kernel_();
  } catch (std::exception& e) {
    mlx_error(e.what());
  }
  return nullptr;
}
extern "C" int mlx_closure_metal_kernel_apply(mlx_closure_metal_kernel cls, const mlx_vector_array inputs, const mlx_closure_metal_kernel_desc desc, const mlx_stream stream, mlx_vector_array outputs) {
  try {
    outputs->ctx = cls->ctx(inputs->ctx, desc->output_shapes, desc->output_dtypes, desc->grid, desc->thread_group, desc->template_args, desc->init_value, desc->verbose, stream->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
    """
    )
else:
    print(
        """
typedef struct mlx_closure_metal_kernel_desc_* mlx_closure_metal_kernel_desc;
mlx_closure_metal_kernel_desc mlx_closure_metal_kernel_desc_new();
int mlx_closure_metal_kernel_desc_add_output_arg(mlx_closure_metal_kernel_desc desc, const int* shape, size_t size, mlx_dtype dtype);
int mlx_closure_metal_kernel_desc_set_grid(mlx_closure_metal_kernel_desc desc, int grid1, int grid2, int grid3);
int mlx_closure_metal_kernel_desc_set_thread_group(mlx_closure_metal_kernel_desc desc, int thread1, int thread2, int thread3);
int mlx_closure_metal_kernel_desc_set_init_value(mlx_closure_metal_kernel_desc desc, float value);
int mlx_closure_metal_kernel_desc_set_verbose(mlx_closure_metal_kernel_desc desc, bool verbose);
int mlx_closure_metal_kernel_desc_add_template_arg_dtype(mlx_closure_metal_kernel_desc desc, const char* name, mlx_dtype dtype);
int mlx_closure_metal_kernel_desc_add_template_arg_int(mlx_closure_metal_kernel_desc desc, const char* name, int value);
int mlx_closure_metal_kernel_desc_add_template_arg_bool(mlx_closure_metal_kernel_desc desc, const char* name, bool value);

typedef struct mlx_closure_metal_kernel_* mlx_closure_metal_kernel;
mlx_closure_metal_kernel mlx_closure_metal_kernel_new();
int mlx_closure_metal_kernel_apply(mlx_closure_metal_kernel cls, const mlx_vector_array inputs, const mlx_closure_metal_kernel_desc desc, const mlx_stream stream, mlx_vector_array outputs);
    """
    )

print(end)
