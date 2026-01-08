/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_DEVICE_PRIVATE_H
#define MLX_DEVICE_PRIVATE_H

#include "mlx/c/device.h"
#include "mlx/mlx.h"

inline mlx_device mlx_device_new_() {
  return mlx_device({nullptr});
}

inline mlx_device mlx_device_new_(const mlx::core::Device& s) {
  return mlx_device({new mlx::core::Device(s)});
}

inline mlx_device mlx_device_new_(mlx::core::Device&& s) {
  return mlx_device({new mlx::core::Device(std::move(s))});
}

inline mlx_device& mlx_device_set_(mlx_device& d, const mlx::core::Device& s) {
  if (d.ctx) {
    *static_cast<mlx::core::Device*>(d.ctx) = s;
  } else {
    d.ctx = new mlx::core::Device(s);
  }
  return d;
}

inline mlx_device& mlx_device_set_(mlx_device& d, mlx::core::Device&& s) {
  if (d.ctx) {
    *static_cast<mlx::core::Device*>(d.ctx) = std::move(s);
  } else {
    d.ctx = new mlx::core::Device(std::move(s));
  }
  return d;
}

inline mlx::core::Device& mlx_device_get_(mlx_device d) {
  if (!d.ctx) {
    throw std::runtime_error("expected a non-empty mlx_device");
  }
  return *static_cast<mlx::core::Device*>(d.ctx);
}

inline void mlx_device_free_(mlx_device d) {
  if (d.ctx) {
    delete static_cast<mlx::core::Device*>(d.ctx);
  }
}

#endif
