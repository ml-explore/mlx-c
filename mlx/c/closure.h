/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_CLOSURE_H
#define MLX_CLOSURE_H

#include "mlx/c/array.h"
#include "mlx/c/optional.h"
#include "mlx/c/stream.h"
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
mlx_closure mlx_closure_new();
mlx_closure mlx_closure_new_func(
    void (*fun)(const mlx_vector_array, mlx_vector_array));
mlx_closure mlx_closure_new_func_payload(
    void (*fun)(const mlx_vector_array, void*, mlx_vector_array),
    void* payload,
    void (*dtor)(void*));
int mlx_closure_apply(
    mlx_closure cls,
    const mlx_vector_array input,
    mlx_vector_array res);

mlx_closure mlx_closure_new_unary(void (*fun)(const mlx_array, mlx_array));

typedef struct mlx_closure_value_and_grad_* mlx_closure_value_and_grad;
mlx_closure_value_and_grad mlx_closure_value_and_grad_new();
mlx_closure_value_and_grad mlx_closure_value_and_grad_new_func(
    void (*fun)(const mlx_vector_array, mlx_vector_array, mlx_vector_array));
mlx_closure_value_and_grad mlx_closure_value_and_grad_new_func_payload(
    void (*fun)(
        const mlx_vector_array,
        void*,
        mlx_vector_array,
        mlx_vector_array),
    void* payload,
    void (*dtor)(void*));
int mlx_closure_value_and_grad_apply(
    mlx_closure_value_and_grad cls,
    const mlx_vector_array input,
    mlx_vector_array res_0,
    mlx_vector_array res_1);

typedef struct mlx_closure_custom_* mlx_closure_custom;
mlx_closure_custom mlx_closure_custom_new();
mlx_closure_custom mlx_closure_custom_new_func(void (*fun)(
    const mlx_vector_array,
    const mlx_vector_array,
    const mlx_vector_array,
    mlx_vector_array));
mlx_closure_custom mlx_closure_custom_new_func_payload(
    void (*fun)(
        const mlx_vector_array,
        const mlx_vector_array,
        const mlx_vector_array,
        void*,
        mlx_vector_array),
    void* payload,
    void (*dtor)(void*));
int mlx_closure_custom_apply(
    mlx_closure_custom cls,
    const mlx_vector_array input_0,
    const mlx_vector_array input_1,
    const mlx_vector_array input_2,
    mlx_vector_array res);

typedef struct mlx_closure_custom_jvp_* mlx_closure_custom_jvp;
mlx_closure_custom_jvp mlx_closure_custom_jvp_new();
mlx_closure_custom_jvp mlx_closure_custom_jvp_new_func(void (*fun)(
    const mlx_vector_array,
    const mlx_vector_array,
    const int*,
    size_t _num,
    mlx_vector_array));
mlx_closure_custom_jvp mlx_closure_custom_jvp_new_func_payload(
    void (*fun)(
        const mlx_vector_array,
        const mlx_vector_array,
        const int*,
        size_t _num,
        void*,
        mlx_vector_array),
    void* payload,
    void (*dtor)(void*));
int mlx_closure_custom_jvp_apply(
    mlx_closure_custom_jvp cls,
    const mlx_vector_array input_0,
    const mlx_vector_array input_1,
    const int* input_2,
    size_t input_2_num,
    mlx_vector_array res);

typedef struct mlx_closure_custom_vmap_* mlx_closure_custom_vmap;
mlx_closure_custom_vmap mlx_closure_custom_vmap_new();
mlx_closure_custom_vmap mlx_closure_custom_vmap_new_func(void (*fun)(
    const mlx_vector_array,
    const int*,
    size_t _num,
    mlx_vector_array,
    mlx_vector_int));
mlx_closure_custom_vmap mlx_closure_custom_vmap_new_func_payload(
    void (*fun)(
        const mlx_vector_array,
        const int*,
        size_t _num,
        void*,
        mlx_vector_array,
        mlx_vector_int),
    void* payload,
    void (*dtor)(void*));
int mlx_closure_custom_vmap_apply(
    mlx_closure_custom_vmap cls,
    const mlx_vector_array input_0,
    const int* input_1,
    size_t input_1_num,
    mlx_vector_array res_0,
    mlx_vector_int res_1);

typedef struct mlx_closure_metal_kernel_* mlx_closure_metal_kernel;
mlx_closure_metal_kernel mlx_closure_metal_kernel_new();
int mlx_closure_metal_kernel_apply(
    mlx_closure_metal_kernel cls,
    const mlx_vector_array inputs,
    const mlx_stream stream,
    mlx_vector_array outputs);
int mlx_closure_metal_kernel_add_output_arg(
    mlx_closure_metal_kernel cls,
    const int* shape,
    size_t size,
    mlx_dtype dtype);
int mlx_closure_metal_kernel_set_grid(
    mlx_closure_metal_kernel cls,
    int grid1,
    int grid2,
    int grid3);
int mlx_closure_metal_kernel_set_thread_group(
    mlx_closure_metal_kernel cls,
    int thread1,
    int thread2,
    int thread3);
int mlx_closure_metal_kernel_set_init_value(
    mlx_closure_metal_kernel cls,
    float value);
int mlx_closure_metal_kernel_set_verbose(
    mlx_closure_metal_kernel cls,
    bool verbose);
int mlx_closure_metal_kernel_add_template_arg_dtype(
    mlx_closure_metal_kernel cls,
    const char* name,
    mlx_dtype dtype);
int mlx_closure_metal_kernel_add_template_arg_int(
    mlx_closure_metal_kernel cls,
    const char* name,
    int value);
int mlx_closure_metal_kernel_add_template_arg_bool(
    mlx_closure_metal_kernel cls,
    const char* name,
    bool value);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
