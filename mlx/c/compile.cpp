/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/compile.h"

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

namespace {
mlx_compile_mode to_c_type(mlx::core::CompileMode type) {
  static mlx_compile_mode map[] = {
      MLX_COMPILE_MODE_DISABLED,
      MLX_COMPILE_MODE_NO_SIMPLIFY,
      MLX_COMPILE_MODE_NO_FUSE,
      MLX_COMPILE_MODE_ENABLED};
  return map[(int)type];
}
mlx::core::CompileMode to_cpp_type(mlx_compile_mode type) {
  static mlx::core::CompileMode map[] = {
      mlx::core::CompileMode::disabled,
      mlx::core::CompileMode::no_simplify,
      mlx::core::CompileMode::no_fuse,
      mlx::core::CompileMode::enabled};
  return map[(int)type];
}
} // namespace
extern "C" mlx_closure mlx_compile(mlx_closure fun, bool shapeless) {
  RETURN_MLX_C_CLOSURE(mlx::core::compile(MLX_CPP_CLOSURE(fun), shapeless));
}
extern "C" void mlx_disable_compile() {
  RETURN_MLX_C_VOID(mlx::core::disable_compile());
}
extern "C" void mlx_enable_compile() {
  RETURN_MLX_C_VOID(mlx::core::enable_compile());
}
extern "C" void mlx_set_compile_mode(mlx_compile_mode mode) {
  RETURN_MLX_C_VOID(mlx::core::set_compile_mode(to_cpp_type(mode)));
}
