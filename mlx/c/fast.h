/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_FAST_H
#define MLX_FAST_H

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
 * \defgroup fast Fast custom operations
 */
/**@{*/
mlx_array mlx_fast_layer_norm(
    mlx_array x,
    mlx_array weight,
    mlx_array bias,
    float eps,
    mlx_stream s);
mlx_array
mlx_fast_rms_norm(mlx_array x, mlx_array weight, float eps, mlx_stream s);
mlx_array mlx_fast_rope(
    mlx_array x,
    int dims,
    bool traditional,
    float base,
    float scale,
    int offset,
    mlx_stream s);
mlx_array mlx_fast_scaled_dot_product_attention(
    mlx_array queries,
    mlx_array keys,
    mlx_array values,
    float scale,
    mlx_array mask,
    mlx_stream s);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
