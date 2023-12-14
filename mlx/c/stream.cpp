#include <cstring>

#include "mlx/c/device.h"
#include "mlx/c/private/device.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/stream.h"

char* mlx_stream_::tostring() {
  std::ostringstream os;
  os << ctx;
  std::string str = os.str();
  char* c_str = (char*)malloc(str.size() + 1);
  memcpy(c_str, str.data(), str.size());
  c_str[str.size()] = '\0';
  return c_str;
}

mlx_stream MLX_CPU_STREAM =
    new mlx_stream_(default_stream(mlx::core::Device::DeviceType::cpu));
mlx_stream MLX_GPU_STREAM =
    new mlx_stream_(default_stream(mlx::core::Device::DeviceType::gpu));

extern "C" mlx_stream mlx_stream_new(int index, mlx_device dev) {
  return new mlx_stream_(mlx::core::Stream(index, dev->ctx));
}
extern "C" mlx_stream mlx_stream_new_on_device(mlx_device dev) {
  return new mlx_stream_(new_stream(dev->ctx));
}
extern "C" bool mlx_stream_equal(mlx_stream lhs, mlx_stream rhs) {
  return lhs->ctx == rhs->ctx;
}
extern "C" mlx_stream mlx_default_stream(mlx_device dev) {
  return new mlx_stream_(default_stream(dev->ctx));
}
extern "C" mlx_stream mlx_set_default_stream(mlx_stream stream) {
  set_default_stream(stream->ctx);
  return stream;
}
