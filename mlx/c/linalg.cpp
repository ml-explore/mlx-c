/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/linalg.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" int mlx_linalg_cholesky(
    const mlx_array a,
    bool upper,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::linalg::cholesky(a->ctx, upper, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_linalg_cholesky_inv(
    const mlx_array a,
    bool upper,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::linalg::cholesky_inv(a->ctx, upper, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_linalg_inv(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::linalg::inv(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_linalg_norm_p(
    const mlx_array a,
    double ord,
    const int* axis /* may be null */,
    size_t axis_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::linalg::norm(
        a->ctx,
        ord,
        (axis ? std::make_optional(std::vector<int>(axis, axis + axis_num))
              : std::nullopt),
        keepdims,
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_linalg_norm_ord(
    const mlx_array a,
    const char* ord,
    const int* axis /* may be null */,
    size_t axis_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::linalg::norm(
        a->ctx,
        std::string(ord),
        (axis ? std::make_optional(std::vector<int>(axis, axis + axis_num))
              : std::nullopt),
        keepdims,
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_linalg_norm(
    const mlx_array a,
    const int* axis /* may be null */,
    size_t axis_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::linalg::norm(
        a->ctx,
        (axis ? std::make_optional(std::vector<int>(axis, axis + axis_num))
              : std::nullopt),
        keepdims,
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_linalg_pinv(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::linalg::pinv(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_linalg_qr(
    const mlx_array a,
    const mlx_stream s,
    mlx_array res_0,
    mlx_array res_1) {
  try {
    std::tie(res_0->ctx, res_1->ctx) = mlx::core::linalg::qr(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_linalg_svd(const mlx_array a, const mlx_stream s, mlx_vector_array res) {
  try {
    res->ctx = mlx::core::linalg::svd(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_linalg_tri_inv(
    const mlx_array a,
    bool upper,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::linalg::tri_inv(a->ctx, upper, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
