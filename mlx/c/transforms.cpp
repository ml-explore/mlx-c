/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/transforms.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

extern "C" mlx_closure mlx_checkpoint(mlx_closure fun) {
  return MLX_C_CLOSURE(mlx::core::checkpoint(MLX_CPP_CLOSURE(fun)));
}
extern "C" void mlx_eval(const mlx_vector_array outputs) {
  return MLX_C_VOID(mlx::core::eval(MLX_CPP_ARRVEC(outputs)));
}
extern "C" mlx_vector_vector_array mlx_jvp(
    mlx_closure fun,
    const mlx_vector_array primals,
    const mlx_vector_array tangents) {
  return MLX_C_VECTORARRAYPAIR(mlx::core::jvp(
      MLX_CPP_CLOSURE(fun), MLX_CPP_ARRVEC(primals), MLX_CPP_ARRVEC(tangents)));
}
extern "C" mlx_closure_value_and_grad
mlx_value_and_grad(mlx_closure fun, const int* argnums, size_t num_argnums) {
  return MLX_C_CLOSURE_VALUE_AND_GRAD(mlx::core::value_and_grad(
      MLX_CPP_CLOSURE(fun), MLX_CPP_INTVEC(argnums, num_argnums)));
}
extern "C" mlx_vector_vector_array mlx_vjp(
    mlx_closure fun,
    const mlx_vector_array primals,
    const mlx_vector_array cotangents) {
  return MLX_C_VECTORARRAYPAIR(mlx::core::vjp(
      MLX_CPP_CLOSURE(fun),
      MLX_CPP_ARRVEC(primals),
      MLX_CPP_ARRVEC(cotangents)));
}
