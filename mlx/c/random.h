/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_RANDOM_H
#define MLX_RANDOM_H

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
 * \defgroup random Random number operations
 */
/**@{*/
mlx_array mlx_random_bernoulli(
    mlx_array p,
    const int* shape,
    size_t num_shape,
    mlx_array key,
    mlx_stream s);
mlx_array mlx_random_bits(
    const int* shape,
    size_t num_shape,
    int width,
    mlx_array key,
    mlx_stream s);
mlx_array mlx_random_categorical_shape(
    mlx_array logits,
    int axis,
    const int* shape,
    size_t num_shape,
    mlx_array key,
    mlx_stream s);
mlx_array mlx_random_categorical_num_samples(
    mlx_array logits_,
    int axis,
    int num_samples,
    mlx_array key,
    mlx_stream s);
mlx_array
mlx_random_categorical(mlx_array logits, int axis, mlx_array key, mlx_stream s);
mlx_array mlx_random_gumbel(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s);
mlx_array mlx_random_key(uint64_t seed);
mlx_array mlx_random_normal(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    float loc,
    float scale,
    mlx_array key,
    mlx_stream s);
mlx_array mlx_random_randint(
    mlx_array low,
    mlx_array high,
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s);
void mlx_random_seed(uint64_t seed);
mlx_array mlx_random_split_equal_parts(mlx_array key, int num, mlx_stream s);
mlx_vector_array mlx_random_split(mlx_array key, mlx_stream s);
mlx_array mlx_random_truncated_normal(
    mlx_array lower,
    mlx_array upper,
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s);
mlx_array mlx_random_uniform(
    mlx_array low,
    mlx_array high,
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
