/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_OBJECT_H
#define MLX_OBJECT_H

#include "mlx/c/string.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_object Object
 * MLX object general methods.
 */
/**@{*/

/**
 * Returns a new string representing the object.
 */
mlx_string mlx_tostring(void* obj);
/**
 * Increases the reference count of the object.
 */
void mlx_retain(void* obj);
/**
 * Decreases the reference count of the object, and free if it gets to zero.
 */
void mlx_free(void* obj);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
