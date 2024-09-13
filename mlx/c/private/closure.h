/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_CLOSURE_PRIVATE_H
#define MLX_CLOSURE_PRIVATE_H

#include "mlx/c/closure.h"
#include "mlx/c/private/object.h"
#include "mlx/mlx.h"

struct mlx_closure_ : mlx_object_ {
  mlx_closure_(std::function<std::vector<mlx::core::array>(
                   const std::vector<mlx::core::array>&)> ctx)
      : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  std::function<std::vector<mlx::core::array>(
      const std::vector<mlx::core::array>&)>
      ctx;
};

struct mlx_closure_value_and_grad_ : mlx_object_ {
  mlx_closure_value_and_grad_(
      std::function<std::pair<
          std::vector<mlx::core::array>,
          std::vector<mlx::core::array>>(const std::vector<mlx::core::array>&)>
          ctx)
      : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  std::function<
      std::pair<std::vector<mlx::core::array>, std::vector<mlx::core::array>>(
          const std::vector<mlx::core::array>&)>
      ctx;
};

struct mlx_closure_custom_function_ : mlx_object_ {
  mlx_closure_custom_function_(std::function<std::vector<mlx::core::array>(
                                   const std::vector<mlx::core::array>&,
                                   const std::vector<mlx::core::array>&,
                                   const std::vector<mlx::core::array>&)> ctx)
      : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  std::function<std::vector<mlx::core::array>(
      const std::vector<mlx::core::array>&,
      const std::vector<mlx::core::array>&,
      const std::vector<mlx::core::array>&)>
      ctx;
};

struct mlx_closure_custom_function_jvp_ : mlx_object_ {
  mlx_closure_custom_function_jvp_(std::function<std::vector<mlx::core::array>(
                                       const std::vector<mlx::core::array>&,
                                       const std::vector<mlx::core::array>&,
                                       const std::vector<int>&)> ctx)
      : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  std::function<std::vector<mlx::core::array>(
      const std::vector<mlx::core::array>&,
      const std::vector<mlx::core::array>&,
      const std::vector<int>&)>
      ctx;
};

struct mlx_closure_custom_function_vmap_ : mlx_object_ {
  mlx_closure_custom_function_vmap_(
      std::function<std::pair<std::vector<mlx::core::array>, std::vector<int>>(
          const std::vector<mlx::core::array>&,
          const std::vector<int>&)> ctx)
      : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  std::function<std::pair<std::vector<mlx::core::array>, std::vector<int>>(
      const std::vector<mlx::core::array>&,
      const std::vector<int>&)>
      ctx;
};

struct mlx_closure_metal_kernel_function_ : mlx_object_ {
  mlx_closure_metal_kernel_function_(
      std::function<std::vector<mlx::core::array>(
          const std::vector<mlx::core::array>&,
          const std::vector<std::vector<int>>&,
          const std::vector<mlx::core::Dtype>&,
          const std::tuple<int, int, int>&,
          const std::tuple<int, int, int>&,
          const std::vector<
              std::pair<std::string, mlx::core::fast::TemplateArg>>&,
          std::optional<float>,
          bool,
          const mlx::core::Stream&)> ctx)
      : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  std::function<std::vector<mlx::core::array>(
      const std::vector<mlx::core::array>&,
      const std::vector<std::vector<int>>&,
      const std::vector<mlx::core::Dtype>&,
      const std::tuple<int, int, int>&,
      const std::tuple<int, int, int>&,
      const std::vector<std::pair<std::string, mlx::core::fast::TemplateArg>>&,
      std::optional<float>,
      bool,
      const mlx::core::Stream&)>
      ctx;
};

#endif
