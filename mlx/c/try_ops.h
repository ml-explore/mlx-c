/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include <stdio.h>

#ifndef MLX_TRY_OPS_H
#define MLX_TRY_OPS_H
#include "mlx/c/result.h"

#include "mlx/c/array.h"
#include "mlx/c/closure.h"
#include "mlx/c/future.h"
#include "mlx/c/ioutils.h"
#include "mlx/c/map.h"
#include "mlx/c/stream.h"
#include "mlx/c/string.h"

#ifdef __cplusplus
extern "C" {
#endif

mlx_array_result mlx_try_abs(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_add(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_addmm(
    mlx_array c,
    mlx_array a,
    mlx_array b,
    float alpha,
    float beta,
    mlx_stream s);
mlx_array_result mlx_try_all_axes(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array_result
mlx_try_all_axis(mlx_array a, int axis, bool keepdims, mlx_stream s);
mlx_array_result mlx_try_all_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array_result mlx_try_allclose(
    mlx_array a,
    mlx_array b,
    double rtol,
    double atol,
    bool equal_nan,
    mlx_stream s);
mlx_array_result mlx_try_any(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array_result mlx_try_any_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array_result mlx_try_arange(
    double start,
    double stop,
    double step,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array_result mlx_try_arccos(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_arccosh(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_arcsin(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_arcsinh(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_arctan(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_arctan2(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_arctanh(mlx_array a, mlx_stream s);
mlx_array_result
mlx_try_argmax(mlx_array a, int axis, bool keepdims, mlx_stream s);
mlx_array_result mlx_try_argmax_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array_result
mlx_try_argmin(mlx_array a, int axis, bool keepdims, mlx_stream s);
mlx_array_result mlx_try_argmin_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array_result
mlx_try_argpartition(mlx_array a, int kth, int axis, mlx_stream s);
mlx_array_result mlx_try_argpartition_all(mlx_array a, int kth, mlx_stream s);
mlx_array_result mlx_try_argsort(mlx_array a, int axis, mlx_stream s);
mlx_array_result mlx_try_argsort_all(mlx_array a, mlx_stream s);
mlx_array_result
mlx_try_array_equal(mlx_array a, mlx_array b, bool equal_nan, mlx_stream s);
mlx_array_result mlx_try_as_strided(
    mlx_array a,
    const int* shape,
    size_t num_shape,
    const size_t* strides,
    size_t num_strides,
    size_t offset,
    mlx_stream s);
mlx_array_result
mlx_try_astype(mlx_array a, mlx_array_dtype dtype, mlx_stream s);
mlx_array_result mlx_try_atleast_1d(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_atleast_2d(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_atleast_3d(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_bitwise_and(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_bitwise_or(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_bitwise_xor(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_block_masked_mm(
    mlx_array a,
    mlx_array b,
    int block_size,
    mlx_array mask_out,
    mlx_array mask_lhs,
    mlx_array mask_rhs,
    mlx_stream s);
mlx_vector_array_result mlx_try_broadcast_arrays(
    const mlx_vector_array inputs,
    mlx_stream s);
mlx_array_result mlx_try_broadcast_to(
    mlx_array a,
    const int* shape,
    size_t num_shape,
    mlx_stream s);
mlx_array_result mlx_try_ceil(mlx_array a, mlx_stream s);
mlx_array_result
mlx_try_clip(mlx_array a, mlx_array a_min, mlx_array a_max, mlx_stream s);
mlx_array_result
mlx_try_concatenate(const mlx_vector_array arrays, int axis, mlx_stream s);
mlx_array_result mlx_try_concatenate_all(
    const mlx_vector_array arrays,
    mlx_stream s);
mlx_array_result mlx_try_conjugate(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_conv1d(
    mlx_array input,
    mlx_array weight,
    int stride,
    int padding,
    int dilation,
    int groups,
    mlx_stream s);
mlx_array_result mlx_try_conv2d(
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
mlx_array_result mlx_try_conv3d(
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
    mlx_stream s);
mlx_array_result mlx_try_conv_general(
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
mlx_array_result mlx_try_copy(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_cos(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_cosh(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_cummax(
    mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    mlx_stream s);
mlx_array_result mlx_try_cummin(
    mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    mlx_stream s);
mlx_array_result mlx_try_cumprod(
    mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    mlx_stream s);
mlx_array_result mlx_try_cumsum(
    mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    mlx_stream s);
mlx_array_result mlx_try_degrees(mlx_array a, mlx_stream s);
mlx_vector_array_result mlx_try_depends(
    const mlx_vector_array inputs,
    const mlx_vector_array dependencies);
mlx_array_result mlx_try_dequantize(
    mlx_array w,
    mlx_array scales,
    mlx_array biases,
    int group_size,
    int bits,
    mlx_stream s);
mlx_array_result mlx_try_diag(mlx_array a, int k, mlx_stream s);
mlx_array_result
mlx_try_diagonal(mlx_array a, int offset, int axis1, int axis2, mlx_stream s);
mlx_array_result mlx_try_divide(mlx_array a, mlx_array b, mlx_stream s);
mlx_vector_array_result mlx_try_divmod(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_equal(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_erf(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_erfinv(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_exp(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_expand_dims(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_try_expm1(mlx_array a, mlx_stream s);
mlx_array_result
mlx_try_eye(int n, int m, int k, mlx_array_dtype dtype, mlx_stream s);
mlx_array_result
mlx_try_flatten(mlx_array a, int start_axis, int end_axis, mlx_stream s);
mlx_array_result mlx_try_floor(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_floor_divide(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_full(
    const int* shape,
    size_t num_shape,
    mlx_array vals,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array_result mlx_try_gather(
    mlx_array a,
    const mlx_vector_array indices,
    const int* axes,
    size_t num_axes,
    const int* slice_sizes,
    size_t num_slice_sizes,
    mlx_stream s);
mlx_array_result mlx_try_gather_mm(
    mlx_array a,
    mlx_array b,
    mlx_array lhs_indices,
    mlx_array rhs_indices,
    mlx_stream s);
mlx_array_result mlx_try_gather_qmm(
    mlx_array x,
    mlx_array w,
    mlx_array scales,
    mlx_array biases,
    mlx_array lhs_indices,
    mlx_array rhs_indices,
    bool transpose,
    int group_size,
    int bits,
    mlx_stream s);
mlx_array_result mlx_try_greater(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_greater_equal(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_identity(int n, mlx_array_dtype dtype, mlx_stream s);
mlx_array_result mlx_try_inner(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_isclose(
    mlx_array a,
    mlx_array b,
    double rtol,
    double atol,
    bool equal_nan,
    mlx_stream s);
mlx_array_result mlx_try_isinf(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_isnan(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_isneginf(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_isposinf(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_left_shift(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_less(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_less_equal(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_linspace(
    double start,
    double stop,
    int num,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array_result mlx_try_log(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_log10(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_log1p(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_log2(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_logaddexp(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_logical_and(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_logical_not(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_logical_or(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_logsumexp(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array_result
mlx_try_logsumexp_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array_result mlx_try_matmul(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_max(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array_result mlx_try_max_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array_result mlx_try_maximum(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_mean(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array_result mlx_try_mean_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_vector_array_result mlx_try_meshgrid(
    const mlx_vector_array arrays,
    bool sparse,
    mlx_string indexing,
    mlx_stream s);
mlx_array_result mlx_try_min(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array_result mlx_try_min_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array_result mlx_try_minimum(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result
mlx_try_moveaxis(mlx_array a, int source, int destination, mlx_stream s);
mlx_array_result mlx_try_multiply(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_negative(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_not_equal(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_number_of_elements(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool inverted,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array_result mlx_try_ones(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array_result mlx_try_ones_like(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_outer(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_pad(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    const int* low_pad_size,
    size_t num_low_pad_size,
    const int* high_pad_size,
    size_t num_high_pad_size,
    mlx_array pad_value,
    mlx_stream s);
mlx_array_result
mlx_try_partition(mlx_array a, int kth, int axis, mlx_stream s);
mlx_array_result mlx_try_partition_all(mlx_array a, int kth, mlx_stream s);
mlx_array_result mlx_try_power(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_prod(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array_result mlx_try_prod_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_vector_array_result
mlx_try_quantize(mlx_array w, int group_size, int bits, mlx_stream s);
mlx_array_result mlx_try_quantized_matmul(
    mlx_array x,
    mlx_array w,
    mlx_array scales,
    mlx_array biases,
    bool transpose,
    int group_size,
    int bits,
    mlx_stream s);
mlx_array_result mlx_try_radians(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_reciprocal(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_remainder(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result
mlx_try_repeat(mlx_array arr, int repeats, int axis, mlx_stream s);
mlx_array_result mlx_try_repeat_all(mlx_array arr, int repeats, mlx_stream s);
mlx_array_result
mlx_try_reshape(mlx_array a, const int* shape, size_t num_shape, mlx_stream s);
mlx_array_result mlx_try_right_shift(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_round(mlx_array a, int decimals, mlx_stream s);
mlx_array_result mlx_try_rsqrt(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_scatter(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_try_scatter_add(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_try_scatter_max(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_try_scatter_min(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_try_scatter_prod(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_try_sigmoid(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_sign(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_sin(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_sinh(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_slice(
    mlx_array a,
    const int* start,
    size_t num_start,
    const int* stop,
    size_t num_stop,
    const int* strides,
    size_t num_strides,
    mlx_stream s);
mlx_array_result mlx_try_slice_update(
    mlx_array src,
    mlx_array update,
    const int* start,
    size_t num_start,
    const int* stop,
    size_t num_stop,
    const int* strides,
    size_t num_strides,
    mlx_stream s);
mlx_array_result mlx_try_softmax(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool precise,
    mlx_stream s);
mlx_array_result mlx_try_softmax_all(mlx_array a, bool precise, mlx_stream s);
mlx_array_result mlx_try_sort(mlx_array a, int axis, mlx_stream s);
mlx_array_result mlx_try_sort_all(mlx_array a, mlx_stream s);
mlx_vector_array_result
mlx_try_split_equal_parts(mlx_array a, int num_splits, int axis, mlx_stream s);
mlx_vector_array_result mlx_try_split(
    mlx_array a,
    const int* indices,
    size_t num_indices,
    int axis,
    mlx_stream s);
mlx_array_result mlx_try_sqrt(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_square(mlx_array a, mlx_stream s);
mlx_array_result
mlx_try_squeeze(mlx_array a, const int* axes, size_t num_axes, mlx_stream s);
mlx_array_result mlx_try_squeeze_all(mlx_array a, mlx_stream s);
mlx_array_result
mlx_try_stack(const mlx_vector_array arrays, int axis, mlx_stream s);
mlx_array_result mlx_try_stack_all(const mlx_vector_array arrays, mlx_stream s);
mlx_array_result mlx_try_std(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    int ddof,
    mlx_stream s);
mlx_array_result
mlx_try_std_all(mlx_array a, bool keepdims, int ddof, mlx_stream s);
mlx_array_result mlx_try_stop_gradient(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_subtract(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_try_sum(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array_result mlx_try_sum_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array_result
mlx_try_swapaxes(mlx_array a, int axis1, int axis2, mlx_stream s);
mlx_array_result
mlx_try_take(mlx_array a, mlx_array indices, int axis, mlx_stream s);
mlx_array_result mlx_try_take_all(mlx_array a, mlx_array indices, mlx_stream s);
mlx_array_result
mlx_try_take_along_axis(mlx_array a, mlx_array indices, int axis, mlx_stream s);
mlx_array_result mlx_try_tan(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_tanh(mlx_array a, mlx_stream s);
mlx_array_result mlx_try_tensordot(
    mlx_array a,
    mlx_array b,
    const int* axes_a,
    size_t num_axes_a,
    const int* axes_b,
    size_t num_axes_b,
    mlx_stream s);
mlx_array_result
mlx_try_tensordot_along_axis(mlx_array a, mlx_array b, int axis, mlx_stream s);
mlx_array_result
mlx_try_tile(mlx_array arr, const int* reps, size_t num_reps, mlx_stream s);
mlx_array_result mlx_try_topk(mlx_array a, int k, int axis, mlx_stream s);
mlx_array_result mlx_try_topk_all(mlx_array a, int k, mlx_stream s);
mlx_array_result mlx_try_trace(
    mlx_array a,
    int offset,
    int axis1,
    int axis2,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array_result
mlx_try_transpose(mlx_array a, const int* axes, size_t num_axes, mlx_stream s);
mlx_array_result mlx_try_transpose_all(mlx_array a, mlx_stream s);
mlx_array_result
mlx_try_tri(int n, int m, int k, mlx_array_dtype type, mlx_stream s);
mlx_array_result mlx_try_tril(mlx_array x, int k, mlx_stream s);
mlx_array_result mlx_try_triu(mlx_array x, int k, mlx_stream s);
mlx_array_result mlx_try_var(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    int ddof,
    mlx_stream s);
mlx_array_result
mlx_try_var_all(mlx_array a, bool keepdims, int ddof, mlx_stream s);
mlx_array_result
mlx_try_where(mlx_array condition, mlx_array x, mlx_array y, mlx_stream s);
mlx_array_result mlx_try_zeros(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array_result mlx_try_zeros_like(mlx_array a, mlx_stream s);

#ifdef __cplusplus
}
#endif

#endif
