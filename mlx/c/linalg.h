/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_LINALG_H
#define MLX_LINALG_H

#include <stdio.h>

#include "mlx/c/array.h"
#include "mlx/c/closure.h"
#include "mlx/c/distributed_group.h"
#include "mlx/c/map.h"
#include "mlx/c/stream.h"
#include "mlx/c/string.h"
#include "mlx/c/vector.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup linalg Linear algebra operations
 */
/**@{*/
int mlx_linalg_cholesky(
    const mlx_array a,
    bool upper,
    const mlx_stream s,
    mlx_array res);
int mlx_linalg_cholesky_inv(
    const mlx_array a,
    bool upper,
    const mlx_stream s,
    mlx_array res);
int mlx_linalg_inv(const mlx_array a, const mlx_stream s, mlx_array res);
int mlx_linalg_norm_p(
    const mlx_array a,
    double ord,
    const int* axis /* may be null */,
    size_t axis_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array res);
int mlx_linalg_norm_ord(
    const mlx_array a,
    const char* ord,
    const int* axis /* may be null */,
    size_t axis_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array res);
int mlx_linalg_norm(
    const mlx_array a,
    const int* axis /* may be null */,
    size_t axis_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array res);
int mlx_linalg_pinv(const mlx_array a, const mlx_stream s, mlx_array res);
int mlx_linalg_qr(
    const mlx_array a,
    const mlx_stream s,
    mlx_array res_0,
    mlx_array res_1);
int mlx_linalg_svd(const mlx_array a, const mlx_stream s, mlx_vector_array res);
int mlx_linalg_tri_inv(
    const mlx_array a,
    bool upper,
    const mlx_stream s,
    mlx_array res);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
