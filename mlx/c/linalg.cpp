/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/linalg.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

extern "C" mlx_array mlx_linalg_inv(mlx_array a, mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::linalg::inv(a->ctx, s->ctx));
}
extern "C" mlx_array mlx_linalg_norm_p(
    mlx_array a,
    double ord,
    const int* axis,
    size_t num_axis,
    bool keepdims,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::linalg::norm(
      a->ctx, ord, MLX_CPP_OPT_INTVEC(axis, num_axis), keepdims, s->ctx));
}
extern "C" mlx_array mlx_linalg_norm_ord(
    mlx_array a,
    mlx_string ord,
    const int* axis,
    size_t num_axis,
    bool keepdims,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::linalg::norm(
      a->ctx,
      MLX_CPP_STRING(ord),
      MLX_CPP_OPT_INTVEC(axis, num_axis),
      keepdims,
      s->ctx));
}
extern "C" mlx_array mlx_linalg_norm(
    mlx_array a,
    const int* axis,
    size_t num_axis,
    bool keepdims,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::linalg::norm(
      a->ctx, MLX_CPP_OPT_INTVEC(axis, num_axis), keepdims, s->ctx));
}
extern "C" mlx_vector_array mlx_linalg_qr(mlx_array a, mlx_stream s) {
  return MLX_C_ARRAYPAIR(mlx::core::linalg::qr(a->ctx, s->ctx));
}
extern "C" mlx_vector_array mlx_linalg_svd(mlx_array a, mlx_stream s) {
  return MLX_C_ARRAYS(mlx::core::linalg::svd(a->ctx, s->ctx));
}
