/* Copyright © 2023-2024 Apple Inc. */

#include "mlx/c/ioutils.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/string.h"

mlx_string_* mlx_safetensors_::tostring() {
  return new mlx_string_("mlx_safetensors");
}

extern "C" mlx_safetensors mlx_safetensors_new() {
  return new mlx_safetensors_();
}

/**
 * Returns the data map.
 */
extern "C" mlx_map_string_to_array mlx_safetensors_data(mlx_safetensors st) {
  mlx_retain(st->data);
  return st->data;
}
/**
 * Returns the metadata map.
 */
extern "C" mlx_map_string_to_string mlx_safetensors_metadata(
    mlx_safetensors st) {
  mlx_retain(st->metadata);
  return st->metadata;
}
