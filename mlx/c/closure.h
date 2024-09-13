/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_CLOSURE_H
#define MLX_CLOSURE_H

#include "mlx/c/array.h"
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

typedef struct mlx_closure_value_and_grad_* mlx_closure_value_and_grad;
mlx_closure_value_and_grad mlx_closure_value_and_grad_new(
    mlx_tuple_vector_array_vector_array (*fun)(const mlx_vector_array));
mlx_closure_value_and_grad mlx_closure_value_and_grad_new_with_payload(
    mlx_tuple_vector_array_vector_array (*fun)(const mlx_vector_array, void*),
    void* payload,
    void (*dtor)(void*));
mlx_tuple_vector_array_vector_array mlx_closure_value_and_grad_apply(
    mlx_closure_value_and_grad cls,
    const mlx_vector_array input);

typedef struct mlx_closure_custom_function_* mlx_closure_custom_function;
mlx_closure_custom_function mlx_closure_custom_function_new(
    mlx_vector_array (*fun)(
        const mlx_vector_array,
        const mlx_vector_array,
        const mlx_vector_array));
mlx_closure_custom_function mlx_closure_custom_function_new_with_payload(
    mlx_vector_array (*fun)(
        const mlx_vector_array,
        const mlx_vector_array,
        const mlx_vector_array,
        void*),
    void* payload,
    void (*dtor)(void*));
mlx_vector_array mlx_closure_custom_function_apply(
    mlx_closure_custom_function cls,
    const mlx_vector_array input_0,
    const mlx_vector_array input_1,
    const mlx_vector_array input_2);

typedef struct mlx_closure_custom_function_jvp_*
    mlx_closure_custom_function_jvp;
mlx_closure_custom_function_jvp mlx_closure_custom_function_jvp_new(
    mlx_vector_array (*fun)(
        const mlx_vector_array,
        const mlx_vector_array,
        const mlx_vector_int));
mlx_closure_custom_function_jvp
mlx_closure_custom_function_jvp_new_with_payload(
    mlx_vector_array (*fun)(
        const mlx_vector_array,
        const mlx_vector_array,
        const mlx_vector_int,
        void*),
    void* payload,
    void (*dtor)(void*));
mlx_vector_array mlx_closure_custom_function_jvp_apply(
    mlx_closure_custom_function_jvp cls,
    const mlx_vector_array input_0,
    const mlx_vector_array input_1,
    const mlx_vector_int input_2);

typedef struct mlx_closure_custom_function_vmap_*
    mlx_closure_custom_function_vmap;
mlx_closure_custom_function_vmap mlx_closure_custom_function_vmap_new(
    mlx_tuple_vector_array_vector_int (
        *fun)(const mlx_vector_array, const mlx_vector_int));
mlx_closure_custom_function_vmap
mlx_closure_custom_function_vmap_new_with_payload(
    mlx_tuple_vector_array_vector_int (
        *fun)(const mlx_vector_array, const mlx_vector_int, void*),
    void* payload,
    void (*dtor)(void*));
mlx_tuple_vector_array_vector_int mlx_closure_custom_function_vmap_apply(
    mlx_closure_custom_function_vmap cls,
    const mlx_vector_array input_0,
    const mlx_vector_int input_1);

typedef struct mlx_closure_metal_kernel_function_*
    mlx_closure_metal_kernel_function;
mlx_closure_metal_kernel_function mlx_closure_metal_kernel_function_new(
    mlx_vector_array (*fun)(
        const mlx_vector_array,
        const mlx_vector_vector_int,
        const mlx_vector_array_dtype,
        const mlx_tuple_int_int_int,
        const mlx_tuple_int_int_int,
        const mlx_vector_tuple_string_variant_int_bool_array_dtype,
        float,
        bool,
        const mlx_stream));
mlx_closure_metal_kernel_function
mlx_closure_metal_kernel_function_new_with_payload(
    mlx_vector_array (*fun)(
        const mlx_vector_array,
        const mlx_vector_vector_int,
        const mlx_vector_array_dtype,
        const mlx_tuple_int_int_int,
        const mlx_tuple_int_int_int,
        const mlx_vector_tuple_string_variant_int_bool_array_dtype,
        float,
        bool,
        const mlx_stream,
        void*),
    void* payload,
    void (*dtor)(void*));
mlx_vector_array mlx_closure_metal_kernel_function_apply(
    mlx_closure_metal_kernel_function cls,
    const mlx_vector_array input_0,
    const mlx_vector_vector_int input_1,
    const mlx_vector_array_dtype input_2,
    const mlx_tuple_int_int_int input_3,
    const mlx_tuple_int_int_int input_4,
    const mlx_vector_tuple_string_variant_int_bool_array_dtype input_5,
    float input_6,
    bool input_7,
    const mlx_stream input_8);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
