/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_TUPLE_H
#define MLX_TUPLE_H

#include "mlx/c/array.h"
#include "mlx/c/string.h"
#include "mlx/c/vector.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_tuple MLX tuples.
 */
/**@{*/

/**
 * A tuple of (mlx_vector_array, mlx_vector_int).
 */
typedef struct mlx_tuple_vector_array_vector_int_*
    mlx_tuple_vector_array_vector_int;
mlx_tuple_vector_array_vector_int mlx_tuple_vector_array_vector_int_new(
    mlx_vector_array va,
    mlx_vector_int vi);
mlx_vector_array mlx_tuple_vector_array_vector_int_get_0(
    mlx_tuple_vector_array_vector_int tuple);
mlx_vector_int mlx_tuple_vector_array_vector_int_get_1(
    mlx_tuple_vector_array_vector_int tuple);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
