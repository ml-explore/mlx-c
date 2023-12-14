#include <cstring>

#include "mlx/c/array.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/utils.h"

char* mlx_array_::tostring() {
  std::ostringstream os;
  os << ctx;
  std::string str = os.str();
  char* c_str = (char*)malloc(str.size() + 1);
  memcpy(c_str, str.data(), str.size());
  c_str[str.size()] = '\0';
  return c_str;
}

extern "C" mlx_array mlx_array_from_bool(bool val) {
  return MLX_C_ARRAY(mlx::core::array(val));
}
extern "C" mlx_array mlx_array_from_int(int val) {
  return MLX_C_ARRAY(mlx::core::array(val));
}
extern "C" mlx_array mlx_array_from_float(float val) {
  return MLX_C_ARRAY(mlx::core::array(val));
}
extern "C" mlx_array mlx_array_from_complex(float real_val, float imag_val) {
  std::complex<float> cpp_val(real_val, imag_val);
  return MLX_C_ARRAY(mlx::core::array(cpp_val));
}
extern "C" mlx_array
mlx_array_from_data(void* data, int* shape, int dim, mlx_array_dtype dtype) {
  std::vector<int> cpp_shape;
  cpp_shape.assign(shape, shape + dim);
  mlx::core::Dtype cpp_dtype = MLX_CPP_ARRAY_DTYPE(dtype);
  switch (cpp_dtype) {
    case mlx::core::bool_:
      return MLX_C_ARRAY(mlx::core::array((bool*)data, cpp_shape, cpp_dtype));
    case mlx::core::uint8:
      return MLX_C_ARRAY(
          mlx::core::array((uint8_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::uint16:
      return MLX_C_ARRAY(
          mlx::core::array((uint16_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::uint32:
      return MLX_C_ARRAY(
          mlx::core::array((uint32_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::uint64:
      return MLX_C_ARRAY(
          mlx::core::array((uint64_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::int8:
      return MLX_C_ARRAY(mlx::core::array((int8_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::int16:
      return MLX_C_ARRAY(
          mlx::core::array((int16_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::int32:
      return MLX_C_ARRAY(
          mlx::core::array((int32_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::int64:
      return MLX_C_ARRAY(
          mlx::core::array((int64_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::float16:
      return MLX_C_ARRAY(
          mlx::core::array((mlx::core::float16_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::float32:
      return MLX_C_ARRAY(mlx::core::array((float*)data, cpp_shape, cpp_dtype));
    case mlx::core::bfloat16:
      return MLX_C_ARRAY(
          mlx::core::array((mlx::core::bfloat16_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::complex64:
      return MLX_C_ARRAY(mlx::core::array(
          (mlx::core::complex64_t*)data, cpp_shape, cpp_dtype));
    default:
      return nullptr; // TODO: error
  }
}

extern "C" size_t mlx_array_itemsize(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).itemsize();
}
extern "C" size_t mlx_array_size(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).size();
}
extern "C" size_t mlx_array_nbytes(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).nbytes();
}
extern "C" size_t mlx_array_ndim(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).ndim();
}
extern "C" int* mlx_array_shape(mlx_array arr) {
  return (int*)MLX_CPP_ARRAY(arr).shape().data();
}
extern "C" size_t* mlx_array_strides(mlx_array arr) {
  return (size_t*)MLX_CPP_ARRAY(arr).strides().data();
}
extern "C" int mlx_array_dim(mlx_array arr, int dim) {
  return MLX_CPP_ARRAY(arr).shape(dim);
}
extern "C" mlx_array_dtype mlx_array_get_dtype(mlx_array arr) {
  return MLX_C_ARRAY_DTYPE(MLX_CPP_ARRAY(arr).dtype());
}
