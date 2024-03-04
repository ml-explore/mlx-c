/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_TRANSFORMS_IMPL_H
#define MLX_TRANSFORMS_IMPL_H

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
 * \defgroup transforms_impl Implementation detail operations
 */
/**@{*/
mlx_closure mlx_detail_compile(
    mlx_closure fun,
    size_t fun_id,
    bool shapeless,
    const uint64_t* constants,
    size_t num_constants);
void mlx_detail_compile_erase(size_t fun_id);
mlx_vector_array mlx_detail_vmap_replace(
    const mlx_vector_array inputs,
    const mlx_vector_array s_inputs,
    const mlx_vector_array s_outputs,
    const int* in_axes,
    size_t num_in_axes,
    const int* out_axes,
    size_t num_out_axes);
mlx_vector_vector_array mlx_detail_vmap_trace(
    mlx_closure fun,
    const mlx_vector_array inputs,
    const int* in_axes,
    size_t num_in_axes);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
