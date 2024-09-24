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
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases,
    int group_size,
    int bits,
    const mlx_stream s,
    mlx_array res);
int mlx_fast_affine_quantize(
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases,
    int group_size,
    int bits,
    const mlx_stream s,
    mlx_array res);
int mlx_fast_layer_norm(
    const mlx_array x,
    const mlx_array weight /* may be null */,
    const mlx_array bias /* may be null */,
    float eps,
    const mlx_stream s,
    mlx_array res);
int mlx_fast_metal_kernel(
    const char* name,
    const mlx_vector_string input_names,
    const mlx_vector_string output_names,
    const char* source,
    const char* header,
    bool ensure_row_contiguous,
    bool atomic_outputs,
    mlx_closure_metal_kernel res);
int mlx_fast_rms_norm(
    const mlx_array x,
    const mlx_array weight,
    float eps,
    const mlx_stream s,
    mlx_array res);
int mlx_fast_rope(
    const mlx_array x,
    int dims,
    bool traditional,
    mlx_optional_float base,
    float scale,
    int offset,
    const mlx_array freqs /* may be null */,
    const mlx_stream s,
    mlx_array res);
int mlx_fast_scaled_dot_product_attention(
    const mlx_array queries,
    const mlx_array keys,
    const mlx_array values,
    float scale,
    const mlx_array mask /* may be null */,
    mlx_optional_int memory_efficient_threshold,
    const mlx_stream s,
    mlx_array res);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
