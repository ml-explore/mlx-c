/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_OPS_H
#define MLX_OPS_H

#include <stdio.h>

#include "mlx/c/array.h"
#include "mlx/c/closure.h"
#include "mlx/c/ioutils.h"
#include "mlx/c/map.h"
#include "mlx/c/stream.h"
#include "mlx/c/string.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup ops Core array operations
 */
/**@{*/
mlx_array mlx_abs(mlx_array a, mlx_stream s);
mlx_array mlx_add(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_addmm(
    mlx_array c,
    mlx_array a,
    mlx_array b,
    float alpha,
    float beta,
    mlx_stream s);
mlx_array mlx_all_axes(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array mlx_all_axis(mlx_array a, int axis, bool keepdims, mlx_stream s);
mlx_array mlx_all_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array mlx_allclose(
    mlx_array a,
    mlx_array b,
    double rtol,
    double atol,
    bool equal_nan,
    mlx_stream s);
mlx_array mlx_any(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array mlx_any_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array mlx_arange(
    double start,
    double stop,
    double step,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array mlx_arccos(mlx_array a, mlx_stream s);
mlx_array mlx_arccosh(mlx_array a, mlx_stream s);
mlx_array mlx_arcsin(mlx_array a, mlx_stream s);
mlx_array mlx_arcsinh(mlx_array a, mlx_stream s);
mlx_array mlx_arctan(mlx_array a, mlx_stream s);
mlx_array mlx_arctanh(mlx_array a, mlx_stream s);
mlx_array mlx_argmax(mlx_array a, int axis, bool keepdims, mlx_stream s);
mlx_array mlx_argmax_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array mlx_argmin(mlx_array a, int axis, bool keepdims, mlx_stream s);
mlx_array mlx_argmin_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array mlx_argpartition(mlx_array a, int kth, int axis, mlx_stream s);
mlx_array mlx_argpartition_all(mlx_array a, int kth, mlx_stream s);
mlx_array mlx_argsort(mlx_array a, int axis, mlx_stream s);
mlx_array mlx_argsort_all(mlx_array a, mlx_stream s);
mlx_array
mlx_array_equal(mlx_array a, mlx_array b, bool equal_nan, mlx_stream s);
mlx_array mlx_as_strided(
    mlx_array a,
    const int* shape,
    size_t num_shape,
    const size_t* strides,
    size_t num_strides,
    size_t offset,
    mlx_stream s);
mlx_array mlx_astype(mlx_array a, mlx_array_dtype dtype, mlx_stream s);
mlx_array mlx_atleast_1d(mlx_array a, mlx_stream s);
mlx_array mlx_atleast_2d(mlx_array a, mlx_stream s);
mlx_array mlx_atleast_3d(mlx_array a, mlx_stream s);
mlx_vector_array mlx_broadcast_arrays(
    const mlx_vector_array inputs,
    mlx_stream s);
mlx_array
mlx_broadcast_to(mlx_array a, const int* shape, size_t num_shape, mlx_stream s);
mlx_array mlx_ceil(mlx_array a, mlx_stream s);
mlx_array mlx_clip(mlx_array a, mlx_array a_min, mlx_array a_max, mlx_stream s);
mlx_array
mlx_concatenate(const mlx_vector_array arrays, int axis, mlx_stream s);
mlx_array mlx_concatenate_all(const mlx_vector_array arrays, mlx_stream s);
mlx_array mlx_conv1d(
    mlx_array input,
    mlx_array weight,
    int stride,
    int padding,
    int dilation,
    int groups,
    mlx_stream s);
mlx_array mlx_conv2d(
    mlx_array input,
    mlx_array weight,
    int f_stride,
    int s_stride,
    int f_padding,
    int s_padding,
    int f_dilation,
    int s_dilation,
    int groups,
    mlx_stream s);
mlx_array mlx_conv_general(
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
    mlx_stream s);
mlx_array mlx_copy(mlx_array a, mlx_stream s);
mlx_array mlx_cos(mlx_array a, mlx_stream s);
mlx_array mlx_cosh(mlx_array a, mlx_stream s);
mlx_array
mlx_cummax(mlx_array a, int axis, bool reverse, bool inclusive, mlx_stream s);
mlx_array
mlx_cummin(mlx_array a, int axis, bool reverse, bool inclusive, mlx_stream s);
mlx_array
mlx_cumprod(mlx_array a, int axis, bool reverse, bool inclusive, mlx_stream s);
mlx_array
mlx_cumsum(mlx_array a, int axis, bool reverse, bool inclusive, mlx_stream s);
mlx_vector_array mlx_depends(
    const mlx_vector_array inputs,
    const mlx_vector_array dependencies);
mlx_array mlx_dequantize(
    mlx_array w,
    mlx_array scales,
    mlx_array biases,
    int group_size,
    int bits,
    mlx_stream s);
mlx_array mlx_diag(mlx_array a, int k, mlx_stream s);
mlx_array
mlx_diagonal(mlx_array a, int offset, int axis1, int axis2, mlx_stream s);
mlx_array mlx_divide(mlx_array a, mlx_array b, mlx_stream s);
mlx_vector_array mlx_divmod(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_equal(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_erf(mlx_array a, mlx_stream s);
mlx_array mlx_erfinv(mlx_array a, mlx_stream s);
mlx_array mlx_exp(mlx_array a, mlx_stream s);
mlx_array
mlx_expand_dims(mlx_array a, const int* axes, size_t num_axes, mlx_stream s);
mlx_array mlx_eye(int n, int m, int k, mlx_array_dtype dtype, mlx_stream s);
mlx_array mlx_flatten(mlx_array a, int start_axis, int end_axis, mlx_stream s);
mlx_array mlx_floor(mlx_array a, mlx_stream s);
mlx_array mlx_floor_divide(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_full(
    const int* shape,
    size_t num_shape,
    mlx_array vals,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array mlx_gather(
    mlx_array a,
    const mlx_vector_array indices,
    const int* axes,
    size_t num_axes,
    const int* slice_sizes,
    size_t num_slice_sizes,
    mlx_stream s);
mlx_array mlx_greater(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_greater_equal(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_identity(int n, mlx_array_dtype dtype, mlx_stream s);
mlx_array mlx_inner(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_isclose(
    mlx_array a,
    mlx_array b,
    double rtol,
    double atol,
    bool equal_nan,
    mlx_stream s);
mlx_array mlx_isinf(mlx_array a, mlx_stream s);
mlx_array mlx_isnan(mlx_array a, mlx_stream s);
mlx_array mlx_isneginf(mlx_array a, mlx_stream s);
mlx_array mlx_isposinf(mlx_array a, mlx_stream s);
mlx_array mlx_less(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_less_equal(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_linspace(
    double start,
    double stop,
    int num,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array mlx_log(mlx_array a, mlx_stream s);
mlx_array mlx_log10(mlx_array a, mlx_stream s);
mlx_array mlx_log1p(mlx_array a, mlx_stream s);
mlx_array mlx_log2(mlx_array a, mlx_stream s);
mlx_array mlx_logaddexp(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_logical_and(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_logical_not(mlx_array a, mlx_stream s);
mlx_array mlx_logical_or(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_logsumexp(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array mlx_logsumexp_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array mlx_matmul(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_max(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array mlx_max_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array mlx_maximum(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_mean(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array mlx_mean_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array mlx_min(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array mlx_min_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array mlx_minimum(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_moveaxis(mlx_array a, int source, int destination, mlx_stream s);
mlx_array mlx_multiply(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_negative(mlx_array a, mlx_stream s);
mlx_array mlx_not_equal(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_number_of_elements(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool inverted,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array mlx_ones(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array mlx_ones_like(mlx_array a, mlx_stream s);
mlx_array mlx_outer(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_pad(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    const int* low_pad_size,
    size_t num_low_pad_size,
    const int* high_pad_size,
    size_t num_high_pad_size,
    mlx_array pad_value,
    mlx_stream s);
mlx_array mlx_partition(mlx_array a, int kth, int axis, mlx_stream s);
mlx_array mlx_partition_all(mlx_array a, int kth, mlx_stream s);
mlx_array mlx_power(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_prod(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array mlx_prod_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_vector_array
mlx_quantize(mlx_array w, int group_size, int bits, mlx_stream s);
mlx_array mlx_quantized_matmul(
    mlx_array x,
    mlx_array w,
    mlx_array scales,
    mlx_array biases,
    bool transpose,
    int group_size,
    int bits,
    mlx_stream s);
mlx_array mlx_reciprocal(mlx_array a, mlx_stream s);
mlx_array mlx_remainder(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_repeat(mlx_array arr, int repeats, int axis, mlx_stream s);
mlx_array mlx_repeat_all(mlx_array arr, int repeats, mlx_stream s);
mlx_array
mlx_reshape(mlx_array a, const int* shape, size_t num_shape, mlx_stream s);
mlx_array mlx_round(mlx_array a, int decimals, mlx_stream s);
mlx_array mlx_rsqrt(mlx_array a, mlx_stream s);
mlx_array mlx_scatter(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array mlx_scatter_add(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array mlx_scatter_max(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array mlx_scatter_min(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array mlx_scatter_prod(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array mlx_sigmoid(mlx_array a, mlx_stream s);
mlx_array mlx_sign(mlx_array a, mlx_stream s);
mlx_array mlx_sin(mlx_array a, mlx_stream s);
mlx_array mlx_sinh(mlx_array a, mlx_stream s);
mlx_array mlx_slice(
    mlx_array a,
    const int* start,
    size_t num_start,
    const int* stop,
    size_t num_stop,
    const int* strides,
    size_t num_strides,
    mlx_stream s);
mlx_array mlx_slice_update(
    mlx_array src,
    mlx_array update,
    const int* start,
    size_t num_start,
    const int* stop,
    size_t num_stop,
    const int* strides,
    size_t num_strides,
    mlx_stream s);
mlx_array
mlx_softmax(mlx_array a, const int* axes, size_t num_axes, mlx_stream s);
mlx_array mlx_softmax_all(mlx_array a, mlx_stream s);
mlx_array mlx_sort(mlx_array a, int axis, mlx_stream s);
mlx_array mlx_sort_all(mlx_array a, mlx_stream s);
mlx_vector_array
mlx_split_equal_parts(mlx_array a, int num_splits, int axis, mlx_stream s);
mlx_vector_array mlx_split(
    mlx_array a,
    const int* indices,
    size_t num_indices,
    int axis,
    mlx_stream s);
mlx_array mlx_sqrt(mlx_array a, mlx_stream s);
mlx_array mlx_square(mlx_array a, mlx_stream s);
mlx_array
mlx_squeeze(mlx_array a, const int* axes, size_t num_axes, mlx_stream s);
mlx_array mlx_squeeze_all(mlx_array a, mlx_stream s);
mlx_array mlx_stack(const mlx_vector_array arrays, int axis, mlx_stream s);
mlx_array mlx_stack_all(const mlx_vector_array arrays, mlx_stream s);
mlx_array mlx_stop_gradient(mlx_array a, mlx_stream s);
mlx_array mlx_subtract(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_sum(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array mlx_sum_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array mlx_swapaxes(mlx_array a, int axis1, int axis2, mlx_stream s);
mlx_array mlx_take(mlx_array a, mlx_array indices, int axis, mlx_stream s);
mlx_array mlx_take_all(mlx_array a, mlx_array indices, mlx_stream s);
mlx_array
mlx_take_along_axis(mlx_array a, mlx_array indices, int axis, mlx_stream s);
mlx_array mlx_tan(mlx_array a, mlx_stream s);
mlx_array mlx_tanh(mlx_array a, mlx_stream s);
mlx_array mlx_tensordot(
    mlx_array a,
    mlx_array b,
    const int* axes_a,
    size_t num_axes_a,
    const int* axes_b,
    size_t num_axes_b,
    mlx_stream s);
mlx_array
mlx_tensordot_along_axis(mlx_array a, mlx_array b, int axis, mlx_stream s);
mlx_array
mlx_tile(mlx_array arr, const int* reps, size_t num_reps, mlx_stream s);
mlx_array mlx_topk(mlx_array a, int k, int axis, mlx_stream s);
mlx_array mlx_topk_all(mlx_array a, int k, mlx_stream s);
mlx_array
mlx_transpose(mlx_array a, const int* axes, size_t num_axes, mlx_stream s);
mlx_array mlx_transpose_all(mlx_array a, mlx_stream s);
mlx_array mlx_tri(int n, int m, int k, mlx_array_dtype type, mlx_stream s);
mlx_array mlx_tril(mlx_array x, int k, mlx_stream s);
mlx_array mlx_triu(mlx_array x, int k, mlx_stream s);
mlx_array mlx_var(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    int ddof,
    mlx_stream s);
mlx_array mlx_var_all(mlx_array a, bool keepdims, int ddof, mlx_stream s);
mlx_array
mlx_where(mlx_array condition, mlx_array x, mlx_array y, mlx_stream s);
mlx_array mlx_zeros(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array mlx_zeros_like(mlx_array a, mlx_stream s);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
