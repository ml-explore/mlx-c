/* Copyright © 2023-2024 Apple Inc. */

#include <cstring>

#include "mlx/c/device.h"
#include "mlx/c/private/device.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

extern "C" mlx_string mlx_device_tostring(mlx_device dev) {
  try {
    std::ostringstream os;
    os << mlx_device_get_(dev);
    std::string str = os.str();
    return mlx_string_new_(str);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_string_new_();
  }
}

namespace {
mlx_device_type to_c_device_type(mlx::core::Device::DeviceType type) {
  static mlx_device_type map[] = {MLX_CPU, MLX_GPU};
  return map[(int)type];
}
mlx::core::Device::DeviceType to_cpp_device_type(mlx_device_type type) {
  static mlx::core::Device::DeviceType map[] = {
      mlx::core::Device::DeviceType::cpu, mlx::core::Device::DeviceType::gpu};
  return map[(int)type];
}
} // namespace

extern "C" mlx_device mlx_device_new(mlx_device_type type, int index) {
  try {
    auto cpp_type = to_cpp_device_type(type);
    return mlx_device_new_(mlx::core::Device(cpp_type, index));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_device_new_();
  }
}

extern "C" mlx_device_type mlx_device_get_type(mlx_device dev) {
  try {
    return to_c_device_type(mlx_device_get_(dev).type);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return MLX_CPU; // DEBUG: could have a specific value
  }
}
extern "C" bool mlx_device_equal(mlx_device lhs, mlx_device rhs) {
  return mlx_device_get_(lhs) == mlx_device_get_(rhs);
}
extern "C" mlx_device mlx_default_device(void) {
  try {
    return mlx_device_new_(mlx::core::default_device());
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_device_new_();
  }
}
extern "C" int mlx_set_default_device(mlx_device dev) {
  try {
    mlx::core::set_default_device(mlx_device_get_(dev));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
