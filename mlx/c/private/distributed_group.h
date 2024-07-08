/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_DISTRIBUTED_GROUP_PRIVATE_H
#define MLX_DISTRIBUTED_GROUP_PRIVATE_H

#include "mlx/c/distributed_group.h"
#include "mlx/c/private/object.h"
#include "mlx/mlx.h"

struct mlx_distributed_group_ : mlx_object_ {
  mlx_distributed_group_(mlx::core::distributed::Group ctx)
      : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  mlx::core::distributed::Group ctx;
};

#endif
