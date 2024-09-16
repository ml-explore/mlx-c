/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/metal.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/tuple.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" void mlx_metal_clear_cache() {
  return (mlx::core::metal::clear_cache());
}
extern "C" mlx_map_string_to_variant_string_size_t mlx_metal_device_info() {
  RETURN_MLX_C_PTR(new mlx_map_string_to_variant_string_size_t_(
      (mlx::core::metal::device_info())));
}
extern "C" size_t mlx_metal_get_active_memory() {
  return (mlx::core::metal::get_active_memory());
}
extern "C" size_t mlx_metal_get_cache_memory() {
  return (mlx::core::metal::get_cache_memory());
}
extern "C" size_t mlx_metal_get_peak_memory() {
  return (mlx::core::metal::get_peak_memory());
}
extern "C" bool mlx_metal_is_available() {
  return (mlx::core::metal::is_available());
}
extern "C" void mlx_metal_reset_peak_memory() {
  return (mlx::core::metal::reset_peak_memory());
}
extern "C" size_t mlx_metal_set_cache_limit(size_t limit) {
  return (mlx::core::metal::set_cache_limit(limit));
}
extern "C" size_t mlx_metal_set_memory_limit(size_t limit, bool relaxed) {
  return (mlx::core::metal::set_memory_limit(limit, relaxed));
}
extern "C" void mlx_metal_start_capture(mlx_string path) {
  return (mlx::core::metal::start_capture(MLX_CPP_STRING(path)));
}
extern "C" void mlx_metal_stop_capture() {
  return (mlx::core::metal::stop_capture());
}
