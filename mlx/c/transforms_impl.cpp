/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/transforms_impl.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

extern "C" mlx_closure mlx_detail_compile(
    mlx_closure fun,
    size_t fun_id,
    bool shapeless,
    const uint64_t* constants,
    size_t num_constants) {
  return MLX_C_CLOSURE(mlx::core::detail::compile(
      MLX_CPP_CLOSURE(fun),
      fun_id,
      shapeless,
      MLX_CPP_UINT64VEC(constants, num_constants)));
}
extern "C" void mlx_detail_compile_erase(size_t fun_id) {
  return MLX_C_VOID(mlx::core::detail::compile_erase(fun_id));
}
extern "C" mlx_vector_array mlx_detail_vmap_replace(
    const mlx_vector_array inputs,
    const mlx_vector_array s_inputs,
    const mlx_vector_array s_outputs,
    const int* in_axes,
    size_t num_in_axes,
    const int* out_axes,
    size_t num_out_axes) {
  return MLX_C_ARRAYS(mlx::core::detail::vmap_replace(
      MLX_CPP_ARRVEC(inputs),
      MLX_CPP_ARRVEC(s_inputs),
      MLX_CPP_ARRVEC(s_outputs),
      MLX_CPP_INTVEC(in_axes, num_in_axes),
      MLX_CPP_INTVEC(out_axes, num_out_axes)));
}
extern "C" mlx_vector_vector_array mlx_detail_vmap_trace(
    mlx_closure fun,
    const mlx_vector_array inputs,
    const int* in_axes,
    size_t num_in_axes) {
  return MLX_C_VECTORARRAYPAIR(mlx::core::detail::vmap_trace(
      MLX_CPP_CLOSURE(fun),
      MLX_CPP_ARRVEC(inputs),
      MLX_CPP_INTVEC(in_axes, num_in_axes)));
}
