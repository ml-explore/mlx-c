/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/fast.h"

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

extern "C" int mlx_fast_affine_dequantize(
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases,
    int group_size,
    int bits,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::fast::affine_dequantize(
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::fast::affine_quantize(
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::fast::layer_norm(
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
extern "C" int mlx_fast_metal_kernel(
    const char* name,
    const mlx_vector_string input_names,
    const mlx_vector_string output_names,
    const char* source,
    const char* header,
    bool ensure_row_contiguous,
    bool atomic_outputs,
    mlx_closure_metal_kernel res) {
  try {
    res->ctx = mlx::core::fast::metal_kernel(
        std::string(name),
        input_names->ctx,
        output_names->ctx,
        std::string(source),
        std::string(header),
        ensure_row_contiguous,
        atomic_outputs);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::fast::rms_norm(x->ctx, weight->ctx, eps, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::fast::rope(
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::fast::scaled_dot_product_attention(
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
