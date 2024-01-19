#ifndef MLX_MAP_H
#define MLX_MAP_H

#include "mlx/c/array.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mlx_map_string_to_array_* mlx_map_string_to_array;
typedef struct mlx_map_string_to_array_iterator_*
    mlx_map_string_to_array_iterator;

mlx_map_string_to_array mlx_map_string_to_array_new(void);
bool mlx_map_string_to_array_insert(
    mlx_map_string_to_array map,
    const char* key,
    const mlx_array value);
mlx_array mlx_map_string_to_array_get(
    mlx_map_string_to_array map,
    const char* key);

mlx_map_string_to_array_iterator mlx_map_string_to_array_iterate(
    mlx_map_string_to_array map);
bool mlx_map_string_to_array_iterator_next(mlx_map_string_to_array_iterator it);
bool mlx_map_string_to_array_iterator_end(mlx_map_string_to_array_iterator it);
const char* mlx_map_string_to_array_iterator_key(
    mlx_map_string_to_array_iterator it);
mlx_array mlx_map_string_to_array_iterator_value(
    mlx_map_string_to_array_iterator it);

#ifdef __cplusplus
}
#endif

#endif
