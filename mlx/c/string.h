/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_STRING_H
#define MLX_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_string String
 * MLX string object.
 */
/**@{*/

/**
 * A MLX string object.
 */
typedef struct mlx_string_* mlx_string;

/**
 * Returns a new string, copying contents from `str`, which must end with `\0`.
 */
mlx_string mlx_string_new(const char* str);

/**
 * Returns a pointer to the string contents.
 * The pointer is valid for the life duration of the string.
 */
const char* mlx_string_data(mlx_string str);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
