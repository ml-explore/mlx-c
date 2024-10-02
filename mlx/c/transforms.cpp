/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/transforms.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/tuple.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" void mlx_async_eval(const mlx_vector_array outputs) {
  RETURN_MLX_C_VOID(mlx::core::async_eval(MLX_CPP_ARRVEC(outputs)));
}
extern "C" mlx_closure mlx_checkpoint(mlx_closure fun) {
  RETURN_MLX_C_CLOSURE(mlx::core::checkpoint((fun)->ctx));
}
extern "C" mlx_closure mlx_custom_function(
    mlx_closure fun,
    mlx_closure_custom_function fun_vjp,
    mlx_closure_custom_function_jvp fun_jvp,
    mlx_closure_custom_function_vmap fun_vmap) {
  RETURN_MLX_C_CLOSURE(mlx::core::custom_function(
      (fun)->ctx,
      (fun_vjp ? std::make_optional((fun_vjp)->ctx) : std::nullopt),
      (fun_jvp ? std::make_optional((fun_jvp)->ctx) : std::nullopt),
      (fun_vmap ? std::make_optional((fun_vmap)->ctx) : std::nullopt)));
}
extern "C" mlx_closure mlx_custom_vjp(
    mlx_closure fun,
    mlx_closure_custom_function fun_vjp) {
  RETURN_MLX_C_CLOSURE(mlx::core::custom_vjp((fun)->ctx, (fun_vjp)->ctx));
}
extern "C" void mlx_eval(const mlx_vector_array outputs) {
  RETURN_MLX_C_VOID(mlx::core::eval(MLX_CPP_ARRVEC(outputs)));
}
extern "C" mlx_tuple_vector_array_vector_array mlx_jvp(
    mlx_closure fun,
    const mlx_vector_array primals,
    const mlx_vector_array tangents) {
  RETURN_MLX_C_VECTORARRAYPAIR(mlx::core::jvp(
      (fun)->ctx, MLX_CPP_ARRVEC(primals), MLX_CPP_ARRVEC(tangents)));
}
extern "C" mlx_closure_value_and_grad
mlx_value_and_grad(mlx_closure fun, const int* argnums, size_t num_argnums) {
  RETURN_MLX_C_CLOSURE_VALUE_AND_GRAD(mlx::core::value_and_grad(
      (fun)->ctx, MLX_CPP_INTVEC(argnums, num_argnums)));
}
extern "C" mlx_tuple_vector_array_vector_array mlx_vjp(
    mlx_closure fun,
    const mlx_vector_array primals,
    const mlx_vector_array cotangents) {
  RETURN_MLX_C_VECTORARRAYPAIR(mlx::core::vjp(
      (fun)->ctx, MLX_CPP_ARRVEC(primals), MLX_CPP_ARRVEC(cotangents)));
}
