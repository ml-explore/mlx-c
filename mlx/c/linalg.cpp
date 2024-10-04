/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/linalg.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" int mlx_linalg_cholesky(
    const mlx_array a,
    bool upper,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::linalg::cholesky(
            mlx_array_get_(a), upper, mlx_stream_get_(s)));
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
    mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::linalg::cholesky_inv(
            mlx_array_get_(a), upper, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_linalg_cross(
    const mlx_array a,
    const mlx_array b,
    int axis,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::linalg::cross(
            mlx_array_get_(a), mlx_array_get_(b), axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_linalg_inv(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        res, mlx::core::linalg::inv(mlx_array_get_(a), mlx_stream_get_(s)));
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
    mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::linalg::norm(
            mlx_array_get_(a),
            ord,
            (axis ? std::make_optional(std::vector<int>(axis, axis + axis_num))
                  : std::nullopt),
            keepdims,
            mlx_stream_get_(s)));
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
    mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::linalg::norm(
            mlx_array_get_(a),
            std::string(ord),
            (axis ? std::make_optional(std::vector<int>(axis, axis + axis_num))
                  : std::nullopt),
            keepdims,
            mlx_stream_get_(s)));
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
    mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::linalg::norm(
            mlx_array_get_(a),
            (axis ? std::make_optional(std::vector<int>(axis, axis + axis_num))
                  : std::nullopt),
            keepdims,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_linalg_pinv(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        res, mlx::core::linalg::pinv(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_linalg_qr(
    const mlx_array a,
    const mlx_stream s,
    mlx_array* res_0,
    mlx_array* res_1) {
  try {
    std::tie(mlx_array_get_(*res_0), mlx_array_get_(*res_1)) =
        mlx::core::linalg::qr(mlx_array_get_(a), mlx_stream_get_(s));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_linalg_svd(const mlx_array a, const mlx_stream s, mlx_vector_array* res) {
  try {
    mlx_vector_array_set_(
        res, mlx::core::linalg::svd(mlx_array_get_(a), mlx_stream_get_(s)));
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
    mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::linalg::tri_inv(
            mlx_array_get_(a), upper, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
