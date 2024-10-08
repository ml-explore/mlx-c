/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/transforms_impl.h"
#include "mlx/c/error.h"
#include "mlx/c/private/mlx.h"
#include "mlx/transforms_impl.h"

extern "C" int mlx_detail_compile(
    mlx_closure* res,
    const mlx_closure fun,
    uintptr_t fun_id,
    bool shapeless,
    const uint64_t* constants,
    size_t constants_num) {
  try {
    mlx_closure_set_(
        *res,
        mlx::core::detail::compile(
            mlx_closure_get_(fun),
            fun_id,
            shapeless,
            std::vector<uint64_t>(constants, constants + constants_num)));
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
    mlx_vector_array* res,
    const mlx_vector_array inputs,
    const mlx_vector_array s_inputs,
    const mlx_vector_array s_outputs,
    const int* in_axes,
    size_t in_axes_num,
    const int* out_axes,
    size_t out_axes_num) {
  try {
    mlx_vector_array_set_(
        *res,
        mlx::core::detail::vmap_replace(
            mlx_vector_array_get_(inputs),
            mlx_vector_array_get_(s_inputs),
            mlx_vector_array_get_(s_outputs),
            std::vector<int>(in_axes, in_axes + in_axes_num),
            std::vector<int>(out_axes, out_axes + out_axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_detail_vmap_trace(
    mlx_vector_array* res_0,
    mlx_vector_array* res_1,
    const mlx_closure fun,
    const mlx_vector_array inputs,
    const int* in_axes,
    size_t in_axes_num) {
  try {
    std::tie(mlx_vector_array_get_(*res_0), mlx_vector_array_get_(*res_1)) =
        mlx::core::detail::vmap_trace(
            mlx_closure_get_(fun),
            mlx_vector_array_get_(inputs),
            std::vector<int>(in_axes, in_axes + in_axes_num));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
