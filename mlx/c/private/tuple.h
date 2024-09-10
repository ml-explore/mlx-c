/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_TUPLE_PRIVATE_H
#define MLX_TUPLE_PRIVATE_H

#include "mlx/c/object.h"
#include "mlx/c/private/object.h"
#include "mlx/c/tuple.h"
#include "mlx/mlx.h"

#include <utility>

struct mlx_tuple_vector_array_vector_int_ : mlx_object_ {
  mlx_tuple_vector_array_vector_int_() : mlx_object_(){};
  mlx_tuple_vector_array_vector_int_(
      std::pair<std::vector<mlx::core::array>, std::vector<int>>&& ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  mlx_tuple_vector_array_vector_int_(
      const std::pair<std::vector<mlx::core::array>, std::vector<int>>& ctx)
      : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  std::pair<std::vector<mlx::core::array>, std::vector<int>> ctx;
};

#endif
