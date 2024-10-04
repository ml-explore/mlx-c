/* Copyright © 2023-2024 Apple Inc. */

#include <cstring>

#include "mlx/c/device.h"
#include "mlx/c/private/device.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

extern "C" mlx_string mlx_device_tostring(mlx_device dev) {
  std::ostringstream os;
  os << mlx_device_get_(dev);
  std::string str = os.str();
  return mlx_string_new_(str);
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
  auto cpp_type = to_cpp_device_type(type);
  return mlx_device_new_(mlx::core::Device(cpp_type, index));
}

extern "C" mlx_device_type mlx_device_get_type(mlx_device dev) {
  return to_c_device_type(mlx_device_get_(dev).type);
}
extern "C" bool mlx_device_equal(mlx_device lhs, mlx_device rhs) {
  return mlx_device_get_(lhs) == mlx_device_get_(rhs);
}
extern "C" mlx_device mlx_default_device(void) {
  return mlx_device_new_(mlx::core::default_device());
}
extern "C" void mlx_set_default_device(mlx_device dev) {
  mlx::core::set_default_device(mlx_device_get_(dev));
}
