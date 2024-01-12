#ifndef MLX_CLOSURE_H
#define MLX_CLOSURE_H

#include "mlx/c/array.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mlx_closure_* mlx_closure;

mlx_closure mlx_closure_new(mlx_vector_array (*fun)(const mlx_array*, size_t));
mlx_closure mlx_closure_new_unary(mlx_array (*fun)(const mlx_array));
mlx_closure mlx_closure_new_with_payload(
    mlx_vector_array (*fun)(const mlx_array*, size_t, void*),
    void* payload,
    void (*dtor)(void*));
mlx_vector_array
mlx_closure_apply(mlx_closure cls, const mlx_array* inputs, size_t num_inputs);

#ifdef __cplusplus
}
#endif

#endif
