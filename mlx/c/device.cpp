/* Copyright © 2023-2024 Apple Inc. */

#include <cstring>

#include "mlx/c/device.h"
#include "mlx/c/error.h"
#include "mlx/c/private/mlx.h"

extern "C" int mlx_device_tostring(mlx_string* str_, mlx_device dev) {
  try {
    std::ostringstream os;
    os << mlx_device_get_(dev);
    std::string str = os.str();
    mlx_string_set_(*str_, str);
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" mlx_device mlx_device_new() {
  return mlx_device_new_();
}

extern "C" mlx_device mlx_device_new_type(mlx_device_type type, int index) {
  try {
    auto cpp_type = mlx_device_type_to_cpp(type);
    return mlx_device_new_(mlx::core::Device(cpp_type, index));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_device_new_();
  }
}

extern "C" int mlx_device_set(mlx_device* dev, const mlx_device src) {
  try {
    mlx_device_set_(*dev, mlx_device_get_(src));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_device_get_index(int* index, mlx_device dev) {
  try {
    *index = mlx_device_get_(dev).index;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_device_get_type(mlx_device_type* type, mlx_device dev) {
  try {
    *type = mlx_device_type_to_c(mlx_device_get_(dev).type);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" bool mlx_device_equal(mlx_device lhs, mlx_device rhs) {
  return mlx_device_get_(lhs) == mlx_device_get_(rhs);
}

extern "C" int mlx_get_default_device(mlx_device* dev) {
  try {
    mlx_device_set_(*dev, mlx::core::default_device());
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
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

extern "C" int mlx_device_free(mlx_device dev) {
  try {
    mlx_device_free_(dev);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
