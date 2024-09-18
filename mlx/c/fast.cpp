/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/fast.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
//    #include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/tuple.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" int mlx_fast_affine_dequantize(
    mlx_array w,
    mlx_array scales,
    mlx_array biases,
    int group_size,
    int bits,
    mlx_stream s,
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
    mlx_array w,
    mlx_array scales,
    mlx_array biases,
    int group_size,
    int bits,
    mlx_stream s,
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
    mlx_array x,
    mlx_array weight,
    mlx_array bias,
    float eps,
    mlx_stream s,
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
extern "C" int mlx_fast_rms_norm(
    mlx_array x,
    mlx_array weight,
    float eps,
    mlx_stream s,
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
    mlx_array x,
    int dims,
    bool traditional,
    mlx_optional_float base,
    float scale,
    int offset,
    mlx_array freqs,
    mlx_stream s,
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
    mlx_array queries,
    mlx_array keys,
    mlx_array values,
    float scale,
    mlx_array mask,
    mlx_optional_int memory_efficient_threshold,
    mlx_stream s,
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
