#include "mlx/c/ops.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/utils.h"

extern "C" mlx_array
mlx_divide(mlx_array arr1, mlx_array arr2, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::divide(arr1->ctx, arr2->ctx, stream->ctx));
}

extern "C" mlx_array mlx_arange(
    double start,
    double stop,
    double step,
    mlx_array_dtype dtype,
    mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::arange(
      start, stop, step, MLX_CPP_ARRAY_DTYPE(dtype), stream->ctx));
}

extern "C" mlx_array
mlx_astype(mlx_array a, mlx_array_dtype dtype, mlx_stream stream) {
  return MLX_C_ARRAY(
      mlx::core::astype(a->ctx, MLX_CPP_ARRAY_DTYPE(dtype), stream->ctx));
}
extern "C" mlx_array mlx_as_strided(
    mlx_array a,
    int* shape,
    size_t* strides,
    int dim,
    size_t offset,
    mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::as_strided(
      a->ctx,
      MLX_CPP_INTVEC(shape, dim),
      MLX_CPP_SIZEVEC(strides, dim),
      offset,
      stream->ctx));
}
extern "C" mlx_array mlx_copy(mlx_array a, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::copy(a->ctx, stream->ctx));
}
extern "C" mlx_array mlx_full(
    int* shape,
    int dim,
    mlx_array vals,
    mlx_array_dtype dtype,
    mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::full(
      MLX_CPP_INTVEC(shape, dim),
      vals->ctx,
      MLX_CPP_ARRAY_DTYPE(dtype),
      stream->ctx));
}
extern "C" mlx_array
mlx_zeros(int* shape, int dim, mlx_array_dtype dtype, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::zeros(
      MLX_CPP_INTVEC(shape, dim), MLX_CPP_ARRAY_DTYPE(dtype), stream->ctx));
}
extern "C" mlx_array mlx_zeros_like(mlx_array a, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::zeros_like(a->ctx, stream->ctx));
}
extern "C" mlx_array
mlx_ones(int* shape, int dim, mlx_array_dtype dtype, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::ones(
      MLX_CPP_INTVEC(shape, dim), MLX_CPP_ARRAY_DTYPE(dtype), stream->ctx));
}
extern "C" mlx_array mlx_ones_like(mlx_array a, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::ones_like(a->ctx, stream->ctx));
}
extern "C" mlx_array
mlx_eye(int n, int m, int k, mlx_array_dtype dtype, mlx_stream stream) {
  return MLX_C_ARRAY(
      mlx::core::eye(n, m, k, MLX_CPP_ARRAY_DTYPE(dtype), stream->ctx));
}
extern "C" mlx_array
mlx_identity(int n, mlx_array_dtype dtype, mlx_stream stream) {
  return MLX_C_ARRAY(
      mlx::core::identity(n, MLX_CPP_ARRAY_DTYPE(dtype), stream->ctx));
}
extern "C" mlx_array
mlx_reshape(mlx_array a, int* shape, int dim, mlx_stream stream) {
  return MLX_C_ARRAY(
      mlx::core::reshape(a->ctx, MLX_CPP_INTVEC(shape, dim), stream->ctx));
}
extern "C" mlx_array
mlx_squeeze(mlx_array a, int* axes, int n, mlx_stream stream) {
  return MLX_C_ARRAY(
      mlx::core::squeeze(a->ctx, MLX_CPP_INTVEC(axes, n), stream->ctx));
}
extern "C" mlx_array mlx_squeeze_all(mlx_array a, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::squeeze(a->ctx, stream->ctx));
}
extern "C" mlx_array
mlx_expand_dims(mlx_array a, int* axes, int n, mlx_stream stream) {
  return MLX_C_ARRAY(
      mlx::core::expand_dims(a->ctx, MLX_CPP_INTVEC(axes, n), stream->ctx));
}
extern "C" mlx_array mlx_slice(
    mlx_array a,
    int* start,
    int* stop,
    int* strides,
    int n,
    mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::slice(
      a->ctx,
      MLX_CPP_INTVEC(start, n),
      MLX_CPP_INTVEC(stop, n),
      MLX_CPP_INTVEC(strides, n),
      stream->ctx));
}

extern "C" mlx_array*
mlx_split_in_n(mlx_array a, int num_splits, int axis, mlx_stream stream) {
  return MLX_C_ARRAYS(mlx::core::split(a->ctx, num_splits, axis, stream->ctx));
}
extern "C" mlx_array*
mlx_split(mlx_array a, int* indices, int n, int axis, mlx_stream stream) {
  return MLX_C_ARRAYS(
      mlx::core::split(a->ctx, MLX_CPP_INTVEC(indices, n), axis, stream->ctx));
}
extern "C" mlx_array
mlx_concatenate(mlx_array* arrays, size_t n, int axis, mlx_stream stream) {
  return MLX_C_ARRAY(
      mlx::core::concatenate(MLX_CPP_ARRVEC(arrays, n), axis, stream->ctx));
}
extern "C" mlx_array
mlx_transpose(mlx_array a, int* axes, int n, mlx_stream stream) {
  return MLX_C_ARRAY(
      mlx::core::transpose(a->ctx, MLX_CPP_INTVEC(axes, n), stream->ctx));
}
extern "C" mlx_array mlx_transpose_all(mlx_array a, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::transpose(a->ctx, stream->ctx));
}
extern "C" mlx_array mlx_pad(
    mlx_array a,
    int* axes,
    int* low_pad_size,
    int* high_pad_size,
    int n,
    mlx_array pad_value,
    mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::pad(
      a->ctx,
      MLX_CPP_INTVEC(axes, n),
      MLX_CPP_INTVEC(low_pad_size, n),
      MLX_CPP_INTVEC(high_pad_size, n),
      pad_value->ctx,
      stream->ctx));
}
extern "C" mlx_array
mlx_broadcast_to(mlx_array a, int* shape, int dim, mlx_stream stream) {
  return MLX_C_ARRAY(
      mlx::core::broadcast_to(a->ctx, MLX_CPP_INTVEC(shape, dim), stream->ctx));
}
extern "C" mlx_array*
mlx_broadcast_arrays(mlx_array* inputs, size_t n, mlx_stream stream) {
  return MLX_C_ARRAYS(
      mlx::core::broadcast_arrays(MLX_CPP_ARRVEC(inputs, n), stream->ctx));
}
extern "C" mlx_array mlx_equal(mlx_array a, mlx_array b, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::equal(a->ctx, b->ctx, stream->ctx));
}
extern "C" mlx_array
mlx_not_equal(mlx_array a, mlx_array b, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::not_equal(a->ctx, b->ctx, stream->ctx));
}
extern "C" mlx_array mlx_greater(mlx_array a, mlx_array b, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::greater(a->ctx, b->ctx, stream->ctx));
}
extern "C" mlx_array
mlx_greater_equal(mlx_array a, mlx_array b, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::greater_equal(a->ctx, b->ctx, stream->ctx));
}
extern "C" mlx_array mlx_less(mlx_array a, mlx_array b, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::less(a->ctx, b->ctx, stream->ctx));
}
extern "C" mlx_array
mlx_less_equal(mlx_array a, mlx_array b, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::less_equal(a->ctx, b->ctx, stream->ctx));
}
extern "C" mlx_array
mlx_array_equal(mlx_array a, mlx_array b, bool equal_nan, mlx_stream stream) {
  return MLX_C_ARRAY(
      mlx::core::array_equal(a->ctx, b->ctx, equal_nan, stream->ctx));
}
extern "C" mlx_array
mlx_where(mlx_array condition, mlx_array x, mlx_array y, mlx_stream stream) {
  return MLX_C_ARRAY(
      mlx::core::where(condition->ctx, x->ctx, y->ctx, stream->ctx));
}
extern "C" mlx_array
mlx_all_all(mlx_array a, bool keepdims, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::all(a->ctx, keepdims, stream->ctx));
}
extern "C" mlx_array mlx_allclose(
    mlx_array a,
    mlx_array b,
    double rtol,
    double atol,
    mlx_stream stream) {
  return MLX_C_ARRAY(
      mlx::core::allclose(a->ctx, b->ctx, rtol, atol, stream->ctx));
}
extern "C" mlx_array
mlx_all(mlx_array a, int* axes, int n, bool keepdims, mlx_stream stream) {
  return MLX_C_ARRAY(
      mlx::core::all(a->ctx, MLX_CPP_INTVEC(axes, n), keepdims, stream->ctx));
}
extern "C" mlx_array
mlx_any_all(mlx_array a, bool keepdims, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::any(a->ctx, keepdims, stream->ctx));
}
extern "C" mlx_array
mlx_any(mlx_array a, int* axes, int n, bool keepdims, mlx_stream stream) {
  return MLX_C_ARRAY(
      mlx::core::any(a->ctx, MLX_CPP_INTVEC(axes, n), keepdims, stream->ctx));
}
extern "C" mlx_array
mlx_sum_all(mlx_array a, bool keepdims, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::sum(a->ctx, keepdims, stream->ctx));
}
extern "C" mlx_array
mlx_sum(mlx_array a, int* axes, int n, bool keepdims, mlx_stream stream) {
  return MLX_C_ARRAY(
      mlx::core::sum(a->ctx, MLX_CPP_INTVEC(axes, n), keepdims, stream->ctx));
}
extern "C" mlx_array
mlx_mean_all(mlx_array a, bool keepdims, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::mean(a->ctx, keepdims, stream->ctx));
}
extern "C" mlx_array
mlx_mean(mlx_array a, int* axes, int n, bool keepdims, mlx_stream stream) {
  return MLX_C_ARRAY(
      mlx::core::mean(a->ctx, MLX_CPP_INTVEC(axes, n), keepdims, stream->ctx));
}
extern "C" mlx_array
mlx_var_all(mlx_array a, bool keepdims, int ddof, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::var(a->ctx, keepdims, ddof, stream->ctx));
}
extern "C" mlx_array mlx_var(
    mlx_array a,
    int* axes,
    int n,
    bool keepdims,
    int ddof,
    mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::var(
      a->ctx, MLX_CPP_INTVEC(axes, n), keepdims, ddof, stream->ctx));
}
extern "C" mlx_array
mlx_prod_all(mlx_array a, bool keepdims, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::prod(a->ctx, keepdims, stream->ctx));
}
extern "C" mlx_array
mlx_prod(mlx_array a, int* axes, int n, bool keepdims, mlx_stream stream) {
  return MLX_C_ARRAY(
      mlx::core::prod(a->ctx, MLX_CPP_INTVEC(axes, n), keepdims, stream->ctx));
}
extern "C" mlx_array
mlx_max_all(mlx_array a, bool keepdims, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::max(a->ctx, keepdims, stream->ctx));
}
extern "C" mlx_array
mlx_max(mlx_array a, int* axes, int n, bool keepdims, mlx_stream stream) {
  return MLX_C_ARRAY(
      mlx::core::max(a->ctx, MLX_CPP_INTVEC(axes, n), keepdims, stream->ctx));
}
extern "C" mlx_array
mlx_min_all(mlx_array a, bool keepdims, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::min(a->ctx, keepdims, stream->ctx));
}
extern "C" mlx_array
mlx_min(mlx_array a, int* axes, int n, bool keepdims, mlx_stream stream) {
  return MLX_C_ARRAY(
      mlx::core::min(a->ctx, MLX_CPP_INTVEC(axes, n), keepdims, stream->ctx));
}
extern "C" mlx_array
mlx_argmin_all(mlx_array a, bool keepdims, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::argmin(a->ctx, keepdims, stream->ctx));
}
extern "C" mlx_array
mlx_argmin(mlx_array a, int axis, bool keepdims, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::argmin(a->ctx, axis, keepdims, stream->ctx));
}
extern "C" mlx_array
mlx_argmax_all(mlx_array a, bool keepdims, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::argmax(a->ctx, keepdims, stream->ctx));
}
extern "C" mlx_array
mlx_argmax(mlx_array a, int axis, bool keepdims, mlx_stream stream) {
  return MLX_C_ARRAY(mlx::core::argmax(a->ctx, axis, keepdims, stream->ctx));
}
