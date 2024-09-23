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

struct mlx_closure_custom_ : mlx_object_ {
  mlx_closure_custom_(std::function<std::vector<mlx::core::array>(
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

struct mlx_closure_custom_jvp_ : mlx_object_ {
  mlx_closure_custom_jvp_(std::function<std::vector<mlx::core::array>(
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

struct mlx_closure_custom_vmap_ : mlx_object_ {
  mlx_closure_custom_vmap_(
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

struct mlx_closure_metal_kernel_desc_ : mlx_object_ {
  mlx_closure_metal_kernel_desc_() : mlx_object_(){};
  virtual mlx_string_* tostring() override;

  std::vector<std::vector<int>> output_shapes;
  std::vector<mlx::core::Dtype> output_dtypes;
  std::tuple<int, int, int> grid;
  std::tuple<int, int, int> thread_group;
  std::vector<std::pair<std::string, mlx::core::fast::TemplateArg>>
      template_args;
  std::optional<float> init_value;
  bool verbose;
};

struct mlx_closure_metal_kernel_ : mlx_object_ {
  mlx_closure_metal_kernel_() : mlx_object_() {
    ctx = [](const std::vector<mlx::core::array>&,
             const std::vector<std::vector<int>>&,
             const std::vector<mlx::core::Dtype>&,
             std::tuple<int, int, int>,
             std::tuple<int, int, int>,
             std::vector<std::pair<std::string, mlx::core::fast::TemplateArg>>,
             std::optional<float>,
             bool,
             mlx::core::StreamOrDevice) {
      return std::vector<mlx::core::array>();
    };
  };
  mlx_closure_metal_kernel_(mlx::core::fast::MetalKernelFunction ctx)
      : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  mlx::core::fast::MetalKernelFunction ctx;
};

#endif
