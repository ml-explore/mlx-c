/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_FUTURE_PRIVATE_H
#define MLX_FUTURE_PRIVATE_H

#include <future>

#include "mlx/c/future.h"
#include "mlx/c/private/object.h"
#include "mlx/mlx.h"

struct mlx_future_ : mlx_object_ {
  mlx_future_(std::shared_future<void>&& ctx)
      : mlx_object_(), ctx(std::move(ctx)) {};
  virtual mlx_string_* tostring() override;
  std::shared_future<void> ctx;
};

#endif
