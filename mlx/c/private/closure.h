/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_CLOSURE_PRIVATE_H
#define MLX_CLOSURE_PRIVATE_H

#include "mlx/c/closure.h"
#include "mlx/c/private/object.h"
#include "mlx/mlx.h"

// std::function<std::vector<array>(std::vector<array>)>

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

#endif
