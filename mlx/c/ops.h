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

#ifdef __cplusplus
}
#endif

#endif
