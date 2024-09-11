/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_TUPLE_H
#define MLX_TUPLE_H

#include "mlx/c/array.h"
#include "mlx/c/string.h"
#include "mlx/c/vector.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_tuple Tuples
 * MLX tuple objects.
 */
/**@{*/

/**
 * A tuple of (const mlx_array, const mlx_array).
 */
typedef struct mlx_tuple_array_array_* mlx_tuple_array_array;
mlx_tuple_array_array mlx_tuple_array_array_new(
    const mlx_array input_0,
    const mlx_array input_1);

mlx_array mlx_tuple_array_array_get_0(mlx_tuple_array_array tuple);
mlx_array mlx_tuple_array_array_get_1(mlx_tuple_array_array tuple);

/**
 * A tuple of (const mlx_array, const mlx_array, const mlx_array).
 */
typedef struct mlx_tuple_array_array_array_* mlx_tuple_array_array_array;
mlx_tuple_array_array_array mlx_tuple_array_array_array_new(
    const mlx_array input_0,
    const mlx_array input_1,
    const mlx_array input_2);

mlx_array mlx_tuple_array_array_array_get_0(mlx_tuple_array_array_array tuple);
mlx_array mlx_tuple_array_array_array_get_1(mlx_tuple_array_array_array tuple);
mlx_array mlx_tuple_array_array_array_get_2(mlx_tuple_array_array_array tuple);

/**
 * A tuple of (const mlx_vector_array, const mlx_vector_array).
 */
typedef struct mlx_tuple_vector_array_vector_array_*
    mlx_tuple_vector_array_vector_array;
mlx_tuple_vector_array_vector_array mlx_tuple_vector_array_vector_array_new(
    const mlx_vector_array input_0,
    const mlx_vector_array input_1);

mlx_vector_array mlx_tuple_vector_array_vector_array_get_0(
    mlx_tuple_vector_array_vector_array tuple);
mlx_vector_array mlx_tuple_vector_array_vector_array_get_1(
    mlx_tuple_vector_array_vector_array tuple);

/**
 * A tuple of (const mlx_vector_array, const mlx_vector_int).
 */
typedef struct mlx_tuple_vector_array_vector_int_*
    mlx_tuple_vector_array_vector_int;
mlx_tuple_vector_array_vector_int mlx_tuple_vector_array_vector_int_new(
    const mlx_vector_array input_0,
    const mlx_vector_int input_1);

mlx_vector_array mlx_tuple_vector_array_vector_int_get_0(
    mlx_tuple_vector_array_vector_int tuple);
mlx_vector_int mlx_tuple_vector_array_vector_int_get_1(
    mlx_tuple_vector_array_vector_int tuple);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
