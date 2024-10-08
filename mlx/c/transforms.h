/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_TRANSFORMS_H
#define MLX_TRANSFORMS_H

#include <stdio.h>

#include "mlx/c/array.h"
#include "mlx/c/closure.h"
#include "mlx/c/distributed_group.h"
#include "mlx/c/ioutils.h"
#include "mlx/c/map.h"
#include "mlx/c/stream.h"
#include "mlx/c/string.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup transforms Transform operations
 */
/**@{*/
void mlx_async_eval(const mlx_vector_array outputs);
mlx_closure mlx_checkpoint(mlx_closure fun);
mlx_closure mlx_custom_function(
    mlx_closure fun,
    mlx_closure_custom_function fun_vjp,
    mlx_closure_custom_function_jvp fun_jvp,
    mlx_closure_custom_function_vmap fun_vmap);
mlx_closure mlx_custom_vjp(
    mlx_closure fun,
    mlx_closure_custom_function fun_vjp);
void mlx_eval(const mlx_vector_array outputs);
mlx_tuple_vector_array_vector_array mlx_jvp(
    mlx_closure fun,
    const mlx_vector_array primals,
    const mlx_vector_array tangents);
mlx_closure_value_and_grad
mlx_value_and_grad(mlx_closure fun, const int* argnums, size_t num_argnums);
mlx_tuple_vector_array_vector_array mlx_vjp(
    mlx_closure fun,
    const mlx_vector_array primals,
    const mlx_vector_array cotangents);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
