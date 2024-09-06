/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_VARIANT_PRIVATE_H
#define MLX_VARIANT_PRIVATE_H

#include <string>
#include <variant>
#include "mlx/c/private/object.h"

struct mlx_string_size_t_variant_ : mlx_object_ {
  mlx_string_size_t_variant_(const std::variant<std::string, size_t>& ctx)
      : mlx_object_(), ctx(ctx){};
  mlx_string_size_t_variant_(const std::variant<std::string, size_t>&& ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  virtual mlx_string_* tostring() override;
  std::variant<std::string, size_t> ctx;
};

#endif
