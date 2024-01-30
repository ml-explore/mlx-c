/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_CLOSURE_H
#define MLX_CLOSURE_H

#include "mlx/c/array.h"

#ifdef __cplusplus
extern "C" {
#endif

// mlx_closure takes a vector of arrays, and returns a vector of arrays.
typedef struct mlx_closure_* mlx_closure;

mlx_closure mlx_closure_new(
    mlx_vector_array (*fun)(const mlx_vector_array arrs));
mlx_closure mlx_closure_new_unary(mlx_array (*fun)(const mlx_array));
mlx_closure mlx_closure_new_with_payload(
    mlx_vector_array (*fun)(const mlx_vector_array, void*),
    void* payload,
    void (*dtor)(void*));
mlx_vector_array mlx_closure_apply(mlx_closure cls, const mlx_vector_array);

// mlx_closure_value_and_grad takes a vector of arrays, and returns a vector of
// vector of arrays (of size 2)
typedef struct mlx_closure_value_and_grad_* mlx_closure_value_and_grad;
mlx_vector_vector_array mlx_closure_value_and_grad_apply(
    mlx_closure_value_and_grad cls,
    const mlx_vector_array inputs);

#ifdef __cplusplus
}
#endif

#endif
