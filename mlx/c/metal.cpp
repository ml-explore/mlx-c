/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/metal.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

extern "C" size_t mlx_metal_get_active_memory() {
  return size_t(mlx::core::metal::get_active_memory());
}
extern "C" size_t mlx_metal_get_cache_memory() {
  return size_t(mlx::core::metal::get_cache_memory());
}
extern "C" size_t mlx_metal_get_peak_memory() {
  return size_t(mlx::core::metal::get_peak_memory());
}
extern "C" bool mlx_metal_is_available() {
  return bool(mlx::core::metal::is_available());
}
extern "C" size_t mlx_metal_set_cache_limit(size_t limit) {
  return size_t(mlx::core::metal::set_cache_limit(limit));
}
extern "C" size_t mlx_metal_set_memory_limit(size_t limit, bool relaxed) {
  return size_t(mlx::core::metal::set_memory_limit(limit, relaxed));
}
