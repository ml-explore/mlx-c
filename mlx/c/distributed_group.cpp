/* Copyright © 2023-2024 Apple Inc. */

#include <cstring>

#include "mlx/c/distributed_group.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/utils.h"

extern "C" int mlx_distributed_group_rank(mlx_distributed_group group) {
  return mlx_distributed_group_get_(group).rank();
}

extern "C" int mlx_distributed_group_size(mlx_distributed_group group) {
  return mlx_distributed_group_get_(group).size();
}

extern "C" mlx_distributed_group
mlx_distributed_group_split(mlx_distributed_group group, int color, int key) {
  return mlx_distributed_group_new_(
      mlx_distributed_group_get_(group).split(color, key));
}

extern "C" bool mlx_distributed_is_available() {
  return mlx::core::distributed::is_available();
}

extern "C" mlx_distributed_group mlx_distributed_init(bool strict) {
  return mlx_distributed_group_new_(mlx::core::distributed::init(strict));
}
