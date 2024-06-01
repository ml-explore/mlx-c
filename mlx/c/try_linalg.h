/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include <stdio.h>

#ifndef MLX_TRY_LINALG_H
#define MLX_TRY_LINALG_H
#include "mlx/c/result.h"

#include "mlx/c/array.h"
#include "mlx/c/closure.h"
#include "mlx/c/future.h"
#include "mlx/c/ioutils.h"
#include "mlx/c/map.h"
#include "mlx/c/stream.h"
#include "mlx/c/string.h"

#ifdef __cplusplus
extern "C" {
#endif

mlx_array_result mlx_linalg_try_cholesky(mlx_array a, bool upper, mlx_stream s);
mlx_array_result mlx_linalg_try_inv(mlx_array a, mlx_stream s);
mlx_array_result mlx_linalg_try_norm_p(
    mlx_array a,
    double ord,
    const int* axis,
    size_t num_axis,
    bool keepdims,
    mlx_stream s);
mlx_array_result mlx_linalg_try_norm_ord(
    mlx_array a,
    mlx_string ord,
    const int* axis,
    size_t num_axis,
    bool keepdims,
    mlx_stream s);
mlx_array_result mlx_linalg_try_norm(
    mlx_array a,
    const int* axis,
    size_t num_axis,
    bool keepdims,
    mlx_stream s);
mlx_vector_array_result mlx_linalg_try_qr(mlx_array a, mlx_stream s);
mlx_vector_array_result mlx_linalg_try_svd(mlx_array a, mlx_stream s);

#ifdef __cplusplus
}
#endif

#endif
