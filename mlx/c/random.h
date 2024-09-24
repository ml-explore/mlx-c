/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_RANDOM_H
#define MLX_RANDOM_H

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
 * \defgroup random Random number operations
 */
/**@{*/
int mlx_random_bernoulli(
    const mlx_array p,
    const int* shape,
    size_t shape_num,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array res);
int mlx_random_bits(
    const int* shape,
    size_t shape_num,
    int width,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array res);
int mlx_random_categorical_shape(
    const mlx_array logits,
    int axis,
    const int* shape,
    size_t shape_num,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array res);
int mlx_random_categorical_num_samples(
    const mlx_array logits_,
    int axis,
    int num_samples,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array res);
int mlx_random_categorical(
    const mlx_array logits,
    int axis,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array res);
int mlx_random_gumbel(
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array res);
int mlx_random_key(uint64_t seed, mlx_array res);
int mlx_random_laplace(
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    float loc,
    float scale,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array res);
int mlx_random_multivariate_normal(
    const mlx_array mean,
    const mlx_array cov,
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array res);
int mlx_random_normal(
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    float loc,
    float scale,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array res);
int mlx_random_randint(
    const mlx_array low,
    const mlx_array high,
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array res);
int mlx_random_seed(uint64_t seed);
int mlx_random_split_equal_parts(
    const mlx_array key,
    int num,
    const mlx_stream s,
    mlx_array res);
int mlx_random_split(
    const mlx_array key,
    const mlx_stream s,
    mlx_array res_0,
    mlx_array res_1);
int mlx_random_truncated_normal(
    const mlx_array lower,
    const mlx_array upper,
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array res);
int mlx_random_uniform(
    const mlx_array low,
    const mlx_array high,
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array res);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
