/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_OPS_H
#define MLX_OPS_H

#include <stdio.h>

#include "mlx/c/array.h"
//    #include "mlx/c/closure.h"
#include "mlx/c/distributed_group.h"
#include "mlx/c/ioutils.h"
#include "mlx/c/map.h"
#include "mlx/c/stream.h"
#include "mlx/c/string.h"
#include "mlx/c/vector.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup ops Core array operations
 */
/**@{*/
int mlx_abs(mlx_array a, mlx_stream s, mlx_array res);
int mlx_add(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_addmm(
    mlx_array c,
    mlx_array a,
    mlx_array b,
    float alpha,
    float beta,
    mlx_stream s,
    mlx_array res);
int mlx_all_axes(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s,
    mlx_array res);
int mlx_all_axis(
    mlx_array a,
    int axis,
    bool keepdims,
    mlx_stream s,
    mlx_array res);
int mlx_all_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res);
int mlx_allclose(
    mlx_array a,
    mlx_array b,
    double rtol,
    double atol,
    bool equal_nan,
    mlx_stream s,
    mlx_array res);
int mlx_any(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s,
    mlx_array res);
int mlx_any_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res);
int mlx_arange(
    double start,
    double stop,
    double step,
    mlx_array_dtype dtype,
    mlx_stream s,
    mlx_array res);
int mlx_arccos(mlx_array a, mlx_stream s, mlx_array res);
int mlx_arccosh(mlx_array a, mlx_stream s, mlx_array res);
int mlx_arcsin(mlx_array a, mlx_stream s, mlx_array res);
int mlx_arcsinh(mlx_array a, mlx_stream s, mlx_array res);
int mlx_arctan(mlx_array a, mlx_stream s, mlx_array res);
int mlx_arctan2(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_arctanh(mlx_array a, mlx_stream s, mlx_array res);
int mlx_argmax(
    mlx_array a,
    int axis,
    bool keepdims,
    mlx_stream s,
    mlx_array res);
int mlx_argmax_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res);
int mlx_argmin(
    mlx_array a,
    int axis,
    bool keepdims,
    mlx_stream s,
    mlx_array res);
int mlx_argmin_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res);
int mlx_argpartition(
    mlx_array a,
    int kth,
    int axis,
    mlx_stream s,
    mlx_array res);
int mlx_argpartition_all(mlx_array a, int kth, mlx_stream s, mlx_array res);
int mlx_argsort(mlx_array a, int axis, mlx_stream s, mlx_array res);
int mlx_argsort_all(mlx_array a, mlx_stream s, mlx_array res);
int mlx_array_equal(
    mlx_array a,
    mlx_array b,
    bool equal_nan,
    mlx_stream s,
    mlx_array res);
int mlx_as_strided(
    mlx_array a,
    const int* shape,
    size_t num_shape,
    const size_t* strides,
    size_t num_strides,
    size_t offset,
    mlx_stream s,
    mlx_array res);
int mlx_astype(mlx_array a, mlx_array_dtype dtype, mlx_stream s, mlx_array res);
int mlx_atleast_1d(mlx_array a, mlx_stream s, mlx_array res);
int mlx_atleast_2d(mlx_array a, mlx_stream s, mlx_array res);
int mlx_atleast_3d(mlx_array a, mlx_stream s, mlx_array res);
int mlx_bitwise_and(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_bitwise_or(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_bitwise_xor(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_block_masked_mm(
    mlx_array a,
    mlx_array b,
    int block_size,
    mlx_array mask_out,
    mlx_array mask_lhs,
    mlx_array mask_rhs,
    mlx_stream s,
    mlx_array res);
int mlx_broadcast_arrays(
    const mlx_vector_array inputs,
    mlx_stream s,
    mlx_vector_array res);
int mlx_broadcast_to(
    mlx_array a,
    const int* shape,
    size_t num_shape,
    mlx_stream s,
    mlx_array res);
int mlx_ceil(mlx_array a, mlx_stream s, mlx_array res);
int mlx_clip(
    mlx_array a,
    mlx_array a_min,
    mlx_array a_max,
    mlx_stream s,
    mlx_array res);
int mlx_concatenate(
    const mlx_vector_array arrays,
    int axis,
    mlx_stream s,
    mlx_array res);
int mlx_concatenate_all(
    const mlx_vector_array arrays,
    mlx_stream s,
    mlx_array res);
int mlx_conjugate(mlx_array a, mlx_stream s, mlx_array res);
int mlx_conv1d(
    mlx_array input,
    mlx_array weight,
    int stride,
    int padding,
    int dilation,
    int groups,
    mlx_stream s,
    mlx_array res);
int mlx_conv2d(
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
    mlx_array res);
int mlx_conv3d(
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
    mlx_array res);
int mlx_conv_general(
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
    mlx_array res);
int mlx_conv_transpose1d(
    mlx_array input,
    mlx_array weight,
    int stride,
    int padding,
    int dilation,
    int groups,
    mlx_stream s,
    mlx_array res);
int mlx_conv_transpose2d(
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
    mlx_array res);
int mlx_conv_transpose3d(
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
    mlx_array res);
int mlx_copy(mlx_array a, mlx_stream s, mlx_array res);
int mlx_cos(mlx_array a, mlx_stream s, mlx_array res);
int mlx_cosh(mlx_array a, mlx_stream s, mlx_array res);
int mlx_cummax(
    mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    mlx_stream s,
    mlx_array res);
int mlx_cummin(
    mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    mlx_stream s,
    mlx_array res);
int mlx_cumprod(
    mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    mlx_stream s,
    mlx_array res);
int mlx_cumsum(
    mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    mlx_stream s,
    mlx_array res);
int mlx_degrees(mlx_array a, mlx_stream s, mlx_array res);
int mlx_depends(
    const mlx_vector_array inputs,
    const mlx_vector_array dependencies,
    mlx_vector_array res);
int mlx_dequantize(
    mlx_array w,
    mlx_array scales,
    mlx_array biases,
    int group_size,
    int bits,
    mlx_stream s,
    mlx_array res);
int mlx_diag(mlx_array a, int k, mlx_stream s, mlx_array res);
int mlx_diagonal(
    mlx_array a,
    int offset,
    int axis1,
    int axis2,
    mlx_stream s,
    mlx_array res);
int mlx_divide(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_divmod(mlx_array a, mlx_array b, mlx_stream s, mlx_vector_array res);
int mlx_einsum(
    mlx_string subscripts,
    const mlx_vector_array operands,
    mlx_stream s,
    mlx_array res);
int mlx_equal(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_erf(mlx_array a, mlx_stream s, mlx_array res);
int mlx_erfinv(mlx_array a, mlx_stream s, mlx_array res);
int mlx_exp(mlx_array a, mlx_stream s, mlx_array res);
int mlx_expand_dims(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    mlx_stream s,
    mlx_array res);
int mlx_expm1(mlx_array a, mlx_stream s, mlx_array res);
int mlx_eye(
    int n,
    int m,
    int k,
    mlx_array_dtype dtype,
    mlx_stream s,
    mlx_array res);
int mlx_flatten(
    mlx_array a,
    int start_axis,
    int end_axis,
    mlx_stream s,
    mlx_array res);
int mlx_floor(mlx_array a, mlx_stream s, mlx_array res);
int mlx_floor_divide(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_full(
    const int* shape,
    size_t num_shape,
    mlx_array vals,
    mlx_array_dtype dtype,
    mlx_stream s,
    mlx_array res);
int mlx_gather(
    mlx_array a,
    const mlx_vector_array indices,
    const int* axes,
    size_t num_axes,
    const int* slice_sizes,
    size_t num_slice_sizes,
    mlx_stream s,
    mlx_array res);
int mlx_gather_mm(
    mlx_array a,
    mlx_array b,
    mlx_array lhs_indices,
    mlx_array rhs_indices,
    mlx_stream s,
    mlx_array res);
int mlx_gather_qmm(
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
    mlx_array res);
int mlx_greater(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_greater_equal(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_hadamard_transform(
    mlx_array a,
    mlx_optional_float scale,
    mlx_stream s,
    mlx_array res);
int mlx_identity(int n, mlx_array_dtype dtype, mlx_stream s, mlx_array res);
int mlx_inner(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_isclose(
    mlx_array a,
    mlx_array b,
    double rtol,
    double atol,
    bool equal_nan,
    mlx_stream s,
    mlx_array res);
int mlx_isfinite(mlx_array a, mlx_stream s, mlx_array res);
int mlx_isinf(mlx_array a, mlx_stream s, mlx_array res);
int mlx_isnan(mlx_array a, mlx_stream s, mlx_array res);
int mlx_isneginf(mlx_array a, mlx_stream s, mlx_array res);
int mlx_isposinf(mlx_array a, mlx_stream s, mlx_array res);
int mlx_left_shift(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_less(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_less_equal(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_linspace(
    double start,
    double stop,
    int num,
    mlx_array_dtype dtype,
    mlx_stream s,
    mlx_array res);
int mlx_log(mlx_array a, mlx_stream s, mlx_array res);
int mlx_log10(mlx_array a, mlx_stream s, mlx_array res);
int mlx_log1p(mlx_array a, mlx_stream s, mlx_array res);
int mlx_log2(mlx_array a, mlx_stream s, mlx_array res);
int mlx_logaddexp(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_logical_and(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_logical_not(mlx_array a, mlx_stream s, mlx_array res);
int mlx_logical_or(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_logsumexp(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s,
    mlx_array res);
int mlx_logsumexp_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res);
int mlx_matmul(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_max(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s,
    mlx_array res);
int mlx_max_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res);
int mlx_maximum(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_mean(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s,
    mlx_array res);
int mlx_mean_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res);
int mlx_meshgrid(
    const mlx_vector_array arrays,
    bool sparse,
    mlx_string indexing,
    mlx_stream s,
    mlx_vector_array res);
int mlx_min(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s,
    mlx_array res);
int mlx_min_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res);
int mlx_minimum(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_moveaxis(
    mlx_array a,
    int source,
    int destination,
    mlx_stream s,
    mlx_array res);
int mlx_multiply(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_nan_to_num(
    mlx_array a,
    float nan,
    mlx_optional_float posinf,
    mlx_optional_float neginf,
    mlx_stream s,
    mlx_array res);
int mlx_negative(mlx_array a, mlx_stream s, mlx_array res);
int mlx_not_equal(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_number_of_elements(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool inverted,
    mlx_array_dtype dtype,
    mlx_stream s,
    mlx_array res);
int mlx_ones(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_stream s,
    mlx_array res);
int mlx_ones_like(mlx_array a, mlx_stream s, mlx_array res);
int mlx_outer(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_pad(
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
    mlx_array res);
int mlx_partition(mlx_array a, int kth, int axis, mlx_stream s, mlx_array res);
int mlx_partition_all(mlx_array a, int kth, mlx_stream s, mlx_array res);
int mlx_power(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_prod(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s,
    mlx_array res);
int mlx_prod_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res);
int mlx_put_along_axis(
    mlx_array a,
    mlx_array indices,
    mlx_array values,
    int axis,
    mlx_stream s,
    mlx_array res);
int mlx_quantize(
    mlx_array w,
    int group_size,
    int bits,
    mlx_stream s,
    mlx_array res_0,
    mlx_array res_1,
    mlx_array res_2);
int mlx_quantized_matmul(
    mlx_array x,
    mlx_array w,
    mlx_array scales,
    mlx_array biases,
    bool transpose,
    int group_size,
    int bits,
    mlx_stream s,
    mlx_array res);
int mlx_radians(mlx_array a, mlx_stream s, mlx_array res);
int mlx_reciprocal(mlx_array a, mlx_stream s, mlx_array res);
int mlx_remainder(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_repeat(
    mlx_array arr,
    int repeats,
    int axis,
    mlx_stream s,
    mlx_array res);
int mlx_repeat_all(mlx_array arr, int repeats, mlx_stream s, mlx_array res);
int mlx_reshape(
    mlx_array a,
    const int* shape,
    size_t num_shape,
    mlx_stream s,
    mlx_array res);
int mlx_right_shift(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_round(mlx_array a, int decimals, mlx_stream s, mlx_array res);
int mlx_rsqrt(mlx_array a, mlx_stream s, mlx_array res);
int mlx_scatter(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s,
    mlx_array res);
int mlx_scatter_add(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s,
    mlx_array res);
int mlx_scatter_max(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s,
    mlx_array res);
int mlx_scatter_min(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s,
    mlx_array res);
int mlx_scatter_prod(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s,
    mlx_array res);
int mlx_sigmoid(mlx_array a, mlx_stream s, mlx_array res);
int mlx_sign(mlx_array a, mlx_stream s, mlx_array res);
int mlx_sin(mlx_array a, mlx_stream s, mlx_array res);
int mlx_sinh(mlx_array a, mlx_stream s, mlx_array res);
int mlx_slice(
    mlx_array a,
    const int* start,
    size_t num_start,
    const int* stop,
    size_t num_stop,
    const int* strides,
    size_t num_strides,
    mlx_stream s,
    mlx_array res);
int mlx_slice_update(
    mlx_array src,
    mlx_array update,
    const int* start,
    size_t num_start,
    const int* stop,
    size_t num_stop,
    const int* strides,
    size_t num_strides,
    mlx_stream s,
    mlx_array res);
int mlx_softmax(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool precise,
    mlx_stream s,
    mlx_array res);
int mlx_softmax_all(mlx_array a, bool precise, mlx_stream s, mlx_array res);
int mlx_sort(mlx_array a, int axis, mlx_stream s, mlx_array res);
int mlx_sort_all(mlx_array a, mlx_stream s, mlx_array res);
int mlx_split_equal_parts(
    mlx_array a,
    int num_splits,
    int axis,
    mlx_stream s,
    mlx_vector_array res);
int mlx_split(
    mlx_array a,
    const int* indices,
    size_t num_indices,
    int axis,
    mlx_stream s,
    mlx_vector_array res);
int mlx_sqrt(mlx_array a, mlx_stream s, mlx_array res);
int mlx_square(mlx_array a, mlx_stream s, mlx_array res);
int mlx_squeeze(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    mlx_stream s,
    mlx_array res);
int mlx_squeeze_all(mlx_array a, mlx_stream s, mlx_array res);
int mlx_stack(
    const mlx_vector_array arrays,
    int axis,
    mlx_stream s,
    mlx_array res);
int mlx_stack_all(const mlx_vector_array arrays, mlx_stream s, mlx_array res);
int mlx_std(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    int ddof,
    mlx_stream s,
    mlx_array res);
int mlx_std_all(
    mlx_array a,
    bool keepdims,
    int ddof,
    mlx_stream s,
    mlx_array res);
int mlx_stop_gradient(mlx_array a, mlx_stream s, mlx_array res);
int mlx_subtract(mlx_array a, mlx_array b, mlx_stream s, mlx_array res);
int mlx_sum(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s,
    mlx_array res);
int mlx_sum_all(mlx_array a, bool keepdims, mlx_stream s, mlx_array res);
int mlx_swapaxes(
    mlx_array a,
    int axis1,
    int axis2,
    mlx_stream s,
    mlx_array res);
int mlx_take(
    mlx_array a,
    mlx_array indices,
    int axis,
    mlx_stream s,
    mlx_array res);
int mlx_take_all(mlx_array a, mlx_array indices, mlx_stream s, mlx_array res);
int mlx_take_along_axis(
    mlx_array a,
    mlx_array indices,
    int axis,
    mlx_stream s,
    mlx_array res);
int mlx_tan(mlx_array a, mlx_stream s, mlx_array res);
int mlx_tanh(mlx_array a, mlx_stream s, mlx_array res);
int mlx_tensordot(
    mlx_array a,
    mlx_array b,
    const int* axes_a,
    size_t num_axes_a,
    const int* axes_b,
    size_t num_axes_b,
    mlx_stream s,
    mlx_array res);
int mlx_tensordot_along_axis(
    mlx_array a,
    mlx_array b,
    int axis,
    mlx_stream s,
    mlx_array res);
int mlx_tile(
    mlx_array arr,
    const int* reps,
    size_t num_reps,
    mlx_stream s,
    mlx_array res);
int mlx_topk(mlx_array a, int k, int axis, mlx_stream s, mlx_array res);
int mlx_topk_all(mlx_array a, int k, mlx_stream s, mlx_array res);
int mlx_trace(
    mlx_array a,
    int offset,
    int axis1,
    int axis2,
    mlx_array_dtype dtype,
    mlx_stream s,
    mlx_array res);
int mlx_transpose(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    mlx_stream s,
    mlx_array res);
int mlx_transpose_all(mlx_array a, mlx_stream s, mlx_array res);
int mlx_tri(
    int n,
    int m,
    int k,
    mlx_array_dtype type,
    mlx_stream s,
    mlx_array res);
int mlx_tril(mlx_array x, int k, mlx_stream s, mlx_array res);
int mlx_triu(mlx_array x, int k, mlx_stream s, mlx_array res);
int mlx_var(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    int ddof,
    mlx_stream s,
    mlx_array res);
int mlx_var_all(
    mlx_array a,
    bool keepdims,
    int ddof,
    mlx_stream s,
    mlx_array res);
int mlx_view(mlx_array a, mlx_array_dtype dtype, mlx_stream s, mlx_array res);
int mlx_where(
    mlx_array condition,
    mlx_array x,
    mlx_array y,
    mlx_stream s,
    mlx_array res);
int mlx_zeros(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_stream s,
    mlx_array res);
int mlx_zeros_like(mlx_array a, mlx_stream s, mlx_array res);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
