/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/transforms_impl.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" int mlx_detail_compile(
    const mlx_closure fun,
    uintptr_t fun_id,
    bool shapeless,
    const uint64_t* constants,
    size_t constants_num,
    mlx_closure* res) {
  try {
    (*res)->ctx = mlx::core::detail::compile(
        fun->ctx,
        fun_id,
        shapeless,
        std::vector<uint64_t>(constants, constants + constants_num));
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
    size_t in_axes_num,
    const int* out_axes,
    size_t out_axes_num,
    mlx_vector_array* res) {
  try {
    (*res)->ctx = mlx::core::detail::vmap_replace(
        inputs->ctx,
        s_inputs->ctx,
        s_outputs->ctx,
        std::vector<int>(in_axes, in_axes + in_axes_num),
        std::vector<int>(out_axes, out_axes + out_axes_num));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_detail_vmap_trace(
    const mlx_closure fun,
    const mlx_vector_array inputs,
    const int* in_axes,
    size_t in_axes_num,
    mlx_vector_array* res_0,
    mlx_vector_array* res_1) {
  try {
    std::tie((*res_0)->ctx, (*res_1)->ctx) = mlx::core::detail::vmap_trace(
        fun->ctx,
        inputs->ctx,
        std::vector<int>(in_axes, in_axes + in_axes_num));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
