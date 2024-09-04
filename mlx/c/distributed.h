/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_OPS_H
#define MLX_OPS_H

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
 * \defgroup distributed_ops Distributed collectives
 */
/**@{*/
mlx_array mlx_distributed_all_gather(
    mlx_array x,
    mlx_distributed_group group,
    mlx_stream S);
mlx_array
mlx_distributed_all_sum(mlx_array x, mlx_distributed_group group, mlx_stream s);
mlx_array mlx_distributed_recv(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    int src,
    mlx_distributed_group group,
    mlx_stream s);
mlx_array mlx_distributed_recv_like(
    mlx_array x,
    int src,
    mlx_distributed_group group,
    mlx_stream s);
mlx_array mlx_distributed_send(
    mlx_array x,
    int dst,
    mlx_distributed_group group,
    mlx_stream s);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
