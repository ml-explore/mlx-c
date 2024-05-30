/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include <stdio.h>

#ifndef MLX_OPS_TRY_H
#define MLX_OPS_TRY_H
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

mlx_array_result mlx_abs_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_add_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_addmm_try(
    mlx_array c,
    mlx_array a,
    mlx_array b,
    float alpha,
    float beta,
    mlx_stream s);
mlx_array_result mlx_all_axes_try(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array_result
mlx_all_axis_try(mlx_array a, int axis, bool keepdims, mlx_stream s);
mlx_array_result mlx_all_all_try(mlx_array a, bool keepdims, mlx_stream s);
mlx_array_result mlx_allclose_try(
    mlx_array a,
    mlx_array b,
    double rtol,
    double atol,
    bool equal_nan,
    mlx_stream s);
mlx_array_result mlx_any_try(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array_result mlx_any_all_try(mlx_array a, bool keepdims, mlx_stream s);
mlx_array_result mlx_arange_try(
    double start,
    double stop,
    double step,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array_result mlx_arccos_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_arccosh_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_arcsin_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_arcsinh_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_arctan_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_arctan2_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_arctanh_try(mlx_array a, mlx_stream s);
mlx_array_result
mlx_argmax_try(mlx_array a, int axis, bool keepdims, mlx_stream s);
mlx_array_result mlx_argmax_all_try(mlx_array a, bool keepdims, mlx_stream s);
mlx_array_result
mlx_argmin_try(mlx_array a, int axis, bool keepdims, mlx_stream s);
mlx_array_result mlx_argmin_all_try(mlx_array a, bool keepdims, mlx_stream s);
mlx_array_result
mlx_argpartition_try(mlx_array a, int kth, int axis, mlx_stream s);
mlx_array_result mlx_argpartition_all_try(mlx_array a, int kth, mlx_stream s);
mlx_array_result mlx_argsort_try(mlx_array a, int axis, mlx_stream s);
mlx_array_result mlx_argsort_all_try(mlx_array a, mlx_stream s);
mlx_array_result
mlx_array_equal_try(mlx_array a, mlx_array b, bool equal_nan, mlx_stream s);
mlx_array_result mlx_as_strided_try(
    mlx_array a,
    const int* shape,
    size_t num_shape,
    const size_t* strides,
    size_t num_strides,
    size_t offset,
    mlx_stream s);
mlx_array_result
mlx_astype_try(mlx_array a, mlx_array_dtype dtype, mlx_stream s);
mlx_array_result mlx_atleast_1d_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_atleast_2d_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_atleast_3d_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_bitwise_and_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_bitwise_or_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_bitwise_xor_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_block_masked_mm_try(
    mlx_array a,
    mlx_array b,
    int block_size,
    mlx_array mask_out,
    mlx_array mask_lhs,
    mlx_array mask_rhs,
    mlx_stream s);
mlx_vector_array_result mlx_broadcast_arrays_try(
    const mlx_vector_array inputs,
    mlx_stream s);
mlx_array_result mlx_broadcast_to_try(
    mlx_array a,
    const int* shape,
    size_t num_shape,
    mlx_stream s);
mlx_array_result mlx_ceil_try(mlx_array a, mlx_stream s);
mlx_array_result
mlx_clip_try(mlx_array a, mlx_array a_min, mlx_array a_max, mlx_stream s);
mlx_array_result
mlx_concatenate_try(const mlx_vector_array arrays, int axis, mlx_stream s);
mlx_array_result mlx_concatenate_all_try(
    const mlx_vector_array arrays,
    mlx_stream s);
mlx_array_result mlx_conjugate_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_conv1d_try(
    mlx_array input,
    mlx_array weight,
    int stride,
    int padding,
    int dilation,
    int groups,
    mlx_stream s);
mlx_array_result mlx_conv2d_try(
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
mlx_array_result mlx_conv3d_try(
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
mlx_array_result mlx_conv_general_try(
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
mlx_array_result mlx_copy_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_cos_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_cosh_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_cummax_try(
    mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    mlx_stream s);
mlx_array_result mlx_cummin_try(
    mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    mlx_stream s);
mlx_array_result mlx_cumprod_try(
    mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    mlx_stream s);
mlx_array_result mlx_cumsum_try(
    mlx_array a,
    int axis,
    bool reverse,
    bool inclusive,
    mlx_stream s);
mlx_array_result mlx_degrees_try(mlx_array a, mlx_stream s);
mlx_vector_array_result mlx_depends_try(
    const mlx_vector_array inputs,
    const mlx_vector_array dependencies);
mlx_array_result mlx_dequantize_try(
    mlx_array w,
    mlx_array scales,
    mlx_array biases,
    int group_size,
    int bits,
    mlx_stream s);
mlx_array_result mlx_diag_try(mlx_array a, int k, mlx_stream s);
mlx_array_result
mlx_diagonal_try(mlx_array a, int offset, int axis1, int axis2, mlx_stream s);
mlx_array_result mlx_divide_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_vector_array_result mlx_divmod_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_equal_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_erf_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_erfinv_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_exp_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_expand_dims_try(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_expm1_try(mlx_array a, mlx_stream s);
mlx_array_result
mlx_eye_try(int n, int m, int k, mlx_array_dtype dtype, mlx_stream s);
mlx_array_result
mlx_flatten_try(mlx_array a, int start_axis, int end_axis, mlx_stream s);
mlx_array_result mlx_floor_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_floor_divide_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_full_try(
    const int* shape,
    size_t num_shape,
    mlx_array vals,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array_result mlx_gather_try(
    mlx_array a,
    const mlx_vector_array indices,
    const int* axes,
    size_t num_axes,
    const int* slice_sizes,
    size_t num_slice_sizes,
    mlx_stream s);
mlx_array_result mlx_gather_mm_try(
    mlx_array a,
    mlx_array b,
    mlx_array lhs_indices,
    mlx_array rhs_indices,
    mlx_stream s);
mlx_array_result mlx_gather_qmm_try(
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
mlx_array_result mlx_greater_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_greater_equal_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_identity_try(int n, mlx_array_dtype dtype, mlx_stream s);
mlx_array_result mlx_inner_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_isclose_try(
    mlx_array a,
    mlx_array b,
    double rtol,
    double atol,
    bool equal_nan,
    mlx_stream s);
mlx_array_result mlx_isinf_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_isnan_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_isneginf_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_isposinf_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_left_shift_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_less_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_less_equal_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_linspace_try(
    double start,
    double stop,
    int num,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array_result mlx_log_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_log10_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_log1p_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_log2_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_logaddexp_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_logical_and_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_logical_not_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_logical_or_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_logsumexp_try(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array_result
mlx_logsumexp_all_try(mlx_array a, bool keepdims, mlx_stream s);
mlx_array_result mlx_matmul_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_max_try(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array_result mlx_max_all_try(mlx_array a, bool keepdims, mlx_stream s);
mlx_array_result mlx_maximum_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_mean_try(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array_result mlx_mean_all_try(mlx_array a, bool keepdims, mlx_stream s);
mlx_vector_array_result mlx_meshgrid_try(
    const mlx_vector_array arrays,
    bool sparse,
    mlx_string indexing,
    mlx_stream s);
mlx_array_result mlx_min_try(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array_result mlx_min_all_try(mlx_array a, bool keepdims, mlx_stream s);
mlx_array_result mlx_minimum_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result
mlx_moveaxis_try(mlx_array a, int source, int destination, mlx_stream s);
mlx_array_result mlx_multiply_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_negative_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_not_equal_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_number_of_elements_try(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool inverted,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array_result mlx_ones_try(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array_result mlx_ones_like_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_outer_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_pad_try(
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
mlx_partition_try(mlx_array a, int kth, int axis, mlx_stream s);
mlx_array_result mlx_partition_all_try(mlx_array a, int kth, mlx_stream s);
mlx_array_result mlx_power_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_prod_try(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array_result mlx_prod_all_try(mlx_array a, bool keepdims, mlx_stream s);
mlx_vector_array_result
mlx_quantize_try(mlx_array w, int group_size, int bits, mlx_stream s);
mlx_array_result mlx_quantized_matmul_try(
    mlx_array x,
    mlx_array w,
    mlx_array scales,
    mlx_array biases,
    bool transpose,
    int group_size,
    int bits,
    mlx_stream s);
mlx_array_result mlx_radians_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_reciprocal_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_remainder_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result
mlx_repeat_try(mlx_array arr, int repeats, int axis, mlx_stream s);
mlx_array_result mlx_repeat_all_try(mlx_array arr, int repeats, mlx_stream s);
mlx_array_result
mlx_reshape_try(mlx_array a, const int* shape, size_t num_shape, mlx_stream s);
mlx_array_result mlx_right_shift_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_round_try(mlx_array a, int decimals, mlx_stream s);
mlx_array_result mlx_rsqrt_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_scatter_try(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_scatter_add_try(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_scatter_max_try(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_scatter_min_try(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_scatter_prod_try(
    mlx_array a,
    const mlx_vector_array indices,
    mlx_array updates,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_sigmoid_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_sign_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_sin_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_sinh_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_slice_try(
    mlx_array a,
    const int* start,
    size_t num_start,
    const int* stop,
    size_t num_stop,
    const int* strides,
    size_t num_strides,
    mlx_stream s);
mlx_array_result mlx_slice_update_try(
    mlx_array src,
    mlx_array update,
    const int* start,
    size_t num_start,
    const int* stop,
    size_t num_stop,
    const int* strides,
    size_t num_strides,
    mlx_stream s);
mlx_array_result mlx_softmax_try(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool precise,
    mlx_stream s);
mlx_array_result mlx_softmax_all_try(mlx_array a, bool precise, mlx_stream s);
mlx_array_result mlx_sort_try(mlx_array a, int axis, mlx_stream s);
mlx_array_result mlx_sort_all_try(mlx_array a, mlx_stream s);
mlx_vector_array_result
mlx_split_equal_parts_try(mlx_array a, int num_splits, int axis, mlx_stream s);
mlx_vector_array_result mlx_split_try(
    mlx_array a,
    const int* indices,
    size_t num_indices,
    int axis,
    mlx_stream s);
mlx_array_result mlx_sqrt_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_square_try(mlx_array a, mlx_stream s);
mlx_array_result
mlx_squeeze_try(mlx_array a, const int* axes, size_t num_axes, mlx_stream s);
mlx_array_result mlx_squeeze_all_try(mlx_array a, mlx_stream s);
mlx_array_result
mlx_stack_try(const mlx_vector_array arrays, int axis, mlx_stream s);
mlx_array_result mlx_stack_all_try(const mlx_vector_array arrays, mlx_stream s);
mlx_array_result mlx_std_try(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    int ddof,
    mlx_stream s);
mlx_array_result
mlx_std_all_try(mlx_array a, bool keepdims, int ddof, mlx_stream s);
mlx_array_result mlx_stop_gradient_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_subtract_try(mlx_array a, mlx_array b, mlx_stream s);
mlx_array_result mlx_sum_try(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array_result mlx_sum_all_try(mlx_array a, bool keepdims, mlx_stream s);
mlx_array_result
mlx_swapaxes_try(mlx_array a, int axis1, int axis2, mlx_stream s);
mlx_array_result
mlx_take_try(mlx_array a, mlx_array indices, int axis, mlx_stream s);
mlx_array_result mlx_take_all_try(mlx_array a, mlx_array indices, mlx_stream s);
mlx_array_result
mlx_take_along_axis_try(mlx_array a, mlx_array indices, int axis, mlx_stream s);
mlx_array_result mlx_tan_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_tanh_try(mlx_array a, mlx_stream s);
mlx_array_result mlx_tensordot_try(
    mlx_array a,
    mlx_array b,
    const int* axes_a,
    size_t num_axes_a,
    const int* axes_b,
    size_t num_axes_b,
    mlx_stream s);
mlx_array_result
mlx_tensordot_along_axis_try(mlx_array a, mlx_array b, int axis, mlx_stream s);
mlx_array_result
mlx_tile_try(mlx_array arr, const int* reps, size_t num_reps, mlx_stream s);
mlx_array_result mlx_topk_try(mlx_array a, int k, int axis, mlx_stream s);
mlx_array_result mlx_topk_all_try(mlx_array a, int k, mlx_stream s);
mlx_array_result mlx_trace_try(
    mlx_array a,
    int offset,
    int axis1,
    int axis2,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array_result
mlx_transpose_try(mlx_array a, const int* axes, size_t num_axes, mlx_stream s);
mlx_array_result mlx_transpose_all_try(mlx_array a, mlx_stream s);
mlx_array_result
mlx_tri_try(int n, int m, int k, mlx_array_dtype type, mlx_stream s);
mlx_array_result mlx_tril_try(mlx_array x, int k, mlx_stream s);
mlx_array_result mlx_triu_try(mlx_array x, int k, mlx_stream s);
mlx_array_result mlx_var_try(
    mlx_array a,
    const int* axes,
    size_t num_axes,
    bool keepdims,
    int ddof,
    mlx_stream s);
mlx_array_result
mlx_var_all_try(mlx_array a, bool keepdims, int ddof, mlx_stream s);
mlx_array_result
mlx_where_try(mlx_array condition, mlx_array x, mlx_array y, mlx_stream s);
mlx_array_result mlx_zeros_try(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array_result mlx_zeros_like_try(mlx_array a, mlx_stream s);

#ifdef __cplusplus
}
#endif

#endif
