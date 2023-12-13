#ifndef MLX_DEVICE_PRIVATE_H
#define MLX_DEVICE_PRIVATE_H

#include "mlx/c/device.h"
#include "mlx/c/private/object.h"
#include "mlx/mlx.h"

struct mlx_device_ : mlx_object_ {
  mlx_device_(mlx::core::Device ctx) : mlx_object_(), ctx(ctx){};
  virtual char* tostring() override;
  mlx::core::Device ctx;
};

#endif
