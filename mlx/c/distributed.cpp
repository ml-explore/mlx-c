/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/ops.h"

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

extern "C" mlx_array mlx_distributed_all_gather(
    mlx_array x,
    mlx_distributed_group group) {
  RETURN_MLX_C_ARRAY(mlx::core::distributed::all_gather(
      x->ctx, (group ? std::make_optional(group->ctx) : std::nullopt)));
}
extern "C" mlx_array mlx_distributed_all_sum(
    mlx_array x,
    mlx_distributed_group group) {
  RETURN_MLX_C_ARRAY(mlx::core::distributed::all_sum(
      x->ctx, (group ? std::make_optional(group->ctx) : std::nullopt)));
}
