/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_STRING_PRIVATE_H
#define MLX_STRING_PRIVATE_H

#include <string>
#include "mlx/c/private/object.h"

struct mlx_string_ : mlx_object_ {
  mlx_string_(const std::string& ctx) : mlx_object_(), ctx(ctx){};
  mlx_string_(const std::string&& ctx) : mlx_object_(), ctx(std::move(ctx)){};
  virtual mlx_string_* tostring() override;
  std::string ctx;
};

#endif
