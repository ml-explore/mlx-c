/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/distributed.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
//    #include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/tuple.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" int mlx_distributed_all_gather(
    mlx_array x,
    mlx_distributed_group group,
    mlx_stream S,
    mlx_array res) {
  try {
    res->ctx = mlx::core::distributed::all_gather(
        x->ctx,
        (group ? std::make_optional(group->ctx) : std::nullopt),
        S->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_distributed_all_sum(
    mlx_array x,
    mlx_distributed_group group,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::distributed::all_sum(
        x->ctx,
        (group ? std::make_optional(group->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_distributed_recv(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    int src,
    mlx_distributed_group group,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::distributed::recv(
        MLX_CPP_INTVEC(shape, num_shape),
        MLX_CPP_ARRAY_DTYPE(dtype),
        src,
        (group ? std::make_optional(group->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_distributed_recv_like(
    mlx_array x,
    int src,
    mlx_distributed_group group,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::distributed::recv_like(
        x->ctx,
        src,
        (group ? std::make_optional(group->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_distributed_send(
    mlx_array x,
    int dst,
    mlx_distributed_group group,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::distributed::send(
        x->ctx,
        dst,
        (group ? std::make_optional(group->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
