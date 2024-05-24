/* Copyright © 2023-2024 Apple Inc. */

#include <cstring>

#include "mlx/c/device.h"
#include "mlx/c/private/device.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/stream.h"

mlx_string_* mlx_stream_::tostring() {
  std::ostringstream os;
  os << ctx;
  std::string str = os.str();
  return new mlx_string_(str);
}

extern "C" mlx_stream mlx_stream_new(int index, mlx_device dev) {
  return new mlx_stream_(mlx::core::Stream(index, dev->ctx));
}
extern "C" mlx_stream mlx_stream_new_on_device(mlx_device dev) {
  return new mlx_stream_(new_stream(dev->ctx));
}
extern "C" bool mlx_stream_equal(mlx_stream lhs, mlx_stream rhs) {
  return lhs->ctx == rhs->ctx;
}
extern "C" mlx_device mlx_stream_get_device(mlx_stream stream) {
  return new mlx_device_(stream->ctx.device);
}
extern "C" void mlx_synchronize(mlx_stream stream) {
  mlx::core::synchronize(stream->ctx);
}
extern "C" mlx_stream mlx_default_stream(mlx_device dev) {
  return new mlx_stream_(default_stream(dev->ctx));
}
extern "C" mlx_stream mlx_set_default_stream(mlx_stream stream) {
  set_default_stream(stream->ctx);
  return stream;
}
extern "C" mlx_stream mlx_cpu_stream() {
  return new mlx_stream_(default_stream(mlx::core::Device::DeviceType::cpu));
}
extern "C" mlx_stream mlx_gpu_stream() {
  return new mlx_stream_(default_stream(mlx::core::Device::DeviceType::gpu));
}
