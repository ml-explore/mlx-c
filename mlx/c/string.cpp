/* Copyright © 2023-2024 Apple Inc. */

#include "mlx/c/string.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

extern "C" mlx_string mlx_string_new(const char* str) {
  return mlx_string_new_(str);
}

extern "C" const char* mlx_string_data(mlx_string str) {
  return mlx_string_get_(str).c_str();
}

extern "C" void mlx_string_free(mlx_string str) {
  mlx_string_free_(str);
}
