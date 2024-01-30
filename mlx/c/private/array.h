/* Copyright © 2023-2024 Apple Inc. */

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

struct mlx_vector_array_ : mlx_object_ {
  mlx_vector_array_() : mlx_object_(){};
  mlx_vector_array_(const std::vector<mlx::core::array>& ctx)
      : mlx_object_(), ctx(ctx){};
  mlx_vector_array_(std::vector<mlx::core::array>&& ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  mlx_vector_array_(const std::pair<mlx::core::array, mlx::core::array>& ctx)
      : mlx_object_(), ctx({ctx.first, ctx.second}){};
  mlx_vector_array_(
      const std::tuple<mlx::core::array, mlx::core::array, mlx::core::array>&
          ctx)
      : mlx_object_(),
        ctx({std::get<0>(ctx), std::get<1>(ctx), std::get<2>(ctx)}){};
  virtual mlx_string_* tostring() override;
  std::vector<mlx::core::array> ctx;
};

struct mlx_vector_vector_array_ : mlx_object_ {
  mlx_vector_vector_array_() : mlx_object_(){};
  mlx_vector_vector_array_(
      const std::vector<std::vector<mlx::core::array>>& ctx)
      : mlx_object_(), ctx(ctx){};
  mlx_vector_vector_array_(std::vector<std::vector<mlx::core::array>>&& ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  mlx_vector_vector_array_(const std::pair<
                           std::vector<mlx::core::array>,
                           std::vector<mlx::core::array>>& ctx)
      : mlx_object_(), ctx({ctx.first, ctx.second}){};
  virtual mlx_string_* tostring() override;
  std::vector<std::vector<mlx::core::array>> ctx;
};

#endif
