/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/fast.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" int mlx_fast_affine_dequantize(
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases,
    int group_size,
    int bits,
    const mlx_stream s,
    mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::fast::affine_dequantize(
        w->ctx, scales->ctx, biases->ctx, group_size, bits, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_affine_quantize(
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases,
    int group_size,
    int bits,
    const mlx_stream s,
    mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::fast::affine_quantize(
        w->ctx, scales->ctx, biases->ctx, group_size, bits, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_layer_norm(
    const mlx_array x,
    const mlx_array weight /* may be null */,
    const mlx_array bias /* may be null */,
    float eps,
    const mlx_stream s,
    mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::fast::layer_norm(
        x->ctx,
        (weight ? std::make_optional(weight->ctx) : std::nullopt),
        (bias ? std::make_optional(bias->ctx) : std::nullopt),
        eps,
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_fast_metal_kernel_add_output_arg(
    mlx_fast_metal_kernel cls,
    const int* shape,
    size_t size,
    mlx_dtype dtype) {
  try {
    cls->output_shapes.push_back(std::vector<int>(shape, shape + size));
    cls->output_dtypes.push_back(mlx_dtype_to_cpp(dtype));
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
    cls->grid = std::make_tuple(grid1, grid2, grid3);
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
    cls->thread_group = std::make_tuple(thread1, thread2, thread3);
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
    cls->init_value = value;
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
    cls->verbose = verbose;
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
    cls->template_args.push_back(
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
    cls->template_args.push_back(std::make_pair(std::string(name), value));
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
    cls->template_args.push_back(std::make_pair(std::string(name), value));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

mlx_string_* mlx_fast_metal_kernel_::tostring() {
  RETURN_MLX_C_STRING("mlx_fast_metal_kernel_");
}

extern "C" mlx_fast_metal_kernel mlx_fast_metal_kernel_new(
    const char* name,
    const char* source,
    const char* header) {
  try {
    return new mlx_fast_metal_kernel_(name, source, header);
  } catch (std::exception& e) {
    mlx_error(e.what());
  }
  return nullptr;
}
extern "C" int
mlx_fast_metal_kernel_set_input_names(mlx_fast_metal_kernel cls, int num, ...) {
  try {
    va_list input_names;
    va_start(input_names, num);
    cls->input_names.clear();
    for (int i = 0; i < num; i++) {
      cls->input_names.push_back(va_arg(input_names, const char*));
    }
    va_end(input_names);
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
    cls->output_names.clear();
    for (int i = 0; i < num; i++) {
      cls->output_names.push_back(va_arg(output_names, const char*));
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
  cls->contiguous_rows = flag;
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_atomic_outputs(
    mlx_fast_metal_kernel cls,
    bool flag) {
  cls->atomic_outputs = flag;
  return 0;
}
extern "C" int mlx_fast_metal_kernel_apply(
    mlx_fast_metal_kernel cls,
    const mlx_vector_array inputs,
    const mlx_stream stream,
    mlx_vector_array outputs) {
  try {
    if (!cls->ctx) {
      cls->ctx = mlx::core::fast::metal_kernel(
          cls->name,
          cls->input_names,
          cls->output_names,
          cls->source,
          cls->header,
          cls->contiguous_rows,
          cls->atomic_outputs);
    }
    outputs->ctx = cls->ctx(
        inputs->ctx,
        cls->output_shapes,
        cls->output_dtypes,
        cls->grid,
        cls->thread_group,
        cls->template_args,
        cls->init_value,
        cls->verbose,
        stream->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_fast_rms_norm(
    const mlx_array x,
    const mlx_array weight,
    float eps,
    const mlx_stream s,
    mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::fast::rms_norm(x->ctx, weight->ctx, eps, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_rope(
    const mlx_array x,
    int dims,
    bool traditional,
    mlx_optional_float base,
    float scale,
    int offset,
    const mlx_array freqs /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::fast::rope(
        x->ctx,
        dims,
        traditional,
        (base.has_value ? std::make_optional<float>(base.value) : std::nullopt),
        scale,
        offset,
        (freqs ? std::make_optional(freqs->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_scaled_dot_product_attention(
    const mlx_array queries,
    const mlx_array keys,
    const mlx_array values,
    float scale,
    const mlx_array mask /* may be null */,
    mlx_optional_int memory_efficient_threshold,
    const mlx_stream s,
    mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::fast::scaled_dot_product_attention(
        queries->ctx,
        keys->ctx,
        values->ctx,
        scale,
        (mask ? std::make_optional(mask->ctx) : std::nullopt),
        (memory_efficient_threshold.has_value
             ? std::make_optional<int>(memory_efficient_threshold.value)
             : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
