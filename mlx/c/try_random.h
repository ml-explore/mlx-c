/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include <stdio.h>

#ifndef MLX_TRY_RANDOM_H
#define MLX_TRY_RANDOM_H
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

mlx_array_result mlx_random_try_bernoulli(
    mlx_array p,
    const int* shape,
    size_t num_shape,
    mlx_array key,
    mlx_stream s);
mlx_array_result mlx_random_try_bits(
    const int* shape,
    size_t num_shape,
    int width,
    mlx_array key,
    mlx_stream s);
mlx_array_result mlx_random_try_categorical_shape(
    mlx_array logits,
    int axis,
    const int* shape,
    size_t num_shape,
    mlx_array key,
    mlx_stream s);
mlx_array_result mlx_random_try_categorical_num_samples(
    mlx_array logits_,
    int axis,
    int num_samples,
    mlx_array key,
    mlx_stream s);
mlx_array_result mlx_random_try_categorical(
    mlx_array logits,
    int axis,
    mlx_array key,
    mlx_stream s);
mlx_array_result mlx_random_try_gumbel(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s);
mlx_array_result mlx_random_try_key(uint64_t seed);
mlx_array_result mlx_random_try_multivariate_normal(
    mlx_array mean,
    mlx_array cov,
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s);
mlx_array_result mlx_random_try_normal(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    float loc,
    float scale,
    mlx_array key,
    mlx_stream s);
mlx_array_result mlx_random_try_randint(
    mlx_array low,
    mlx_array high,
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s);
mlx_array_result
mlx_random_try_split_equal_parts(mlx_array key, int num, mlx_stream s);
mlx_vector_array_result mlx_random_try_split(mlx_array key, mlx_stream s);
mlx_array_result mlx_random_try_truncated_normal(
    mlx_array lower,
    mlx_array upper,
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s);
mlx_array_result mlx_random_try_uniform(
    mlx_array low,
    mlx_array high,
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s);

#ifdef __cplusplus
}
#endif

#endif
