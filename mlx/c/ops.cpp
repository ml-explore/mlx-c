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
