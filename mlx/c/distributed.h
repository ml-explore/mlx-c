/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_DISTRIBUTED_H
#define MLX_DISTRIBUTED_H

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
 * \defgroup distributed Distributed collectives
 */
/**@{*/
int mlx_distributed_all_gather(
    const mlx_array x,
    const mlx_distributed_group group /* may be null */,
    const mlx_stream S,
    mlx_array* res);
int mlx_distributed_all_sum(
    const mlx_array x,
    const mlx_distributed_group group /* may be null */,
    const mlx_stream s,
    mlx_array* res);
int mlx_distributed_recv(
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    int src,
    const mlx_distributed_group group /* may be null */,
    const mlx_stream s,
    mlx_array* res);
int mlx_distributed_recv_like(
    const mlx_array x,
    int src,
    const mlx_distributed_group group /* may be null */,
    const mlx_stream s,
    mlx_array* res);
int mlx_distributed_send(
    const mlx_array x,
    int dst,
    const mlx_distributed_group group /* may be null */,
    const mlx_stream s,
    mlx_array* res);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
