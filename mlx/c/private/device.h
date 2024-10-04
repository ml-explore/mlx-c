/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_DEVICE_PRIVATE_H
#define MLX_DEVICE_PRIVATE_H

#include "mlx/c/device.h"
#include "mlx/c/private/object.h"
#include "mlx/mlx.h"

mlx_device mlx_device_new_(mlx::core::Device&& s) {
  return mlx_device({new mlx::core::Device(std::move(s))});
}
mlx_device mlx_device_new_(const mlx::core::Device& s) {
  return mlx_device({new mlx::core::Device(s)});
}

mlx_device mlx_device_set_(mlx_device d, mlx::core::Device s) {
  if (d.ctx) {
    *static_cast<mlx::core::Device*>(d.ctx) = s;
  } else {
    d.ctx = new mlx::core::Device(s);
  }
  return d;
}

mlx::core::Device& mlx_device_get_(mlx_device d) {
  return *static_cast<mlx::core::Device*>(d.ctx);
}

#endif
