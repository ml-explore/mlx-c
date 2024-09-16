/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/einsum.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/future.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/tuple.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" mlx_array mlx_einsum(
    mlx_string subscripts,
    const mlx_vector_array operands,
    mlx_stream s) {
  RETURN_MLX_C_PTR(new mlx_array_((mlx::core::einsum(
      MLX_CPP_STRING(subscripts), MLX_CPP_ARRVEC(operands), s->ctx))));
}
