/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/distributed.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" int mlx_distributed_all_gather(
    const mlx_array x,
    const mlx_distributed_group group /* may be null */,
    const mlx_stream S,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::distributed::all_gather(
            mlx_array_get_(x),
            (group.ctx ? std::make_optional(mlx_distributed_group_get_(group))
                       : std::nullopt),
            mlx_stream_get_(S)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_distributed_all_sum(
    const mlx_array x,
    const mlx_distributed_group group /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::distributed::all_sum(
            mlx_array_get_(x),
            (group.ctx ? std::make_optional(mlx_distributed_group_get_(group))
                       : std::nullopt),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_distributed_recv(
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    int src,
    const mlx_distributed_group group /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::distributed::recv(
            std::vector<int>(shape, shape + shape_num),
            mlx_dtype_to_cpp(dtype),
            src,
            (group.ctx ? std::make_optional(mlx_distributed_group_get_(group))
                       : std::nullopt),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_distributed_recv_like(
    const mlx_array x,
    int src,
    const mlx_distributed_group group /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::distributed::recv_like(
            mlx_array_get_(x),
            src,
            (group.ctx ? std::make_optional(mlx_distributed_group_get_(group))
                       : std::nullopt),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_distributed_send(
    const mlx_array x,
    int dst,
    const mlx_distributed_group group /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::distributed::send(
            mlx_array_get_(x),
            dst,
            (group.ctx ? std::make_optional(mlx_distributed_group_get_(group))
                       : std::nullopt),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
