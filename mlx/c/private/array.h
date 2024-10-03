/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_ARRAY_PRIVATE_H
#define MLX_ARRAY_PRIVATE_H

#include "mlx/c/array.h"
#include "mlx/c/private/object.h"
#include "mlx/mlx.h"

static mlx::core::array
    mlx_empty_array_(std::vector<int>{0}, mlx::core::float32, nullptr, {});

struct mlx_array_ : mlx_object_ {
  mlx_array_() : mlx_object_(), ctx(mlx_empty_array_){};
  mlx_array_(mlx::core::array ctx) : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  mlx::core::array ctx;
};

#endif
