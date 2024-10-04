/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/ops.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" int mlx_abs(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(*res, mlx::core::abs(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_add(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
    const mlx_array c,
    const mlx_array a,
    const mlx_array b,
    float alpha,
    float beta,
    const mlx_stream s,
    mlx_array* res) {
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
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_all_axis(
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_all_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::all(mlx_array_get_(a), keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_allclose(
    const mlx_array a,
    const mlx_array b,
    double rtol,
    double atol,
    bool equal_nan,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_any(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_any_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::any(mlx_array_get_(a), keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_arange(
    double start,
    double stop,
    double step,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int
mlx_arccos(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::arccos(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_arccosh(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::arccosh(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_arcsin(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::arcsin(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_arcsinh(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::arcsinh(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_arctan(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::arctan(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_arctan2(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int
mlx_arctanh(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::arctanh(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_argmax(
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_argmax_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::argmax(mlx_array_get_(a), keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_argmin(
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_argmin_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::argmin(mlx_array_get_(a), keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_argpartition(
    const mlx_array a,
    int kth,
    int axis,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_argpartition_all(
    const mlx_array a,
    int kth,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::argpartition(mlx_array_get_(a), kth, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_argsort(const mlx_array a, int axis, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::argsort(mlx_array_get_(a), axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_argsort_all(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::argsort(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_array_equal(
    const mlx_array a,
    const mlx_array b,
    bool equal_nan,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_as_strided(
    const mlx_array a,
    const int* shape,
    size_t shape_num,
    const size_t* strides,
    size_t strides_num,
    size_t offset,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::as_strided(
            mlx_array_get_(a),
            std::vector<int>(shape, shape + shape_num),
            std::vector<size_t>(strides, strides + strides_num),
            offset,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_astype(
    const mlx_array a,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int
mlx_atleast_1d(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::atleast_1d(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_atleast_2d(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::atleast_2d(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_atleast_3d(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::atleast_3d(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_bitwise_and(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_bitwise_or(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_bitwise_xor(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
    const mlx_array a,
    const mlx_array b,
    int block_size,
    const mlx_array mask_out /* may be null */,
    const mlx_array mask_lhs /* may be null */,
    const mlx_array mask_rhs /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
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
    const mlx_vector_array inputs,
    const mlx_stream s,
    mlx_vector_array* res) {
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
    const mlx_array a,
    const int* shape,
    size_t shape_num,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_ceil(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::ceil(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_clip(
    const mlx_array a,
    const mlx_array a_min /* may be null */,
    const mlx_array a_max /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_concatenate(
    const mlx_vector_array arrays,
    int axis,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_concatenate_all(
    const mlx_vector_array arrays,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::concatenate(
            mlx_vector_array_get_(arrays), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_conjugate(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::conjugate(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conv1d(
    const mlx_array input,
    const mlx_array weight,
    int stride,
    int padding,
    int dilation,
    int groups,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_conv2d(
    const mlx_array input,
    const mlx_array weight,
    int stride_0,
    int stride_1,
    int padding_0,
    int padding_1,
    int dilation_0,
    int dilation_1,
    int groups,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_conv3d(
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
    const mlx_stream s,
    mlx_array* res) {
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
    const mlx_stream s,
    mlx_array* res) {
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
    const mlx_array input,
    const mlx_array weight,
    int stride,
    int padding,
    int dilation,
    int groups,
    const mlx_stream s,
    mlx_array* res) {
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
    const mlx_array input,
    const mlx_array weight,
    int stride_0,
    int stride_1,
    int padding_0,
    int padding_1,
    int dilation_0,
    int dilation_1,
    int groups,
    const mlx_stream s,
    mlx_array* res) {
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
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_copy(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::copy(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cos(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(*res, mlx::core::cos(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cosh(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::cosh(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cummax(
    const mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_cummin(
    const mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_cumprod(
    const mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_cumsum(
    const mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int
mlx_degrees(const mlx_array a, const mlx_stream s, mlx_array* res) {
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
    const mlx_vector_array inputs,
    const mlx_vector_array dependencies,
    mlx_vector_array* res) {
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
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases,
    int group_size,
    int bits,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int
mlx_diag(const mlx_array a, int k, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::diag(mlx_array_get_(a), k, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_diagonal(
    const mlx_array a,
    int offset,
    int axis1,
    int axis2,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_divide(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_divmod(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_vector_array* res) {
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
    const char* subscripts,
    const mlx_vector_array operands,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_equal(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_erf(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(*res, mlx::core::erf(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_erfinv(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::erfinv(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_exp(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(*res, mlx::core::exp(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_expand_dims(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int
mlx_expm1(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::expm1(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_eye(
    int n,
    int m,
    int k,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_flatten(
    const mlx_array a,
    int start_axis,
    int end_axis,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int
mlx_floor(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::floor(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_floor_divide(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
    const int* shape,
    size_t shape_num,
    const mlx_array vals,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res) {
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
    const mlx_array a,
    const mlx_vector_array indices,
    const int* axes,
    size_t axes_num,
    const int* slice_sizes,
    size_t slice_sizes_num,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_gather_mm(
    const mlx_array a,
    const mlx_array b,
    const mlx_array lhs_indices /* may be null */,
    const mlx_array rhs_indices /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
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
    const mlx_array x,
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases,
    const mlx_array lhs_indices /* may be null */,
    const mlx_array rhs_indices /* may be null */,
    bool transpose,
    int group_size,
    int bits,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_greater(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_greater_equal(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_hadamard_transform(
    const mlx_array a,
    mlx_optional_float scale,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int
mlx_identity(int n, mlx_dtype dtype, const mlx_stream s, mlx_array* res) {
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
extern "C" int mlx_inner(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_isclose(
    const mlx_array a,
    const mlx_array b,
    double rtol,
    double atol,
    bool equal_nan,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int
mlx_isfinite(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::isfinite(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_isinf(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::isinf(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_isnan(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::isnan(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_isneginf(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::isneginf(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_isposinf(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::isposinf(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_left_shift(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_less(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_less_equal(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_linspace(
    double start,
    double stop,
    int num,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_log(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(*res, mlx::core::log(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_log10(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::log10(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_log1p(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::log1p(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_log2(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::log2(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_logaddexp(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_logical_and(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int
mlx_logical_not(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::logical_not(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_logical_or(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_logsumexp(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_logsumexp_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::logsumexp(mlx_array_get_(a), keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_matmul(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_max(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_max_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::max(mlx_array_get_(a), keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_maximum(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_mean(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_mean_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::mean(mlx_array_get_(a), keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_meshgrid(
    const mlx_vector_array arrays,
    bool sparse,
    const char* indexing,
    const mlx_stream s,
    mlx_vector_array* res) {
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
extern "C" int mlx_min(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_min_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::min(mlx_array_get_(a), keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_minimum(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_moveaxis(
    const mlx_array a,
    int source,
    int destination,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_multiply(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_nan_to_num(
    const mlx_array a,
    float nan,
    mlx_optional_float posinf,
    mlx_optional_float neginf,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int
mlx_negative(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::negative(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_not_equal(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool inverted,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_ones(
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int
mlx_ones_like(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::ones_like(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_outer(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    const int* low_pad_size,
    size_t low_pad_size_num,
    const int* high_pad_size,
    size_t high_pad_size_num,
    const mlx_array pad_value,
    const char* mode,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::pad(
            mlx_array_get_(a),
            std::vector<int>(axes, axes + axes_num),
            std::vector<int>(low_pad_size, low_pad_size + low_pad_size_num),
            std::vector<int>(high_pad_size, high_pad_size + high_pad_size_num),
            mlx_array_get_(pad_value),
            std::string(mode),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_partition(
    const mlx_array a,
    int kth,
    int axis,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_partition_all(
    const mlx_array a,
    int kth,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::partition(mlx_array_get_(a), kth, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_power(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_prod(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_prod_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::prod(mlx_array_get_(a), keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_put_along_axis(
    const mlx_array a,
    const mlx_array indices,
    const mlx_array values,
    int axis,
    const mlx_stream s,
    mlx_array* res) {
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
    const mlx_array w,
    int group_size,
    int bits,
    const mlx_stream s,
    mlx_array* res_0,
    mlx_array* res_1,
    mlx_array* res_2) {
  try {
    std::tie(
        mlx_array_get_(*res_0),
        mlx_array_get_(*res_1),
        mlx_array_get_(*res_2)) =
        mlx::core::quantize(
            mlx_array_get_(w), group_size, bits, mlx_stream_get_(s));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_quantized_matmul(
    const mlx_array x,
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases,
    bool transpose,
    int group_size,
    int bits,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int
mlx_radians(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::radians(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_reciprocal(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::reciprocal(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_remainder(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_repeat(
    const mlx_array arr,
    int repeats,
    int axis,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_repeat_all(
    const mlx_array arr,
    int repeats,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::repeat(mlx_array_get_(arr), repeats, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_reshape(
    const mlx_array a,
    const int* shape,
    size_t shape_num,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_right_shift(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int
mlx_round(const mlx_array a, int decimals, const mlx_stream s, mlx_array* res) {
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
extern "C" int
mlx_rsqrt(const mlx_array a, const mlx_stream s, mlx_array* res) {
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
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res) {
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
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_scatter_max(
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res) {
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
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res) {
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
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int
mlx_sigmoid(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::sigmoid(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sign(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::sign(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sin(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(*res, mlx::core::sin(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sinh(const mlx_array a, const mlx_stream s, mlx_array* res) {
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
    const mlx_array a,
    const int* start,
    size_t start_num,
    const int* stop,
    size_t stop_num,
    const int* strides,
    size_t strides_num,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::slice(
            mlx_array_get_(a),
            std::vector<int>(start, start + start_num),
            std::vector<int>(stop, stop + stop_num),
            std::vector<int>(strides, strides + strides_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_slice_update(
    const mlx_array src,
    const mlx_array update,
    const int* start,
    size_t start_num,
    const int* stop,
    size_t stop_num,
    const int* strides,
    size_t strides_num,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::slice_update(
            mlx_array_get_(src),
            mlx_array_get_(update),
            std::vector<int>(start, start + start_num),
            std::vector<int>(stop, stop + stop_num),
            std::vector<int>(strides, strides + strides_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_softmax(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool precise,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_softmax_all(
    const mlx_array a,
    bool precise,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::softmax(mlx_array_get_(a), precise, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_sort(const mlx_array a, int axis, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::sort(mlx_array_get_(a), axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_sort_all(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::sort(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_split_equal_parts(
    const mlx_array a,
    int num_splits,
    int axis,
    const mlx_stream s,
    mlx_vector_array* res) {
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
extern "C" int mlx_split(
    const mlx_array a,
    const int* indices,
    size_t indices_num,
    int axis,
    const mlx_stream s,
    mlx_vector_array* res) {
  try {
    mlx_vector_array_set_(
        *res,
        mlx::core::split(
            mlx_array_get_(a),
            std::vector<int>(indices, indices + indices_num),
            axis,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sqrt(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::sqrt(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_square(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::square(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_squeeze(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int
mlx_squeeze_all(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::squeeze(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_stack(
    const mlx_vector_array arrays,
    int axis,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_stack_all(
    const mlx_vector_array arrays,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::stack(mlx_vector_array_get_(arrays), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_std(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    int ddof,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_std_all(
    const mlx_array a,
    bool keepdims,
    int ddof,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::std(mlx_array_get_(a), keepdims, ddof, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_stop_gradient(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::stop_gradient(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_subtract(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_sum(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_sum_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::sum(mlx_array_get_(a), keepdims, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_swapaxes(
    const mlx_array a,
    int axis1,
    int axis2,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_take(
    const mlx_array a,
    const mlx_array indices,
    int axis,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_take_all(
    const mlx_array a,
    const mlx_array indices,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::take(
            mlx_array_get_(a), mlx_array_get_(indices), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_take_along_axis(
    const mlx_array a,
    const mlx_array indices,
    int axis,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_tan(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(*res, mlx::core::tan(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tanh(const mlx_array a, const mlx_stream s, mlx_array* res) {
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
    const mlx_array a,
    const mlx_array b,
    const int* axes_a,
    size_t axes_a_num,
    const int* axes_b,
    size_t axes_b_num,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::tensordot(
            mlx_array_get_(a),
            mlx_array_get_(b),
            std::vector<int>(axes_a, axes_a + axes_a_num),
            std::vector<int>(axes_b, axes_b + axes_b_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tensordot_along_axis(
    const mlx_array a,
    const mlx_array b,
    int axis,
    const mlx_stream s,
    mlx_array* res) {
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
    const mlx_array arr,
    const int* reps,
    size_t reps_num,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_topk(
    const mlx_array a,
    int k,
    int axis,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::topk(mlx_array_get_(a), k, axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_topk_all(const mlx_array a, int k, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::topk(mlx_array_get_(a), k, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_trace(
    const mlx_array a,
    int offset,
    int axis1,
    int axis2,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_transpose(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int
mlx_transpose_all(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::transpose(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tri(
    int n,
    int m,
    int k,
    mlx_dtype type,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int
mlx_tril(const mlx_array x, int k, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::tril(mlx_array_get_(x), k, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_triu(const mlx_array x, int k, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::triu(mlx_array_get_(x), k, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_var(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    int ddof,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_var_all(
    const mlx_array a,
    bool keepdims,
    int ddof,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::var(mlx_array_get_(a), keepdims, ddof, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_view(
    const mlx_array a,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res) {
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
    const mlx_array condition,
    const mlx_array x,
    const mlx_array y,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int mlx_zeros(
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res) {
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
extern "C" int
mlx_zeros_like(const mlx_array a, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        *res, mlx::core::zeros_like(mlx_array_get_(a), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
