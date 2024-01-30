/* Copyright © 2023-2024 Apple Inc. */

#include <cstring>

#include "mlx/c/device.h"
#include "mlx/c/private/device.h"
#include "mlx/c/private/string.h"

mlx_string_* mlx_device_::tostring() {
  std::ostringstream os;
  os << ctx;
  std::string str = os.str();
  return new mlx_string_(str);
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
  return new mlx_device_(mlx::core::Device(cpp_type, index));
}

extern "C" mlx_device_type mlx_device_get_type(mlx_device dev) {
  return to_c_device_type(dev->ctx.type);
}
extern "C" bool mlx_device_equal(mlx_device lhs, mlx_device rhs) {
  return lhs->ctx == rhs->ctx;
}
extern "C" mlx_device mlx_default_device(void) {
  return new mlx_device_(mlx::core::default_device());
}
extern "C" mlx_device mlx_set_default_device(mlx_device dev) {
  mlx::core::set_default_device(dev->ctx);
  return dev;
}
