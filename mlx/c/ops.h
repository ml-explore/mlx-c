#ifndef MLX_OPS_H
#define MLX_OPS_H

#include "mlx/c/array.h"
#include "mlx/c/stream.h"

#ifdef __cplusplus
extern "C" {
#endif

mlx_array mlx_divide(mlx_array arr1, mlx_array arr2, mlx_stream stream);
mlx_array mlx_arange(
    double start,
    double stop,
    double step,
    mlx_array_dtype dtype,
    mlx_stream stream);
mlx_array mlx_astype(mlx_array a, mlx_array_dtype dtype, mlx_stream stream);
mlx_array mlx_as_strided(
    mlx_array a,
    int* shape,
    size_t* strides,
    int dim,
    size_t offset,
    mlx_stream stream);
mlx_array mlx_copy(mlx_array a, mlx_stream stream);
mlx_array mlx_full(
    int* shape,
    int dim,
    mlx_array vals,
    mlx_array_dtype dtype,
    mlx_stream stream);
mlx_array
mlx_zeros(int* shape, int dim, mlx_array_dtype dtype, mlx_stream stream);
mlx_array mlx_zeros_like(mlx_array a, mlx_stream stream);
mlx_array
mlx_ones(int* shape, int dim, mlx_array_dtype dtype, mlx_stream stream);
mlx_array mlx_ones_like(mlx_array a, mlx_stream stream);
mlx_array
mlx_eye(int n, int m, int k, mlx_array_dtype dtype, mlx_stream stream);
mlx_array mlx_identity(int n, mlx_array_dtype dtype, mlx_stream stream);
mlx_array mlx_reshape(mlx_array a, int* shape, int dim, mlx_stream stream);
mlx_array mlx_squeeze(mlx_array a, int* axes, int n, mlx_stream stream);
mlx_array mlx_squeeze_all(mlx_array a, mlx_stream stream);
mlx_array mlx_expand_dims(mlx_array a, int* axes, int n, mlx_stream stream);
mlx_array mlx_slice(
    mlx_array a,
    int* start,
    int* stop,
    int* strides,
    int n,
    mlx_stream stream);

mlx_array*
mlx_split_in_n(mlx_array a, int num_splits, int axis, mlx_stream stream);
mlx_array*
mlx_split(mlx_array a, int* indices, int n, int axis, mlx_stream stream);
mlx_array
mlx_concatenate(mlx_array* arrays, size_t n, int axis, mlx_stream stream);
mlx_array mlx_transpose(mlx_array a, int* axes, int n, mlx_stream stream);
mlx_array mlx_transpose_all(mlx_array a, mlx_stream stream);
mlx_array mlx_pad(
    mlx_array a,
    int* axes,
    int* low_pad_size,
    int* high_pad_size,
    int n,
    mlx_array pad_value,
    mlx_stream stream);
mlx_array mlx_broadcast_to(mlx_array a, int* shape, int dim, mlx_stream stream);
mlx_array* mlx_broadcast_arrays(mlx_array* inputs, size_t n, mlx_stream stream);
mlx_array mlx_equal(mlx_array a, mlx_array b, mlx_stream stream);
mlx_array mlx_not_equal(mlx_array a, mlx_array b, mlx_stream stream);
mlx_array mlx_greater(mlx_array a, mlx_array b, mlx_stream stream);
mlx_array mlx_greater_equal(mlx_array a, mlx_array b, mlx_stream stream);
mlx_array mlx_less(mlx_array a, mlx_array b, mlx_stream stream);
mlx_array mlx_less_equal(mlx_array a, mlx_array b, mlx_stream stream);
mlx_array
mlx_array_equal(mlx_array a, mlx_array b, bool equal_nan, mlx_stream stream);
mlx_array
mlx_where(mlx_array condition, mlx_array x, mlx_array y, mlx_stream stream);

#ifdef __cplusplus
}
#endif

#endif
