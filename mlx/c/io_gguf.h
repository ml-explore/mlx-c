/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_IO_GGUF_H
#define MLX_IO_GGUF_H

#include "mlx/c/array.h"
#include "mlx/c/map.h"
#include "mlx/c/stream.h"
#include "mlx/c/string.h"
#include "mlx/c/vector.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_io_gguf GGUF I/O
 * GGUF file format loading and saving.
 */
/**@{*/

/**
 * GGUF metadata type tag
 */
typedef enum {
  MLX_GGUF_METADATA_NONE = 0,
  MLX_GGUF_METADATA_ARRAY = 1,
  MLX_GGUF_METADATA_STRING = 2,
  MLX_GGUF_METADATA_STRING_VECTOR = 3
} mlx_gguf_metadata_type;

/**
 * GGUF metadata value (opaque handle to variant type)
 */
typedef struct mlx_gguf_metadata_ {
  void* ctx;
} mlx_gguf_metadata;

/**
 * Map from string to GGUF metadata
 */
typedef struct mlx_map_string_to_gguf_metadata_ {
  void* ctx;
} mlx_map_string_to_gguf_metadata;

/**
 * Create new GGUF metadata from string
 */
mlx_gguf_metadata mlx_gguf_metadata_new_string(const char* value);

/**
 * Create new GGUF metadata from array
 */
mlx_gguf_metadata mlx_gguf_metadata_new_array(const mlx_array value);

/**
 * Create new GGUF metadata from string vector
 */
mlx_gguf_metadata mlx_gguf_metadata_new_string_vector(
    const mlx_vector_string value);

/**
 * Get metadata type
 */
mlx_gguf_metadata_type mlx_gguf_metadata_get_type(
    const mlx_gguf_metadata metadata);

/**
 * Get string value (only valid if type is STRING)
 * Returns 0 on success, 1 if wrong type
 */
int mlx_gguf_metadata_get_string(
    mlx_string* res,
    const mlx_gguf_metadata metadata);

/**
 * Get array value (only valid if type is ARRAY)
 * Returns 0 on success, 1 if wrong type
 */
int mlx_gguf_metadata_get_array(
    mlx_array* res,
    const mlx_gguf_metadata metadata);

/**
 * Get string vector value (only valid if type is STRING_VECTOR)
 * Returns 0 on success, 1 if wrong type
 */
int mlx_gguf_metadata_get_string_vector(
    mlx_vector_string* res,
    const mlx_gguf_metadata metadata);

/**
 * Free GGUF metadata
 */
int mlx_gguf_metadata_free(mlx_gguf_metadata metadata);

/**
 * Create new metadata map
 */
mlx_map_string_to_gguf_metadata mlx_map_string_to_gguf_metadata_new(void);

/**
 * Set map to provided src map
 */
int mlx_map_string_to_gguf_metadata_set(
    mlx_map_string_to_gguf_metadata* map,
    const mlx_map_string_to_gguf_metadata src);

/**
 * Insert into metadata map
 */
int mlx_map_string_to_gguf_metadata_insert(
    mlx_map_string_to_gguf_metadata map,
    const char* key,
    const mlx_gguf_metadata value);

/**
 * Get from metadata map
 * Returns 0 on success, 2 if key not found
 */
int mlx_map_string_to_gguf_metadata_get(
    mlx_gguf_metadata* res,
    const mlx_map_string_to_gguf_metadata map,
    const char* key);

/**
 * Free metadata map
 */
int mlx_map_string_to_gguf_metadata_free(mlx_map_string_to_gguf_metadata map);

/**
 * An iterator over a string-to-gguf-metadata map.
 */
typedef struct mlx_map_string_to_gguf_metadata_iterator_ {
  void* ctx;
  void* map_ctx;
} mlx_map_string_to_gguf_metadata_iterator;

/**
 * Returns a new iterator over the given map.
 */
mlx_map_string_to_gguf_metadata_iterator
mlx_map_string_to_gguf_metadata_iterator_new(
    mlx_map_string_to_gguf_metadata map);

/**
 * Free iterator.
 */
int mlx_map_string_to_gguf_metadata_iterator_free(
    mlx_map_string_to_gguf_metadata_iterator it);

/**
 * Increment iterator.
 * Returns 0 if there are more elements, 1 if at end.
 */
int mlx_map_string_to_gguf_metadata_iterator_next(
    const char** key,
    mlx_gguf_metadata* value,
    mlx_map_string_to_gguf_metadata_iterator it);

/**
 * Load GGUF file
 *
 * @param res_arrays Output map of array name -> array
 * @param res_metadata Output map of metadata name -> metadata value
 * @param file Path to GGUF file
 * @param s Stream or device
 * @return 0 on success, non-zero on error
 */
int mlx_load_gguf(
    mlx_map_string_to_array* res_arrays,
    mlx_map_string_to_gguf_metadata* res_metadata,
    const char* file,
    const mlx_stream s);

/**
 * Save GGUF file
 *
 * @param file Path to output GGUF file
 * @param arrays Map of array name -> array to save
 * @param metadata Map of metadata name -> metadata value
 * @return 0 on success, non-zero on error
 */
int mlx_save_gguf(
    const char* file,
    const mlx_map_string_to_array arrays,
    const mlx_map_string_to_gguf_metadata metadata);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif // MLX_IO_GGUF_H
