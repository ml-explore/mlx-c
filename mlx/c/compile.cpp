/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/compile.h"
#include "mlx/c/error.h"
#include "mlx/c/private/mlx.h"
#include "mlx/compile.h"

extern "C" int
mlx_compile(mlx_closure* res, const mlx_closure fun, bool shapeless) {
  try {
    mlx_closure_set_(
        *res, mlx::core::compile(mlx_closure_get_(fun), shapeless));
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
