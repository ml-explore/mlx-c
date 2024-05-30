/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/transforms_try.h"
#include "mlx/c/result.h"
#include "mlx/c/transforms.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/future.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

extern "C" mlx_vector_vector_array_result mlx_jvp_try(
    mlx_closure fun,
    const mlx_vector_array primals,
    const mlx_vector_array tangents) {
  MLX_C_VECTORARRAYPAIR_TRY(mlx::core::jvp(
      MLX_CPP_CLOSURE(fun), MLX_CPP_ARRVEC(primals), MLX_CPP_ARRVEC(tangents)))
}
extern "C" mlx_vector_vector_array_result mlx_vjp_try(
    mlx_closure fun,
    const mlx_vector_array primals,
    const mlx_vector_array cotangents) {
  MLX_C_VECTORARRAYPAIR_TRY(mlx::core::vjp(
      MLX_CPP_CLOSURE(fun),
      MLX_CPP_ARRVEC(primals),
      MLX_CPP_ARRVEC(cotangents)))
}
