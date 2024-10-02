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

#include <tuple>
#include <utility>

struct mlx_tuple_array_array_ : mlx_object_ {
  mlx_tuple_array_array_(std::pair<mlx::core::array, mlx::core::array>&& ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  mlx_tuple_array_array_(
      const std::pair<mlx::core::array, mlx::core::array>& ctx)
      : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  std::pair<mlx::core::array, mlx::core::array> ctx;
};

struct mlx_tuple_array_array_array_ : mlx_object_ {
  mlx_tuple_array_array_array_(
      std::tuple<mlx::core::array, mlx::core::array, mlx::core::array>&& ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  mlx_tuple_array_array_array_(
      const std::tuple<mlx::core::array, mlx::core::array, mlx::core::array>&
          ctx)
      : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  std::tuple<mlx::core::array, mlx::core::array, mlx::core::array> ctx;
};

struct mlx_tuple_vector_array_vector_array_ : mlx_object_ {
  mlx_tuple_vector_array_vector_array_(
      std::pair<std::vector<mlx::core::array>, std::vector<mlx::core::array>>&&
          ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  mlx_tuple_vector_array_vector_array_(const std::pair<
                                       std::vector<mlx::core::array>,
                                       std::vector<mlx::core::array>>& ctx)
      : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  std::pair<std::vector<mlx::core::array>, std::vector<mlx::core::array>> ctx;
};

struct mlx_tuple_vector_array_vector_int_ : mlx_object_ {
  mlx_tuple_vector_array_vector_int_(
      std::pair<std::vector<mlx::core::array>, std::vector<int>>&& ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  mlx_tuple_vector_array_vector_int_(
      const std::pair<std::vector<mlx::core::array>, std::vector<int>>& ctx)
      : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  std::pair<std::vector<mlx::core::array>, std::vector<int>> ctx;
};

struct mlx_tuple_int_int_int_ : mlx_object_ {
  mlx_tuple_int_int_int_(std::tuple<int, int, int>&& ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  mlx_tuple_int_int_int_(const std::tuple<int, int, int>& ctx)
      : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  std::tuple<int, int, int> ctx;
};

struct mlx_tuple_string_variant_int_bool_array_dtype_ : mlx_object_ {
  mlx_tuple_string_variant_int_bool_array_dtype_(
      std::pair<std::string, std::variant<int, bool, mlx::core::Dtype>>&& ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  mlx_tuple_string_variant_int_bool_array_dtype_(
      const std::pair<std::string, std::variant<int, bool, mlx::core::Dtype>>&
          ctx)
      : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  std::pair<std::string, std::variant<int, bool, mlx::core::Dtype>> ctx;
};

#endif
