/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_CLOSURE_H
#define MLX_CLOSURE_H

#include "mlx/c/array.h"
#include "mlx/c/optional.h"
#include "mlx/c/stream.h"
#include "mlx/c/tuple.h"
#include "mlx/c/vector.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_closure Closures
 * MLX closure objects.
 */
/**@{*/

typedef struct mlx_closure_* mlx_closure;
mlx_closure mlx_closure_new(mlx_vector_array (*fun)(const mlx_vector_array));
mlx_closure mlx_closure_new_with_payload(
    mlx_vector_array (*fun)(const mlx_vector_array, void*),
    void* payload,
    void (*dtor)(void*));
mlx_vector_array mlx_closure_apply(
    mlx_closure cls,
    const mlx_vector_array input);

mlx_closure mlx_closure_new_unary(mlx_array (*fun)(const mlx_array));
