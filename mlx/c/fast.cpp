/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/fast.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

extern "C" mlx_array mlx_fast_layer_norm(
    mlx_array x,
    mlx_array weight,
    mlx_array bias,
    float eps,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::fast::layer_norm(
      x->ctx,
      (weight ? std::make_optional(weight->ctx) : std::nullopt),
      (bias ? std::make_optional(bias->ctx) : std::nullopt),
      eps,
      s->ctx));
}
extern "C" mlx_array
mlx_fast_rms_norm(mlx_array x, mlx_array weight, float eps, mlx_stream s) {
  return MLX_C_ARRAY(
      mlx::core::fast::rms_norm(x->ctx, weight->ctx, eps, s->ctx));
}
extern "C" mlx_array mlx_fast_rope(
    mlx_array x,
    int dims,
    bool traditional,
    float base,
    float scale,
    int offset,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::fast::rope(
      x->ctx, dims, traditional, base, scale, offset, s->ctx));
}
extern "C" mlx_array mlx_fast_scaled_dot_product_attention(
    mlx_array queries,
    mlx_array keys,
    mlx_array values,
    float scale,
    mlx_array mask,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::fast::scaled_dot_product_attention(
      queries->ctx,
      keys->ctx,
      values->ctx,
      scale,
      (mask ? std::make_optional(mask->ctx) : std::nullopt),
      s->ctx));
}
