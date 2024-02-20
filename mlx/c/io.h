/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_IO_H
#define MLX_IO_H

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
 * \defgroup io IO operations
 */
/**@{*/
mlx_array mlx_load_file(FILE* in_stream, mlx_stream s);
mlx_array mlx_load(mlx_string file, mlx_stream s);
mlx_safetensors mlx_load_safetensors_file(FILE* in_stream, mlx_stream s);
mlx_safetensors mlx_load_safetensors(mlx_string file, mlx_stream s);
void mlx_save_file(FILE* out_stream, mlx_array a);
void mlx_save(mlx_string file, mlx_array a);
void mlx_save_safetensors_file(
    FILE* in_stream,
    mlx_map_string_to_array param,
    mlx_map_string_to_string metadata);
void mlx_save_safetensors(
    mlx_string file,
    mlx_map_string_to_array param,
    mlx_map_string_to_string metadata);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
