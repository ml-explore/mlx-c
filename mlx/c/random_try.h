/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include <stdio.h>

#ifndef MLX_RANDOM_TRY_H
#define MLX_RANDOM_TRY_H
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

mlx_array_result mlx_random_bernoulli_try(
    mlx_array p,
    const int* shape,
    size_t num_shape,
    mlx_array key,
    mlx_stream s);
mlx_array_result mlx_random_bits_try(
    const int* shape,
    size_t num_shape,
    int width,
    mlx_array key,
    mlx_stream s);
mlx_array_result mlx_random_categorical_shape_try(
    mlx_array logits,
    int axis,
    const int* shape,
    size_t num_shape,
    mlx_array key,
    mlx_stream s);
mlx_array_result mlx_random_categorical_num_samples_try(
    mlx_array logits_,
    int axis,
    int num_samples,
    mlx_array key,
    mlx_stream s);
mlx_array_result mlx_random_categorical_try(
    mlx_array logits,
    int axis,
    mlx_array key,
    mlx_stream s);
mlx_array_result mlx_random_gumbel_try(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s);
mlx_array_result mlx_random_key_try(uint64_t seed);
mlx_array_result mlx_random_multivariate_normal_try(
    mlx_array mean,
    mlx_array cov,
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s);
mlx_array_result mlx_random_normal_try(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    float loc,
    float scale,
    mlx_array key,
    mlx_stream s);
mlx_array_result mlx_random_randint_try(
    mlx_array low,
    mlx_array high,
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s);
mlx_array_result
mlx_random_split_equal_parts_try(mlx_array key, int num, mlx_stream s);
mlx_vector_array_result mlx_random_split_try(mlx_array key, mlx_stream s);
mlx_array_result mlx_random_truncated_normal_try(
    mlx_array lower,
    mlx_array upper,
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s);
mlx_array_result mlx_random_uniform_try(
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
