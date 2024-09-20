/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_VECTOR_H
#define MLX_VECTOR_H

#include "mlx/c/array.h"
#include "mlx/c/string.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_vector Vectors
 * MLX vector objects.
 */
/**@{*/

/**
 * A vector of array.
 */
typedef struct mlx_vector_array_* mlx_vector_array;
mlx_vector_array mlx_vector_array_new();
mlx_vector_array mlx_vector_array_from_data(const mlx_array* data, size_t size);
mlx_vector_array mlx_vector_array_from_value(const mlx_array val);
void mlx_vector_array_add_data(
    mlx_vector_array vec,
    const mlx_array* data,
    size_t size);
void mlx_vector_array_add_value(mlx_vector_array vec, const mlx_array val);
size_t mlx_vector_array_size(mlx_vector_array vec);
mlx_array mlx_vector_array_get(mlx_vector_array vec, size_t idx);
mlx_array* mlx_vector_array_data(mlx_vector_array vec);

/**
 * A vector of vector_array.
 */
typedef struct mlx_vector_vector_array_* mlx_vector_vector_array;
mlx_vector_vector_array mlx_vector_vector_array_new();
mlx_vector_vector_array mlx_vector_vector_array_from_data(
    const mlx_vector_array* data,
    size_t size);
mlx_vector_vector_array mlx_vector_vector_array_from_value(
    const mlx_vector_array val);
void mlx_vector_vector_array_add_data(
    mlx_vector_vector_array vec,
    const mlx_vector_array* data,
    size_t size);
void mlx_vector_vector_array_add_value(
    mlx_vector_vector_array vec,
    const mlx_vector_array val);
size_t mlx_vector_vector_array_size(mlx_vector_vector_array vec);
mlx_vector_array mlx_vector_vector_array_get(
    mlx_vector_vector_array vec,
    size_t idx);
mlx_vector_array* mlx_vector_vector_array_data(mlx_vector_vector_array vec);

/**
 * A vector of int.
 */
typedef struct mlx_vector_int_* mlx_vector_int;
mlx_vector_int mlx_vector_int_new();
mlx_vector_int mlx_vector_int_from_data(const int* data, size_t size);
mlx_vector_int mlx_vector_int_from_value(const int val);
void mlx_vector_int_add_data(mlx_vector_int vec, const int* data, size_t size);
void mlx_vector_int_add_value(mlx_vector_int vec, const int val);
size_t mlx_vector_int_size(mlx_vector_int vec);
int mlx_vector_int_get(mlx_vector_int vec, size_t idx);
int* mlx_vector_int_data(mlx_vector_int vec);

/**
 * A vector of vector_int.
 */
typedef struct mlx_vector_vector_int_* mlx_vector_vector_int;
mlx_vector_vector_int mlx_vector_vector_int_new();
mlx_vector_vector_int mlx_vector_vector_int_from_data(
    const mlx_vector_int* data,
    size_t size);
mlx_vector_vector_int mlx_vector_vector_int_from_value(
    const mlx_vector_int val);
void mlx_vector_vector_int_add_data(
    mlx_vector_vector_int vec,
    const mlx_vector_int* data,
    size_t size);
void mlx_vector_vector_int_add_value(
    mlx_vector_vector_int vec,
    const mlx_vector_int val);
size_t mlx_vector_vector_int_size(mlx_vector_vector_int vec);
mlx_vector_int mlx_vector_vector_int_get(mlx_vector_vector_int vec, size_t idx);
mlx_vector_int* mlx_vector_vector_int_data(mlx_vector_vector_int vec);

/**
 * A vector of string.
 */
typedef struct mlx_vector_string_* mlx_vector_string;
mlx_vector_string mlx_vector_string_new();
mlx_vector_string mlx_vector_string_from_data(
    const mlx_string* data,
    size_t size);
mlx_vector_string mlx_vector_string_from_value(const mlx_string val);
void mlx_vector_string_add_data(
    mlx_vector_string vec,
    const mlx_string* data,
    size_t size);
void mlx_vector_string_add_value(mlx_vector_string vec, const mlx_string val);
size_t mlx_vector_string_size(mlx_vector_string vec);
mlx_string mlx_vector_string_get(mlx_vector_string vec, size_t idx);
mlx_string* mlx_vector_string_data(mlx_vector_string vec);

/**
 * A vector of array_dtype.
 */
typedef struct mlx_vector_array_dtype_* mlx_vector_array_dtype;
mlx_vector_array_dtype mlx_vector_array_dtype_new();
mlx_vector_array_dtype mlx_vector_array_dtype_from_data(
    const mlx_array_dtype* data,
    size_t size);
mlx_vector_array_dtype mlx_vector_array_dtype_from_value(
    const mlx_array_dtype val);
void mlx_vector_array_dtype_add_data(
    mlx_vector_array_dtype vec,
    const mlx_array_dtype* data,
    size_t size);
void mlx_vector_array_dtype_add_value(
    mlx_vector_array_dtype vec,
    const mlx_array_dtype val);
size_t mlx_vector_array_dtype_size(mlx_vector_array_dtype vec);
mlx_array_dtype mlx_vector_array_dtype_get(
    mlx_vector_array_dtype vec,
    size_t idx);
mlx_array_dtype* mlx_vector_array_dtype_data(mlx_vector_array_dtype vec);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
