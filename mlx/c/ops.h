/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_OPS_H
#define MLX_OPS_H

#include <stdint.h>
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
int mlx_abs(mlx_array* res, const mlx_array a);
int mlx_abs_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_add(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_add_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_addmm(
    mlx_array* res,
    const mlx_array c,
    const mlx_array a,
    const mlx_array b);
int mlx_addmm_x(
    mlx_array* res,
    const mlx_array c,
    const mlx_array a,
    const mlx_array b,
    float alpha,
    float beta,
    const mlx_stream s);
int mlx_all_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num);
int mlx_all_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s);
int mlx_all_axis(mlx_array* res, const mlx_array a, int axis);
int mlx_all_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s);
int mlx_all(mlx_array* res, const mlx_array a, bool keepdims);
int mlx_allclose(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_allclose_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    double rtol,
    double atol,
    bool equal_nan,
    const mlx_stream s);
int mlx_any_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num);
int mlx_any_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s);
int mlx_any_axis(mlx_array* res, const mlx_array a, int axis);
int mlx_any_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s);
int mlx_any(mlx_array* res, const mlx_array a, bool keepdims);
int mlx_arange_x(
    mlx_array* res,
    double start,
    double stop,
    double step,
    mlx_dtype dtype,
    const mlx_stream s);
int mlx_arange(mlx_array* res, double stop);
int mlx_arccos(mlx_array* res, const mlx_array a);
int mlx_arccos_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_arccosh(mlx_array* res, const mlx_array a);
int mlx_arccosh_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_arcsin(mlx_array* res, const mlx_array a);
int mlx_arcsin_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_arcsinh(mlx_array* res, const mlx_array a);
int mlx_arcsinh_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_arctan(mlx_array* res, const mlx_array a);
int mlx_arctan_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_arctan2(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_arctan2_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_arctanh(mlx_array* res, const mlx_array a);
int mlx_arctanh_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_argmax_axis(mlx_array* res, const mlx_array a, int axis);
int mlx_argmax_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s);
int mlx_argmax(mlx_array* res, const mlx_array a, bool keepdims);
int mlx_argmin_axis(mlx_array* res, const mlx_array a, int axis);
int mlx_argmin_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s);
int mlx_argmin(mlx_array* res, const mlx_array a, bool keepdims);
int mlx_argpartition_axis(mlx_array* res, const mlx_array a, int kth, int axis);
int mlx_argpartition_axis_x(
    mlx_array* res,
    const mlx_array a,
    int kth,
    int axis,
    const mlx_stream s);
int mlx_argpartition(mlx_array* res, const mlx_array a, int kth);
int mlx_argsort_axis(mlx_array* res, const mlx_array a, int axis);
int mlx_argsort_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    const mlx_stream s);
int mlx_argsort(mlx_array* res, const mlx_array a);
int mlx_array_equal_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    bool equal_nan,
    const mlx_stream s);
int mlx_array_equal(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_as_strided(
    mlx_array* res,
    const mlx_array a,
    const int* shape,
    size_t shape_num,
    const int64_t* strides,
    size_t strides_num,
    size_t offset);
int mlx_as_strided_x(
    mlx_array* res,
    const mlx_array a,
    const int* shape,
    size_t shape_num,
    const int64_t* strides,
    size_t strides_num,
    size_t offset,
    const mlx_stream s);
int mlx_astype(mlx_array* res, const mlx_array a, mlx_dtype dtype);
int mlx_astype_x(
    mlx_array* res,
    const mlx_array a,
    mlx_dtype dtype,
    const mlx_stream s);
int mlx_atleast_1d(mlx_array* res, const mlx_array a);
int mlx_atleast_1d_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_atleast_2d(mlx_array* res, const mlx_array a);
int mlx_atleast_2d_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_atleast_3d(mlx_array* res, const mlx_array a);
int mlx_atleast_3d_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_bitwise_and(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_bitwise_and_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_bitwise_invert(mlx_array* res, const mlx_array a);
int mlx_bitwise_invert_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_bitwise_or(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_bitwise_or_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_bitwise_xor(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_bitwise_xor_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_block_masked_mm(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    int block_size);
int mlx_block_masked_mm_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    int block_size,
    const mlx_array mask_out /* may be null */,
    const mlx_array mask_lhs /* may be null */,
    const mlx_array mask_rhs /* may be null */,
    const mlx_stream s);
int mlx_broadcast_arrays(mlx_vector_array* res, const mlx_vector_array inputs);
int mlx_broadcast_arrays_x(
    mlx_vector_array* res,
    const mlx_vector_array inputs,
    const mlx_stream s);
int mlx_broadcast_to(
    mlx_array* res,
    const mlx_array a,
    const int* shape,
    size_t shape_num);
int mlx_broadcast_to_x(
    mlx_array* res,
    const mlx_array a,
    const int* shape,
    size_t shape_num,
    const mlx_stream s);
int mlx_ceil(mlx_array* res, const mlx_array a);
int mlx_ceil_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_clip(mlx_array* res, const mlx_array a);
int mlx_clip_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array a_min /* may be null */,
    const mlx_array a_max /* may be null */,
    const mlx_stream s);
int mlx_concatenate_axis(
    mlx_array* res,
    const mlx_vector_array arrays,
    int axis);
int mlx_concatenate_axis_x(
    mlx_array* res,
    const mlx_vector_array arrays,
    int axis,
    const mlx_stream s);
int mlx_concatenate(mlx_array* res, const mlx_vector_array arrays);
int mlx_conjugate(mlx_array* res, const mlx_array a);
int mlx_conjugate_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_contiguous(mlx_array* res, const mlx_array a);
int mlx_contiguous_x(
    mlx_array* res,
    const mlx_array a,
    bool allow_col_major,
    const mlx_stream s);
int mlx_conv1d(mlx_array* res, const mlx_array input, const mlx_array weight);
int mlx_conv1d_x(
    mlx_array* res,
    const mlx_array input,
    const mlx_array weight,
    int stride,
    int padding,
    int dilation,
    int groups,
    const mlx_stream s);
int mlx_conv2d(mlx_array* res, const mlx_array input, const mlx_array weight);
int mlx_conv2d_x(
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
    const mlx_stream s);
int mlx_conv3d(mlx_array* res, const mlx_array input, const mlx_array weight);
int mlx_conv3d_x(
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
    const mlx_stream s);
int mlx_conv_general(
    mlx_array* res,
    const mlx_array input,
    const mlx_array weight);
int mlx_conv_general_x(
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
    const mlx_stream s);
int mlx_conv_transpose1d(
    mlx_array* res,
    const mlx_array input,
    const mlx_array weight);
int mlx_conv_transpose1d_x(
    mlx_array* res,
    const mlx_array input,
    const mlx_array weight,
    int stride,
    int padding,
    int dilation,
    int groups,
    const mlx_stream s);
int mlx_conv_transpose2d(
    mlx_array* res,
    const mlx_array input,
    const mlx_array weight);
int mlx_conv_transpose2d_x(
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
    const mlx_stream s);
int mlx_conv_transpose3d(
    mlx_array* res,
    const mlx_array input,
    const mlx_array weight);
int mlx_conv_transpose3d_x(
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
    const mlx_stream s);
int mlx_copy(mlx_array* res, const mlx_array a);
int mlx_copy_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_cos(mlx_array* res, const mlx_array a);
int mlx_cos_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_cosh(mlx_array* res, const mlx_array a);
int mlx_cosh_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_cummax(mlx_array* res, const mlx_array a, int axis);
int mlx_cummax_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    const mlx_stream s);
int mlx_cummin(mlx_array* res, const mlx_array a, int axis);
int mlx_cummin_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    const mlx_stream s);
int mlx_cumprod(mlx_array* res, const mlx_array a, int axis);
int mlx_cumprod_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    const mlx_stream s);
int mlx_cumsum(mlx_array* res, const mlx_array a, int axis);
int mlx_cumsum_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    const mlx_stream s);
int mlx_degrees(mlx_array* res, const mlx_array a);
int mlx_degrees_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_depends(
    mlx_vector_array* res,
    const mlx_vector_array inputs,
    const mlx_vector_array dependencies);
int mlx_dequantize(
    mlx_array* res,
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases);
int mlx_dequantize_x(
    mlx_array* res,
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases,
    int group_size,
    int bits,
    const mlx_stream s);
int mlx_diag(mlx_array* res, const mlx_array a);
int mlx_diag_x(mlx_array* res, const mlx_array a, int k, const mlx_stream s);
int mlx_diagonal(mlx_array* res, const mlx_array a);
int mlx_diagonal_x(
    mlx_array* res,
    const mlx_array a,
    int offset,
    int axis1,
    int axis2,
    const mlx_stream s);
int mlx_divide(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_divide_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_divmod(mlx_vector_array* res, const mlx_array a, const mlx_array b);
int mlx_divmod_x(
    mlx_vector_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_einsum(
    mlx_array* res,
    const char* subscripts,
    const mlx_vector_array operands);
int mlx_einsum_x(
    mlx_array* res,
    const char* subscripts,
    const mlx_vector_array operands,
    const mlx_stream s);
int mlx_equal(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_equal_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_erf(mlx_array* res, const mlx_array a);
int mlx_erf_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_erfinv(mlx_array* res, const mlx_array a);
int mlx_erfinv_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_exp(mlx_array* res, const mlx_array a);
int mlx_exp_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_expand_dims_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num);
int mlx_expand_dims_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    const mlx_stream s);
int mlx_expand_dims(mlx_array* res, const mlx_array a, int axis);
int mlx_expm1(mlx_array* res, const mlx_array a);
int mlx_expm1_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_eye_x(
    mlx_array* res,
    int n,
    int m,
    int k,
    mlx_dtype dtype,
    const mlx_stream s);
int mlx_eye(mlx_array* res, int n);
int mlx_flatten_x(
    mlx_array* res,
    const mlx_array a,
    int start_axis,
    int end_axis,
    const mlx_stream s);
int mlx_flatten(mlx_array* res, const mlx_array a);
int mlx_floor(mlx_array* res, const mlx_array a);
int mlx_floor_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_floor_divide(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_floor_divide_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_full(
    mlx_array* res,
    const int* shape,
    size_t shape_num,
    const mlx_array vals,
    mlx_dtype dtype);
int mlx_full_x(
    mlx_array* res,
    const int* shape,
    size_t shape_num,
    const mlx_array vals,
    mlx_dtype dtype,
    const mlx_stream s);
int mlx_gather(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const int* axes,
    size_t axes_num,
    const int* slice_sizes,
    size_t slice_sizes_num);
int mlx_gather_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const int* axes,
    size_t axes_num,
    const int* slice_sizes,
    size_t slice_sizes_num,
    const mlx_stream s);
int mlx_gather_mm(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_gather_mm_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_array lhs_indices /* may be null */,
    const mlx_array rhs_indices /* may be null */,
    const mlx_stream s);
int mlx_gather_qmm(
    mlx_array* res,
    const mlx_array x,
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases);
int mlx_gather_qmm_x(
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
    const mlx_stream s);
int mlx_greater(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_greater_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_greater_equal(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_greater_equal_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_hadamard_transform(mlx_array* res, const mlx_array a);
int mlx_hadamard_transform_x(
    mlx_array* res,
    const mlx_array a,
    mlx_optional_float scale,
    const mlx_stream s);
int mlx_identity(mlx_array* res, int n, mlx_dtype dtype);
int mlx_identity_x(mlx_array* res, int n, mlx_dtype dtype, const mlx_stream s);
int mlx_imag(mlx_array* res, const mlx_array a);
int mlx_imag_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_inner(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_inner_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_isclose(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_isclose_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    double rtol,
    double atol,
    bool equal_nan,
    const mlx_stream s);
int mlx_isfinite(mlx_array* res, const mlx_array a);
int mlx_isfinite_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_isinf(mlx_array* res, const mlx_array a);
int mlx_isinf_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_isnan(mlx_array* res, const mlx_array a);
int mlx_isnan_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_isneginf(mlx_array* res, const mlx_array a);
int mlx_isneginf_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_isposinf(mlx_array* res, const mlx_array a);
int mlx_isposinf_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_kron(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_kron_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_left_shift(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_left_shift_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_less(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_less_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_less_equal(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_less_equal_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_linspace(mlx_array* res, double start, double stop);
int mlx_linspace_x(
    mlx_array* res,
    double start,
    double stop,
    int num,
    mlx_dtype dtype,
    const mlx_stream s);
int mlx_log(mlx_array* res, const mlx_array a);
int mlx_log_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_log10(mlx_array* res, const mlx_array a);
int mlx_log10_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_log1p(mlx_array* res, const mlx_array a);
int mlx_log1p_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_log2(mlx_array* res, const mlx_array a);
int mlx_log2_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_logaddexp(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_logaddexp_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_logical_and(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_logical_and_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_logical_not(mlx_array* res, const mlx_array a);
int mlx_logical_not_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_logical_or(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_logical_or_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_logsumexp_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num);
int mlx_logsumexp_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s);
int mlx_logsumexp_axis(mlx_array* res, const mlx_array a, int axis);
int mlx_logsumexp_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s);
int mlx_logsumexp(mlx_array* res, const mlx_array a, bool keepdims);
int mlx_matmul(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_matmul_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_max_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num);
int mlx_max_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s);
int mlx_max_axis(mlx_array* res, const mlx_array a, int axis);
int mlx_max_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s);
int mlx_max(mlx_array* res, const mlx_array a, bool keepdims);
int mlx_maximum(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_maximum_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_mean_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num);
int mlx_mean_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s);
int mlx_mean_axis(mlx_array* res, const mlx_array a, int axis);
int mlx_mean_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s);
int mlx_mean(mlx_array* res, const mlx_array a, bool keepdims);
int mlx_meshgrid(mlx_vector_array* res, const mlx_vector_array arrays);
int mlx_meshgrid_x(
    mlx_vector_array* res,
    const mlx_vector_array arrays,
    bool sparse,
    const char* indexing,
    const mlx_stream s);
int mlx_min_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num);
int mlx_min_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s);
int mlx_min_axis(mlx_array* res, const mlx_array a, int axis);
int mlx_min_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s);
int mlx_min(mlx_array* res, const mlx_array a, bool keepdims);
int mlx_minimum(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_minimum_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_moveaxis(
    mlx_array* res,
    const mlx_array a,
    int source,
    int destination);
int mlx_moveaxis_x(
    mlx_array* res,
    const mlx_array a,
    int source,
    int destination,
    const mlx_stream s);
int mlx_multiply(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_multiply_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_nan_to_num(mlx_array* res, const mlx_array a);
int mlx_nan_to_num_x(
    mlx_array* res,
    const mlx_array a,
    float nan,
    mlx_optional_float posinf,
    mlx_optional_float neginf,
    const mlx_stream s);
int mlx_negative(mlx_array* res, const mlx_array a);
int mlx_negative_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_not_equal(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_not_equal_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_number_of_elements(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool inverted);
int mlx_number_of_elements_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool inverted,
    mlx_dtype dtype,
    const mlx_stream s);
int mlx_ones(
    mlx_array* res,
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype);
int mlx_ones_x(
    mlx_array* res,
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    const mlx_stream s);
int mlx_ones_like(mlx_array* res, const mlx_array a);
int mlx_ones_like_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_outer(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_outer_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_pad(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    const int* low_pad_size,
    size_t low_pad_size_num,
    const int* high_pad_size,
    size_t high_pad_size_num);
int mlx_pad_symmetric(mlx_array* res, const mlx_array a, int pad_width);
int mlx_pad_symmetric_x(
    mlx_array* res,
    const mlx_array a,
    int pad_width,
    const mlx_array pad_value,
    const char* mode,
    const mlx_stream s);
int mlx_partition_axis(mlx_array* res, const mlx_array a, int kth, int axis);
int mlx_partition_axis_x(
    mlx_array* res,
    const mlx_array a,
    int kth,
    int axis,
    const mlx_stream s);
int mlx_partition(mlx_array* res, const mlx_array a, int kth);
int mlx_power(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_power_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_prod_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num);
int mlx_prod_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s);
int mlx_prod_axis(mlx_array* res, const mlx_array a, int axis);
int mlx_prod_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s);
int mlx_prod(mlx_array* res, const mlx_array a, bool keepdims);
int mlx_put_along_axis(
    mlx_array* res,
    const mlx_array a,
    const mlx_array indices,
    const mlx_array values,
    int axis);
int mlx_put_along_axis_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array indices,
    const mlx_array values,
    int axis,
    const mlx_stream s);
int mlx_quantize(
    mlx_array* res_0,
    mlx_array* res_1,
    mlx_array* res_2,
    const mlx_array w);
int mlx_quantize_x(
    mlx_array* res_0,
    mlx_array* res_1,
    mlx_array* res_2,
    const mlx_array w,
    int group_size,
    int bits,
    const mlx_stream s);
int mlx_quantized_matmul(
    mlx_array* res,
    const mlx_array x,
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases);
int mlx_quantized_matmul_x(
    mlx_array* res,
    const mlx_array x,
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases,
    bool transpose,
    int group_size,
    int bits,
    const mlx_stream s);
int mlx_radians(mlx_array* res, const mlx_array a);
int mlx_radians_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_real(mlx_array* res, const mlx_array a);
int mlx_real_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_reciprocal(mlx_array* res, const mlx_array a);
int mlx_reciprocal_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_remainder(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_remainder_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_repeat_axis(mlx_array* res, const mlx_array arr, int repeats, int axis);
int mlx_repeat_axis_x(
    mlx_array* res,
    const mlx_array arr,
    int repeats,
    int axis,
    const mlx_stream s);
int mlx_repeat(mlx_array* res, const mlx_array arr, int repeats);
int mlx_reshape(
    mlx_array* res,
    const mlx_array a,
    const int* shape,
    size_t shape_num);
int mlx_reshape_x(
    mlx_array* res,
    const mlx_array a,
    const int* shape,
    size_t shape_num,
    const mlx_stream s);
int mlx_right_shift(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_right_shift_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_roll_axes(
    mlx_array* res,
    const mlx_array a,
    const int* shift,
    size_t shift_num,
    int axis);
int mlx_roll_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* shift,
    size_t shift_num,
    int axis,
    const mlx_stream s);
int mlx_roll_axis(
    mlx_array* res,
    const mlx_array a,
    const int* shift,
    size_t shift_num,
    const int* axes,
    size_t axes_num);
int mlx_roll_axis_x(
    mlx_array* res,
    const mlx_array a,
    const int* shift,
    size_t shift_num,
    const int* axes,
    size_t axes_num,
    const mlx_stream s);
int mlx_roll(
    mlx_array* res,
    const mlx_array a,
    const int* shift,
    size_t shift_num);
int mlx_round_x(
    mlx_array* res,
    const mlx_array a,
    int decimals,
    const mlx_stream s);
int mlx_round(mlx_array* res, const mlx_array a);
int mlx_rsqrt(mlx_array* res, const mlx_array a);
int mlx_rsqrt_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_scatter(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num);
int mlx_scatter_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s);
int mlx_scatter_add(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num);
int mlx_scatter_add_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s);
int mlx_scatter_add_axis(
    mlx_array* res,
    const mlx_array a,
    const mlx_array indices,
    const mlx_array values,
    int axis);
int mlx_scatter_add_axis_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array indices,
    const mlx_array values,
    int axis,
    const mlx_stream s);
int mlx_scatter_max(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num);
int mlx_scatter_max_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s);
int mlx_scatter_min(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num);
int mlx_scatter_min_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s);
int mlx_scatter_prod(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num);
int mlx_scatter_prod_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_vector_array indices,
    const mlx_array updates,
    const int* axes,
    size_t axes_num,
    const mlx_stream s);
int mlx_sigmoid(mlx_array* res, const mlx_array a);
int mlx_sigmoid_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_sign(mlx_array* res, const mlx_array a);
int mlx_sign_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_sin(mlx_array* res, const mlx_array a);
int mlx_sin_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_sinh(mlx_array* res, const mlx_array a);
int mlx_sinh_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_slice(
    mlx_array* res,
    const mlx_array a,
    const int* start,
    size_t start_num,
    const int* stop,
    size_t stop_num,
    const int* strides,
    size_t strides_num);
int mlx_slice_dynamic(
    mlx_array* res,
    const mlx_array a,
    const mlx_array start,
    const int* axes,
    size_t axes_num,
    const int* slice_size,
    size_t slice_size_num);
int mlx_slice_dynamic_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array start,
    const int* axes,
    size_t axes_num,
    const int* slice_size,
    size_t slice_size_num,
    const mlx_stream s);
int mlx_slice_update(
    mlx_array* res,
    const mlx_array src,
    const mlx_array update,
    const int* start,
    size_t start_num,
    const int* stop,
    size_t stop_num,
    const int* strides,
    size_t strides_num);
int mlx_slice_update_dynamic(
    mlx_array* res,
    const mlx_array src,
    const mlx_array update,
    const mlx_array start,
    const int* axes,
    size_t axes_num);
int mlx_slice_update_dynamic_x(
    mlx_array* res,
    const mlx_array src,
    const mlx_array update,
    const mlx_array start,
    const int* axes,
    size_t axes_num,
    const mlx_stream s);
int mlx_softmax_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num);
int mlx_softmax_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool precise,
    const mlx_stream s);
int mlx_softmax_axis(mlx_array* res, const mlx_array a, int axis);
int mlx_softmax_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool precise,
    const mlx_stream s);
int mlx_softmax(mlx_array* res, const mlx_array a);
int mlx_sort_axis(mlx_array* res, const mlx_array a, int axis);
int mlx_sort_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    const mlx_stream s);
int mlx_sort(mlx_array* res, const mlx_array a);
int mlx_split_x(
    mlx_vector_array* res,
    const mlx_array a,
    int num_splits,
    int axis,
    const mlx_stream s);
int mlx_split_sections_x(
    mlx_vector_array* res,
    const mlx_array a,
    const int* indices,
    size_t indices_num,
    int axis);
int mlx_split(mlx_vector_array* res, const mlx_array a, int num_splits);
int mlx_split_sections(
    mlx_vector_array* res,
    const mlx_array a,
    const int* indices,
    size_t indices_num);
int mlx_sqrt(mlx_array* res, const mlx_array a);
int mlx_sqrt_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_square(mlx_array* res, const mlx_array a);
int mlx_square_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_squeeze_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num);
int mlx_squeeze_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    const mlx_stream s);
int mlx_squeeze_axis(mlx_array* res, const mlx_array a, int axis);
int mlx_squeeze_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    const mlx_stream s);
int mlx_squeeze(mlx_array* res, const mlx_array a);
int mlx_stack_axis(mlx_array* res, const mlx_vector_array arrays, int axis);
int mlx_stack_axis_x(
    mlx_array* res,
    const mlx_vector_array arrays,
    int axis,
    const mlx_stream s);
int mlx_stack(mlx_array* res, const mlx_vector_array arrays);
int mlx_std_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num);
int mlx_std_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    int ddof,
    const mlx_stream s);
int mlx_std_axis(mlx_array* res, const mlx_array a, int axis);
int mlx_std_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    int ddof,
    const mlx_stream s);
int mlx_std(mlx_array* res, const mlx_array a, bool keepdims);
int mlx_stop_gradient(mlx_array* res, const mlx_array a);
int mlx_stop_gradient_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_subtract(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_subtract_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const mlx_stream s);
int mlx_sum_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num);
int mlx_sum_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    const mlx_stream s);
int mlx_sum_axis(mlx_array* res, const mlx_array a, int axis);
int mlx_sum_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    const mlx_stream s);
int mlx_sum(mlx_array* res, const mlx_array a, bool keepdims);
int mlx_swapaxes(mlx_array* res, const mlx_array a, int axis1, int axis2);
int mlx_swapaxes_x(
    mlx_array* res,
    const mlx_array a,
    int axis1,
    int axis2,
    const mlx_stream s);
int mlx_take_axis(
    mlx_array* res,
    const mlx_array a,
    const mlx_array indices,
    int axis);
int mlx_take_axis_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array indices,
    int axis,
    const mlx_stream s);
int mlx_take(mlx_array* res, const mlx_array a, const mlx_array indices);
int mlx_take_along_axis(
    mlx_array* res,
    const mlx_array a,
    const mlx_array indices,
    int axis);
int mlx_take_along_axis_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array indices,
    int axis,
    const mlx_stream s);
int mlx_tan(mlx_array* res, const mlx_array a);
int mlx_tan_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_tanh(mlx_array* res, const mlx_array a);
int mlx_tanh_x(mlx_array* res, const mlx_array a, const mlx_stream s);
int mlx_tensordot(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    const int* axes_a,
    size_t axes_a_num,
    const int* axes_b,
    size_t axes_b_num);
int mlx_tensordot_axis(mlx_array* res, const mlx_array a, const mlx_array b);
int mlx_tensordot_axis_x(
    mlx_array* res,
    const mlx_array a,
    const mlx_array b,
    int axis,
    const mlx_stream s);
int mlx_tile(
    mlx_array* res,
    const mlx_array arr,
    const int* reps,
    size_t reps_num);
int mlx_tile_x(
    mlx_array* res,
    const mlx_array arr,
    const int* reps,
    size_t reps_num,
    const mlx_stream s);
int mlx_topk_axis(mlx_array* res, const mlx_array a, int k, int axis);
int mlx_topk_axis_x(
    mlx_array* res,
    const mlx_array a,
    int k,
    int axis,
    const mlx_stream s);
int mlx_topk(mlx_array* res, const mlx_array a, int k);
int mlx_trace_x(
    mlx_array* res,
    const mlx_array a,
    int offset,
    int axis1,
    int axis2,
    mlx_dtype dtype,
    const mlx_stream s);
int mlx_trace(mlx_array* res, const mlx_array a);
int mlx_transpose_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num);
int mlx_transpose_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    const mlx_stream s);
int mlx_transpose(mlx_array* res, const mlx_array a);
int mlx_tri_x(
    mlx_array* res,
    int n,
    int m,
    int k,
    mlx_dtype type,
    const mlx_stream s);
int mlx_tri(mlx_array* res, int n, mlx_dtype type);
int mlx_tril(mlx_array* res, const mlx_array x);
int mlx_tril_x(mlx_array* res, const mlx_array x, int k, const mlx_stream s);
int mlx_triu(mlx_array* res, const mlx_array x);
int mlx_triu_x(mlx_array* res, const mlx_array x, int k, const mlx_stream s);
int mlx_unflatten(
    mlx_array* res,
    const mlx_array a,
    int axis,
    const int* shape,
    size_t shape_num);
int mlx_unflatten_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    const int* shape,
    size_t shape_num,
    const mlx_stream s);
int mlx_var_axes(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num);
int mlx_var_axes_x(
    mlx_array* res,
    const mlx_array a,
    const int* axes,
    size_t axes_num,
    bool keepdims,
    int ddof,
    const mlx_stream s);
int mlx_var_axis(mlx_array* res, const mlx_array a, int axis);
int mlx_var_axis_x(
    mlx_array* res,
    const mlx_array a,
    int axis,
    bool keepdims,
    int ddof,
    const mlx_stream s);
int mlx_var(mlx_array* res, const mlx_array a, bool keepdims);
int mlx_view(mlx_array* res, const mlx_array a, mlx_dtype dtype);
int mlx_view_x(
    mlx_array* res,
    const mlx_array a,
    mlx_dtype dtype,
    const mlx_stream s);
int mlx_where(
    mlx_array* res,
    const mlx_array condition,
    const mlx_array x,
    const mlx_array y);
int mlx_where_x(
    mlx_array* res,
    const mlx_array condition,
    const mlx_array x,
    const mlx_array y,
    const mlx_stream s);
int mlx_zeros(
    mlx_array* res,
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype);
int mlx_zeros_x(
    mlx_array* res,
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    const mlx_stream s);
int mlx_zeros_like(mlx_array* res, const mlx_array a);
int mlx_zeros_like_x(mlx_array* res, const mlx_array a, const mlx_stream s);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
