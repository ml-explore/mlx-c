/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_COMPILE_H
#define MLX_COMPILE_H

#include <stdio.h>

#include "mlx/c/array.h"
#include "mlx/c/closure.h"
#include "mlx/c/distributed_group.h"
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
typedef enum mlx_compile_mode_ {
  MLX_COMPILE_MODE_DISABLED,
  MLX_COMPILE_MODE_NO_SIMPLIFY,
  MLX_COMPILE_MODE_NO_FUSE,
  MLX_COMPILE_MODE_ENABLED
} mlx_compile_mode;
mlx_closure mlx_compile(mlx_closure fun, bool shapeless);
void mlx_disable_compile();
void mlx_enable_compile();
void mlx_set_compile_mode(mlx_compile_mode mode);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
