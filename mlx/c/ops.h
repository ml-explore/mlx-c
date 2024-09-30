/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_OPS_H
#define MLX_OPS_H

#include <stdio.h>

#include "mlx/c/array.h"
#include "mlx/c/closure.h"
#include "mlx/c/distributed_group.h"
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
int mlx_abs(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_add(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_addmm(
    const mlx_array c,
    const mlx_array a,
    const mlx_array b,
    float alpha,
    float beta,
    const mlx_stream s,
    mlx_array* res);
int mlx_all_axes(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_all_axis(
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_all_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_allclose(
    const mlx_array a,
    const mlx_array b,
    double rtol,
    double atol,
    bool equal_nan,
    const mlx_stream s,
    mlx_array* res);
int mlx_any(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_any_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_arange(
    double start,
    double stop,
    double step,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res);
int mlx_arccos(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_arccosh(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_arcsin(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_arcsinh(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_arctan(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_arctan2(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_arctanh(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_argmax(
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_argmax_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_argmin(
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_argmin_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_argpartition(
    const mlx_array a,
    int kth,
    int axis,
    const mlx_stream s,
    mlx_array* res);
int mlx_argpartition_all(
    const mlx_array a,
    int kth,
    const mlx_stream s,
    mlx_array* res);
int mlx_argsort(
    const mlx_array a,
    int axis,
    const mlx_stream s,
    mlx_array* res);
int mlx_argsort_all(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_array_equal(
    const mlx_array a,
    const mlx_array b,
    bool equal_nan,
    const mlx_stream s,
    mlx_array* res);
int mlx_as_strided(
    const mlx_array a,
    const int* shape,
    size_t shape_num,
    const size_t* strides,
    size_t strides_num,
    size_t offset,
    const mlx_stream s,
    mlx_array* res);
int mlx_astype(
    const mlx_array a,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res);
int mlx_atleast_1d(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_atleast_2d(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_atleast_3d(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_bitwise_and(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_bitwise_or(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_bitwise_xor(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_block_masked_mm(
    const mlx_array a,
    const mlx_array b,
    int block_size,
    const mlx_array mask_out /* may be null */,
    const mlx_array mask_lhs /* may be null */,
    const mlx_array mask_rhs /* may be null */,
    const mlx_stream s,
    mlx_array* res);
int mlx_broadcast_arrays(
    const mlx_vector_array inputs,
    const mlx_stream s,
    mlx_vector_array* res);
int mlx_broadcast_to(
    const mlx_array a,
    const int* shape,
    size_t shape_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_ceil(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_clip(
    const mlx_array a,
    const mlx_array a_min /* may be null */,
    const mlx_array a_max /* may be null */,
    const mlx_stream s,
    mlx_array* res);
int mlx_concatenate(
    const mlx_vector_array arrays,
    int axis,
    const mlx_stream s,
    mlx_array* res);
int mlx_concatenate_all(
    const mlx_vector_array arrays,
    const mlx_stream s,
    mlx_array* res);
int mlx_conjugate(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_conv1d(
    const mlx_array input,
    const mlx_array weight,
    int stride,
    int padding,
    int dilation,
    int groups,
    const mlx_stream s,
    mlx_array* res);
int mlx_conv2d(
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
    mlx_array* res);
int mlx_conv3d(
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
    mlx_array* res);
int mlx_conv_general(
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
    mlx_array* res);
int mlx_conv_transpose1d(
    const mlx_array input,
    const mlx_array weight,
    int stride,
    int padding,
    int dilation,
    int groups,
    const mlx_stream s,
    mlx_array* res);
int mlx_conv_transpose2d(
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
    mlx_array* res);
int mlx_conv_transpose3d(
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
    mlx_array* res);
int mlx_copy(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_cos(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_cosh(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_cummax(
    const mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    const mlx_stream s,
    mlx_array* res);
int mlx_cummin(
    const mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    const mlx_stream s,
    mlx_array* res);
int mlx_cumprod(
    const mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    const mlx_stream s,
    mlx_array* res);
int mlx_cumsum(
    const mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    const mlx_stream s,
    mlx_array* res);
int mlx_degrees(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_depends(
    const mlx_vector_array inputs,
    const mlx_vector_array dependencies,
    mlx_vector_array* res);
int mlx_dequantize(
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases,
    int group_size,
    int bits,
    const mlx_stream s,
    mlx_array* res);
int mlx_diag(const mlx_array a, int k, const mlx_stream s, mlx_array* res);
int mlx_diagonal(
    const mlx_array a,
    int offset,
    int axis1,
    int axis2,
    const mlx_stream s,
    mlx_array* res);
int mlx_divide(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_divmod(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_vector_array* res);
int mlx_einsum(
    const char* subscripts,
    const mlx_vector_array operands,
    const mlx_stream s,
    mlx_array* res);
int mlx_equal(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_erf(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_erfinv(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_exp(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_expand_dims(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_expm1(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_eye(
    int n,
    int m,
    int k,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res);
int mlx_flatten(
    const mlx_array a,
    int start_axis,
    int end_axis,
    const mlx_stream s,
    mlx_array* res);
int mlx_floor(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_floor_divide(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_full(
    const int* shape,
    size_t shape_num,
    const mlx_array vals,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res);
int mlx_gather(
    const mlx_array a,
    const mlx_vector_array indices,
    const int* axes,
    size_t axes_num,
    const int* slice_sizes,
    size_t slice_sizes_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_gather_mm(
    const mlx_array a,
    const mlx_array b,
    const mlx_array lhs_indices /* may be null */,
    const mlx_array rhs_indices /* may be null */,
    const mlx_stream s,
    mlx_array* res);
int mlx_gather_qmm(
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
    mlx_array* res);
int mlx_greater(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_greater_equal(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_hadamard_transform(
    const mlx_array a,
    mlx_optional_float scale,
    const mlx_stream s,
    mlx_array* res);
int mlx_identity(int n, mlx_dtype dtype, const mlx_stream s, mlx_array* res);
int mlx_inner(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_isclose(
    const mlx_array a,
    const mlx_array b,
    double rtol,
    double atol,
    bool equal_nan,
    const mlx_stream s,
    mlx_array* res);
int mlx_isfinite(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_isinf(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_isnan(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_isneginf(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_isposinf(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_left_shift(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_less(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_less_equal(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_linspace(
    double start,
    double stop,
    int num,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res);
int mlx_log(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_log10(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_log1p(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_log2(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_logaddexp(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_logical_and(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_logical_not(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_logical_or(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_logsumexp(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_logsumexp_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_matmul(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_max(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_max_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_maximum(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_mean(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_mean_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_meshgrid(
    const mlx_vector_array arrays,
    bool sparse,
    const char* indexing,
    const mlx_stream s,
    mlx_vector_array* res);
int mlx_min(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_min_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_minimum(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_moveaxis(
    const mlx_array a,
    int source,
    int destination,
    const mlx_stream s,
    mlx_array* res);
int mlx_multiply(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_nan_to_num(
    const mlx_array a,
    float nan,
    mlx_optional_float posinf,
    mlx_optional_float neginf,
    const mlx_stream s,
    mlx_array* res);
int mlx_negative(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_not_equal(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_number_of_elements(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool inverted,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res);
int mlx_ones(
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res);
int mlx_ones_like(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_outer(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_pad(
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
    mlx_array* res);
int mlx_partition(
    const mlx_array a,
    int kth,
    int axis,
    const mlx_stream s,
    mlx_array* res);
int mlx_partition_all(
    const mlx_array a,
    int kth,
    const mlx_stream s,
    mlx_array* res);
int mlx_power(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_prod(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_prod_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_put_along_axis(
    const mlx_array a,
    const mlx_array indices,
    const mlx_array values,
    int axis,
    const mlx_stream s,
    mlx_array* res);
int mlx_quantize(
    const mlx_array w,
    int group_size,
    int bits,
    const mlx_stream s,
    mlx_array* res_0,
    mlx_array* res_1,
    mlx_array* res_2);
int mlx_quantized_matmul(
    const mlx_array x,
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases,
    bool transpose,
    int group_size,
    int bits,
    const mlx_stream s,
    mlx_array* res);
int mlx_radians(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_reciprocal(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_remainder(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_repeat(
    const mlx_array arr,
    int repeats,
    int axis,
    const mlx_stream s,
    mlx_array* res);
int mlx_repeat_all(
    const mlx_array arr,
    int repeats,
    const mlx_stream s,
    mlx_array* res);
int mlx_reshape(
    const mlx_array a,
    const int* shape,
    size_t shape_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_right_shift(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_round(
    const mlx_array a,
    int decimals,
    const mlx_stream s,
    mlx_array* res);
int mlx_rsqrt(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_scatter(
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_scatter_add(
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_scatter_max(
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_scatter_min(
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_scatter_prod(
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_sigmoid(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_sign(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_sin(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_sinh(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_slice(
    const mlx_array a,
    const int* start,
    size_t start_num,
    const int* stop,
    size_t stop_num,
    const int* strides,
    size_t strides_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_slice_update(
    const mlx_array src,
    const mlx_array update,
    const int* start,
    size_t start_num,
    const int* stop,
    size_t stop_num,
    const int* strides,
    size_t strides_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_softmax(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool precise,
    const mlx_stream s,
    mlx_array* res);
int mlx_softmax_all(
    const mlx_array a,
    bool precise,
    const mlx_stream s,
    mlx_array* res);
int mlx_sort(const mlx_array a, int axis, const mlx_stream s, mlx_array* res);
int mlx_sort_all(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_split_equal_parts(
    const mlx_array a,
    int num_splits,
    int axis,
    const mlx_stream s,
    mlx_vector_array* res);
int mlx_split(
    const mlx_array a,
    const int* indices,
    size_t indices_num,
    int axis,
    const mlx_stream s,
    mlx_vector_array* res);
int mlx_sqrt(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_square(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_squeeze(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_squeeze_all(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_stack(
    const mlx_vector_array arrays,
    int axis,
    const mlx_stream s,
    mlx_array* res);
int mlx_stack_all(
    const mlx_vector_array arrays,
    const mlx_stream s,
    mlx_array* res);
int mlx_std(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    int ddof,
    const mlx_stream s,
    mlx_array* res);
int mlx_std_all(
    const mlx_array a,
    bool keepdims,
    int ddof,
    const mlx_stream s,
    mlx_array* res);
int mlx_stop_gradient(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_subtract(
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s,
    mlx_array* res);
int mlx_sum(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_sum_all(
    const mlx_array a,
    bool keepdims,
    const mlx_stream s,
    mlx_array* res);
int mlx_swapaxes(
    const mlx_array a,
    int axis1,
    int axis2,
    const mlx_stream s,
    mlx_array* res);
int mlx_take(
    const mlx_array a,
    const mlx_array indices,
    int axis,
    const mlx_stream s,
    mlx_array* res);
int mlx_take_all(
    const mlx_array a,
    const mlx_array indices,
    const mlx_stream s,
    mlx_array* res);
int mlx_take_along_axis(
    const mlx_array a,
    const mlx_array indices,
    int axis,
    const mlx_stream s,
    mlx_array* res);
int mlx_tan(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_tanh(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_tensordot(
    const mlx_array a,
    const mlx_array b,
    const int* axes_a,
    size_t axes_a_num,
    const int* axes_b,
    size_t axes_b_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_tensordot_along_axis(
    const mlx_array a,
    const mlx_array b,
    int axis,
    const mlx_stream s,
    mlx_array* res);
int mlx_tile(
    const mlx_array arr,
    const int* reps,
    size_t reps_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_topk(
    const mlx_array a,
    int k,
    int axis,
    const mlx_stream s,
    mlx_array* res);
int mlx_topk_all(const mlx_array a, int k, const mlx_stream s, mlx_array* res);
int mlx_trace(
    const mlx_array a,
    int offset,
    int axis1,
    int axis2,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res);
int mlx_transpose(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_transpose_all(const mlx_array a, const mlx_stream s, mlx_array* res);
int mlx_tri(
    int n,
    int m,
    int k,
    mlx_dtype type,
    const mlx_stream s,
    mlx_array* res);
int mlx_tril(const mlx_array x, int k, const mlx_stream s, mlx_array* res);
int mlx_triu(const mlx_array x, int k, const mlx_stream s, mlx_array* res);
int mlx_var(
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    int ddof,
    const mlx_stream s,
    mlx_array* res);
int mlx_var_all(
    const mlx_array a,
    bool keepdims,
    int ddof,
    const mlx_stream s,
    mlx_array* res);
int mlx_view(
    const mlx_array a,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res);
int mlx_where(
    const mlx_array condition,
    const mlx_array x,
    const mlx_array y,
    const mlx_stream s,
    mlx_array* res);
int mlx_zeros(
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    const mlx_stream s,
    mlx_array* res);
int mlx_zeros_like(const mlx_array a, const mlx_stream s, mlx_array* res);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
