/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_METAL_H
#define MLX_METAL_H

#include <stdio.h>

#include "mlx/c/array.h"
#include "mlx/c/closure.h"
#include "mlx/c/ioutils.h"
#include "mlx/c/map.h"
#include "mlx/c/stream.h"
#include "mlx/c/string.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup metal Metal specific operations
 */
/**@{*/
size_t mlx_metal_get_active_memory();
size_t mlx_metal_get_cache_memory();
size_t mlx_metal_get_peak_memory();
bool mlx_metal_is_available();
size_t mlx_metal_set_cache_limit(size_t limit);
size_t mlx_metal_set_memory_limit(size_t limit, bool relaxed);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
