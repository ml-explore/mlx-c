/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_VARIANT_H
#define MLX_VARIANT_H

#include "mlx/c/array.h"
#include "mlx/c/string.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_variant Variants
 * MLX variant objects.
 */
/**@{*/

/**
 * A variant of (mlx_string, size_t).
 */
typedef struct mlx_variant_string_size_t_* mlx_variant_string_size_t;

mlx_variant_string_size_t mlx_variant_string_size_t_new_with_string(
    mlx_string val);
mlx_variant_string_size_t mlx_variant_string_size_t_new_with_size_t(size_t val);
mlx_string mlx_variant_string_size_t_get_string(mlx_variant_string_size_t var);
size_t mlx_variant_string_size_t_get_size_t(mlx_variant_string_size_t var);
bool mlx_variant_string_size_t_holds_string(mlx_variant_string_size_t var);
bool mlx_variant_string_size_t_holds_size_t(mlx_variant_string_size_t var);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
