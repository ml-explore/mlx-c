/* Copyright © 2023-2024 Apple Inc. */

#include "mlx/c/string.h"
#include "mlx/c/object.h"
#include "mlx/c/private/string.h"

mlx_string mlx_string_::tostring() {
  mlx_retain(this);
  return this;
}

extern "C" mlx_string mlx_string_new(const char* str) {
  std::string str_cpp(str);
  return new mlx_string_(str_cpp);
}

extern "C" const char* mlx_string_data(mlx_string str) {
  return str->ctx.c_str();
}
