#ifndef MLX_ARRAY_H
#define MLX_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mlx_array_* mlx_array;

enum mlx_array_dtype {
  MLX_BOOL,
  MLX_UINT8,
  MLX_UINT16,
  MLX_UINT32,
  MLX_UINT64,
  MLX_INT8,
  MLX_INT16,
  MLX_INT32,
  MLX_INT64,
  MLX_FLOAT16,
  MLX_FLOAT32,
  MLX_BFLOAT16,
  MLX_COMPLEX64,
};

mlx_array mlx_array_from_bool(bool val);
mlx_array mlx_array_from_int(int val);
mlx_array mlx_array_from_float(float val);
mlx_array mlx_array_from_complex(float real_val, float imag_val);
mlx_array
mlx_array_from_data(void* data, int* shape, int dim, mlx_array_dtype dtype);

size_t mlx_array_itemsize(mlx_array arr);
size_t mlx_array_size(mlx_array arr);
size_t* mlx_array_strides(mlx_array arr);
size_t mlx_array_nbytes(mlx_array arr);
size_t mlx_array_ndim(mlx_array arr);
int* mlx_array_shape(mlx_array arr);
size_t* mlx_array_strides(mlx_array arr);
int mlx_array_dim(mlx_array arr, int dim);
mlx_array_dtype mlx_array_get_dtype(mlx_array arr);

#ifdef __cplusplus
}
#endif

#endif
