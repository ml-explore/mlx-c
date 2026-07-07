/* Copyright © 2023-2024 Apple Inc. */

#include "mlx/c/string.h"
#include "mlx/c/error.h"
#include "mlx/c/private/mlx.h"

extern "C" mlx_string mlx_string_new(void) {
  return mlx_string_new_();
}

extern "C" mlx_string mlx_string_new_data(const char* str) {
  try {
    return mlx_string_new_(str);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_string_new_();
  }
}

extern "C" int mlx_string_set(mlx_string* str, const mlx_string src) {
  try {
    mlx_string_set_(*str, mlx_string_get_(src));
  } catch (const std::invalid_argument& e) {
    mlx_error_with_code(MLX_ERROR_INVALID_ARGUMENT, "%s", e.what());
    return 1;
  } catch (const std::out_of_range& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_RANGE, "%s", e.what());
    return 1;
  } catch (const std::bad_alloc& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_MEMORY, "%s", e.what());
    return 1;
  } catch (const std::exception& e) {
    mlx_error_with_code(MLX_ERROR_RUNTIME, "%s", e.what());
    return 1;
  } catch (...) {
    mlx_error_with_code(MLX_ERROR_UNKNOWN, "unknown (non-std) exception");
    return 1;
  }
  return 0;
}

extern "C" const char* mlx_string_data(mlx_string str) {
  try {
    return mlx_string_get_(str).c_str();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return nullptr;
  }
}

extern "C" int mlx_string_free(mlx_string str) {
  try {
    mlx_string_free_(str);
  } catch (const std::invalid_argument& e) {
    mlx_error_with_code(MLX_ERROR_INVALID_ARGUMENT, "%s", e.what());
    return 1;
  } catch (const std::out_of_range& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_RANGE, "%s", e.what());
    return 1;
  } catch (const std::bad_alloc& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_MEMORY, "%s", e.what());
    return 1;
  } catch (const std::exception& e) {
    mlx_error_with_code(MLX_ERROR_RUNTIME, "%s", e.what());
    return 1;
  } catch (...) {
    mlx_error_with_code(MLX_ERROR_UNKNOWN, "unknown (non-std) exception");
    return 1;
  }
  return 0;
}
