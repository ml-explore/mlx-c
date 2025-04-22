/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_EXPORT_H
#define MLX_EXPORT_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "mlx/c/array.h"
#include "mlx/c/closure.h"
#include "mlx/c/distributed_group.h"
#include "mlx/c/export_impl.h"
#include "mlx/c/io_types.h"
#include "mlx/c/map.h"
#include "mlx/c/stream.h"
#include "mlx/c/string.h"
#include "mlx/c/vector.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup export Function serialization
 */
/**@{*/
int mlx_export_function(
    const char* file,
    const mlx_closure fun,
    const mlx_vector_array args,
    bool shapeless);
int mlx_export_function_kwargs(
    const char* file,
    const mlx_closure_kwargs fun,
    const mlx_map_string_to_array kwargs,
    bool shapeless);
int mlx_exporter(
    mlx_function_exporter* res,
    const char* file,
    const mlx_closure fun,
    bool shapeless);
int mlx_import_function(mlx_imported_function* res, const char* file);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
