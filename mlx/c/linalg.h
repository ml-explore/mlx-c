/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_LINALG_H
#define MLX_LINALG_H

#include <stdio.h>

#include "mlx/c/array.h"
#include "mlx/c/closure.h"
#include "mlx/c/ioutils.h"
#include "mlx/c/map.h"
#include "mlx/c/stream.h"
#include "mlx/c/string.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup linalg Linear algebra operations
 */
/**@{*/
mlx_array mlx_linalg_inv(mlx_array a, mlx_stream s);
mlx_array mlx_linalg_norm_p(
    mlx_array a,
    double ord,
    const int* axis,
    size_t num_axis,
    bool keepdims,
    mlx_stream s);
mlx_array mlx_linalg_norm_ord(
    mlx_array a,
    mlx_string ord,
    const int* axis,
    size_t num_axis,
    bool keepdims,
    mlx_stream s);
mlx_array mlx_linalg_norm(
    mlx_array a,
    const int* axis,
    size_t num_axis,
    bool keepdims,
    mlx_stream s);
mlx_vector_array mlx_linalg_qr(mlx_array a, mlx_stream s);
mlx_vector_array mlx_linalg_svd(mlx_array a, mlx_stream s);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
