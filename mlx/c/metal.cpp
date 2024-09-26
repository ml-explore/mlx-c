/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/metal.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" int mlx_metal_clear_cache() {
  try {
    mlx::core::metal::clear_cache();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

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

extern "C" int mlx_metal_get_active_memory(size_t* res) {
  try {
    *res = mlx::core::metal::get_active_memory();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_metal_get_cache_memory(size_t* res) {
  try {
    *res = mlx::core::metal::get_cache_memory();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_metal_get_peak_memory(size_t* res) {
  try {
    *res = mlx::core::metal::get_peak_memory();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
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
extern "C" int mlx_metal_reset_peak_memory() {
  try {
    mlx::core::metal::reset_peak_memory();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_metal_set_cache_limit(size_t limit, size_t* res) {
  try {
    *res = mlx::core::metal::set_cache_limit(limit);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_metal_set_memory_limit(size_t limit, bool relaxed, size_t* res) {
  try {
    *res = mlx::core::metal::set_memory_limit(limit, relaxed);
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
