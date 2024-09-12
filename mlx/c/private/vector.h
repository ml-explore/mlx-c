/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_VECTOR_PRIVATE_H
#define MLX_VECTOR_PRIVATE_H

#include "mlx/c/object.h"
#include "mlx/c/private/object.h"
#include "mlx/c/vector.h"
#include "mlx/mlx.h"

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
  mlx_vector_vector_array_(const std::tuple<
                           std::vector<mlx::core::array>,
                           std::vector<mlx::core::array>,
                           std::vector<mlx::core::array>>& ctx)
      : mlx_object_(),
        ctx({std::get<0>(ctx), std::get<1>(ctx), std::get<2>(ctx)}){};
  virtual mlx_string_* tostring() override;
  std::vector<std::vector<mlx::core::array>> ctx;
};

struct mlx_vector_int_ : mlx_object_ {
  mlx_vector_int_() : mlx_object_(){};
  mlx_vector_int_(const std::vector<int>& ctx) : mlx_object_(), ctx(ctx){};
  mlx_vector_int_(std::vector<int>&& ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  mlx_vector_int_(const std::pair<int, int>& ctx)
      : mlx_object_(), ctx({ctx.first, ctx.second}){};
  mlx_vector_int_(const std::tuple<int, int, int>& ctx)
      : mlx_object_(),
        ctx({std::get<0>(ctx), std::get<1>(ctx), std::get<2>(ctx)}){};
  virtual mlx_string_* tostring() override;
  std::vector<int> ctx;
};

struct mlx_vector_vector_int_ : mlx_object_ {
  mlx_vector_vector_int_() : mlx_object_(){};
  mlx_vector_vector_int_(const std::vector<std::vector<int>>& ctx)
      : mlx_object_(), ctx(ctx){};
  mlx_vector_vector_int_(std::vector<std::vector<int>>&& ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  mlx_vector_vector_int_(
      const std::pair<std::vector<int>, std::vector<int>>& ctx)
      : mlx_object_(), ctx({ctx.first, ctx.second}){};
  mlx_vector_vector_int_(
      const std::tuple<std::vector<int>, std::vector<int>, std::vector<int>>&
          ctx)
      : mlx_object_(),
        ctx({std::get<0>(ctx), std::get<1>(ctx), std::get<2>(ctx)}){};
  virtual mlx_string_* tostring() override;
  std::vector<std::vector<int>> ctx;
};

struct mlx_vector_string_ : mlx_object_ {
  mlx_vector_string_() : mlx_object_(){};
  mlx_vector_string_(const std::vector<std::string>& ctx)
      : mlx_object_(), ctx(ctx){};
  mlx_vector_string_(std::vector<std::string>&& ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  mlx_vector_string_(const std::pair<std::string, std::string>& ctx)
      : mlx_object_(), ctx({ctx.first, ctx.second}){};
  mlx_vector_string_(
      const std::tuple<std::string, std::string, std::string>& ctx)
      : mlx_object_(),
        ctx({std::get<0>(ctx), std::get<1>(ctx), std::get<2>(ctx)}){};
  virtual mlx_string_* tostring() override;
  std::vector<std::string> ctx;
};

struct mlx_vector_array_dtype_ : mlx_object_ {
  mlx_vector_array_dtype_() : mlx_object_(){};
  mlx_vector_array_dtype_(const std::vector<mlx::core::Dtype>& ctx)
      : mlx_object_(), ctx(ctx){};
  mlx_vector_array_dtype_(std::vector<mlx::core::Dtype>&& ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  mlx_vector_array_dtype_(
      const std::pair<mlx::core::Dtype, mlx::core::Dtype>& ctx)
      : mlx_object_(), ctx({ctx.first, ctx.second}){};
  mlx_vector_array_dtype_(
      const std::tuple<mlx::core::Dtype, mlx::core::Dtype, mlx::core::Dtype>&
          ctx)
      : mlx_object_(),
        ctx({std::get<0>(ctx), std::get<1>(ctx), std::get<2>(ctx)}){};
  virtual mlx_string_* tostring() override;
  std::vector<mlx::core::Dtype> ctx;
};

struct mlx_vector_tuple_string_variant_int_bool_array_dtype_ : mlx_object_ {
  mlx_vector_tuple_string_variant_int_bool_array_dtype_() : mlx_object_(){};
  mlx_vector_tuple_string_variant_int_bool_array_dtype_(
      const std::vector<
          std::pair<std::string, std::variant<int, bool, mlx::core::Dtype>>>&
          ctx)
      : mlx_object_(), ctx(ctx){};
  mlx_vector_tuple_string_variant_int_bool_array_dtype_(
      std::vector<
          std::pair<std::string, std::variant<int, bool, mlx::core::Dtype>>>&&
          ctx)
      : mlx_object_(), ctx(std::move(ctx)){};
  mlx_vector_tuple_string_variant_int_bool_array_dtype_(
      const std::pair<
          std::pair<std::string, std::variant<int, bool, mlx::core::Dtype>>,
          std::pair<std::string, std::variant<int, bool, mlx::core::Dtype>>>&
          ctx)
      : mlx_object_(), ctx({ctx.first, ctx.second}){};
  mlx_vector_tuple_string_variant_int_bool_array_dtype_(
      const std::tuple<
          std::pair<std::string, std::variant<int, bool, mlx::core::Dtype>>,
          std::pair<std::string, std::variant<int, bool, mlx::core::Dtype>>,
          std::pair<std::string, std::variant<int, bool, mlx::core::Dtype>>>&
          ctx)
      : mlx_object_(),
        ctx({std::get<0>(ctx), std::get<1>(ctx), std::get<2>(ctx)}){};
  virtual mlx_string_* tostring() override;
  std::vector<std::pair<std::string, std::variant<int, bool, mlx::core::Dtype>>>
      ctx;
};

#endif
