/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/compile.h"
#include "mlx/c/error.h"
#include "mlx/c/private/mlx.h"
#include "mlx/compile_impl.h"

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
extern "C" int mlx_detail_compile_replace(
    mlx_vector_array* res,
    const mlx_vector_array tape,
    const mlx_vector_array trace_inputs,
    const mlx_vector_array trace_outputs,
    const mlx_vector_array inputs,
    bool shapeless) {
  try {
    mlx_vector_array_set_(
        *res,
        mlx::core::detail::compile_replace(
            mlx_vector_array_get_(tape),
            mlx_vector_array_get_(trace_inputs),
            mlx_vector_array_get_(trace_outputs),
            mlx_vector_array_get_(inputs),
            shapeless));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_detail_compile_trace(
    mlx_vector_array* res_0,
    mlx_vector_array* res_1,
    const mlx_closure fun,
    const mlx_vector_array inputs,
    bool shapeless) {
  try {
    {
      auto [tpl_0, tpl_1] = mlx::core::detail::compile_trace(
          mlx_closure_get_(fun), mlx_vector_array_get_(inputs), shapeless);
      mlx_vector_array_set_(*res_0, tpl_0);
      mlx_vector_array_set_(*res_1, tpl_1);
    };
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_detail_compile_validate_shapeless(
    const mlx_vector_array tape) {
  try {
    mlx::core::detail::compile_validate_shapeless(mlx_vector_array_get_(tape));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_disable_compile() {
  try {
    mlx::core::disable_compile();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_enable_compile() {
  try {
    mlx::core::enable_compile();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_set_compile_mode(mlx_compile_mode mode) {
  try {
    mlx::core::set_compile_mode(mlx_compile_mode_to_cpp(mode));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
