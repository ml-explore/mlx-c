#ifndef MLX_ARRAY_PRIVATE_H
#define MLX_ARRAY_PRIVATE_H

#include "mlx/c/array.h"
#include "mlx/c/private/object.h"
#include "mlx/mlx.h"

struct mlx_array_ : mlx_object_ {
  mlx_array_(mlx::core::array ctx) : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  mlx::core::array ctx;
};

#endif
