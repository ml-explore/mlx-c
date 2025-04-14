/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/metal.h"
#include "mlx/backend/metal/metal.h"
#include "mlx/c/error.h"
#include "mlx/c/private/mlx.h"

mlx_metal_device_info_t mlx_metal_device_info() {
  auto info = mlx::core::metal::device_info();

  mlx_metal_device_info_t c_info;
  std::strncpy(
      c_info.architecture,
      std::get<std::string>(info["architecture"]).c_str(),
      256);
  c_info.max_buffer_length = std::get<size_t>(info["max_buffer_length"]);
  c_info.max_recommended_working_set_size =
      std::get<size_t>(info["max_recommended_working_set_size"]);
  c_info.memory_size = std::get<size_t>(info["memory_size"]);
  return c_info;
}

extern "C" int mlx_metal_is_available(bool* res) {
  try {
    *res = mlx::core::metal::is_available();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_metal_start_capture(const char* path) {
  try {
    mlx::core::metal::start_capture(std::string(path));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_metal_stop_capture() {
  try {
    mlx::core::metal::stop_capture();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
