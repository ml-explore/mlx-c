/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/ops.h"
#include "mlx/c/error.h"
#include "mlx/c/private/mlx.h"
#include "mlx/einsum.h"

extern "C" int mlx_abs(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::abs(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_abs_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(*res, mlx::core::abs(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_add(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(*res, mlx::core::add(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_add_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::add(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_addmm(
    mlx_array* res,
    const mlx_array c,
    const mlx_array a,
    const mlx_array b) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::addmm(
            mlx_array_get_(c), mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_addmm_x(
    mlx_array* res,
    const mlx_array c,
    const mlx_array a,
    const mlx_array b,
    float alpha,
    float beta,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::addmm(
            mlx_array_get_(c),
            mlx_array_get_(a),
            mlx_array_get_(b),
            alpha,
            beta,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_all_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::all(
            mlx_array_get_(a), std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_all_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::all(
            mlx_array_get_(a),
            std::vector<int>(axes, axes + axes_num),
            keepdims,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_all_axis(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::all(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_all_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::all(mlx_array_get_(a), axis, keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_all(mlx_array* res, const mlx_array a, bool keepdims) {
  try {
    mlx_array_set_(*res, mlx::core::all(mlx_array_get_(a), keepdims));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_allclose(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::allclose(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_allclose_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    double rtol,
    double atol,
    bool equal_nan,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::allclose(
            mlx_array_get_(a),
            mlx_array_get_(b),
            rtol,
            atol,
            equal_nan,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_any_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::any(
            mlx_array_get_(a), std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_any_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::any(
            mlx_array_get_(a),
            std::vector<int>(axes, axes + axes_num),
            keepdims,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_any_axis(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::any(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_any_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::any(mlx_array_get_(a), axis, keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_any(mlx_array* res, const mlx_array a, bool keepdims) {
  try {
    mlx_array_set_(*res, mlx::core::any(mlx_array_get_(a), keepdims));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_arange_x(
    mlx_array* res,
    double start,
    double stop,
    double step,
    mlx_dtype dtype,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::arange(
            start, stop, step, mlx_dtype_to_cpp(dtype), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_arange(mlx_array* res, double stop) {
  try {
    mlx_array_set_(*res, mlx::core::arange(stop));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_arccos(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::arccos(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_arccos_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::arccos(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_arccosh(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::arccosh(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_arccosh_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::arccosh(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_arcsin(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::arcsin(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_arcsin_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::arcsin(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_arcsinh(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::arcsinh(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_arcsinh_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::arcsinh(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_arctan(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::arctan(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_arctan_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::arctan(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_arctan2(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::arctan2(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_arctan2_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::arctan2(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_arctanh(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::arctanh(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_arctanh_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::arctanh(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_argmax_axis(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::argmax(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_argmax_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::argmax(
            mlx_array_get_(a), axis, keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_argmax(mlx_array* res, const mlx_array a, bool keepdims) {
  try {
    mlx_array_set_(*res, mlx::core::argmax(mlx_array_get_(a), keepdims));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_argmin_axis(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::argmin(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_argmin_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::argmin(
            mlx_array_get_(a), axis, keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_argmin(mlx_array* res, const mlx_array a, bool keepdims) {
  try {
    mlx_array_set_(*res, mlx::core::argmin(mlx_array_get_(a), keepdims));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_argpartition_axis(mlx_array* res, const mlx_array a, int kth, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::argpartition(mlx_array_get_(a), kth, axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_argpartition_axis_x(
    mlx_array* res,
    const mlx_array a,
    int kth,
    int axis,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::argpartition(
            mlx_array_get_(a), kth, axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_argpartition(mlx_array* res, const mlx_array a, int kth) {
  try {
    mlx_array_set_(*res, mlx::core::argpartition(mlx_array_get_(a), kth));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_argsort_axis(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::argsort(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_argsort_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::argsort(mlx_array_get_(a), axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_argsort(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::argsort(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_array_equal_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    bool equal_nan,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::array_equal(
            mlx_array_get_(a),
            mlx_array_get_(b),
            equal_nan,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_array_equal(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::array_equal(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_as_strided(
    mlx_array* res,
    const mlx_array a,
    const int* shape,
    size_t shape_num,
    const int64_t* strides,
    size_t strides_num,
    size_t offset) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::as_strided(
            mlx_array_get_(a),
            std::vector<int>(shape, shape + shape_num),
            std::vector<int64_t>(strides, strides + strides_num),
            offset));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_as_strided_x(
    mlx_array* res,
    const mlx_array a,
    const int* shape,
    size_t shape_num,
    const int64_t* strides,
    size_t strides_num,
    size_t offset,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::as_strided(
            mlx_array_get_(a),
            std::vector<int>(shape, shape + shape_num),
            std::vector<int64_t>(strides, strides + strides_num),
            offset,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_astype(mlx_array* res, const mlx_array a, mlx_dtype dtype) {
  try {
    mlx_array_set_(
        *res, mlx::core::astype(mlx_array_get_(a), mlx_dtype_to_cpp(dtype)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_astype_x(
    mlx_array* res,
    const mlx_array a,
    mlx_dtype dtype,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::astype(
            mlx_array_get_(a), mlx_dtype_to_cpp(dtype), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_atleast_1d(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::atleast_1d(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_atleast_1d_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::atleast_1d(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_atleast_2d(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::atleast_2d(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_atleast_2d_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::atleast_2d(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_atleast_3d(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::atleast_3d(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_atleast_3d_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::atleast_3d(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_bitwise_and(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::bitwise_and(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_bitwise_and_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::bitwise_and(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_bitwise_invert(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::bitwise_invert(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_bitwise_invert_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::bitwise_invert(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_bitwise_or(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::bitwise_or(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_bitwise_or_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::bitwise_or(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_bitwise_xor(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::bitwise_xor(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_bitwise_xor_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::bitwise_xor(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_block_masked_mm(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    int block_size) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::block_masked_mm(
            mlx_array_get_(a), mlx_array_get_(b), block_size));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_block_masked_mm_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    int block_size,
    const mlx_array mask_out /* may be null */,
    const mlx_array mask_lhs /* may be null */,
    const mlx_array mask_rhs /* may be null */,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::block_masked_mm(
            mlx_array_get_(a),
            mlx_array_get_(b),
            block_size,
            (mask_out.ctx ? std::make_optional(mlx_array_get_(mask_out))
                          : std::nullopt),
            (mask_lhs.ctx ? std::make_optional(mlx_array_get_(mask_lhs))
                          : std::nullopt),
            (mask_rhs.ctx ? std::make_optional(mlx_array_get_(mask_rhs))
                          : std::nullopt),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_broadcast_arrays(
    mlx_vector_array* res,
    const mlx_vector_array inputs) {
  try {
    mlx_vector_array_set_(
        *res, mlx::core::broadcast_arrays(mlx_vector_array_get_(inputs)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_broadcast_arrays_x(
    mlx_vector_array* res,
    const mlx_vector_array inputs,
    const mlx_stream s) {
  try {
    mlx_vector_array_set_(
        *res,
        mlx::core::broadcast_arrays(
            mlx_vector_array_get_(inputs), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_broadcast_to(
    mlx_array* res,
    const mlx_array a,
    const int* shape,
    size_t shape_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::broadcast_to(
            mlx_array_get_(a), std::vector<int>(shape, shape + shape_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_broadcast_to_x(
    mlx_array* res,
    const mlx_array a,
    const int* shape,
    size_t shape_num,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::broadcast_to(
            mlx_array_get_(a),
            std::vector<int>(shape, shape + shape_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_ceil(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::ceil(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_ceil_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::ceil(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_clip(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::clip(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_clip_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array a_min /* may be null */,
    const mlx_array a_max /* may be null */,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::clip(
            mlx_array_get_(a),
            (a_min.ctx ? std::make_optional(mlx_array_get_(a_min))
                       : std::nullopt),
            (a_max.ctx ? std::make_optional(mlx_array_get_(a_max))
                       : std::nullopt),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_concatenate_axis(mlx_array* res, const mlx_vector_array arrays, int axis) {
  try {
    mlx_array_set_(
        *res, mlx::core::concatenate(mlx_vector_array_get_(arrays), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_concatenate_axis_x(
    mlx_array* res,
    const mlx_vector_array arrays,
    int axis,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::concatenate(
            mlx_vector_array_get_(arrays), axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_concatenate(mlx_array* res, const mlx_vector_array arrays) {
  try {
    mlx_array_set_(*res, mlx::core::concatenate(mlx_vector_array_get_(arrays)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conjugate(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::conjugate(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_conjugate_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::conjugate(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_contiguous(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::contiguous(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_contiguous_x(
    mlx_array* res,
    const mlx_array a,
    bool allow_col_major,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::contiguous(
            mlx_array_get_(a), allow_col_major, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_conv1d(mlx_array* res, const mlx_array input, const mlx_array weight) {
  try {
    mlx_array_set_(
        *res, mlx::core::conv1d(mlx_array_get_(input), mlx_array_get_(weight)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conv1d_x(
    mlx_array* res,
    const mlx_array input,
    const mlx_array weight,
    int stride,
    int padding,
    int dilation,
    int groups,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::conv1d(
            mlx_array_get_(input),
            mlx_array_get_(weight),
            stride,
            padding,
            dilation,
            groups,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_conv2d(mlx_array* res, const mlx_array input, const mlx_array weight) {
  try {
    mlx_array_set_(
        *res, mlx::core::conv2d(mlx_array_get_(input), mlx_array_get_(weight)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conv2d_x(
    mlx_array* res,
    const mlx_array input,
    const mlx_array weight,
    int stride_0,
    int stride_1,
    int padding_0,
    int padding_1,
    int dilation_0,
    int dilation_1,
    int groups,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::conv2d(
            mlx_array_get_(input),
            mlx_array_get_(weight),
            std::make_pair(stride_0, stride_1),
            std::make_pair(padding_0, padding_1),
            std::make_pair(dilation_0, dilation_1),
            groups,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_conv3d(mlx_array* res, const mlx_array input, const mlx_array weight) {
  try {
    mlx_array_set_(
        *res, mlx::core::conv3d(mlx_array_get_(input), mlx_array_get_(weight)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conv3d_x(
    mlx_array* res,
    const mlx_array input,
    const mlx_array weight,
    int stride_0,
    int stride_1,
    int stride_2,
    int padding_0,
    int padding_1,
    int padding_2,
    int dilation_0,
    int dilation_1,
    int dilation_2,
    int groups,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::conv3d(
            mlx_array_get_(input),
            mlx_array_get_(weight),
            std::make_tuple(stride_0, stride_1, stride_2),
            std::make_tuple(padding_0, padding_1, padding_2),
            std::make_tuple(dilation_0, dilation_1, dilation_2),
            groups,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conv_general(
    mlx_array* res,
    const mlx_array input,
    const mlx_array weight) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::conv_general(mlx_array_get_(input), mlx_array_get_(weight)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conv_general_x(
    mlx_array* res,
    const mlx_array input,
    const mlx_array weight,
    const int* stride,
    size_t stride_num,
    const int* padding_lo,
    size_t padding_lo_num,
    const int* padding_hi,
    size_t padding_hi_num,
    const int* kernel_dilation,
    size_t kernel_dilation_num,
    const int* input_dilation,
    size_t input_dilation_num,
    int groups,
    bool flip,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::conv_general(
            mlx_array_get_(input),
            mlx_array_get_(weight),
            std::vector<int>(stride, stride + stride_num),
            std::vector<int>(padding_lo, padding_lo + padding_lo_num),
            std::vector<int>(padding_hi, padding_hi + padding_hi_num),
            std::vector<int>(
                kernel_dilation, kernel_dilation + kernel_dilation_num),
            std::vector<int>(
                input_dilation, input_dilation + input_dilation_num),
            groups,
            flip,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conv_transpose1d(
    mlx_array* res,
    const mlx_array input,
    const mlx_array weight) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::conv_transpose1d(
            mlx_array_get_(input), mlx_array_get_(weight)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conv_transpose1d_x(
    mlx_array* res,
    const mlx_array input,
    const mlx_array weight,
    int stride,
    int padding,
    int dilation,
    int groups,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::conv_transpose1d(
            mlx_array_get_(input),
            mlx_array_get_(weight),
            stride,
            padding,
            dilation,
            groups,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conv_transpose2d(
    mlx_array* res,
    const mlx_array input,
    const mlx_array weight) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::conv_transpose2d(
            mlx_array_get_(input), mlx_array_get_(weight)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conv_transpose2d_x(
    mlx_array* res,
    const mlx_array input,
    const mlx_array weight,
    int stride_0,
    int stride_1,
    int padding_0,
    int padding_1,
    int dilation_0,
    int dilation_1,
    int groups,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::conv_transpose2d(
            mlx_array_get_(input),
            mlx_array_get_(weight),
            std::make_pair(stride_0, stride_1),
            std::make_pair(padding_0, padding_1),
            std::make_pair(dilation_0, dilation_1),
            groups,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conv_transpose3d(
    mlx_array* res,
    const mlx_array input,
    const mlx_array weight) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::conv_transpose3d(
            mlx_array_get_(input), mlx_array_get_(weight)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conv_transpose3d_x(
    mlx_array* res,
    const mlx_array input,
    const mlx_array weight,
    int stride_0,
    int stride_1,
    int stride_2,
    int padding_0,
    int padding_1,
    int padding_2,
    int dilation_0,
    int dilation_1,
    int dilation_2,
    int groups,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::conv_transpose3d(
            mlx_array_get_(input),
            mlx_array_get_(weight),
            std::make_tuple(stride_0, stride_1, stride_2),
            std::make_tuple(padding_0, padding_1, padding_2),
            std::make_tuple(dilation_0, dilation_1, dilation_2),
            groups,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_copy(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::copy(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_copy_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::copy(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cos(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::cos(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_cos_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(*res, mlx::core::cos(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cosh(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::cosh(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_cosh_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::cosh(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cummax(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::cummax(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cummax_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::cummax(
            mlx_array_get_(a), axis, reverse, inclusive, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cummin(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::cummin(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cummin_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::cummin(
            mlx_array_get_(a), axis, reverse, inclusive, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cumprod(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::cumprod(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cumprod_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::cumprod(
            mlx_array_get_(a), axis, reverse, inclusive, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cumsum(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::cumsum(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cumsum_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::cumsum(
            mlx_array_get_(a), axis, reverse, inclusive, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_degrees(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::degrees(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_degrees_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::degrees(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_depends(
    mlx_vector_array* res,
    const mlx_vector_array inputs,
    const mlx_vector_array dependencies) {
  try {
    mlx_vector_array_set_(
        *res,
        mlx::core::depends(
            mlx_vector_array_get_(inputs),
            mlx_vector_array_get_(dependencies)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_dequantize(
    mlx_array* res,
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::dequantize(
            mlx_array_get_(w), mlx_array_get_(scales), mlx_array_get_(biases)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_dequantize_x(
    mlx_array* res,
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases,
    int group_size,
    int bits,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::dequantize(
            mlx_array_get_(w),
            mlx_array_get_(scales),
            mlx_array_get_(biases),
            group_size,
            bits,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_diag(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::diag(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_diag_x(mlx_array* res, const mlx_array a, int k, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::diag(mlx_array_get_(a), k, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_diagonal(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::diagonal(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_diagonal_x(
    mlx_array* res,
    const mlx_array a,
    int offset,
    int axis1,
    int axis2,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::diagonal(
            mlx_array_get_(a), offset, axis1, axis2, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_divide(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::divide(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_divide_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::divide(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_divmod(mlx_vector_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_vector_array_set_(
        *res, mlx::core::divmod(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_divmod_x(
    mlx_vector_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_vector_array_set_(
        *res,
        mlx::core::divmod(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_einsum(
    mlx_array* res,
    const char* subscripts,
    const mlx_vector_array operands) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::einsum(
            std::string(subscripts), mlx_vector_array_get_(operands)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_einsum_x(
    mlx_array* res,
    const char* subscripts,
    const mlx_vector_array operands,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::einsum(
            std::string(subscripts),
            mlx_vector_array_get_(operands),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_equal(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::equal(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_equal_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::equal(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_erf(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::erf(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_erf_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(*res, mlx::core::erf(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_erfinv(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::erfinv(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_erfinv_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::erfinv(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_exp(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::exp(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_exp_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(*res, mlx::core::exp(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_expand_dims_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::expand_dims(
            mlx_array_get_(a), std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_expand_dims_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::expand_dims(
            mlx_array_get_(a),
            std::vector<int>(axes, axes + axes_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_expand_dims(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::expand_dims(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_expm1(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::expm1(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_expm1_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::expm1(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_eye_x(
    mlx_array* res,
    int n,
    int m,
    int k,
    mlx_dtype dtype,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::eye(n, m, k, mlx_dtype_to_cpp(dtype), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_eye(mlx_array* res, int n) {
  try {
    mlx_array_set_(*res, mlx::core::eye(n));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_flatten_x(
    mlx_array* res,
    const mlx_array a,
    int start_axis,
    int end_axis,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::flatten(
            mlx_array_get_(a), start_axis, end_axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_flatten(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::flatten(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_floor(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::floor(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_floor_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::floor(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_floor_divide(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::floor_divide(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_floor_divide_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::floor_divide(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_full(
    mlx_array* res,
    const int* shape,
    size_t shape_num,
    const mlx_array vals,
    mlx_dtype dtype) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::full(
            std::vector<int>(shape, shape + shape_num),
            mlx_array_get_(vals),
            mlx_dtype_to_cpp(dtype)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_full_x(
    mlx_array* res,
    const int* shape,
    size_t shape_num,
    const mlx_array vals,
    mlx_dtype dtype,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::full(
            std::vector<int>(shape, shape + shape_num),
            mlx_array_get_(vals),
            mlx_dtype_to_cpp(dtype),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_gather(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const int* axes,
    size_t axes_num,
    const int* slice_sizes,
    size_t slice_sizes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::gather(
            mlx_array_get_(a),
            mlx_vector_array_get_(indices),
            std::vector<int>(axes, axes + axes_num),
            std::vector<int>(slice_sizes, slice_sizes + slice_sizes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_gather_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const int* axes,
    size_t axes_num,
    const int* slice_sizes,
    size_t slice_sizes_num,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::gather(
            mlx_array_get_(a),
            mlx_vector_array_get_(indices),
            std::vector<int>(axes, axes + axes_num),
            std::vector<int>(slice_sizes, slice_sizes + slice_sizes_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_gather_mm(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::gather_mm(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_gather_mm_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_array lhs_indices /* may be null */,
    const mlx_array rhs_indices /* may be null */,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::gather_mm(
            mlx_array_get_(a),
            mlx_array_get_(b),
            (lhs_indices.ctx ? std::make_optional(mlx_array_get_(lhs_indices))
                             : std::nullopt),
            (rhs_indices.ctx ? std::make_optional(mlx_array_get_(rhs_indices))
                             : std::nullopt),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_gather_qmm(
    mlx_array* res,
    const mlx_array x,
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::gather_qmm(
            mlx_array_get_(x),
            mlx_array_get_(w),
            mlx_array_get_(scales),
            mlx_array_get_(biases)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_gather_qmm_x(
    mlx_array* res,
    const mlx_array x,
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases,
    const mlx_array lhs_indices /* may be null */,
    const mlx_array rhs_indices /* may be null */,
    bool transpose,
    int group_size,
    int bits,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::gather_qmm(
            mlx_array_get_(x),
            mlx_array_get_(w),
            mlx_array_get_(scales),
            mlx_array_get_(biases),
            (lhs_indices.ctx ? std::make_optional(mlx_array_get_(lhs_indices))
                             : std::nullopt),
            (rhs_indices.ctx ? std::make_optional(mlx_array_get_(rhs_indices))
                             : std::nullopt),
            transpose,
            group_size,
            bits,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_greater(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::greater(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_greater_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::greater(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_greater_equal(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::greater_equal(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_greater_equal_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::greater_equal(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_hadamard_transform(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::hadamard_transform(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_hadamard_transform_x(
    mlx_array* res,
    const mlx_array a,
    mlx_optional_float scale,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::hadamard_transform(
            mlx_array_get_(a),
            (scale.has_value ? std::make_optional<float>(scale.value)
                             : std::nullopt),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_identity(mlx_array* res, int n, mlx_dtype dtype) {
  try {
    mlx_array_set_(*res, mlx::core::identity(n, mlx_dtype_to_cpp(dtype)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_identity_x(mlx_array* res, int n, mlx_dtype dtype, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::identity(n, mlx_dtype_to_cpp(dtype), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_imag(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::imag(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_imag_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::imag(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_inner(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::inner(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_inner_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::inner(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_isclose(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::isclose(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_isclose_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    double rtol,
    double atol,
    bool equal_nan,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::isclose(
            mlx_array_get_(a),
            mlx_array_get_(b),
            rtol,
            atol,
            equal_nan,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_isfinite(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::isfinite(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_isfinite_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::isfinite(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_isinf(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::isinf(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_isinf_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::isinf(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_isnan(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::isnan(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_isnan_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::isnan(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_isneginf(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::isneginf(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_isneginf_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::isneginf(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_isposinf(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::isposinf(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_isposinf_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::isposinf(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_kron(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(*res, mlx::core::kron(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_kron_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::kron(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_left_shift(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::left_shift(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_left_shift_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::left_shift(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_less(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(*res, mlx::core::less(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_less_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::less(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_less_equal(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::less_equal(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_less_equal_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::less_equal(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_linspace(mlx_array* res, double start, double stop) {
  try {
    mlx_array_set_(*res, mlx::core::linspace(start, stop));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_linspace_x(
    mlx_array* res,
    double start,
    double stop,
    int num,
    mlx_dtype dtype,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::linspace(
            start, stop, num, mlx_dtype_to_cpp(dtype), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_log(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::log(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_log_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(*res, mlx::core::log(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_log10(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::log10(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_log10_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::log10(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_log1p(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::log1p(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_log1p_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::log1p(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_log2(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::log2(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_log2_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::log2(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_logaddexp(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::logaddexp(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_logaddexp_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::logaddexp(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_logical_and(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::logical_and(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_logical_and_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::logical_and(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_logical_not(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::logical_not(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_logical_not_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::logical_not(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_logical_or(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::logical_or(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_logical_or_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::logical_or(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_logsumexp_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::logsumexp(
            mlx_array_get_(a), std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_logsumexp_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::logsumexp(
            mlx_array_get_(a),
            std::vector<int>(axes, axes + axes_num),
            keepdims,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_logsumexp_axis(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::logsumexp(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_logsumexp_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::logsumexp(
            mlx_array_get_(a), axis, keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_logsumexp(mlx_array* res, const mlx_array a, bool keepdims) {
  try {
    mlx_array_set_(*res, mlx::core::logsumexp(mlx_array_get_(a), keepdims));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_matmul(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::matmul(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_matmul_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::matmul(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_max_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::max(
            mlx_array_get_(a), std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_max_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::max(
            mlx_array_get_(a),
            std::vector<int>(axes, axes + axes_num),
            keepdims,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_max_axis(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::max(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_max_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::max(mlx_array_get_(a), axis, keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_max(mlx_array* res, const mlx_array a, bool keepdims) {
  try {
    mlx_array_set_(*res, mlx::core::max(mlx_array_get_(a), keepdims));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_maximum(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::maximum(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_maximum_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::maximum(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_mean_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::mean(
            mlx_array_get_(a), std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_mean_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::mean(
            mlx_array_get_(a),
            std::vector<int>(axes, axes + axes_num),
            keepdims,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_mean_axis(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::mean(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_mean_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::mean(mlx_array_get_(a), axis, keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_mean(mlx_array* res, const mlx_array a, bool keepdims) {
  try {
    mlx_array_set_(*res, mlx::core::mean(mlx_array_get_(a), keepdims));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_meshgrid(
    mlx_vector_array* res,
    const mlx_vector_array arrays) {
  try {
    mlx_vector_array_set_(
        *res, mlx::core::meshgrid(mlx_vector_array_get_(arrays)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_meshgrid_x(
    mlx_vector_array* res,
    const mlx_vector_array arrays,
    bool sparse,
    const char* indexing,
    const mlx_stream s) {
  try {
    mlx_vector_array_set_(
        *res,
        mlx::core::meshgrid(
            mlx_vector_array_get_(arrays),
            sparse,
            std::string(indexing),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_min_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::min(
            mlx_array_get_(a), std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_min_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::min(
            mlx_array_get_(a),
            std::vector<int>(axes, axes + axes_num),
            keepdims,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_min_axis(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::min(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_min_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::min(mlx_array_get_(a), axis, keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_min(mlx_array* res, const mlx_array a, bool keepdims) {
  try {
    mlx_array_set_(*res, mlx::core::min(mlx_array_get_(a), keepdims));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_minimum(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::minimum(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_minimum_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::minimum(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_moveaxis(mlx_array* res, const mlx_array a, int source, int destination) {
  try {
    mlx_array_set_(
        *res, mlx::core::moveaxis(mlx_array_get_(a), source, destination));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_moveaxis_x(
    mlx_array* res,
    const mlx_array a,
    int source,
    int destination,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::moveaxis(
            mlx_array_get_(a), source, destination, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_multiply(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::multiply(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_multiply_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::multiply(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_nan_to_num(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::nan_to_num(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_nan_to_num_x(
    mlx_array* res,
    const mlx_array a,
    float nan,
    mlx_optional_float posinf,
    mlx_optional_float neginf,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::nan_to_num(
            mlx_array_get_(a),
            nan,
            (posinf.has_value ? std::make_optional<float>(posinf.value)
                              : std::nullopt),
            (neginf.has_value ? std::make_optional<float>(neginf.value)
                              : std::nullopt),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_negative(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::negative(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_negative_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::negative(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_not_equal(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::not_equal(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_not_equal_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::not_equal(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_number_of_elements(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool inverted) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::number_of_elements(
            mlx_array_get_(a),
            std::vector<int>(axes, axes + axes_num),
            inverted));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_number_of_elements_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool inverted,
    mlx_dtype dtype,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::number_of_elements(
            mlx_array_get_(a),
            std::vector<int>(axes, axes + axes_num),
            inverted,
            mlx_dtype_to_cpp(dtype),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_ones(mlx_array* res, const int* shape, size_t shape_num, mlx_dtype dtype) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::ones(
            std::vector<int>(shape, shape + shape_num),
            mlx_dtype_to_cpp(dtype)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_ones_x(
    mlx_array* res,
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::ones(
            std::vector<int>(shape, shape + shape_num),
            mlx_dtype_to_cpp(dtype),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_ones_like(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::ones_like(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_ones_like_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::ones_like(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_outer(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::outer(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_outer_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::outer(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_pad(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    const int* low_pad_size,
    size_t low_pad_size_num,
    const int* high_pad_size,
    size_t high_pad_size_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::pad(
            mlx_array_get_(a),
            std::vector<int>(axes, axes + axes_num),
            std::vector<int>(low_pad_size, low_pad_size + low_pad_size_num),
            std::vector<int>(
                high_pad_size, high_pad_size + high_pad_size_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_pad_symmetric(mlx_array* res, const mlx_array a, int pad_width) {
  try {
    mlx_array_set_(*res, mlx::core::pad(mlx_array_get_(a), pad_width));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_pad_symmetric_x(
    mlx_array* res,
    const mlx_array a,
    int pad_width,
    const mlx_array pad_value,
    const char* mode,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::pad(
            mlx_array_get_(a),
            pad_width,
            mlx_array_get_(pad_value),
            std::string(mode),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_partition_axis(mlx_array* res, const mlx_array a, int kth, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::partition(mlx_array_get_(a), kth, axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_partition_axis_x(
    mlx_array* res,
    const mlx_array a,
    int kth,
    int axis,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::partition(mlx_array_get_(a), kth, axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_partition(mlx_array* res, const mlx_array a, int kth) {
  try {
    mlx_array_set_(*res, mlx::core::partition(mlx_array_get_(a), kth));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_power(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::power(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_power_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::power(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_prod_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::prod(
            mlx_array_get_(a), std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_prod_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::prod(
            mlx_array_get_(a),
            std::vector<int>(axes, axes + axes_num),
            keepdims,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_prod_axis(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::prod(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_prod_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::prod(mlx_array_get_(a), axis, keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_prod(mlx_array* res, const mlx_array a, bool keepdims) {
  try {
    mlx_array_set_(*res, mlx::core::prod(mlx_array_get_(a), keepdims));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_put_along_axis(
    mlx_array* res,
    const mlx_array a,
    const mlx_array indices,
    const mlx_array values,
    int axis) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::put_along_axis(
            mlx_array_get_(a),
            mlx_array_get_(indices),
            mlx_array_get_(values),
            axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_put_along_axis_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array indices,
    const mlx_array values,
    int axis,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::put_along_axis(
            mlx_array_get_(a),
            mlx_array_get_(indices),
            mlx_array_get_(values),
            axis,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_quantize(
    mlx_array* res_0,
    mlx_array* res_1,
    mlx_array* res_2,
    const mlx_array w) {
  try {
    {
      auto [tpl_0, tpl_1, tpl_2] = mlx::core::quantize(mlx_array_get_(w));
      mlx_array_set_(*res_0, tpl_0);
      mlx_array_set_(*res_1, tpl_1);
      mlx_array_set_(*res_2, tpl_2);
    };
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_quantize_x(
    mlx_array* res_0,
    mlx_array* res_1,
    mlx_array* res_2,
    const mlx_array w,
    int group_size,
    int bits,
    const mlx_stream s) {
  try {
    {
      auto [tpl_0, tpl_1, tpl_2] = mlx::core::quantize(
          mlx_array_get_(w), group_size, bits, mlx_stream_get_(s));
      mlx_array_set_(*res_0, tpl_0);
      mlx_array_set_(*res_1, tpl_1);
      mlx_array_set_(*res_2, tpl_2);
    };
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_quantized_matmul(
    mlx_array* res,
    const mlx_array x,
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::quantized_matmul(
            mlx_array_get_(x),
            mlx_array_get_(w),
            mlx_array_get_(scales),
            mlx_array_get_(biases)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_quantized_matmul_x(
    mlx_array* res,
    const mlx_array x,
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases,
    bool transpose,
    int group_size,
    int bits,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::quantized_matmul(
            mlx_array_get_(x),
            mlx_array_get_(w),
            mlx_array_get_(scales),
            mlx_array_get_(biases),
            transpose,
            group_size,
            bits,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_radians(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::radians(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_radians_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::radians(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_real(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::real(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_real_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::real(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_reciprocal(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::reciprocal(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_reciprocal_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::reciprocal(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_remainder(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::remainder(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_remainder_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::remainder(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_repeat_axis(mlx_array* res, const mlx_array arr, int repeats, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::repeat(mlx_array_get_(arr), repeats, axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_repeat_axis_x(
    mlx_array* res,
    const mlx_array arr,
    int repeats,
    int axis,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::repeat(
            mlx_array_get_(arr), repeats, axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_repeat(mlx_array* res, const mlx_array arr, int repeats) {
  try {
    mlx_array_set_(*res, mlx::core::repeat(mlx_array_get_(arr), repeats));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_reshape(
    mlx_array* res,
    const mlx_array a,
    const int* shape,
    size_t shape_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::reshape(
            mlx_array_get_(a), std::vector<int>(shape, shape + shape_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_reshape_x(
    mlx_array* res,
    const mlx_array a,
    const int* shape,
    size_t shape_num,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::reshape(
            mlx_array_get_(a),
            std::vector<int>(shape, shape + shape_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_right_shift(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::right_shift(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_right_shift_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::right_shift(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_roll_axes(
    mlx_array* res,
    const mlx_array a,
    const int* shift,
    size_t shift_num,
    int axis) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::roll(
            mlx_array_get_(a),
            std::vector<int>(shift, shift + shift_num),
            axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_roll_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* shift,
    size_t shift_num,
    int axis,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::roll(
            mlx_array_get_(a),
            std::vector<int>(shift, shift + shift_num),
            axis,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_roll_axis(
    mlx_array* res,
    const mlx_array a,
    const int* shift,
    size_t shift_num,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::roll(
            mlx_array_get_(a),
            std::vector<int>(shift, shift + shift_num),
            std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_roll_axis_x(
    mlx_array* res,
    const mlx_array a,
    const int* shift,
    size_t shift_num,
    const int* axes,
    size_t axes_num,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::roll(
            mlx_array_get_(a),
            std::vector<int>(shift, shift + shift_num),
            std::vector<int>(axes, axes + axes_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_roll(
    mlx_array* res,
    const mlx_array a,
    const int* shift,
    size_t shift_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::roll(
            mlx_array_get_(a), std::vector<int>(shift, shift + shift_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_round_x(
    mlx_array* res,
    const mlx_array a,
    int decimals,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::round(mlx_array_get_(a), decimals, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_round(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::round(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_rsqrt(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::rsqrt(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_rsqrt_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::rsqrt(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_scatter(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::scatter(
            mlx_array_get_(a),
            mlx_vector_array_get_(indices),
            mlx_array_get_(updates),
            std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_scatter_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::scatter(
            mlx_array_get_(a),
            mlx_vector_array_get_(indices),
            mlx_array_get_(updates),
            std::vector<int>(axes, axes + axes_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_scatter_add(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::scatter_add(
            mlx_array_get_(a),
            mlx_vector_array_get_(indices),
            mlx_array_get_(updates),
            std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_scatter_add_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::scatter_add(
            mlx_array_get_(a),
            mlx_vector_array_get_(indices),
            mlx_array_get_(updates),
            std::vector<int>(axes, axes + axes_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_scatter_add_axis(
    mlx_array* res,
    const mlx_array a,
    const mlx_array indices,
    const mlx_array values,
    int axis) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::scatter_add_axis(
            mlx_array_get_(a),
            mlx_array_get_(indices),
            mlx_array_get_(values),
            axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_scatter_add_axis_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array indices,
    const mlx_array values,
    int axis,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::scatter_add_axis(
            mlx_array_get_(a),
            mlx_array_get_(indices),
            mlx_array_get_(values),
            axis,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_scatter_max(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::scatter_max(
            mlx_array_get_(a),
            mlx_vector_array_get_(indices),
            mlx_array_get_(updates),
            std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_scatter_max_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::scatter_max(
            mlx_array_get_(a),
            mlx_vector_array_get_(indices),
            mlx_array_get_(updates),
            std::vector<int>(axes, axes + axes_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_scatter_min(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::scatter_min(
            mlx_array_get_(a),
            mlx_vector_array_get_(indices),
            mlx_array_get_(updates),
            std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_scatter_min_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::scatter_min(
            mlx_array_get_(a),
            mlx_vector_array_get_(indices),
            mlx_array_get_(updates),
            std::vector<int>(axes, axes + axes_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_scatter_prod(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::scatter_prod(
            mlx_array_get_(a),
            mlx_vector_array_get_(indices),
            mlx_array_get_(updates),
            std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_scatter_prod_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::scatter_prod(
            mlx_array_get_(a),
            mlx_vector_array_get_(indices),
            mlx_array_get_(updates),
            std::vector<int>(axes, axes + axes_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sigmoid(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::sigmoid(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_sigmoid_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::sigmoid(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sign(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::sign(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_sign_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::sign(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sin(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::sin(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_sin_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(*res, mlx::core::sin(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sinh(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::sinh(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_sinh_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::sinh(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_slice(
    mlx_array* res,
    const mlx_array a,
    const int* start,
    size_t start_num,
    const int* stop,
    size_t stop_num,
    const int* strides,
    size_t strides_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::slice(
            mlx_array_get_(a),
            std::vector<int>(start, start + start_num),
            std::vector<int>(stop, stop + stop_num),
            std::vector<int>(strides, strides + strides_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_slice_dynamic(
    mlx_array* res,
    const mlx_array a,
    const mlx_array start,
    const int* axes,
    size_t axes_num,
    const int* slice_size,
    size_t slice_size_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::slice(
            mlx_array_get_(a),
            mlx_array_get_(start),
            std::vector<int>(axes, axes + axes_num),
            std::vector<int>(slice_size, slice_size + slice_size_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_slice_dynamic_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array start,
    const int* axes,
    size_t axes_num,
    const int* slice_size,
    size_t slice_size_num,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::slice(
            mlx_array_get_(a),
            mlx_array_get_(start),
            std::vector<int>(axes, axes + axes_num),
            std::vector<int>(slice_size, slice_size + slice_size_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_slice_update(
    mlx_array* res,
    const mlx_array src,
    const mlx_array update,
    const int* start,
    size_t start_num,
    const int* stop,
    size_t stop_num,
    const int* strides,
    size_t strides_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::slice_update(
            mlx_array_get_(src),
            mlx_array_get_(update),
            std::vector<int>(start, start + start_num),
            std::vector<int>(stop, stop + stop_num),
            std::vector<int>(strides, strides + strides_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_slice_update_dynamic(
    mlx_array* res,
    const mlx_array src,
    const mlx_array update,
    const mlx_array start,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::slice_update(
            mlx_array_get_(src),
            mlx_array_get_(update),
            mlx_array_get_(start),
            std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_slice_update_dynamic_x(
    mlx_array* res,
    const mlx_array src,
    const mlx_array update,
    const mlx_array start,
    const int* axes,
    size_t axes_num,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::slice_update(
            mlx_array_get_(src),
            mlx_array_get_(update),
            mlx_array_get_(start),
            std::vector<int>(axes, axes + axes_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_softmax_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::softmax(
            mlx_array_get_(a), std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_softmax_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool precise,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::softmax(
            mlx_array_get_(a),
            std::vector<int>(axes, axes + axes_num),
            precise,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_softmax_axis(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::softmax(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_softmax_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool precise,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::softmax(
            mlx_array_get_(a), axis, precise, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_softmax(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::softmax(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sort_axis(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::sort(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sort_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::sort(mlx_array_get_(a), axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sort(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::sort(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_split_x(
    mlx_vector_array* res,
    const mlx_array a,
    int num_splits,
    int axis,
    const mlx_stream s) {
  try {
    mlx_vector_array_set_(
        *res,
        mlx::core::split(
            mlx_array_get_(a), num_splits, axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_split_sections_x(
    mlx_vector_array* res,
    const mlx_array a,
    const int* indices,
    size_t indices_num,
    int axis) {
  try {
    mlx_vector_array_set_(
        *res,
        mlx::core::split(
            mlx_array_get_(a),
            std::vector<int>(indices, indices + indices_num),
            axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_split(mlx_vector_array* res, const mlx_array a, int num_splits) {
  try {
    mlx_vector_array_set_(
        *res, mlx::core::split(mlx_array_get_(a), num_splits));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_split_sections(
    mlx_vector_array* res,
    const mlx_array a,
    const int* indices,
    size_t indices_num) {
  try {
    mlx_vector_array_set_(
        *res,
        mlx::core::split(
            mlx_array_get_(a),
            std::vector<int>(indices, indices + indices_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sqrt(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::sqrt(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_sqrt_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::sqrt(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_square(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::square(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_square_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::square(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_squeeze_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::squeeze(
            mlx_array_get_(a), std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_squeeze_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::squeeze(
            mlx_array_get_(a),
            std::vector<int>(axes, axes + axes_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_squeeze_axis(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::squeeze(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_squeeze_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::squeeze(mlx_array_get_(a), axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_squeeze(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::squeeze(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_stack_axis(mlx_array* res, const mlx_vector_array arrays, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::stack(mlx_vector_array_get_(arrays), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_stack_axis_x(
    mlx_array* res,
    const mlx_vector_array arrays,
    int axis,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::stack(
            mlx_vector_array_get_(arrays), axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_stack(mlx_array* res, const mlx_vector_array arrays) {
  try {
    mlx_array_set_(*res, mlx::core::stack(mlx_vector_array_get_(arrays)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_std_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::std(
            mlx_array_get_(a), std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_std_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    int ddof,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::std(
            mlx_array_get_(a),
            std::vector<int>(axes, axes + axes_num),
            keepdims,
            ddof,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_std_axis(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::std(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_std_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    int ddof,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::std(
            mlx_array_get_(a), axis, keepdims, ddof, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_std(mlx_array* res, const mlx_array a, bool keepdims) {
  try {
    mlx_array_set_(*res, mlx::core::std(mlx_array_get_(a), keepdims));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_stop_gradient(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::stop_gradient(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_stop_gradient_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::stop_gradient(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_subtract(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::subtract(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_subtract_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::subtract(
            mlx_array_get_(a), mlx_array_get_(b), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sum_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::sum(
            mlx_array_get_(a), std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sum_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::sum(
            mlx_array_get_(a),
            std::vector<int>(axes, axes + axes_num),
            keepdims,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sum_axis(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::sum(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sum_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::sum(mlx_array_get_(a), axis, keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sum(mlx_array* res, const mlx_array a, bool keepdims) {
  try {
    mlx_array_set_(*res, mlx::core::sum(mlx_array_get_(a), keepdims));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_swapaxes(mlx_array* res, const mlx_array a, int axis1, int axis2) {
  try {
    mlx_array_set_(*res, mlx::core::swapaxes(mlx_array_get_(a), axis1, axis2));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_swapaxes_x(
    mlx_array* res,
    const mlx_array a,
    int axis1,
    int axis2,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::swapaxes(
            mlx_array_get_(a), axis1, axis2, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_take_axis(
    mlx_array* res,
    const mlx_array a,
    const mlx_array indices,
    int axis) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::take(mlx_array_get_(a), mlx_array_get_(indices), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_take_axis_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array indices,
    int axis,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::take(
            mlx_array_get_(a),
            mlx_array_get_(indices),
            axis,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_take(mlx_array* res, const mlx_array a, const mlx_array indices) {
  try {
    mlx_array_set_(
        *res, mlx::core::take(mlx_array_get_(a), mlx_array_get_(indices)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_take_along_axis(
    mlx_array* res,
    const mlx_array a,
    const mlx_array indices,
    int axis) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::take_along_axis(
            mlx_array_get_(a), mlx_array_get_(indices), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_take_along_axis_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array indices,
    int axis,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::take_along_axis(
            mlx_array_get_(a),
            mlx_array_get_(indices),
            axis,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tan(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::tan(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_tan_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(*res, mlx::core::tan(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tanh(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::tanh(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_tanh_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::tanh(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tensordot(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const int* axes_a,
    size_t axes_a_num,
    const int* axes_b,
    size_t axes_b_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::tensordot(
            mlx_array_get_(a),
            mlx_array_get_(b),
            std::vector<int>(axes_a, axes_a + axes_a_num),
            std::vector<int>(axes_b, axes_b + axes_b_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_tensordot_axis(mlx_array* res, const mlx_array a, const mlx_array b) {
  try {
    mlx_array_set_(
        *res, mlx::core::tensordot(mlx_array_get_(a), mlx_array_get_(b)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tensordot_axis_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    int axis,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::tensordot(
            mlx_array_get_(a), mlx_array_get_(b), axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tile(
    mlx_array* res,
    const mlx_array arr,
    const int* reps,
    size_t reps_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::tile(
            mlx_array_get_(arr), std::vector<int>(reps, reps + reps_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tile_x(
    mlx_array* res,
    const mlx_array arr,
    const int* reps,
    size_t reps_num,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::tile(
            mlx_array_get_(arr),
            std::vector<int>(reps, reps + reps_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_topk_axis(mlx_array* res, const mlx_array a, int k, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::topk(mlx_array_get_(a), k, axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_topk_axis_x(
    mlx_array* res,
    const mlx_array a,
    int k,
    int axis,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::topk(mlx_array_get_(a), k, axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_topk(mlx_array* res, const mlx_array a, int k) {
  try {
    mlx_array_set_(*res, mlx::core::topk(mlx_array_get_(a), k));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_trace_x(
    mlx_array* res,
    const mlx_array a,
    int offset,
    int axis1,
    int axis2,
    mlx_dtype dtype,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::trace(
            mlx_array_get_(a),
            offset,
            axis1,
            axis2,
            mlx_dtype_to_cpp(dtype),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_trace(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::trace(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_transpose_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::transpose(
            mlx_array_get_(a), std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_transpose_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::transpose(
            mlx_array_get_(a),
            std::vector<int>(axes, axes + axes_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_transpose(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::transpose(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tri_x(
    mlx_array* res,
    int n,
    int m,
    int k,
    mlx_dtype type,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::tri(n, m, k, mlx_dtype_to_cpp(type), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tri(mlx_array* res, int n, mlx_dtype type) {
  try {
    mlx_array_set_(*res, mlx::core::tri(n, mlx_dtype_to_cpp(type)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tril(mlx_array* res, const mlx_array x) {
  try {
    mlx_array_set_(*res, mlx::core::tril(mlx_array_get_(x)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_tril_x(mlx_array* res, const mlx_array x, int k, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::tril(mlx_array_get_(x), k, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_triu(mlx_array* res, const mlx_array x) {
  try {
    mlx_array_set_(*res, mlx::core::triu(mlx_array_get_(x)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_triu_x(mlx_array* res, const mlx_array x, int k, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::triu(mlx_array_get_(x), k, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_unflatten(
    mlx_array* res,
    const mlx_array a,
    int axis,
    const int* shape,
    size_t shape_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::unflatten(
            mlx_array_get_(a),
            axis,
            std::vector<int>(shape, shape + shape_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_unflatten_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    const int* shape,
    size_t shape_num,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::unflatten(
            mlx_array_get_(a),
            axis,
            std::vector<int>(shape, shape + shape_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_var_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::var(
            mlx_array_get_(a), std::vector<int>(axes, axes + axes_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_var_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    int ddof,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::var(
            mlx_array_get_(a),
            std::vector<int>(axes, axes + axes_num),
            keepdims,
            ddof,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_var_axis(mlx_array* res, const mlx_array a, int axis) {
  try {
    mlx_array_set_(*res, mlx::core::var(mlx_array_get_(a), axis));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_var_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    int ddof,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::var(
            mlx_array_get_(a), axis, keepdims, ddof, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_var(mlx_array* res, const mlx_array a, bool keepdims) {
  try {
    mlx_array_set_(*res, mlx::core::var(mlx_array_get_(a), keepdims));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_view(mlx_array* res, const mlx_array a, mlx_dtype dtype) {
  try {
    mlx_array_set_(
        *res, mlx::core::view(mlx_array_get_(a), mlx_dtype_to_cpp(dtype)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_view_x(
    mlx_array* res,
    const mlx_array a,
    mlx_dtype dtype,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::view(
            mlx_array_get_(a), mlx_dtype_to_cpp(dtype), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_where(
    mlx_array* res,
    const mlx_array condition,
    const mlx_array x,
    const mlx_array y) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::where(
            mlx_array_get_(condition), mlx_array_get_(x), mlx_array_get_(y)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_where_x(
    mlx_array* res,
    const mlx_array condition,
    const mlx_array x,
    const mlx_array y,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::where(
            mlx_array_get_(condition),
            mlx_array_get_(x),
            mlx_array_get_(y),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_zeros(mlx_array* res, const int* shape, size_t shape_num, mlx_dtype dtype) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::zeros(
            std::vector<int>(shape, shape + shape_num),
            mlx_dtype_to_cpp(dtype)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_zeros_x(
    mlx_array* res,
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::zeros(
            std::vector<int>(shape, shape + shape_num),
            mlx_dtype_to_cpp(dtype),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_zeros_like(mlx_array* res, const mlx_array a) {
  try {
    mlx_array_set_(*res, mlx::core::zeros_like(mlx_array_get_(a)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_zeros_like_x(mlx_array* res, const mlx_array a, const mlx_stream s) {
  try {
    mlx_array_set_(
        *res, mlx::core::zeros_like(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
