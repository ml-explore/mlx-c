/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_IOHELPERS_H
#define MLX_IOHELPERS_H

#include "mlx/c/map.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_ioutils IO objects
 * MLX IO objects.
 */
/**@{*/

/**
 * A MLX SafeTensors storage.
 * Holds a string-to-array map (data) and string-to-string map (metadata).
 */
typedef struct mlx_safetensors_* mlx_safetensors;

/**
 * Returns a empty safetensors storage.
 */
mlx_safetensors mlx_safetensors_new();
/**
 * Returns the data map.
 */
mlx_map_string_to_array mlx_safetensors_data(mlx_safetensors st);
/**
 * Returns the metadata map.
 */
mlx_map_string_to_string mlx_safetensors_metadata(mlx_safetensors st);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
