/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/linalg.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

extern "C" mlx_array mlx_linalg_norm(
    mlx_array a,
    mlx_string ord,
    int axis,
    bool keepdims,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::linalg::norm(
      a->ctx, MLX_CPP_STRING(ord), axis, keepdims, s->ctx));
}
