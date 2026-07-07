/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/distributed.h"
#include "mlx/c/error.h"
#include "mlx/c/private/mlx.h"
#include "mlx/distributed/ops.h"

extern "C" int mlx_distributed_all_gather(
    mlx_array* res,
    const mlx_array x,
    const mlx_distributed_group group /* may be null */,
    const mlx_stream S) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::distributed::all_gather(
            mlx_array_get_(x),
            (group.ctx ? std::make_optional(mlx_distributed_group_get_(group))
                       : std::nullopt),
            mlx_stream_get_(S)));
  } catch (const std::invalid_argument& e) {
    mlx_error_with_code(MLX_ERROR_INVALID_ARGUMENT, "%s", e.what());
    return 1;
  } catch (const std::out_of_range& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_RANGE, "%s", e.what());
    return 1;
  } catch (const std::bad_alloc& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_MEMORY, "%s", e.what());
    return 1;
  } catch (const std::exception& e) {
    mlx_error_with_code(MLX_ERROR_RUNTIME, "%s", e.what());
    return 1;
  } catch (...) {
    mlx_error_with_code(MLX_ERROR_UNKNOWN, "unknown (non-std) exception");
    return 1;
  }
  return 0;
}
extern "C" int mlx_distributed_all_max(
    mlx_array* res,
    const mlx_array x,
    const mlx_distributed_group group /* may be null */,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::distributed::all_max(
            mlx_array_get_(x),
            (group.ctx ? std::make_optional(mlx_distributed_group_get_(group))
                       : std::nullopt),
            mlx_stream_get_(s)));
  } catch (const std::invalid_argument& e) {
    mlx_error_with_code(MLX_ERROR_INVALID_ARGUMENT, "%s", e.what());
    return 1;
  } catch (const std::out_of_range& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_RANGE, "%s", e.what());
    return 1;
  } catch (const std::bad_alloc& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_MEMORY, "%s", e.what());
    return 1;
  } catch (const std::exception& e) {
    mlx_error_with_code(MLX_ERROR_RUNTIME, "%s", e.what());
    return 1;
  } catch (...) {
    mlx_error_with_code(MLX_ERROR_UNKNOWN, "unknown (non-std) exception");
    return 1;
  }
  return 0;
}
extern "C" int mlx_distributed_all_min(
    mlx_array* res,
    const mlx_array x,
    const mlx_distributed_group group /* may be null */,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::distributed::all_min(
            mlx_array_get_(x),
            (group.ctx ? std::make_optional(mlx_distributed_group_get_(group))
                       : std::nullopt),
            mlx_stream_get_(s)));
  } catch (const std::invalid_argument& e) {
    mlx_error_with_code(MLX_ERROR_INVALID_ARGUMENT, "%s", e.what());
    return 1;
  } catch (const std::out_of_range& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_RANGE, "%s", e.what());
    return 1;
  } catch (const std::bad_alloc& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_MEMORY, "%s", e.what());
    return 1;
  } catch (const std::exception& e) {
    mlx_error_with_code(MLX_ERROR_RUNTIME, "%s", e.what());
    return 1;
  } catch (...) {
    mlx_error_with_code(MLX_ERROR_UNKNOWN, "unknown (non-std) exception");
    return 1;
  }
  return 0;
}
extern "C" int mlx_distributed_all_sum(
    mlx_array* res,
    const mlx_array x,
    const mlx_distributed_group group /* may be null */,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::distributed::all_sum(
            mlx_array_get_(x),
            (group.ctx ? std::make_optional(mlx_distributed_group_get_(group))
                       : std::nullopt),
            mlx_stream_get_(s)));
  } catch (const std::invalid_argument& e) {
    mlx_error_with_code(MLX_ERROR_INVALID_ARGUMENT, "%s", e.what());
    return 1;
  } catch (const std::out_of_range& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_RANGE, "%s", e.what());
    return 1;
  } catch (const std::bad_alloc& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_MEMORY, "%s", e.what());
    return 1;
  } catch (const std::exception& e) {
    mlx_error_with_code(MLX_ERROR_RUNTIME, "%s", e.what());
    return 1;
  } catch (...) {
    mlx_error_with_code(MLX_ERROR_UNKNOWN, "unknown (non-std) exception");
    return 1;
  }
  return 0;
}
extern "C" int mlx_distributed_recv(
    mlx_array* res,
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    int src,
    const mlx_distributed_group group /* may be null */,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::distributed::recv(
            mlx::core::Shape(shape, shape + shape_num),
            mlx_dtype_to_cpp(dtype),
            src,
            (group.ctx ? std::make_optional(mlx_distributed_group_get_(group))
                       : std::nullopt),
            mlx_stream_get_(s)));
  } catch (const std::invalid_argument& e) {
    mlx_error_with_code(MLX_ERROR_INVALID_ARGUMENT, "%s", e.what());
    return 1;
  } catch (const std::out_of_range& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_RANGE, "%s", e.what());
    return 1;
  } catch (const std::bad_alloc& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_MEMORY, "%s", e.what());
    return 1;
  } catch (const std::exception& e) {
    mlx_error_with_code(MLX_ERROR_RUNTIME, "%s", e.what());
    return 1;
  } catch (...) {
    mlx_error_with_code(MLX_ERROR_UNKNOWN, "unknown (non-std) exception");
    return 1;
  }
  return 0;
}
extern "C" int mlx_distributed_recv_like(
    mlx_array* res,
    const mlx_array x,
    int src,
    const mlx_distributed_group group /* may be null */,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::distributed::recv_like(
            mlx_array_get_(x),
            src,
            (group.ctx ? std::make_optional(mlx_distributed_group_get_(group))
                       : std::nullopt),
            mlx_stream_get_(s)));
  } catch (const std::invalid_argument& e) {
    mlx_error_with_code(MLX_ERROR_INVALID_ARGUMENT, "%s", e.what());
    return 1;
  } catch (const std::out_of_range& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_RANGE, "%s", e.what());
    return 1;
  } catch (const std::bad_alloc& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_MEMORY, "%s", e.what());
    return 1;
  } catch (const std::exception& e) {
    mlx_error_with_code(MLX_ERROR_RUNTIME, "%s", e.what());
    return 1;
  } catch (...) {
    mlx_error_with_code(MLX_ERROR_UNKNOWN, "unknown (non-std) exception");
    return 1;
  }
  return 0;
}
extern "C" int mlx_distributed_send(
    mlx_array* res,
    const mlx_array x,
    int dst,
    const mlx_distributed_group group /* may be null */,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::distributed::send(
            mlx_array_get_(x),
            dst,
            (group.ctx ? std::make_optional(mlx_distributed_group_get_(group))
                       : std::nullopt),
            mlx_stream_get_(s)));
  } catch (const std::invalid_argument& e) {
    mlx_error_with_code(MLX_ERROR_INVALID_ARGUMENT, "%s", e.what());
    return 1;
  } catch (const std::out_of_range& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_RANGE, "%s", e.what());
    return 1;
  } catch (const std::bad_alloc& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_MEMORY, "%s", e.what());
    return 1;
  } catch (const std::exception& e) {
    mlx_error_with_code(MLX_ERROR_RUNTIME, "%s", e.what());
    return 1;
  } catch (...) {
    mlx_error_with_code(MLX_ERROR_UNKNOWN, "unknown (non-std) exception");
    return 1;
  }
  return 0;
}
extern "C" int mlx_distributed_sum_scatter(
    mlx_array* res,
    const mlx_array x,
    const mlx_distributed_group group /* may be null */,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::distributed::sum_scatter(
            mlx_array_get_(x),
            (group.ctx ? std::make_optional(mlx_distributed_group_get_(group))
                       : std::nullopt),
            mlx_stream_get_(s)));
  } catch (const std::invalid_argument& e) {
    mlx_error_with_code(MLX_ERROR_INVALID_ARGUMENT, "%s", e.what());
    return 1;
  } catch (const std::out_of_range& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_RANGE, "%s", e.what());
    return 1;
  } catch (const std::bad_alloc& e) {
    mlx_error_with_code(MLX_ERROR_OUT_OF_MEMORY, "%s", e.what());
    return 1;
  } catch (const std::exception& e) {
    mlx_error_with_code(MLX_ERROR_RUNTIME, "%s", e.what());
    return 1;
  } catch (...) {
    mlx_error_with_code(MLX_ERROR_UNKNOWN, "unknown (non-std) exception");
    return 1;
  }
  return 0;
}
