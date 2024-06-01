/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/try_fast.h"
#include "mlx/c/fast.h"
#include "mlx/c/result.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/future.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

extern "C" mlx_array_result mlx_fast_try_layer_norm(
    mlx_array x,
    mlx_array weight,
    mlx_array bias,
    float eps,
    mlx_stream s) {
  MLX_C_ARRAY_TRY(mlx::core::fast::layer_norm(
      x->ctx,
      (weight ? std::make_optional(weight->ctx) : std::nullopt),
      (bias ? std::make_optional(bias->ctx) : std::nullopt),
      eps,
      s->ctx))
}
extern "C" mlx_array_result
mlx_fast_try_rms_norm(mlx_array x, mlx_array weight, float eps, mlx_stream s) {
  MLX_C_ARRAY_TRY(mlx::core::fast::rms_norm(x->ctx, weight->ctx, eps, s->ctx))
}
extern "C" mlx_array_result mlx_fast_try_rope(
    mlx_array x,
    int dims,
    bool traditional,
    float base,
    float scale,
    int offset,
    mlx_stream s) {
  MLX_C_ARRAY_TRY(mlx::core::fast::rope(
      x->ctx, dims, traditional, base, scale, offset, s->ctx))
}
extern "C" mlx_array_result mlx_fast_try_scaled_dot_product_attention(
    mlx_array queries,
    mlx_array keys,
    mlx_array values,
    float scale,
    mlx_array mask,
    mlx_stream s) {
  MLX_C_ARRAY_TRY(mlx::core::fast::scaled_dot_product_attention(
      queries->ctx,
      keys->ctx,
      values->ctx,
      scale,
      (mask ? std::make_optional(mask->ctx) : std::nullopt),
      s->ctx))
}
