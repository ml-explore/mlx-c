/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/compile.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

extern "C" mlx_closure mlx_compile(mlx_closure fun, bool shapeless) {
  return MLX_C_CLOSURE(mlx::core::compile(MLX_CPP_CLOSURE(fun), shapeless));
}
extern "C" void mlx_disable_compile() {
  return MLX_C_VOID(mlx::core::disable_compile());
}
extern "C" void mlx_enable_compile() {
  return MLX_C_VOID(mlx::core::enable_compile());
}
