/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/metal.h"
#include "mlx/backend/metal/metal.h"
#include "mlx/c/error.h"
#include "mlx/c/private/mlx.h"

extern "C" int mlx_metal_is_available(bool* res) {
  try {
    *res = mlx::core::metal::is_available();
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
extern "C" int mlx_metal_start_capture(const char* path) {
  try {
    mlx::core::metal::start_capture(std::string(path));
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
extern "C" int mlx_metal_stop_capture(void) {
  try {
    mlx::core::metal::stop_capture();
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
