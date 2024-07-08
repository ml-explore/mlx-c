/* Copyright © 2023-2024 Apple Inc. */

#include <cstring>

#include "mlx/c/distributed_group.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

mlx_string_* mlx_distributed_group_::tostring() {
  RETURN_MLX_C_STRING("mlx_distributed_group");
}

extern "C" int mlx_distributed_group_rank(mlx_distributed_group group) {
  return group->ctx.rank();
}

extern "C" int mlx_distributed_group_size(mlx_distributed_group group) {
  return group->ctx.size();
}

extern "C" mlx_distributed_group
mlx_distributed_group_split(mlx_distributed_group group, int color, int key) {
  RETURN_MLX_C_DISTRIBUTED_GROUP(group->ctx.split(color, key));
}

extern "C" bool mlx_distributed_is_available() {
  return mlx::core::distributed::is_available();
}

extern "C" mlx_distributed_group mlx_distributed_init(bool strict) {
  RETURN_MLX_C_DISTRIBUTED_GROUP(mlx::core::distributed::init(strict));
}

extern "C" mlx_stream mlx_distributed_communication_stream() {
  RETURN_MLX_C_STREAM(mlx::core::distributed::detail::communication_stream());
}
