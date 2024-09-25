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

struct mlx_fast_metal_kernel_ : mlx_object_ {
  mlx_fast_metal_kernel_(
      const std::string& name,
      const std::string& source,
      const std::string& header)
      : mlx_object_(),
        name(name),
        source(source),
        header(header),
        contiguous_rows(true){};
  virtual mlx_string_* tostring() override;
  mlx::core::fast::MetalKernelFunction ctx;
  std::string name;
  std::vector<std::string> input_names;
  std::vector<std::string> output_names;
  std::string source;
  std::string header;
  bool contiguous_rows;
  bool atomic_outputs;

  std::vector<std::vector<int>> output_shapes;
  std::vector<mlx::core::Dtype> output_dtypes;
  std::tuple<int, int, int> grid;
  std::tuple<int, int, int> thread_group;
  std::vector<std::pair<std::string, mlx::core::fast::TemplateArg>>
      template_args;
  std::optional<float> init_value;
  bool verbose;
};

#endif
