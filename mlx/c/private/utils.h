#ifndef MLX_UTILS_H
#define MLX_UTILS_H

#include <vector>
#include "mlx/c/array.h"
#include "mlx/mlx.h"

static mlx::core::Dtype mlx_cpp_dtypes[] = {
    mlx::core::bool_,
    mlx::core::uint8,
    mlx::core::uint16,
    mlx::core::uint32,
    mlx::core::uint64,
    mlx::core::int8,
    mlx::core::int16,
    mlx::core::int32,
    mlx::core::int64,
    mlx::core::float16,
    mlx::core::float32,
    mlx::core::bfloat16,
    mlx::core::complex64,
};

static mlx_array_dtype mlx_c_dtypes[] = {
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

inline mlx_array* mlx_cpp_vector_array_to_c(
    const std::vector<mlx::core::array>& vec) {
  mlx_array* c_vec = (mlx_array*)malloc(sizeof(mlx_array) * vec.size());
  if (c_vec) {
    for (size_t i = 0; i < vec.size(); i++) {
      c_vec[i] = new mlx_array_(vec[i]);
    }
  }
  return c_vec;
}

inline std::vector<mlx::core::array> mlx_c_vector_array_to_cpp(
    mlx_array* vec,
    int n) {
  std::vector<mlx::core::array> cpp_vec;
  for (size_t i = 0; i < n; i++) {
    cpp_vec.push_back(vec[i]->ctx);
  }
  return cpp_vec;
}

#define MLX_CPP_ARRAY(arr) ((arr)->ctx)
#define MLX_C_ARRAY(arr) (new mlx_array_(arr))
#define MLX_CPP_ARRAY_DTYPE(dtype) (mlx_cpp_dtypes[dtype])
#define MLX_C_ARRAY_DTYPE(dtype) (mlx_c_dtypes[(int)((dtype).val)])
#define MLX_CPP_INTVEC(vals, size) (std::vector<int>((vals), (vals) + (size)))
#define MLX_CPP_SIZEVEC(vals, size) \
  (std::vector<size_t>((vals), (vals) + (size)))
#define MLX_C_ARRAYS(vec) (mlx_cpp_vector_array_to_c(vec))
#define MLX_CPP_ARRVEC(vec, size) (mlx_c_vector_array_to_cpp((vec), (size)))

#endif
