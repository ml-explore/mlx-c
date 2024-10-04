/* Copyright © 2023-2024 Apple Inc. */

#include <cstring>

#include "mlx/c/device.h"
#include "mlx/c/private/device.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/stream.h"

mlx_string mlx_stream_tostring(mlx_stream stream) {
  std::ostringstream os;
  os << mlx_stream_get_(stream);
  std::string str = os.str();
  return mlx_string_new_(str);
}

extern "C" mlx_stream mlx_stream_new(int index, mlx_device dev) {
  return mlx_stream_new_(mlx::core::Stream(index, mlx_device_get_(dev)));
}
extern "C" mlx_stream mlx_stream_new_on_device(mlx_device dev) {
  return mlx_stream_new_(mlx::core::new_stream(mlx_device_get_(dev)));
}
extern "C" void mlx_stream_free(mlx_stream stream) {
  mlx_stream_free_(stream);
}
extern "C" bool mlx_stream_equal(mlx_stream lhs, mlx_stream rhs) {
  return mlx_stream_get_(lhs) == mlx_stream_get_(rhs);
}
extern "C" mlx_device mlx_stream_get_device(mlx_stream stream) {
  return mlx_device_new_(mlx_stream_get_(stream).device);
}
extern "C" void mlx_synchronize(mlx_stream stream) {
  MLX_TRY_CATCH(mlx::core::synchronize(mlx_stream_get_(stream)), );
}
extern "C" mlx_stream mlx_default_stream(mlx_device dev) {
  return mlx_stream_new_(default_stream(mlx_device_get_(dev)));
}
extern "C" void mlx_set_default_stream(mlx_stream stream) {
  mlx::core::set_default_stream(mlx_stream_get_(stream));
}
extern "C" mlx_stream mlx_cpu_stream() {
  return mlx_stream_new_(
      mlx::core::default_stream(mlx::core::Device::DeviceType::cpu));
}
extern "C" mlx_stream mlx_gpu_stream() {
  return mlx_stream_new_(
      mlx::core::default_stream(mlx::core::Device::DeviceType::gpu));
}
