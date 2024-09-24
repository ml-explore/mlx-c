/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_FAST_H
#define MLX_FAST_H

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
 * \defgroup fast Fast custom operations
 */
/**@{*/
int mlx_fast_affine_dequantize(
    mlx_array w,
    mlx_array scales,
    mlx_array biases,
    int group_size,
    int bits,
    mlx_stream s,
    mlx_array res);
int mlx_fast_affine_quantize(
    mlx_array w,
    mlx_array scales,
    mlx_array biases,
    int group_size,
    int bits,
    mlx_stream s,
    mlx_array res);
int mlx_fast_layer_norm(
    mlx_array x,
    mlx_array weight,
    mlx_array bias,
    float eps,
    mlx_stream s,
    mlx_array res);
int mlx_fast_metal_kernel(
    mlx_string name,
    const mlx_vector_string input_names,
    const mlx_vector_string output_names,
    mlx_string source,
    mlx_string header,
    bool ensure_row_contiguous,
    bool atomic_outputs,
    mlx_closure_metal_kernel res);
int mlx_fast_rms_norm(
    mlx_array x,
    mlx_array weight,
    float eps,
    mlx_stream s,
    mlx_array res);
int mlx_fast_rope(
    mlx_array x,
    int dims,
    bool traditional,
    mlx_optional_float base,
    float scale,
    int offset,
    mlx_array freqs,
    mlx_stream s,
    mlx_array res);
int mlx_fast_scaled_dot_product_attention(
    mlx_array queries,
    mlx_array keys,
    mlx_array values,
    float scale,
    mlx_array mask,
    mlx_optional_int memory_efficient_threshold,
    mlx_stream s,
    mlx_array res);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
