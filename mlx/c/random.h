#ifndef MLX_RANDOM_H
#define MLX_RANDOM_H

#include <stdio.h>

#include "mlx/c/array.h"
#include "mlx/c/stream.h"

#ifdef __cplusplus
extern "C" {
#endif

mlx_array mlx_random_bernoulli(
    mlx_array p,
    int* shape,
    size_t num_shape,
    mlx_array key,
    mlx_stream s);
mlx_array mlx_random_bits(
    int* shape,
    size_t num_shape,
    int width,
    mlx_array key,
    mlx_stream s);
mlx_array mlx_random_categorical(
    mlx_array logits,
    int axis,
    int* shape,
    size_t num_shape,
    mlx_array key,
    mlx_stream s);
mlx_array mlx_random_gumbel(
    int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s);
mlx_array mlx_random_key(uint64_t seed);
mlx_array mlx_random_normal(
    int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s);
mlx_array mlx_random_randint(
    mlx_array low,
    mlx_array high,
    int* shape,
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
    int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s);
mlx_array mlx_random_uniform(
    mlx_array low,
    mlx_array high,
    int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s);

#ifdef __cplusplus
}
#endif

#endif
