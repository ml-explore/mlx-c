/* Copyright © 2023-2024 Apple Inc. */

#include "mlx/c/metal.h"
#include "mlx/backend/metal/metal.h"

extern "C" bool mlx_metal_is_available() {
  return mlx::core::metal::is_available();
}

extern "C" bool mlx_metal_cache_enabled(void) {
  return mlx::core::metal::cache_enabled();
}

extern "C" void mlx_metal_set_cache_enabled(bool enabled) {
  mlx::core::metal::set_cache_enabled(enabled);
}
