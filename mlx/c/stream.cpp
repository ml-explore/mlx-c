/* Copyright © 2023-2024 Apple Inc. */

#include <cstring>

#include "mlx/c/device.h"
#include "mlx/c/private/device.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/stream.h"

mlx_string mlx_stream_tostring(mlx_stream stream) {
  try {
    std::ostringstream os;
    os << mlx_stream_get_(stream);
    std::string str = os.str();
    return mlx_string_new_(str);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_string_new_();
  }
}

extern "C" mlx_stream mlx_stream_new(int index, mlx_device dev) {
  try {
    return mlx_stream_new_(mlx::core::Stream(index, mlx_device_get_(dev)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_stream_new_();
  }
}
extern "C" mlx_stream mlx_stream_new_on_device(mlx_device dev) {
  try {
    return mlx_stream_new_(mlx::core::new_stream(mlx_device_get_(dev)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_stream_new_();
  }
}
extern "C" int mlx_stream_free(mlx_stream stream) {
  try {
    mlx_stream_free_(stream);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" bool mlx_stream_equal(mlx_stream lhs, mlx_stream rhs) {
  return mlx_stream_get_(lhs) == mlx_stream_get_(rhs);
}
extern "C" mlx_device mlx_stream_get_device(mlx_stream stream) {
  try {
    return mlx_device_new_(mlx_stream_get_(stream).device);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_device_new_();
  }
}
extern "C" int mlx_synchronize(mlx_stream stream) {
  try {
    mlx::core::synchronize(mlx_stream_get_(stream));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" mlx_stream mlx_default_stream(mlx_device dev) {
  try {
    return mlx_stream_new_(default_stream(mlx_device_get_(dev)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_stream_new_();
  }
}
extern "C" int mlx_set_default_stream(mlx_stream stream) {
  try {
    mlx::core::set_default_stream(mlx_stream_get_(stream));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" mlx_stream mlx_cpu_stream() {
  try {
    return mlx_stream_new_(
        mlx::core::default_stream(mlx::core::Device::DeviceType::cpu));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_stream_new_();
  }
}
extern "C" mlx_stream mlx_gpu_stream() {
  try {
    return mlx_stream_new_(
        mlx::core::default_stream(mlx::core::Device::DeviceType::gpu));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_stream_new_();
  }
}
