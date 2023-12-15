
#ifndef MLX_OPS_H
#define MLX_OPS_H

#include <stdio.h>

#include "mlx/c/array.h"
#include "mlx/c/stream.h"

#ifdef __cplusplus
extern "C" {
#endif

mlx_array mlx_abs(mlx_array a, mlx_stream s);
mlx_array mlx_add(mlx_array a, mlx_array b, mlx_stream s);
mlx_array
mlx_all(mlx_array a, int* axes, size_t num_axes, bool keepdims, mlx_stream s);
mlx_array mlx_all_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array
mlx_allclose(mlx_array a, mlx_array b, double rtol, double atol, mlx_stream s);
mlx_array
mlx_any(mlx_array a, int* axes, size_t num_axes, bool keepdims, mlx_stream s);
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
    int* shape,
    size_t num_shape,
    size_t* strides,
    size_t num_strides,
    size_t offset,
    mlx_stream s);
mlx_array mlx_astype(mlx_array a, mlx_array_dtype dtype, mlx_stream s);
mlx_array*
mlx_broadcast_arrays(mlx_array* inputs, size_t num_inputs, mlx_stream s);
mlx_array
mlx_broadcast_to(mlx_array a, int* shape, size_t num_shape, mlx_stream s);
mlx_array
mlx_concatenate(mlx_array* arrays, size_t num_arrays, int axis, mlx_stream s);
mlx_array
mlx_concatenate_all(mlx_array* arrays, size_t num_arrays, mlx_stream s);
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
mlx_array mlx_divide(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_equal(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_erf(mlx_array a, mlx_stream s);
mlx_array mlx_erfinv(mlx_array a, mlx_stream s);
mlx_array mlx_exp(mlx_array a, mlx_stream s);
mlx_array
mlx_expand_dims(mlx_array a, int* axes, size_t num_axes, mlx_stream s);
mlx_array mlx_eye(int n, int m, int k, mlx_array_dtype dtype, mlx_stream s);
mlx_array mlx_full(
    int* shape,
    size_t num_shape,
    mlx_array vals,
    mlx_array_dtype dtype,
    mlx_stream s);
mlx_array mlx_gather(
    mlx_array a,
    mlx_array* indices,
    size_t num_indices,
    int* axes,
    size_t num_axes,
    int* slice_sizes,
    size_t num_slice_sizes,
    mlx_stream s);
mlx_array mlx_greater(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_greater_equal(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_identity(int n, mlx_array_dtype dtype, mlx_stream s);
mlx_array mlx_less(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_less_equal(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_load(FILE* in_stream, mlx_stream s);
mlx_array mlx_log(mlx_array a, mlx_stream s);
mlx_array mlx_log10(mlx_array a, mlx_stream s);
mlx_array mlx_log1p(mlx_array a, mlx_stream s);
mlx_array mlx_log2(mlx_array a, mlx_stream s);
mlx_array mlx_logaddexp(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_logical_not(mlx_array a, mlx_stream s);
mlx_array mlx_logsumexp(
    mlx_array a,
    int* axes,
    size_t num_axes,
    bool keepdims,
    mlx_stream s);
mlx_array mlx_logsumexp_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array mlx_matmul(mlx_array a, mlx_array b, mlx_stream s);
mlx_array
mlx_max(mlx_array a, int* axes, size_t num_axes, bool keepdims, mlx_stream s);
mlx_array mlx_max_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array mlx_maximum(mlx_array a, mlx_array b, mlx_stream s);
mlx_array
mlx_mean(mlx_array a, int* axes, size_t num_axes, bool keepdims, mlx_stream s);
mlx_array mlx_mean_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array
mlx_min(mlx_array a, int* axes, size_t num_axes, bool keepdims, mlx_stream s);
mlx_array mlx_min_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array mlx_minimum(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_multiply(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_negative(mlx_array a, mlx_stream s);
mlx_array mlx_not_equal(mlx_array a, mlx_array b, mlx_stream s);
mlx_array
mlx_ones(int* shape, size_t num_shape, mlx_array_dtype dtype, mlx_stream s);
mlx_array mlx_ones_like(mlx_array a, mlx_stream s);
mlx_array mlx_pad(
    mlx_array a,
    int* axes,
    size_t num_axes,
    int* low_pad_size,
    size_t num_low_pad_size,
    int* high_pad_size,
    size_t num_high_pad_size,
    mlx_array pad_value,
    mlx_stream s);
mlx_array mlx_partition(mlx_array a, int kth, int axis, mlx_stream s);
mlx_array mlx_partition_all(mlx_array a, int kth, mlx_stream s);
mlx_array mlx_power(mlx_array a, mlx_array b, mlx_stream s);
mlx_array
mlx_prod(mlx_array a, int* axes, size_t num_axes, bool keepdims, mlx_stream s);
mlx_array mlx_prod_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array mlx_reciprocal(mlx_array a, mlx_stream s);
mlx_array mlx_remainder(mlx_array a, mlx_array b, mlx_stream s);
mlx_array mlx_reshape(mlx_array a, int* shape, size_t num_shape, mlx_stream s);
mlx_array mlx_rsqrt(mlx_array a, mlx_stream s);
void mlx_save(FILE* out_stream, mlx_array a, bool retain_graph);
mlx_array mlx_scatter(
    mlx_array a,
    mlx_array* indices,
    size_t num_indices,
    mlx_array updates,
    int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array mlx_scatter_add(
    mlx_array a,
    mlx_array* indices,
    size_t num_indices,
    mlx_array updates,
    int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array mlx_scatter_max(
    mlx_array a,
    mlx_array* indices,
    size_t num_indices,
    mlx_array updates,
    int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array mlx_scatter_min(
    mlx_array a,
    mlx_array* indices,
    size_t num_indices,
    mlx_array updates,
    int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array mlx_scatter_prod(
    mlx_array a,
    mlx_array* indices,
    size_t num_indices,
    mlx_array updates,
    int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array mlx_sigmoid(mlx_array a, mlx_stream s);
mlx_array mlx_sign(mlx_array a, mlx_stream s);
mlx_array mlx_sin(mlx_array a, mlx_stream s);
mlx_array mlx_sinh(mlx_array a, mlx_stream s);
mlx_array mlx_slice(
    mlx_array a,
    int* start,
    size_t num_start,
    int* stop,
    size_t num_stop,
    int* strides,
    size_t num_strides,
    mlx_stream s);
mlx_array mlx_softmax(mlx_array a, int* axes, size_t num_axes, mlx_stream s);
mlx_array mlx_softmax_all(mlx_array a, mlx_stream s);
mlx_array mlx_sort(mlx_array a, int axis, mlx_stream s);
mlx_array mlx_sort_all(mlx_array a, mlx_stream s);
mlx_array*
mlx_split_equal_parts(mlx_array a, int num_splits, int axis, mlx_stream s);
mlx_array* mlx_split(
    mlx_array a,
    int* indices,
    size_t num_indices,
    int axis,
    mlx_stream s);
mlx_array mlx_sqrt(mlx_array a, mlx_stream s);
mlx_array mlx_square(mlx_array a, mlx_stream s);
mlx_array mlx_squeeze(mlx_array a, int* axes, size_t num_axes, mlx_stream s);
mlx_array mlx_squeeze_all(mlx_array a, mlx_stream s);
mlx_array mlx_stop_gradient(mlx_array a, mlx_stream s);
mlx_array mlx_subtract(mlx_array a, mlx_array b, mlx_stream s);
mlx_array
mlx_sum(mlx_array a, int* axes, size_t num_axes, bool keepdims, mlx_stream s);
mlx_array mlx_sum_all(mlx_array a, bool keepdims, mlx_stream s);
mlx_array mlx_take(mlx_array a, mlx_array indices, int axis, mlx_stream s);
mlx_array mlx_take_all(mlx_array a, mlx_array indices, mlx_stream s);
mlx_array
mlx_take_along_axis(mlx_array a, mlx_array indices, int axis, mlx_stream s);
mlx_array mlx_tan(mlx_array a, mlx_stream s);
mlx_array mlx_tanh(mlx_array a, mlx_stream s);
mlx_array mlx_topk(mlx_array a, int k, int axis, mlx_stream s);
mlx_array mlx_topk_all(mlx_array a, int k, mlx_stream s);
mlx_array mlx_transpose(mlx_array a, int* axes, size_t num_axes, mlx_stream s);
mlx_array mlx_transpose_all(mlx_array a, mlx_stream s);
mlx_array mlx_var(
    mlx_array a,
    int* axes,
    size_t num_axes,
    bool keepdims,
    int ddof,
    mlx_stream s);
mlx_array mlx_var_all(mlx_array a, bool keepdims, int ddof, mlx_stream s);
mlx_array
mlx_where(mlx_array condition, mlx_array x, mlx_array y, mlx_stream s);
mlx_array
mlx_zeros(int* shape, size_t num_shape, mlx_array_dtype dtype, mlx_stream s);
mlx_array mlx_zeros_like(mlx_array a, mlx_stream s);

#ifdef __cplusplus
}
#endif

#endif
