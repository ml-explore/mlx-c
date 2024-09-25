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
mlx_vector_array mlx_vector_array_new_data(const mlx_array* data, size_t size);
mlx_vector_array mlx_vector_array_new_value(const mlx_array val);
int mlx_vector_array_set_data(
    mlx_vector_array vec,
    const mlx_array* data,
    size_t size);
int mlx_vector_array_set_value(mlx_vector_array vec, const mlx_array val);
void mlx_vector_array_add_data(
    mlx_vector_array vec,
    const mlx_array* data,
    size_t size);
void mlx_vector_array_add_value(mlx_vector_array vec, const mlx_array val);
size_t mlx_vector_array_size(mlx_vector_array vec);
int mlx_vector_array_get(mlx_vector_array vec, size_t idx, mlx_array);

/**
 * A vector of vector_array.
 */
typedef struct mlx_vector_vector_array_* mlx_vector_vector_array;
mlx_vector_vector_array mlx_vector_vector_array_new();
mlx_vector_vector_array mlx_vector_vector_array_new_data(
    const mlx_vector_array* data,
    size_t size);
mlx_vector_vector_array mlx_vector_vector_array_new_value(
    const mlx_vector_array val);
int mlx_vector_vector_array_set_data(
    mlx_vector_vector_array vec,
    const mlx_vector_array* data,
    size_t size);
int mlx_vector_vector_array_set_value(
    mlx_vector_vector_array vec,
    const mlx_vector_array val);
void mlx_vector_vector_array_add_data(
    mlx_vector_vector_array vec,
    const mlx_vector_array* data,
    size_t size);
void mlx_vector_vector_array_add_value(
    mlx_vector_vector_array vec,
    const mlx_vector_array val);
size_t mlx_vector_vector_array_size(mlx_vector_vector_array vec);
int mlx_vector_vector_array_get(
    mlx_vector_vector_array vec,
    size_t idx,
    mlx_vector_array);

/**
 * A vector of int.
 */
typedef struct mlx_vector_int_* mlx_vector_int;
mlx_vector_int mlx_vector_int_new();
mlx_vector_int mlx_vector_int_new_data(int* data, size_t size);
mlx_vector_int mlx_vector_int_new_value(int val);
int mlx_vector_int_set_data(mlx_vector_int vec, int* data, size_t size);
int mlx_vector_int_set_value(mlx_vector_int vec, int val);
void mlx_vector_int_add_data(mlx_vector_int vec, int* data, size_t size);
void mlx_vector_int_add_value(mlx_vector_int vec, int val);
size_t mlx_vector_int_size(mlx_vector_int vec);
int mlx_vector_int_get(mlx_vector_int vec, size_t idx, int*);

/**
 * A vector of vector_int.
 */
typedef struct mlx_vector_vector_int_* mlx_vector_vector_int;
mlx_vector_vector_int mlx_vector_vector_int_new();
mlx_vector_vector_int mlx_vector_vector_int_new_data(
    const mlx_vector_int* data,
    size_t size);
mlx_vector_vector_int mlx_vector_vector_int_new_value(const mlx_vector_int val);
int mlx_vector_vector_int_set_data(
    mlx_vector_vector_int vec,
    const mlx_vector_int* data,
    size_t size);
int mlx_vector_vector_int_set_value(
    mlx_vector_vector_int vec,
    const mlx_vector_int val);
void mlx_vector_vector_int_add_data(
    mlx_vector_vector_int vec,
    const mlx_vector_int* data,
    size_t size);
void mlx_vector_vector_int_add_value(
    mlx_vector_vector_int vec,
    const mlx_vector_int val);
size_t mlx_vector_vector_int_size(mlx_vector_vector_int vec);
int mlx_vector_vector_int_get(
    mlx_vector_vector_int vec,
    size_t idx,
    mlx_vector_int);

/**
 * A vector of string.
 */
typedef struct mlx_vector_string_* mlx_vector_string;
mlx_vector_string mlx_vector_string_new();
mlx_vector_string mlx_vector_string_new_data(const char** data, size_t size);
mlx_vector_string mlx_vector_string_new_value(const char* val);
int mlx_vector_string_set_data(
    mlx_vector_string vec,
    const char** data,
    size_t size);
int mlx_vector_string_set_value(mlx_vector_string vec, const char* val);
void mlx_vector_string_add_data(
    mlx_vector_string vec,
    const char** data,
    size_t size);
void mlx_vector_string_add_value(mlx_vector_string vec, const char* val);
size_t mlx_vector_string_size(mlx_vector_string vec);
int mlx_vector_string_get(mlx_vector_string vec, size_t idx, char**);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
