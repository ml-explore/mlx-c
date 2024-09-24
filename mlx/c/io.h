/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_IO_H
#define MLX_IO_H

#include <stdio.h>

#include "mlx/c/array.h"
#include "mlx/c/closure.h"
#include "mlx/c/distributed_group.h"
#include "mlx/c/map.h"
#include "mlx/c/stream.h"
#include "mlx/c/string.h"
#include "mlx/c/vector.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup io IO operations
 */
/**@{*/
int mlx_load_file(FILE* in_stream, const mlx_stream s, mlx_array res);
int mlx_load(const char* file, const mlx_stream s, mlx_array res);
int mlx_load_safetensors_file(
    FILE* in_stream,
    const mlx_stream s,
    mlx_map_string_to_array res_0,
    mlx_map_string_to_string res_1);
int mlx_load_safetensors(
    const char* file,
    const mlx_stream s,
    mlx_map_string_to_array res_0,
    mlx_map_string_to_string res_1);
int mlx_save_file(FILE* out_stream, const mlx_array a);
int mlx_save(const char* file, const mlx_array a);
int mlx_save_safetensors_file(
    FILE* in_stream,
    const mlx_map_string_to_array param,
    const mlx_map_string_to_string metadata);
int mlx_save_safetensors(
    const char* file,
    const mlx_map_string_to_array param,
    const mlx_map_string_to_string metadata);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
