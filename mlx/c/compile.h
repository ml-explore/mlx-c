/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_COMPILE_H
#define MLX_COMPILE_H

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
 * \defgroup compile Compilation operations
 */
/**@{*/
mlx_closure mlx_compile(mlx_closure fun, bool shapeless);
void mlx_disable_compile();
void mlx_enable_compile();
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
