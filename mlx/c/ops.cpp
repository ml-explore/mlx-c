/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/ops.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/future.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" int mlx_abs(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::abs(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_add(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::add(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_addmm(
    mlx_array c,
    mlx_array a,
    mlx_array b,
    float alpha,
    float beta,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::addmm(c->ctx, a->ctx, b->ctx, alpha, beta, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_all_axes(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::all(
        a->ctx, MLX_CPP_INTVEC(axes, num_axes), keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_all_axis(
    mlx_array a,
    int axis,
    bool keepdims,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::all(a->ctx, axis, keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_all_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::all(a->ctx, keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_allclose(
    mlx_array a,
    mlx_array b,
    double rtol,
    double atol,
    bool equal_nan,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx =
        mlx::core::allclose(a->ctx, b->ctx, rtol, atol, equal_nan, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_any(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::any(
        a->ctx, MLX_CPP_INTVEC(axes, num_axes), keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_any_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::any(a->ctx, keepdims, s->ctx);
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
    mlx_array_dtype dtype,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::arange(
        start, stop, step, MLX_CPP_ARRAY_DTYPE(dtype), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_arccos(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::arccos(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_arccosh(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::arccosh(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_arcsin(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::arcsin(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_arcsinh(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::arcsinh(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_arctan(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::arctan(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_arctan2(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::arctan2(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_arctanh(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::arctanh(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_argmax(mlx_array a, int axis, bool keepdims, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::argmax(a->ctx, axis, keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_argmax_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::argmax(a->ctx, keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_argmin(mlx_array a, int axis, bool keepdims, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::argmin(a->ctx, axis, keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_argmin_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::argmin(a->ctx, keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_argpartition(mlx_array a, int kth, int axis, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::argpartition(a->ctx, kth, axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_argpartition_all(mlx_array a, int kth, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::argpartition(a->ctx, kth, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_argsort(mlx_array a, int axis, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::argsort(a->ctx, axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_argsort_all(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::argsort(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_array_equal(
    mlx_array a,
    mlx_array b,
    bool equal_nan,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::array_equal(a->ctx, b->ctx, equal_nan, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_as_strided(
    mlx_array a,
    const int* shape,
    size_t num_shape,
    const size_t* strides,
    size_t num_strides,
    size_t offset,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::as_strided(
        a->ctx,
        MLX_CPP_INTVEC(shape, num_shape),
        MLX_CPP_SIZEVEC(strides, num_strides),
        offset,
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_astype(mlx_array a, mlx_array_dtype dtype, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::astype(a->ctx, MLX_CPP_ARRAY_DTYPE(dtype), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_atleast_1d(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::atleast_1d(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_atleast_2d(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::atleast_2d(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_atleast_3d(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::atleast_3d(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_bitwise_and(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::bitwise_and(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_bitwise_or(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::bitwise_or(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_bitwise_xor(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::bitwise_xor(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_block_masked_mm(
    mlx_array a,
    mlx_array b,
    int block_size,
    mlx_array mask_out,
    mlx_array mask_lhs,
    mlx_array mask_rhs,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::block_masked_mm(
        a->ctx,
        b->ctx,
        block_size,
        (mask_out ? std::make_optional(mask_out->ctx) : std::nullopt),
        (mask_lhs ? std::make_optional(mask_lhs->ctx) : std::nullopt),
        (mask_rhs ? std::make_optional(mask_rhs->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_broadcast_arrays(
    const mlx_vector_array inputs,
    mlx_stream s,
    mlx_vector_array res) {
  try {
    res->ctx = mlx::core::broadcast_arrays(MLX_CPP_ARRVEC(inputs), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_broadcast_to(
    mlx_array a,
    const int* shape,
    size_t num_shape,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::broadcast_to(
        a->ctx, MLX_CPP_INTVEC(shape, num_shape), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_ceil(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::ceil(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_clip(
    mlx_array a,
    mlx_array a_min,
    mlx_array a_max,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::clip(
        a->ctx,
        (a_min ? std::make_optional(a_min->ctx) : std::nullopt),
        (a_max ? std::make_optional(a_max->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_concatenate(
    const mlx_vector_array arrays,
    int axis,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::concatenate(MLX_CPP_ARRVEC(arrays), axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_concatenate_all(
    const mlx_vector_array arrays,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::concatenate(MLX_CPP_ARRVEC(arrays), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conjugate(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::conjugate(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conv1d(
    mlx_array input,
    mlx_array weight,
    int stride,
    int padding,
    int dilation,
    int groups,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::conv1d(
        input->ctx, weight->ctx, stride, padding, dilation, groups, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conv2d(
    mlx_array input,
    mlx_array weight,
    int f_stride,
    int s_stride,
    int f_padding,
    int s_padding,
    int f_dilation,
    int s_dilation,
    int groups,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::conv2d(
        input->ctx,
        weight->ctx,
        MLX_CPP_INTPAIR(f_stride, s_stride),
        MLX_CPP_INTPAIR(f_padding, s_padding),
        MLX_CPP_INTPAIR(f_dilation, s_dilation),
        groups,
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conv3d(
    mlx_array input,
    mlx_array weight,
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
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::conv3d(
        input->ctx,
        weight->ctx,
        MLX_CPP_INTTUPLE3(stride_0, stride_1, stride_2),
        MLX_CPP_INTTUPLE3(padding_0, padding_1, padding_2),
        MLX_CPP_INTTUPLE3(dilation_0, dilation_1, dilation_2),
        groups,
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conv_general(
    mlx_array input,
    mlx_array weight,
    const int* stride,
    size_t num_stride,
    const int* padding_lo,
    size_t num_padding_lo,
    const int* padding_hi,
    size_t num_padding_hi,
    const int* kernel_dilation,
    size_t num_kernel_dilation,
    const int* input_dilation,
    size_t num_input_dilation,
    int groups,
    bool flip,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::conv_general(
        input->ctx,
        weight->ctx,
        MLX_CPP_INTVEC(stride, num_stride),
        MLX_CPP_INTVEC(padding_lo, num_padding_lo),
        MLX_CPP_INTVEC(padding_hi, num_padding_hi),
        MLX_CPP_INTVEC(kernel_dilation, num_kernel_dilation),
        MLX_CPP_INTVEC(input_dilation, num_input_dilation),
        groups,
        flip,
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conv_transpose1d(
    mlx_array input,
    mlx_array weight,
    int stride,
    int padding,
    int dilation,
    int groups,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::conv_transpose1d(
        input->ctx, weight->ctx, stride, padding, dilation, groups, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conv_transpose2d(
    mlx_array input,
    mlx_array weight,
    int f_stride,
    int s_stride,
    int f_padding,
    int s_padding,
    int f_dilation,
    int s_dilation,
    int groups,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::conv_transpose2d(
        input->ctx,
        weight->ctx,
        MLX_CPP_INTPAIR(f_stride, s_stride),
        MLX_CPP_INTPAIR(f_padding, s_padding),
        MLX_CPP_INTPAIR(f_dilation, s_dilation),
        groups,
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_conv_transpose3d(
    mlx_array input,
    mlx_array weight,
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
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::conv_transpose3d(
        input->ctx,
        weight->ctx,
        MLX_CPP_INTTUPLE3(stride_0, stride_1, stride_2),
        MLX_CPP_INTTUPLE3(padding_0, padding_1, padding_2),
        MLX_CPP_INTTUPLE3(dilation_0, dilation_1, dilation_2),
        groups,
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_copy(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::copy(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cos(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::cos(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cosh(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::cosh(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cummax(
    mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::cummax(a->ctx, axis, reverse, inclusive, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cummin(
    mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::cummin(a->ctx, axis, reverse, inclusive, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cumprod(
    mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::cumprod(a->ctx, axis, reverse, inclusive, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cumsum(
    mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::cumsum(a->ctx, axis, reverse, inclusive, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_degrees(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::degrees(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_depends(
    const mlx_vector_array inputs,
    const mlx_vector_array dependencies,
    mlx_vector_array res) {
  try {
    res->ctx = mlx::core::depends(
        MLX_CPP_ARRVEC(inputs), MLX_CPP_ARRVEC(dependencies));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_dequantize(
    mlx_array w,
    mlx_array scales,
    mlx_array biases,
    int group_size,
    int bits,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::dequantize(
        w->ctx, scales->ctx, biases->ctx, group_size, bits, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_diag(mlx_array a, int k, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::diag(a->ctx, k, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_diagonal(
    mlx_array a,
    int offset,
    int axis1,
    int axis2,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::diagonal(a->ctx, offset, axis1, axis2, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_divide(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::divide(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_divmod(mlx_array a, mlx_array b, mlx_stream s, mlx_vector_array res) {
  try {
    res->ctx = mlx::core::divmod(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_equal(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::equal(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_erf(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::erf(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_erfinv(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::erfinv(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_exp(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::exp(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_expand_dims(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx =
        mlx::core::expand_dims(a->ctx, MLX_CPP_INTVEC(axes, num_axes), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_expm1(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::expm1(a->ctx, s->ctx);
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
    mlx_array_dtype dtype,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::eye(n, m, k, MLX_CPP_ARRAY_DTYPE(dtype), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_flatten(
    mlx_array a,
    int start_axis,
    int end_axis,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::flatten(a->ctx, start_axis, end_axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_floor(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::floor(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_floor_divide(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::floor_divide(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_full(
    const int* shape,
    size_t num_shape,
    mlx_array vals,
    mlx_array_dtype dtype,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::full(
        MLX_CPP_INTVEC(shape, num_shape),
        vals->ctx,
        MLX_CPP_ARRAY_DTYPE(dtype),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_gather(
    mlx_array a,
    const mlx_vector_array indices,
    const int* axes,
    size_t num_axes,
    const int* slice_sizes,
    size_t num_slice_sizes,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::gather(
        a->ctx,
        MLX_CPP_ARRVEC(indices),
        MLX_CPP_INTVEC(axes, num_axes),
        MLX_CPP_INTVEC(slice_sizes, num_slice_sizes),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_gather_mm(
    mlx_array a,
    mlx_array b,
    mlx_array lhs_indices,
    mlx_array rhs_indices,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::gather_mm(
        a->ctx,
        b->ctx,
        (lhs_indices ? std::make_optional(lhs_indices->ctx) : std::nullopt),
        (rhs_indices ? std::make_optional(rhs_indices->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_gather_qmm(
    mlx_array x,
    mlx_array w,
    mlx_array scales,
    mlx_array biases,
    mlx_array lhs_indices,
    mlx_array rhs_indices,
    bool transpose,
    int group_size,
    int bits,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::gather_qmm(
        x->ctx,
        w->ctx,
        scales->ctx,
        biases->ctx,
        (lhs_indices ? std::make_optional(lhs_indices->ctx) : std::nullopt),
        (rhs_indices ? std::make_optional(rhs_indices->ctx) : std::nullopt),
        transpose,
        group_size,
        bits,
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_greater(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::greater(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_greater_equal(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::greater_equal(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_hadamard_transform(
    mlx_array a,
    mlx_optional_float scale,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::hadamard_transform(
        a->ctx,
        (scale.has_value ? std::make_optional<float>(scale.value)
                         : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_identity(int n, mlx_array_dtype dtype, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::identity(n, MLX_CPP_ARRAY_DTYPE(dtype), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_inner(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::inner(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_isclose(
    mlx_array a,
    mlx_array b,
    double rtol,
    double atol,
    bool equal_nan,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx =
        mlx::core::isclose(a->ctx, b->ctx, rtol, atol, equal_nan, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_isfinite(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::isfinite(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_isinf(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::isinf(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_isnan(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::isnan(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_isneginf(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::isneginf(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_isposinf(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::isposinf(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_left_shift(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::left_shift(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_less(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::less(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_less_equal(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::less_equal(a->ctx, b->ctx, s->ctx);
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
    mlx_array_dtype dtype,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::linspace(
        start, stop, num, MLX_CPP_ARRAY_DTYPE(dtype), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_log(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::log(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_log10(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::log10(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_log1p(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::log1p(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_log2(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::log2(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_logaddexp(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::logaddexp(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_logical_and(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::logical_and(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_logical_not(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::logical_not(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_logical_or(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::logical_or(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_logsumexp(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::logsumexp(
        a->ctx, MLX_CPP_INTVEC(axes, num_axes), keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_logsumexp_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::logsumexp(a->ctx, keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_matmul(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::matmul(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_max(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::max(
        a->ctx, MLX_CPP_INTVEC(axes, num_axes), keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_max_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::max(a->ctx, keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_maximum(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::maximum(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_mean(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::mean(
        a->ctx, MLX_CPP_INTVEC(axes, num_axes), keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_mean_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::mean(a->ctx, keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_meshgrid(
    const mlx_vector_array arrays,
    bool sparse,
    mlx_string indexing,
    mlx_stream s,
    mlx_vector_array res) {
  try {
    res->ctx = mlx::core::meshgrid(
        MLX_CPP_ARRVEC(arrays), sparse, MLX_CPP_STRING(indexing), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_min(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::min(
        a->ctx, MLX_CPP_INTVEC(axes, num_axes), keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_min_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::min(a->ctx, keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_minimum(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::minimum(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_moveaxis(
    mlx_array a,
    int source,
    int destination,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::moveaxis(a->ctx, source, destination, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_multiply(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::multiply(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_nan_to_num(
    mlx_array a,
    float nan,
    mlx_optional_float posinf,
    mlx_optional_float neginf,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::nan_to_num(
        a->ctx,
        nan,
        (posinf.has_value ? std::make_optional<float>(posinf.value)
                          : std::nullopt),
        (neginf.has_value ? std::make_optional<float>(neginf.value)
                          : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_negative(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::negative(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_not_equal(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::not_equal(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_number_of_elements(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool inverted,
    mlx_array_dtype dtype,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::number_of_elements(
        a->ctx,
        MLX_CPP_INTVEC(axes, num_axes),
        inverted,
        MLX_CPP_ARRAY_DTYPE(dtype),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_ones(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::ones(
        MLX_CPP_INTVEC(shape, num_shape), MLX_CPP_ARRAY_DTYPE(dtype), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_ones_like(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::ones_like(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_outer(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::outer(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_pad(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    const int* low_pad_size,
    size_t num_low_pad_size,
    const int* high_pad_size,
    size_t num_high_pad_size,
    mlx_array pad_value,
    mlx_string mode,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::pad(
        a->ctx,
        MLX_CPP_INTVEC(axes, num_axes),
        MLX_CPP_INTVEC(low_pad_size, num_low_pad_size),
        MLX_CPP_INTVEC(high_pad_size, num_high_pad_size),
        pad_value->ctx,
        MLX_CPP_STRING(mode),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_partition(mlx_array a, int kth, int axis, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::partition(a->ctx, kth, axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_partition_all(mlx_array a, int kth, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::partition(a->ctx, kth, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_power(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::power(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_prod(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::prod(
        a->ctx, MLX_CPP_INTVEC(axes, num_axes), keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_prod_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::prod(a->ctx, keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_quantize(
    mlx_array w,
    int group_size,
    int bits,
    mlx_stream s,
    mlx_array res_0,
    mlx_array res_1,
    mlx_array res_2) {
  try {
    std::tie(res_0->ctx, res_1->ctx, res_2->ctx) =
        mlx::core::quantize(w->ctx, group_size, bits, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_quantized_matmul(
    mlx_array x,
    mlx_array w,
    mlx_array scales,
    mlx_array biases,
    bool transpose,
    int group_size,
    int bits,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::quantized_matmul(
        x->ctx,
        w->ctx,
        scales->ctx,
        biases->ctx,
        transpose,
        group_size,
        bits,
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_radians(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::radians(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_reciprocal(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::reciprocal(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_remainder(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::remainder(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_repeat(mlx_array arr, int repeats, int axis, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::repeat(arr->ctx, repeats, axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_repeat_all(mlx_array arr, int repeats, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::repeat(arr->ctx, repeats, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_reshape(
    mlx_array a,
    const int* shape,
    size_t num_shape,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx =
        mlx::core::reshape(a->ctx, MLX_CPP_INTVEC(shape, num_shape), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_right_shift(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::right_shift(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_round(mlx_array a, int decimals, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::round(a->ctx, decimals, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_rsqrt(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::rsqrt(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_scatter(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::scatter(
        a->ctx,
        MLX_CPP_ARRVEC(indices),
        updates->ctx,
        MLX_CPP_INTVEC(axes, num_axes),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_scatter_add(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::scatter_add(
        a->ctx,
        MLX_CPP_ARRVEC(indices),
        updates->ctx,
        MLX_CPP_INTVEC(axes, num_axes),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_scatter_max(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::scatter_max(
        a->ctx,
        MLX_CPP_ARRVEC(indices),
        updates->ctx,
        MLX_CPP_INTVEC(axes, num_axes),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_scatter_min(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::scatter_min(
        a->ctx,
        MLX_CPP_ARRVEC(indices),
        updates->ctx,
        MLX_CPP_INTVEC(axes, num_axes),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_scatter_prod(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::scatter_prod(
        a->ctx,
        MLX_CPP_ARRVEC(indices),
        updates->ctx,
        MLX_CPP_INTVEC(axes, num_axes),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sigmoid(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::sigmoid(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sign(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::sign(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sin(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::sin(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sinh(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::sinh(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_slice(
    mlx_array a,
    const int* start,
    size_t num_start,
    const int* stop,
    size_t num_stop,
    const int* strides,
    size_t num_strides,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::slice(
        a->ctx,
        MLX_CPP_INTVEC(start, num_start),
        MLX_CPP_INTVEC(stop, num_stop),
        MLX_CPP_INTVEC(strides, num_strides),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_slice_update(
    mlx_array src,
    mlx_array update,
    const int* start,
    size_t num_start,
    const int* stop,
    size_t num_stop,
    const int* strides,
    size_t num_strides,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::slice_update(
        src->ctx,
        update->ctx,
        MLX_CPP_INTVEC(start, num_start),
        MLX_CPP_INTVEC(stop, num_stop),
        MLX_CPP_INTVEC(strides, num_strides),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_softmax(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool precise,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::softmax(
        a->ctx, MLX_CPP_INTVEC(axes, num_axes), precise, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_softmax_all(mlx_array a, bool precise, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::softmax(a->ctx, precise, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sort(mlx_array a, int axis, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::sort(a->ctx, axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sort_all(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::sort(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_split_equal_parts(
    mlx_array a,
    int num_splits,
    int axis,
    mlx_stream s,
    mlx_vector_array res) {
  try {
    res->ctx = mlx::core::split(a->ctx, num_splits, axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_split(
    mlx_array a,
    const int* indices,
    size_t num_indices,
    int axis,
    mlx_stream s,
    mlx_vector_array res) {
  try {
    res->ctx = mlx::core::split(
        a->ctx, MLX_CPP_INTVEC(indices, num_indices), axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sqrt(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::sqrt(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_square(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::square(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_squeeze(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx =
        mlx::core::squeeze(a->ctx, MLX_CPP_INTVEC(axes, num_axes), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_squeeze_all(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::squeeze(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_stack(
    const mlx_vector_array arrays,
    int axis,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::stack(MLX_CPP_ARRVEC(arrays), axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_stack_all(const mlx_vector_array arrays, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::stack(MLX_CPP_ARRVEC(arrays), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_std(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    int ddof,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::std(
        a->ctx, MLX_CPP_INTVEC(axes, num_axes), keepdims, ddof, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_std_all(mlx_array a, bool keepdims, int ddof, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::std(a->ctx, keepdims, ddof, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_stop_gradient(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::stop_gradient(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_subtract(mlx_array a, mlx_array b, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::subtract(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sum(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::sum(
        a->ctx, MLX_CPP_INTVEC(axes, num_axes), keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_sum_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::sum(a->ctx, keepdims, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_swapaxes(mlx_array a, int axis1, int axis2, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::swapaxes(a->ctx, axis1, axis2, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_take(
    mlx_array a,
    mlx_array indices,
    int axis,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::take(a->ctx, indices->ctx, axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_take_all(mlx_array a, mlx_array indices, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::take(a->ctx, indices->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_take_along_axis(
    mlx_array a,
    mlx_array indices,
    int axis,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::take_along_axis(a->ctx, indices->ctx, axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tan(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::tan(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tanh(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::tanh(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tensordot(
    mlx_array a,
    mlx_array b,
    const int* axes_a,
    size_t num_axes_a,
    const int* axes_b,
    size_t num_axes_b,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::tensordot(
        a->ctx,
        b->ctx,
        MLX_CPP_INTVEC(axes_a, num_axes_a),
        MLX_CPP_INTVEC(axes_b, num_axes_b),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tensordot_along_axis(
    mlx_array a,
    mlx_array b,
    int axis,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::tensordot(a->ctx, b->ctx, axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tile(
    mlx_array arr,
    const int* reps,
    size_t num_reps,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx =
        mlx::core::tile(arr->ctx, MLX_CPP_INTVEC(reps, num_reps), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_topk(mlx_array a, int k, int axis, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::topk(a->ctx, k, axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_topk_all(mlx_array a, int k, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::topk(a->ctx, k, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_trace(
    mlx_array a,
    int offset,
    int axis1,
    int axis2,
    mlx_array_dtype dtype,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::trace(
        a->ctx, offset, axis1, axis2, MLX_CPP_ARRAY_DTYPE(dtype), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_transpose(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx =
        mlx::core::transpose(a->ctx, MLX_CPP_INTVEC(axes, num_axes), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_transpose_all(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::transpose(a->ctx, s->ctx);
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
    mlx_array_dtype type,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::tri(n, m, k, MLX_CPP_ARRAY_DTYPE(type), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tril(mlx_array x, int k, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::tril(x->ctx, k, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_triu(mlx_array x, int k, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::triu(x->ctx, k, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_var(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    int ddof,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::var(
        a->ctx, MLX_CPP_INTVEC(axes, num_axes), keepdims, ddof, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_var_all(mlx_array a, bool keepdims, int ddof, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::var(a->ctx, keepdims, ddof, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_view(mlx_array a, mlx_array_dtype dtype, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::view(a->ctx, MLX_CPP_ARRAY_DTYPE(dtype), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_where(
    mlx_array condition,
    mlx_array x,
    mlx_array y,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::where(condition->ctx, x->ctx, y->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_zeros(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::zeros(
        MLX_CPP_INTVEC(shape, num_shape), MLX_CPP_ARRAY_DTYPE(dtype), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_zeros_like(mlx_array a, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::zeros_like(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
