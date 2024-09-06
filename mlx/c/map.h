/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_MAP_H
#define MLX_MAP_H

#include "mlx/c/array.h"
#include "mlx/c/string.h"
#include "mlx/c/variant.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_map_string_to_array string-to-array map
 * MLX string-to-array map object.
 */
/**@{*/

/**
 * A string-to-array map
 */
typedef struct mlx_map_string_to_array_* mlx_map_string_to_array;

/**
 * Returns a new empty string-to-array map.
 */
mlx_map_string_to_array mlx_map_string_to_array_new(void);
/**
 * Insert a new `value` at the specified `key` in the map.
 * Returns `true` if the value was actually inserted.
 */
bool mlx_map_string_to_array_insert(
    mlx_map_string_to_array map,
    const mlx_string key,
    const mlx_array value);
/**
 * Returns the value indexed at the specified `key` in the map.
 * Returns `NULL` if no value was found for `key`.
 */
mlx_array mlx_map_string_to_array_get(
    mlx_map_string_to_array map,
    const mlx_string key);

/**
 * An iterator over a string-to-array map.
 */
typedef struct mlx_map_string_to_array_iterator_*
    mlx_map_string_to_array_iterator;
/**
 * Returns a new iterator over the given map.
 */
mlx_map_string_to_array_iterator mlx_map_string_to_array_iterate(
    mlx_map_string_to_array map);
/**
 * Increment iterator.
 * Returns `true` if iterator could actually be incremented.
 */
bool mlx_map_string_to_array_iterator_next(mlx_map_string_to_array_iterator it);
/**
 * Returns `true` iif iterator is at the end of the map.
 */
bool mlx_map_string_to_array_iterator_end(mlx_map_string_to_array_iterator it);
/**
 * Returns the key associated to the current iterator position in the map.
 */
mlx_string mlx_map_string_to_array_iterator_key(
    mlx_map_string_to_array_iterator it);
/**
 * Returns the value associated to the current iterator position in the map.
 */
mlx_array mlx_map_string_to_array_iterator_value(
    mlx_map_string_to_array_iterator it);

/**@}*/

/**
 * \defgroup mlx_map_string_to_string string-to-string map
 * MLX string-to-string map object.
 */
/**@{*/

/**
 * A string-to-string map
 */
typedef struct mlx_map_string_to_string_* mlx_map_string_to_string;

/**
 * Returns a new empty string-to-string map.
 */
mlx_map_string_to_string mlx_map_string_to_string_new(void);
/**
 * Insert a new `value` at the specified `key` in the map.
 * Returns `true` if the value was actually inserted.
 */
bool mlx_map_string_to_string_insert(
    mlx_map_string_to_string map,
    const mlx_string key,
    const mlx_string value);
/**
 * Returns the value indexed at the specified `key` in the map.
 * Returns `NULL` if no value was found for `key`.
 */
mlx_string mlx_map_string_to_string_get(
    mlx_map_string_to_string map,
    const mlx_string key);

/**
 * An iterator over a string-to-string map.
 */
typedef struct mlx_map_string_to_string_iterator_*
    mlx_map_string_to_string_iterator;
/**
 * Returns a new iterator over the given map.
 */
mlx_map_string_to_string_iterator mlx_map_string_to_string_iterate(
    mlx_map_string_to_string map);
/**
 * Increment iterator.
 * Returns `true` if iterator could actually be incremented.
 */
bool mlx_map_string_to_string_iterator_next(
    mlx_map_string_to_string_iterator it);
/**
 * Returns `true` iif iterator is at the end of the map.
 */
bool mlx_map_string_to_string_iterator_end(
    mlx_map_string_to_string_iterator it);
/**
 * Returns the key associated to the current iterator position in the map.
 */
mlx_string mlx_map_string_to_string_iterator_key(
    mlx_map_string_to_string_iterator it);
/**
 * Returns the value associated to the current iterator position in the map.
 */
mlx_string mlx_map_string_to_string_iterator_value(
    mlx_map_string_to_string_iterator it);

/**@}*/

/**
 * \defgroup mlx_map_string_to_string_size_t_variant
 * string-to-string_size_t_variant map MLX string-to-string_size_t_variant map
 * object.
 */
/**@{*/

/**
 * A string-to-string_size_t_variant map
 */
typedef struct mlx_map_string_to_string_size_t_variant_*
    mlx_map_string_to_string_size_t_variant;

/**
 * Returns a new empty string-to-string_size_t_variant map.
 */
mlx_map_string_to_string_size_t_variant
mlx_map_string_to_string_size_t_variant_new(void);
/**
 * Insert a new `value` at the specified `key` in the map.
 * Returns `true` if the value was actually inserted.
 */
bool mlx_map_string_to_string_size_t_variant_insert(
    mlx_map_string_to_string_size_t_variant map,
    const mlx_string key,
    const mlx_string_size_t_variant value);
/**
 * Returns the value indexed at the specified `key` in the map.
 * Returns `NULL` if no value was found for `key`.
 */
mlx_string_size_t_variant mlx_map_string_to_string_size_t_variant_get(
    mlx_map_string_to_string_size_t_variant map,
    const mlx_string key);

/**
 * An iterator over a string-to-string_size_t_variant map.
 */
typedef struct mlx_map_string_to_string_size_t_variant_iterator_*
    mlx_map_string_to_string_size_t_variant_iterator;
/**
 * Returns a new iterator over the given map.
 */
mlx_map_string_to_string_size_t_variant_iterator
mlx_map_string_to_string_size_t_variant_iterate(
    mlx_map_string_to_string_size_t_variant map);
/**
 * Increment iterator.
 * Returns `true` if iterator could actually be incremented.
 */
bool mlx_map_string_to_string_size_t_variant_iterator_next(
    mlx_map_string_to_string_size_t_variant_iterator it);
/**
 * Returns `true` iif iterator is at the end of the map.
 */
bool mlx_map_string_to_string_size_t_variant_iterator_end(
    mlx_map_string_to_string_size_t_variant_iterator it);
/**
 * Returns the key associated to the current iterator position in the map.
 */
mlx_string mlx_map_string_to_string_size_t_variant_iterator_key(
    mlx_map_string_to_string_size_t_variant_iterator it);
/**
 * Returns the value associated to the current iterator position in the map.
 */
mlx_string_size_t_variant
mlx_map_string_to_string_size_t_variant_iterator_value(
    mlx_map_string_to_string_size_t_variant_iterator it);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
