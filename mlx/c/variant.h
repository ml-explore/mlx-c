/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_VARIANT_H
#define MLX_VARIANT_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_variant Variant type definitions
 * MLX variant objects.
 */
/**@{*/

/**
 * A MLX string size_t variant.
 */
typedef struct mlx_string_size_t_variant_* mlx_string_size_t_variant;

/**
 * Returns a variant from a string.
 */
mlx_string_size_t_variant mlx_string_size_t_variant_new_with_string(
    mlx_string str);

/**
 * Returns a variant from a size_t.
 */
mlx_string_size_t_variant mlx_string_size_t_variant_new_with_size_t(size_t val);

/**
 * Returns string value from variant.
 */
mlx_string mlx_string_size_t_variant_get_string(mlx_string_size_t_variant var);

/**
 * Returns size_t value from variant.
 */
size_t mlx_string_size_t_variant_get_size_t(mlx_string_size_t_variant var);

/**
 * Returns whether variant holds a string value or not.
 */
bool mlx_string_size_t_variant_holds_string(mlx_string_size_t_variant var);

/**
 * Returns whether variant holds a size_t value or not.
 */
bool mlx_string_size_t_variant_holds_size_t(mlx_string_size_t_variant var);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
