/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_VARIANT_PRIVATE_H
#define MLX_VARIANT_PRIVATE_H

#include "mlx/c/object.h"
#include "mlx/c/private/object.h"
#include "mlx/c/variant.h"
#include "mlx/mlx.h"

#include <utility>
#include <variant>

struct mlx_variant_string_size_t_ : mlx_object_ {
  mlx_variant_string_size_t_(const std::variant<std::string, size_t>& ctx)
      : mlx_object_(), ctx(ctx){};
  mlx_variant_string_size_t_(const std::variant<std::string, size_t>&& ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  virtual mlx_string_* tostring() override;
  std::variant<std::string, size_t> ctx;
};

struct mlx_variant_int_bool_array_dtype_ : mlx_object_ {
  mlx_variant_int_bool_array_dtype_(
      const std::variant<int, bool, mlx::core::Dtype>& ctx)
      : mlx_object_(), ctx(ctx){};
  mlx_variant_int_bool_array_dtype_(
      const std::variant<int, bool, mlx::core::Dtype>&& ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  virtual mlx_string_* tostring() override;
  std::variant<int, bool, mlx::core::Dtype> ctx;
};

#endif
