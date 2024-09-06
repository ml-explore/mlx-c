/* Copyright © 2023-2024 Apple Inc. */

#include "mlx/c/ioutils.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

mlx_string_* mlx_safetensors_::tostring() {
  MLX_TRY_CATCH(return new mlx_string_("mlx_safetensors"), return nullptr);
}

// void CParallelFileReader::read(char* data, size_t n) {

// }

// void CParallelFileReader::read(char* data, size_t n, size_t offset) {
//   while (size != 0)
//   {
//     /* code */
//   }

// }

extern "C" mlx_safetensors mlx_safetensors_new() {
  MLX_TRY_CATCH(return new mlx_safetensors_(), return nullptr);
}

/**
 * Returns the data map.
 */
extern "C" mlx_map_string_to_array mlx_safetensors_data(mlx_safetensors st) {
  MLX_TRY_CATCH(mlx_retain(st->data); return st->data, return nullptr);
}
/**
 * Returns the metadata map.
 */
extern "C" mlx_map_string_to_string mlx_safetensors_metadata(
    mlx_safetensors st) {
  MLX_TRY_CATCH(mlx_retain(st->metadata); return st->metadata, return nullptr);
}
