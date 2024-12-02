/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/fast.h"
#include "mlx/c/error.h"
#include "mlx/c/private/mlx.h"
#include "mlx/fast.h"

extern "C" int mlx_fast_affine_dequantize(
    mlx_array* res,
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases,
    int group_size,
    int bits,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::fast::affine_dequantize(
            mlx_array_get_(w),
            mlx_array_get_(scales),
            mlx_array_get_(biases),
            group_size,
            bits,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_affine_quantize(
    mlx_array* res_0,
    mlx_array* res_1,
    mlx_array* res_2,
    const mlx_array w,
    int group_size,
    int bits,
    const mlx_stream s) {
  try {
    {
      auto [tpl_0, tpl_1, tpl_2] = mlx::core::fast::affine_quantize(
          mlx_array_get_(w), group_size, bits, mlx_stream_get_(s));
      mlx_array_set_(*res_0, tpl_0);
      mlx_array_set_(*res_1, tpl_1);
      mlx_array_set_(*res_2, tpl_2);
    };
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_layer_norm(
    mlx_array* res,
    const mlx_array x,
    const mlx_array weight /* may be null */,
    const mlx_array bias /* may be null */,
    float eps,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::fast::layer_norm(
            mlx_array_get_(x),
            (weight.ctx ? std::make_optional(mlx_array_get_(weight))
                        : std::nullopt),
            (bias.ctx ? std::make_optional(mlx_array_get_(bias))
                      : std::nullopt),
            eps,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

struct mlx_fast_metal_kernel_private_ {
  mlx::core::fast::MetalKernelFunction ctx;
  std::string name;
  std::vector<std::string> input_names;
  std::vector<std::string> output_names;
  std::string source;
  std::string header;
  bool contiguous_rows;
  bool atomic_outputs;

  std::vector<std::vector<int>> output_shapes;
  std::vector<mlx::core::Dtype> output_dtypes;
  std::tuple<int, int, int> grid;
  std::tuple<int, int, int> thread_group;
  std::vector<std::pair<std::string, mlx::core::fast::TemplateArg>>
      template_args;
  std::optional<float> init_value;
  bool verbose;
};

inline mlx_fast_metal_kernel mlx_fast_metal_kernel_new_() {
  return mlx_fast_metal_kernel({new mlx_fast_metal_kernel_private_()});
}

inline mlx_fast_metal_kernel_private_& mlx_fast_metal_kernel_get_(
    mlx_fast_metal_kernel d) {
  return *static_cast<mlx_fast_metal_kernel_private_*>(d.ctx);
}

inline void mlx_fast_metal_kernel_free_(mlx_fast_metal_kernel d) {
  if (d.ctx) {
    delete static_cast<mlx_fast_metal_kernel_private_*>(d.ctx);
  }
}

extern "C" void mlx_fast_metal_kernel_free(mlx_fast_metal_kernel cls) {
  mlx_fast_metal_kernel_free_(cls);
}

extern "C" int mlx_fast_metal_kernel_add_output_arg(
    mlx_fast_metal_kernel cls,
    const int* shape,
    size_t size,
    mlx_dtype dtype) {
  try {
    mlx_fast_metal_kernel_get_(cls).output_shapes.push_back(
        std::vector<int>(shape, shape + size));
    mlx_fast_metal_kernel_get_(cls).output_dtypes.push_back(
        mlx_dtype_to_cpp(dtype));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_grid(
    mlx_fast_metal_kernel cls,
    int grid1,
    int grid2,
    int grid3) {
  try {
    mlx_fast_metal_kernel_get_(cls).grid = std::make_tuple(grid1, grid2, grid3);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_thread_group(
    mlx_fast_metal_kernel cls,
    int thread1,
    int thread2,
    int thread3) {
  try {
    mlx_fast_metal_kernel_get_(cls).thread_group =
        std::make_tuple(thread1, thread2, thread3);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_init_value(
    mlx_fast_metal_kernel cls,
    float value) {
  try {
    mlx_fast_metal_kernel_get_(cls).init_value = value;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_verbose(
    mlx_fast_metal_kernel cls,
    bool verbose) {
  try {
    mlx_fast_metal_kernel_get_(cls).verbose = verbose;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_add_template_arg_dtype(
    mlx_fast_metal_kernel cls,
    const char* name,
    mlx_dtype dtype) {
  try {
    mlx_fast_metal_kernel_get_(cls).template_args.push_back(
        std::make_pair(std::string(name), mlx_dtype_to_cpp(dtype)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_add_template_arg_int(
    mlx_fast_metal_kernel cls,
    const char* name,
    int value) {
  try {
    mlx_fast_metal_kernel_get_(cls).template_args.push_back(
        std::make_pair(std::string(name), value));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_add_template_arg_bool(
    mlx_fast_metal_kernel cls,
    const char* name,
    bool value) {
  try {
    mlx_fast_metal_kernel_get_(cls).template_args.push_back(
        std::make_pair(std::string(name), value));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" mlx_fast_metal_kernel mlx_fast_metal_kernel_new(
    const char* name,
    const char* source,
    const char* header) {
  try {
    auto cls = mlx_fast_metal_kernel_new_();
    mlx_fast_metal_kernel_get_(cls).name = std::string(name);
    mlx_fast_metal_kernel_get_(cls).source = std::string(source);
    mlx_fast_metal_kernel_get_(cls).header = std::string(header);
    return cls;
  } catch (std::exception& e) {
    mlx_error(e.what());
  }
  return {nullptr};
}
extern "C" int mlx_fast_metal_kernel_add_input_name(
    mlx_fast_metal_kernel cls,
    const char* name) {
  try {
    mlx_fast_metal_kernel_get_(cls).input_names.push_back(name);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_fast_metal_kernel_set_input_names(mlx_fast_metal_kernel cls, int num, ...) {
  try {
    va_list input_names;
    va_start(input_names, num);
    mlx_fast_metal_kernel_get_(cls).input_names.clear();
    for (int i = 0; i < num; i++) {
      mlx_fast_metal_kernel_get_(cls).input_names.push_back(
          va_arg(input_names, const char*));
    }
    va_end(input_names);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_add_output_name(
    mlx_fast_metal_kernel cls,
    const char* name) {
  try {
    mlx_fast_metal_kernel_get_(cls).output_names.push_back(name);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_output_names(
    mlx_fast_metal_kernel cls,
    int num,
    ...) {
  try {
    va_list output_names;
    va_start(output_names, num);
    mlx_fast_metal_kernel_get_(cls).output_names.clear();
    for (int i = 0; i < num; i++) {
      mlx_fast_metal_kernel_get_(cls).output_names.push_back(
          va_arg(output_names, const char*));
    }
    va_end(output_names);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_contiguous_rows(
    mlx_fast_metal_kernel cls,
    bool flag) {
  mlx_fast_metal_kernel_get_(cls).contiguous_rows = flag;
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_atomic_outputs(
    mlx_fast_metal_kernel cls,
    bool flag) {
  mlx_fast_metal_kernel_get_(cls).atomic_outputs = flag;
  return 0;
}
extern "C" int mlx_fast_metal_kernel_apply(
    mlx_vector_array* outputs,
    mlx_fast_metal_kernel cls,
    const mlx_vector_array inputs,
    const mlx_stream stream) {
  try {
    if (!mlx_fast_metal_kernel_get_(cls).ctx) {
      mlx_fast_metal_kernel_get_(cls).ctx = mlx::core::fast::metal_kernel(
          mlx_fast_metal_kernel_get_(cls).name,
          mlx_fast_metal_kernel_get_(cls).input_names,
          mlx_fast_metal_kernel_get_(cls).output_names,
          mlx_fast_metal_kernel_get_(cls).source,
          mlx_fast_metal_kernel_get_(cls).header,
          mlx_fast_metal_kernel_get_(cls).contiguous_rows,
          mlx_fast_metal_kernel_get_(cls).atomic_outputs);
    }
    mlx_vector_array_set_(
        *outputs,
        mlx_fast_metal_kernel_get_(cls).ctx(
            mlx_vector_array_get_(inputs),
            mlx_fast_metal_kernel_get_(cls).output_shapes,
            mlx_fast_metal_kernel_get_(cls).output_dtypes,
            mlx_fast_metal_kernel_get_(cls).grid,
            mlx_fast_metal_kernel_get_(cls).thread_group,
            mlx_fast_metal_kernel_get_(cls).template_args,
            mlx_fast_metal_kernel_get_(cls).init_value,
            mlx_fast_metal_kernel_get_(cls).verbose,
            mlx_stream_get_(stream)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_fast_rms_norm(
    mlx_array* res,
    const mlx_array x,
    const mlx_array weight,
    float eps,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::fast::rms_norm(
            mlx_array_get_(x),
            mlx_array_get_(weight),
            eps,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_rope(
    mlx_array* res,
    const mlx_array x,
    int dims,
    bool traditional,
    mlx_optional_float base,
    float scale,
    int offset,
    const mlx_array freqs /* may be null */,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::fast::rope(
            mlx_array_get_(x),
            dims,
            traditional,
            (base.has_value ? std::make_optional<float>(base.value)
                            : std::nullopt),
            scale,
            offset,
            (freqs.ctx ? std::make_optional(mlx_array_get_(freqs))
                       : std::nullopt),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_scaled_dot_product_attention(
    mlx_array* res,
    const mlx_array queries,
    const mlx_array keys,
    const mlx_array values,
    float scale,
    const mlx_array mask /* may be null */,
    mlx_optional_int memory_efficient_threshold,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::fast::scaled_dot_product_attention(
            mlx_array_get_(queries),
            mlx_array_get_(keys),
            mlx_array_get_(values),
            scale,
            (mask.ctx ? std::make_optional(mlx_array_get_(mask))
                      : std::nullopt),
            (memory_efficient_threshold.has_value
                 ? std::make_optional<int>(memory_efficient_threshold.value)
                 : std::nullopt),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
