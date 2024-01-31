/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_CLOSURE_H
#define MLX_CLOSURE_H

#include "mlx/c/array.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_closure Closures
 * MLX closure objects.
 */
/**@{*/

/**
 * A closure encapsulating a function taking a vector of arrays, and
 * returning a vector of arrays
 */
typedef struct mlx_closure_* mlx_closure;

/**
 * Returns a closure encapsulating the specified function.
 */
mlx_closure mlx_closure_new(
    mlx_vector_array (*fun)(const mlx_vector_array arrs));
/**
 * Returns a closure encapsulating the specified function.
 * This is a convenience function, mapping `mlx_array` to `mlx_vector_array`
 * under the hood.
 */
mlx_closure mlx_closure_new_unary(mlx_array (*fun)(const mlx_array));
/**
 * Returns a closure encapsulating the specified function, with the given
 * payload. If `dtor` is not `NULL`, it will called when the closure is
 * destroyed to free the payload.
 */
mlx_closure mlx_closure_new_with_payload(
    mlx_vector_array (*fun)(const mlx_vector_array, void*),
    void* payload,
    void (*dtor)(void*));
/**
 * Applies the closure over the given vector of arrays argument.
 */
mlx_vector_array mlx_closure_apply(mlx_closure cls, const mlx_vector_array);

/**
 * A closure which takes a vector of arrays, and returns a vector of vector of
 * arrays of size 2.
 */
typedef struct mlx_closure_value_and_grad_* mlx_closure_value_and_grad;
/**
 * Applies the closure over the given vector of arrays argument.
 */
mlx_vector_vector_array mlx_closure_value_and_grad_apply(
    mlx_closure_value_and_grad cls,
    const mlx_vector_array inputs);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
