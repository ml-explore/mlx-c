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
#include "mlx/c/map.h"
#include "mlx/c/stream.h"
#include "mlx/c/string.h"
#include "mlx/c/vector.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup transforms Transform operations
 */
/**@{*/
int mlx_async_eval(const mlx_vector_array outputs);
int mlx_checkpoint(const mlx_closure fun, mlx_closure res);
int mlx_custom_function(
    const mlx_closure fun,
    const mlx_closure_custom fun_vjp /* may be null */,
    const mlx_closure_custom_jvp fun_jvp /* may be null */,
    const mlx_closure_custom_vmap fun_vmap /* may be null */,
    mlx_closure res);
int mlx_custom_vjp(
    const mlx_closure fun,
    const mlx_closure_custom fun_vjp,
    mlx_closure res);
int mlx_eval(const mlx_vector_array outputs);
int mlx_jvp(
    const mlx_closure fun,
    const mlx_vector_array primals,
    const mlx_vector_array tangents,
    mlx_vector_array res_0,
    mlx_vector_array res_1);
int mlx_value_and_grad(
    const mlx_closure fun,
    const int* argnums,
    size_t argnums_num,
    mlx_closure_value_and_grad res);
int mlx_vjp(
    const mlx_closure fun,
    const mlx_vector_array primals,
    const mlx_vector_array cotangents,
    mlx_vector_array res_0,
    mlx_vector_array res_1);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
