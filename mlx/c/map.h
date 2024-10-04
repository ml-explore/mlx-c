/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_MAP_H
#define MLX_MAP_H

#include "mlx/c/array.h"
#include "mlx/c/string.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_map Maps
 * MLX map objects.
 */
/**@{*/

/**
 * A string-to-array map
 */
typedef struct mlx_map_string_to_array_ {
  void* ctx;
} mlx_map_string_to_array;

/**
 * Returns a new empty string-to-array map.
 */
mlx_map_string_to_array mlx_map_string_to_array_new(void);
/**
 * Free a string-to-array map.
 */
void mlx_map_string_to_array_free(mlx_map_string_to_array map);
/**
 * Insert a new `value` at the specified `key` in the map.
 * Returns `true` if the value was actually inserted.
 */
bool mlx_map_string_to_array_insert(
    mlx_map_string_to_array map,
    const char* key,
    const mlx_array value);
/**
 * Returns the value indexed at the specified `key` in the map.
 * Returns `NULL` if no value was found for `key`.
 */
bool mlx_map_string_to_array_get(
    mlx_map_string_to_array map,
    const char* key,
    mlx_array* value);

/**
 * An iterator over a string-to-array map.
 */
typedef struct mlx_map_string_to_array_iterator_ {
  void* ctx;
  void* map_ctx;
} mlx_map_string_to_array_iterator;
/**
 * Returns a new iterator over the given map.
 */
mlx_map_string_to_array_iterator mlx_map_string_to_array_iterator_new(
    mlx_map_string_to_array map);
/**
 * Free iterator.
 */
void mlx_map_string_to_array_iterator_free(mlx_map_string_to_array_iterator it);
/**
 * Increment iterator.
 * Returns `true` if iterator could actually be incremented.
 */
bool mlx_map_string_to_array_iterator_next(
    mlx_map_string_to_array_iterator it,
    const char** key,
    mlx_array* value);

/**
 * A string-to-string map
 */
typedef struct mlx_map_string_to_string_ {
  void* ctx;
} mlx_map_string_to_string;

/**
 * Returns a new empty string-to-string map.
 */
mlx_map_string_to_string mlx_map_string_to_string_new(void);
/**
 * Free a string-to-string map.
 */
void mlx_map_string_to_string_free(mlx_map_string_to_string map);
/**
 * Insert a new `value` at the specified `key` in the map.
 * Returns `true` if the value was actually inserted.
 */
bool mlx_map_string_to_string_insert(
    mlx_map_string_to_string map,
    const char* key,
    const char* value);
/**
 * Returns the value indexed at the specified `key` in the map.
 * Returns `NULL` if no value was found for `key`.
 */
bool mlx_map_string_to_string_get(
    mlx_map_string_to_string map,
    const char* key,
    const char** value);

/**
 * An iterator over a string-to-string map.
 */
typedef struct mlx_map_string_to_string_iterator_ {
  void* ctx;
  void* map_ctx;
} mlx_map_string_to_string_iterator;
/**
 * Returns a new iterator over the given map.
 */
mlx_map_string_to_string_iterator mlx_map_string_to_string_iterator_new(
    mlx_map_string_to_string map);
/**
 * Free iterator.
 */
void mlx_map_string_to_string_iterator_free(
    mlx_map_string_to_string_iterator it);
/**
 * Increment iterator.
 * Returns `true` if iterator could actually be incremented.
 */
bool mlx_map_string_to_string_iterator_next(
    mlx_map_string_to_string_iterator it,
    const char** key,
    const char** value);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
