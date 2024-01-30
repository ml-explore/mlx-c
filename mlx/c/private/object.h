/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_OBJECT_PRIVATE_H
#define MLX_OBJECT_PRIVATE_H

#include <atomic>

struct mlx_string_;

struct mlx_object_ {
  mlx_object_() : refcount(1){};
  virtual mlx_string_* tostring() = 0;
  virtual ~mlx_object_(){};
  std::atomic<uint64_t> refcount;
};

#endif
