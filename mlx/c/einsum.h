/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_EINSUM_H
#define MLX_EINSUM_H

#include <stdio.h>

#include "mlx/c/array.h"
#include "mlx/c/closure.h"
#include "mlx/c/distributed_group.h"
#include "mlx/c/future.h"
#include "mlx/c/ioutils.h"
#include "mlx/c/map.h"
#include "mlx/c/stream.h"
#include "mlx/c/string.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup einsum Einsum operations
 */
/**@{*/
mlx_array mlx_einsum(
    mlx_string subscripts,
    const mlx_vector_array operands,
    mlx_stream s);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
