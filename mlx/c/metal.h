/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_METAL_H
#define MLX_METAL_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_metal Metal
 * MLX Metal low-level functions.
 */
/**@{*/
/**
 * Query if Metal is available.
 */
bool mlx_metal_is_available();
/**
 * Query if Metal cache is enabled.
 */
bool mlx_metal_cache_enabled(void);
/**
 * Set Metal cache status.
 */
void mlx_metal_set_cache_enabled(bool enabled);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
