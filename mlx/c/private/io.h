/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_IO_PRIVATE_H
#define MLX_IO_PRIVATE_H

#include "mlx/c/private/map.h"
#include "mlx/c/private/object.h"
#include "mlx/mlx.h"

struct mlx_safetensors_ : mlx_object_ {
  mlx_safetensors_() : mlx_object_() {
    data = new mlx_map_string_to_array_();
    metadata = new mlx_map_string_to_string_();
  };
  mlx_safetensors_(std::pair<
                   std::unordered_map<std::string, mlx::core::array>,
                   std::unordered_map<std::string, std::string>>&& ctx)
      : mlx_object_() {
    data = new mlx_map_string_to_array_(std::move(std::get<0>(ctx)));
    metadata = new mlx_map_string_to_string_(std::move(std::get<1>(ctx)));
  };
  virtual mlx_string_* tostring() override;
  struct mlx_map_string_to_array_* data;
  struct mlx_map_string_to_string_* metadata;
  virtual ~mlx_safetensors_() {
    mlx_free(data);
    mlx_free(metadata);
  }
};

#endif
