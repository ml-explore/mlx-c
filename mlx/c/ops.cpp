/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/ops.h"

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

extern "C" int mlx_abs(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::abs(a->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::add(a->ctx, b->ctx, s->ctx);
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
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::all(
        a->ctx, std::vector<int>(axes, axes + axes_num), keepdims, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::all(a->ctx, axis, keepdims, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::all(a->ctx, keepdims, s->ctx);
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
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::any(
        a->ctx, std::vector<int>(axes, axes + axes_num), keepdims, s->ctx);
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
    mlx_array res) {
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
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx =
        mlx::core::arange(start, stop, step, mlx_dtype_to_cpp(dtype), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_arccos(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::arccos(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_arccosh(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::arccosh(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_arcsin(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::arcsin(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_arcsinh(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::arcsinh(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_arctan(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::arctan(a->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::arctan2(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_arctanh(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::arctanh(a->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::argmax(a->ctx, axis, keepdims, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::argmax(a->ctx, keepdims, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::argmin(a->ctx, axis, keepdims, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::argmin(a->ctx, keepdims, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::argpartition(a->ctx, kth, axis, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::argpartition(a->ctx, kth, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_argsort(const mlx_array a, int axis, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::argsort(a->ctx, axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_argsort_all(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::argsort(a->ctx, s->ctx);
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
    const mlx_array a,
    const int* shape,
    size_t shape_num,
    const size_t* strides,
    size_t strides_num,
    size_t offset,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::as_strided(
        a->ctx,
        std::vector<int>(shape, shape + shape_num),
        std::vector<size_t>(strides, strides + strides_num),
        offset,
        s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::astype(a->ctx, mlx_dtype_to_cpp(dtype), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_atleast_1d(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::atleast_1d(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_atleast_2d(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::atleast_2d(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_atleast_3d(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::atleast_3d(a->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::bitwise_and(a->ctx, b->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::bitwise_or(a->ctx, b->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::bitwise_xor(a->ctx, b->ctx, s->ctx);
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
    const mlx_stream s,
    mlx_vector_array res) {
  try {
    res->ctx = mlx::core::broadcast_arrays(inputs->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::broadcast_to(
        a->ctx, std::vector<int>(shape, shape + shape_num), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_ceil(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::ceil(a->ctx, s->ctx);
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
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::concatenate(arrays->ctx, axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_concatenate_all(
    const mlx_vector_array arrays,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::concatenate(arrays->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_conjugate(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::conjugate(a->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::conv2d(
        input->ctx,
        weight->ctx,
        std::make_pair(stride_0, stride_1),
        std::make_pair(padding_0, padding_1),
        std::make_pair(dilation_0, dilation_1),
        groups,
        s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::conv3d(
        input->ctx,
        weight->ctx,
        std::make_tuple(stride_0, stride_1, stride_2),
        std::make_tuple(padding_0, padding_1, padding_2),
        std::make_tuple(dilation_0, dilation_1, dilation_2),
        groups,
        s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::conv_general(
        input->ctx,
        weight->ctx,
        std::vector<int>(stride, stride + stride_num),
        std::vector<int>(padding_lo, padding_lo + padding_lo_num),
        std::vector<int>(padding_hi, padding_hi + padding_hi_num),
        std::vector<int>(
            kernel_dilation, kernel_dilation + kernel_dilation_num),
        std::vector<int>(input_dilation, input_dilation + input_dilation_num),
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
    const mlx_array input,
    const mlx_array weight,
    int stride,
    int padding,
    int dilation,
    int groups,
    const mlx_stream s,
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::conv_transpose2d(
        input->ctx,
        weight->ctx,
        std::make_pair(stride_0, stride_1),
        std::make_pair(padding_0, padding_1),
        std::make_pair(dilation_0, dilation_1),
        groups,
        s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::conv_transpose3d(
        input->ctx,
        weight->ctx,
        std::make_tuple(stride_0, stride_1, stride_2),
        std::make_tuple(padding_0, padding_1, padding_2),
        std::make_tuple(dilation_0, dilation_1, dilation_2),
        groups,
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_copy(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::copy(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cos(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::cos(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_cosh(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::cosh(a->ctx, s->ctx);
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
    const mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    const mlx_stream s,
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
    const mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    const mlx_stream s,
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
    const mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::cumsum(a->ctx, axis, reverse, inclusive, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_degrees(const mlx_array a, const mlx_stream s, mlx_array res) {
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
    res->ctx = mlx::core::depends(inputs->ctx, dependencies->ctx);
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
extern "C" int
mlx_diag(const mlx_array a, int k, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::diag(a->ctx, k, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::diagonal(a->ctx, offset, axis1, axis2, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::divide(a->ctx, b->ctx, s->ctx);
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
    mlx_vector_array res) {
  try {
    res->ctx = mlx::core::divmod(a->ctx, b->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::equal(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_erf(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::erf(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_erfinv(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::erfinv(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_exp(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::exp(a->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::expand_dims(
        a->ctx, std::vector<int>(axes, axes + axes_num), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_expm1(const mlx_array a, const mlx_stream s, mlx_array res) {
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
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::eye(n, m, k, mlx_dtype_to_cpp(dtype), s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::flatten(a->ctx, start_axis, end_axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_floor(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::floor(a->ctx, s->ctx);
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
    mlx_array res) {
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
    size_t shape_num,
    const mlx_array vals,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::full(
        std::vector<int>(shape, shape + shape_num),
        vals->ctx,
        mlx_dtype_to_cpp(dtype),
        s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::gather(
        a->ctx,
        indices->ctx,
        std::vector<int>(axes, axes + axes_num),
        std::vector<int>(slice_sizes, slice_sizes + slice_sizes_num),
        s->ctx);
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
extern "C" int mlx_greater(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::greater(a->ctx, b->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::greater_equal(a->ctx, b->ctx, s->ctx);
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
mlx_identity(int n, mlx_dtype dtype, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::identity(n, mlx_dtype_to_cpp(dtype), s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::inner(a->ctx, b->ctx, s->ctx);
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
extern "C" int
mlx_isfinite(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::isfinite(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_isinf(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::isinf(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_isnan(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::isnan(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_isneginf(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::isneginf(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_isposinf(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::isposinf(a->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::left_shift(a->ctx, b->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::less(a->ctx, b->ctx, s->ctx);
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
    mlx_array res) {
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
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx =
        mlx::core::linspace(start, stop, num, mlx_dtype_to_cpp(dtype), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_log(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::log(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_log10(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::log10(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_log1p(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::log1p(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_log2(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::log2(a->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::logaddexp(a->ctx, b->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::logical_and(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_logical_not(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::logical_not(a->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::logical_or(a->ctx, b->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::logsumexp(
        a->ctx, std::vector<int>(axes, axes + axes_num), keepdims, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::logsumexp(a->ctx, keepdims, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::matmul(a->ctx, b->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::max(
        a->ctx, std::vector<int>(axes, axes + axes_num), keepdims, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::max(a->ctx, keepdims, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::maximum(a->ctx, b->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::mean(
        a->ctx, std::vector<int>(axes, axes + axes_num), keepdims, s->ctx);
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
    mlx_array res) {
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
    const char* indexing,
    const mlx_stream s,
    mlx_vector_array res) {
  try {
    res->ctx =
        mlx::core::meshgrid(arrays->ctx, sparse, std::string(indexing), s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::min(
        a->ctx, std::vector<int>(axes, axes + axes_num), keepdims, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::min(a->ctx, keepdims, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::minimum(a->ctx, b->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::moveaxis(a->ctx, source, destination, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::multiply(a->ctx, b->ctx, s->ctx);
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
extern "C" int
mlx_negative(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::negative(a->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::not_equal(a->ctx, b->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::number_of_elements(
        a->ctx,
        std::vector<int>(axes, axes + axes_num),
        inverted,
        mlx_dtype_to_cpp(dtype),
        s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::ones(
        std::vector<int>(shape, shape + shape_num),
        mlx_dtype_to_cpp(dtype),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_ones_like(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::ones_like(a->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::outer(a->ctx, b->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::pad(
        a->ctx,
        std::vector<int>(axes, axes + axes_num),
        std::vector<int>(low_pad_size, low_pad_size + low_pad_size_num),
        std::vector<int>(high_pad_size, high_pad_size + high_pad_size_num),
        pad_value->ctx,
        std::string(mode),
        s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::partition(a->ctx, kth, axis, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::partition(a->ctx, kth, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::power(a->ctx, b->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::prod(
        a->ctx, std::vector<int>(axes, axes + axes_num), keepdims, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::prod(a->ctx, keepdims, s->ctx);
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
    const mlx_array x,
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases,
    bool transpose,
    int group_size,
    int bits,
    const mlx_stream s,
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
extern "C" int
mlx_radians(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::radians(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_reciprocal(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::reciprocal(a->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::remainder(a->ctx, b->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::repeat(arr->ctx, repeats, axis, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::repeat(arr->ctx, repeats, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::reshape(
        a->ctx, std::vector<int>(shape, shape + shape_num), s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::right_shift(a->ctx, b->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_round(const mlx_array a, int decimals, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::round(a->ctx, decimals, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_rsqrt(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::rsqrt(a->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::scatter(
        a->ctx,
        indices->ctx,
        updates->ctx,
        std::vector<int>(axes, axes + axes_num),
        s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::scatter_add(
        a->ctx,
        indices->ctx,
        updates->ctx,
        std::vector<int>(axes, axes + axes_num),
        s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::scatter_max(
        a->ctx,
        indices->ctx,
        updates->ctx,
        std::vector<int>(axes, axes + axes_num),
        s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::scatter_min(
        a->ctx,
        indices->ctx,
        updates->ctx,
        std::vector<int>(axes, axes + axes_num),
        s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::scatter_prod(
        a->ctx,
        indices->ctx,
        updates->ctx,
        std::vector<int>(axes, axes + axes_num),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_sigmoid(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::sigmoid(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sign(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::sign(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sin(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::sin(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sinh(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::sinh(a->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::slice(
        a->ctx,
        std::vector<int>(start, start + start_num),
        std::vector<int>(stop, stop + stop_num),
        std::vector<int>(strides, strides + strides_num),
        s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::slice_update(
        src->ctx,
        update->ctx,
        std::vector<int>(start, start + start_num),
        std::vector<int>(stop, stop + stop_num),
        std::vector<int>(strides, strides + strides_num),
        s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::softmax(
        a->ctx, std::vector<int>(axes, axes + axes_num), precise, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::softmax(a->ctx, precise, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_sort(const mlx_array a, int axis, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::sort(a->ctx, axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_sort_all(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::sort(a->ctx, s->ctx);
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
    const mlx_array a,
    const int* indices,
    size_t indices_num,
    int axis,
    const mlx_stream s,
    mlx_vector_array res) {
  try {
    res->ctx = mlx::core::split(
        a->ctx, std::vector<int>(indices, indices + indices_num), axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_sqrt(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::sqrt(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_square(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::square(a->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::squeeze(
        a->ctx, std::vector<int>(axes, axes + axes_num), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_squeeze_all(const mlx_array a, const mlx_stream s, mlx_array res) {
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
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::stack(arrays->ctx, axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_stack_all(
    const mlx_vector_array arrays,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::stack(arrays->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::std(
        a->ctx,
        std::vector<int>(axes, axes + axes_num),
        keepdims,
        ddof,
        s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::std(a->ctx, keepdims, ddof, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_stop_gradient(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::stop_gradient(a->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::subtract(a->ctx, b->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::sum(
        a->ctx, std::vector<int>(axes, axes + axes_num), keepdims, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::sum(a->ctx, keepdims, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::swapaxes(a->ctx, axis1, axis2, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::take(a->ctx, indices->ctx, axis, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::take(a->ctx, indices->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::take_along_axis(a->ctx, indices->ctx, axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tan(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::tan(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_tanh(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::tanh(a->ctx, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::tensordot(
        a->ctx,
        b->ctx,
        std::vector<int>(axes_a, axes_a + axes_a_num),
        std::vector<int>(axes_b, axes_b + axes_b_num),
        s->ctx);
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
    const mlx_array arr,
    const int* reps,
    size_t reps_num,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::tile(
        arr->ctx, std::vector<int>(reps, reps + reps_num), s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::topk(a->ctx, k, axis, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_topk_all(const mlx_array a, int k, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::topk(a->ctx, k, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::trace(
        a->ctx, offset, axis1, axis2, mlx_dtype_to_cpp(dtype), s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::transpose(
        a->ctx, std::vector<int>(axes, axes + axes_num), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_transpose_all(const mlx_array a, const mlx_stream s, mlx_array res) {
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
    mlx_dtype type,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::tri(n, m, k, mlx_dtype_to_cpp(type), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_tril(const mlx_array x, int k, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::tril(x->ctx, k, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_triu(const mlx_array x, int k, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::triu(x->ctx, k, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::var(
        a->ctx,
        std::vector<int>(axes, axes + axes_num),
        keepdims,
        ddof,
        s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::var(a->ctx, keepdims, ddof, s->ctx);
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
    mlx_array res) {
  try {
    res->ctx = mlx::core::view(a->ctx, mlx_dtype_to_cpp(dtype), s->ctx);
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
    size_t shape_num,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::zeros(
        std::vector<int>(shape, shape + shape_num),
        mlx_dtype_to_cpp(dtype),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_zeros_like(const mlx_array a, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::zeros_like(a->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
