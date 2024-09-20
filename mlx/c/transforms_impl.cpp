/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/transforms_impl.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/future.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" int mlx_detail_compile(
    mlx_closure fun,
    uintptr_t fun_id,
    bool shapeless,
    const uint64_t* constants,
    size_t num_constants,
    mlx_closure res) {
  try {
    res->ctx = mlx::core::detail::compile(
        (fun)->ctx,
        fun_id,
        shapeless,
        MLX_CPP_UINT64VEC(constants, num_constants));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_detail_compile_clear_cache() {
  try {
    mlx::core::detail::compile_clear_cache();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_detail_compile_erase(uintptr_t fun_id) {
  try {
    mlx::core::detail::compile_erase(fun_id);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_detail_vmap_replace(
    const mlx_vector_array inputs,
    const mlx_vector_array s_inputs,
    const mlx_vector_array s_outputs,
    const int* in_axes,
    size_t num_in_axes,
    const int* out_axes,
    size_t num_out_axes,
    mlx_vector_array res) {
  try {
    res->ctx = mlx::core::detail::vmap_replace(
        MLX_CPP_ARRVEC(inputs),
        MLX_CPP_ARRVEC(s_inputs),
        MLX_CPP_ARRVEC(s_outputs),
        MLX_CPP_INTVEC(in_axes, num_in_axes),
        MLX_CPP_INTVEC(out_axes, num_out_axes));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_detail_vmap_trace(
    mlx_closure fun,
    const mlx_vector_array inputs,
    const int* in_axes,
    size_t num_in_axes,
    mlx_vector_array res_0,
    mlx_vector_array res_1) {
  try {
    std::tie(res_0->ctx, res_1->ctx) = mlx::core::detail::vmap_trace(
        (fun)->ctx,
        MLX_CPP_ARRVEC(inputs),
        MLX_CPP_INTVEC(in_axes, num_in_axes));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
