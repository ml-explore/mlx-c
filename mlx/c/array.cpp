/* Copyright © 2023-2024 Apple Inc. */

#include <cstring>

#include "mlx/c/array.h"
#include "mlx/c/object.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/string.h"

mlx_string mlx_array_::tostring() {
  MLX_TRY_CATCH(std::ostringstream os; os << ctx; std::string str = os.str();
                return new mlx_string_(str);
                , return nullptr);
}

mlx_string mlx_vector_array_::tostring() {
  MLX_TRY_CATCH(std::ostringstream os;
                os << "vector of arrays (size=" << ctx.size() << ")";
                std::string str = os.str();
                return new mlx_string_(str);
                , return nullptr);
}

mlx_string mlx_vector_vector_array_::tostring() {
  MLX_TRY_CATCH(std::ostringstream os;
                os << "vector of vector of arrays (size=" << ctx.size() << ")";
                std::string str = os.str();
                return new mlx_string_(str);
                , return nullptr);
}

extern "C" mlx_vector_array mlx_vector_array_new() {
  RETURN_MLX_C_VECTOR_ARRAY();
}

mlx_vector_array mlx_vector_array_from_arrays(
    mlx_array* arrs,
    size_t num_arrs) {
  std::vector<mlx::core::array> cpp_arrs;
  for (size_t i = 0; i < num_arrs; i++) {
    cpp_arrs.push_back(arrs[i]->ctx);
  }
  RETURN_MLX_C_VECTOR_ARRAY(cpp_arrs);
}

extern "C" mlx_vector_array mlx_vector_array_from_array(const mlx_array arr) {
  RETURN_MLX_C_VECTOR_ARRAY({arr->ctx});
}

extern "C" void mlx_vector_array_add(
    mlx_vector_array vec,
    const mlx_array arr) {
  MLX_TRY_CATCH(vec->ctx.push_back(arr->ctx);, )
}

extern "C" void mlx_vector_array_add_arrays(
    mlx_vector_array vec,
    const mlx_array* arrs,
    size_t num_arrs) {
  MLX_TRY_CATCH(
      for (size_t i = 0; i < num_arrs;
           i++) { vec->ctx.push_back(arrs[i]->ctx); }, );
}

extern "C" mlx_array mlx_vector_array_get(mlx_vector_array vec, size_t index) {
  RETURN_MLX_C_ARRAY(vec->ctx.at(index));
}

extern "C" size_t mlx_vector_array_size(mlx_vector_array vec) {
  return vec->ctx.size();
}

extern "C" mlx_vector_vector_array mlx_vector_vector_array_new() {
  RETURN_MLX_C_VECTOR_VECTOR_ARRAY();
}

extern "C" void mlx_vector_vector_array_add(
    mlx_vector_vector_array vec2,
    const mlx_vector_array vec) {
  MLX_TRY_CATCH(vec2->ctx.push_back(vec->ctx);, );
}

extern "C" mlx_vector_array mlx_vector_vector_array_get(
    mlx_vector_vector_array vec2,
    size_t index) {
  RETURN_MLX_C_VECTOR_ARRAY(vec2->ctx.at(index));
}

extern "C" mlx_array mlx_vector_vector_array_get2d(
    mlx_vector_vector_array vec2,
    size_t index,
    size_t arr_index) {
  RETURN_MLX_C_ARRAY(vec2->ctx.at(index).at(arr_index));
}

extern "C" size_t mlx_vector_vector_array_size(mlx_vector_vector_array vec2) {
  return vec2->ctx.size();
}

extern "C" mlx_array mlx_array_from_bool(bool val) {
  RETURN_MLX_C_ARRAY(mlx::core::array(val));
}
extern "C" mlx_array mlx_array_from_int(int val) {
  RETURN_MLX_C_ARRAY(mlx::core::array(val));
}
extern "C" mlx_array mlx_array_from_float(float val) {
  RETURN_MLX_C_ARRAY(mlx::core::array(val));
}
extern "C" mlx_array mlx_array_from_complex(float real_val, float imag_val) {
  std::complex<float> cpp_val(real_val, imag_val);
  RETURN_MLX_C_ARRAY(mlx::core::array(cpp_val));
}
extern "C" mlx_array mlx_array_from_data(
    const void* data,
    const int* shape,
    int dim,
    mlx_array_dtype dtype) {
  std::vector<int> cpp_shape;
  cpp_shape.assign(shape, shape + dim);
  mlx::core::Dtype cpp_dtype = MLX_CPP_ARRAY_DTYPE(dtype);
  switch (cpp_dtype) {
    case mlx::core::bool_:
      RETURN_MLX_C_ARRAY(mlx::core::array((bool*)data, cpp_shape, cpp_dtype));
    case mlx::core::uint8:
      RETURN_MLX_C_ARRAY(
          mlx::core::array((uint8_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::uint16:
      RETURN_MLX_C_ARRAY(
          mlx::core::array((uint16_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::uint32:
      RETURN_MLX_C_ARRAY(
          mlx::core::array((uint32_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::uint64:
      RETURN_MLX_C_ARRAY(
          mlx::core::array((uint64_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::int8:
      RETURN_MLX_C_ARRAY(mlx::core::array((int8_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::int16:
      RETURN_MLX_C_ARRAY(
          mlx::core::array((int16_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::int32:
      RETURN_MLX_C_ARRAY(
          mlx::core::array((int32_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::int64:
      RETURN_MLX_C_ARRAY(
          mlx::core::array((int64_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::float16:
      RETURN_MLX_C_ARRAY(
          mlx::core::array((mlx::core::float16_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::float32:
      RETURN_MLX_C_ARRAY(mlx::core::array((float*)data, cpp_shape, cpp_dtype));
    case mlx::core::bfloat16:
      RETURN_MLX_C_ARRAY(
          mlx::core::array((mlx::core::bfloat16_t*)data, cpp_shape, cpp_dtype));
    case mlx::core::complex64:
      RETURN_MLX_C_ARRAY(mlx::core::array(
          (mlx::core::complex64_t*)data, cpp_shape, cpp_dtype));
    default:
      mlx_error("unknown data type");
      return nullptr;
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
  RETURN_MLX_C_ARRAY_DTYPE(MLX_CPP_ARRAY(arr).dtype());
}
extern "C" void mlx_array_eval(mlx_array arr) {
  MLX_CPP_ARRAY(arr).eval();
}

extern "C" bool mlx_array_item_bool(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).item<bool>();
}
extern "C" uint8_t mlx_array_item_uint8(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).item<uint8_t>();
}
extern "C" uint16_t mlx_array_item_uint16(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).item<uint16_t>();
}
extern "C" uint32_t mlx_array_item_uint32(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).item<uint32_t>();
}
extern "C" uint64_t mlx_array_item_uint64(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).item<uint64_t>();
}
extern "C" int8_t mlx_array_item_int8(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).item<int8_t>();
}
extern "C" int16_t mlx_array_item_int16(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).item<int16_t>();
}
extern "C" int32_t mlx_array_item_int32(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).item<int32_t>();
}
extern "C" int64_t mlx_array_item_int64(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).item<int64_t>();
}
extern "C" float mlx_array_item_float32(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).item<float>();
}
extern "C" float _Complex mlx_array_item_complex64(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).item<float _Complex>();
}

#ifdef HAS_FLOAT16
extern "C" float16_t mlx_array_item_float16(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).item<float16_t>();
}
#endif

#ifdef HAS_BFLOAT16
extern "C" bfloat16_t mlx_array_item_bfloat16(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).item<bfloat16_t>();
}
#endif

extern "C" const bool* mlx_array_data_bool(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).data<bool>();
}
extern "C" const uint8_t* mlx_array_data_uint8(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).data<uint8_t>();
}
extern "C" const uint16_t* mlx_array_data_uint16(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).data<uint16_t>();
}
extern "C" const uint32_t* mlx_array_data_uint32(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).data<uint32_t>();
}
extern "C" const uint64_t* mlx_array_data_uint64(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).data<uint64_t>();
}
extern "C" const int8_t* mlx_array_data_int8(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).data<int8_t>();
}
extern "C" const int16_t* mlx_array_data_int16(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).data<int16_t>();
}
extern "C" const int32_t* mlx_array_data_int32(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).data<int32_t>();
}
extern "C" const int64_t* mlx_array_data_int64(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).data<int64_t>();
}
extern "C" const float* mlx_array_data_float32(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).data<float>();
}
extern "C" const float _Complex* mlx_array_data_complex64(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).data<float _Complex>();
}

#ifdef HAS_FLOAT16
extern "C" const float16_t* mlx_array_data_float16(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).data<float16_t>();
}
#endif

#ifdef HAS_BFLOAT16
extern "C" const bfloat16_t* mlx_array_data_bfloat16(mlx_array arr) {
  return MLX_CPP_ARRAY(arr).data<bfloat16_t>();
}
#endif
