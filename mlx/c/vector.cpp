/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/vector.h"
#include "mlx/c/object.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/tuple.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

/**
 * \defgroup mlx_vector_array A vector of arrays
 * MLX vector of array object.
 */
/**@{*/

mlx_string mlx_vector_array_::tostring() {
  MLX_TRY_CATCH(std::ostringstream os;
                os << "vector of arrays (size=" << ctx.size() << ")";
                std::string str = os.str();
                return new mlx_string_(str);
                , return nullptr);
}

extern "C" mlx_vector_array mlx_vector_array_new() {
  RETURN_MLX_C_PTR(new mlx_vector_array_())
}

extern "C" mlx_vector_array mlx_vector_array_from_data(
    const mlx_array* data,
    size_t size) {
  std::vector<mlx::core::array> cpp_arrs;
  for (size_t i = 0; i < size; i++) {
    cpp_arrs.push_back(data[i]->ctx);
  }
  RETURN_MLX_C_PTR(new mlx_vector_array_(cpp_arrs))
}

extern "C" mlx_vector_array mlx_vector_array_from_value(const mlx_array val) {
  RETURN_MLX_C_PTR(new mlx_vector_array_({val->ctx}))
}

extern "C" void mlx_vector_array_add_data(
    mlx_vector_array vec,
    const mlx_array* data,
    size_t size) {
  MLX_TRY_CATCH(
      for (size_t i = 0; i < size;
           i++) { vec->ctx.push_back(data[i]->ctx); }, );
}

extern "C" void mlx_vector_array_add_value(
    mlx_vector_array vec,
    const mlx_array value) {
  MLX_TRY_CATCH(vec->ctx.push_back(value->ctx);, )
}

extern "C" mlx_array mlx_vector_array_get(mlx_vector_array vec, size_t index) {
  RETURN_MLX_C_PTR(new mlx_array_(vec->ctx.at(index)));
}

extern "C" size_t mlx_vector_array_size(mlx_vector_array vec) {
  return vec->ctx.size();
}

/**@}*/

/**
 * \defgroup mlx_vector_vector_array A vector of vector_arrays
 * MLX vector of vector_array object.
 */
/**@{*/

mlx_string mlx_vector_vector_array_::tostring() {
  MLX_TRY_CATCH(std::ostringstream os;
                os << "vector of vector_arrays (size=" << ctx.size() << ")";
                std::string str = os.str();
                return new mlx_string_(str);
                , return nullptr);
}

extern "C" mlx_vector_vector_array mlx_vector_vector_array_new() {
  RETURN_MLX_C_PTR(new mlx_vector_vector_array_())
}

extern "C" mlx_vector_vector_array mlx_vector_vector_array_from_data(
    const mlx_vector_array* data,
    size_t size) {
  std::vector<std::vector<mlx::core::array>> cpp_arrs;
  for (size_t i = 0; i < size; i++) {
    cpp_arrs.push_back(data[i]->ctx);
  }
  RETURN_MLX_C_PTR(new mlx_vector_vector_array_(cpp_arrs))
}

extern "C" mlx_vector_vector_array mlx_vector_vector_array_from_value(
    const mlx_vector_array val) {
  RETURN_MLX_C_PTR(new mlx_vector_vector_array_({val->ctx}))
}

extern "C" void mlx_vector_vector_array_add_data(
    mlx_vector_vector_array vec,
    const mlx_vector_array* data,
    size_t size) {
  MLX_TRY_CATCH(
      for (size_t i = 0; i < size;
           i++) { vec->ctx.push_back(data[i]->ctx); }, );
}

extern "C" void mlx_vector_vector_array_add_value(
    mlx_vector_vector_array vec,
    const mlx_vector_array value) {
  MLX_TRY_CATCH(vec->ctx.push_back(value->ctx);, )
}

extern "C" mlx_vector_array mlx_vector_vector_array_get(
    mlx_vector_vector_array vec,
    size_t index) {
  RETURN_MLX_C_PTR(new mlx_vector_array_(vec->ctx.at(index)));
}

extern "C" size_t mlx_vector_vector_array_size(mlx_vector_vector_array vec) {
  return vec->ctx.size();
}

/**@}*/

/**
 * \defgroup mlx_vector_int A vector of ints
 * MLX vector of int object.
 */
/**@{*/

mlx_string mlx_vector_int_::tostring() {
  MLX_TRY_CATCH(std::ostringstream os;
                os << "vector of ints (size=" << ctx.size() << ")";
                std::string str = os.str();
                return new mlx_string_(str);
                , return nullptr);
}

extern "C" mlx_vector_int mlx_vector_int_new() {
  RETURN_MLX_C_PTR(new mlx_vector_int_())
}

extern "C" mlx_vector_int mlx_vector_int_from_data(
    const int* data,
    size_t size) {
  std::vector<int> cpp_arrs;
  for (size_t i = 0; i < size; i++) {
    cpp_arrs.push_back(data[i]);
  }
  RETURN_MLX_C_PTR(new mlx_vector_int_(cpp_arrs))
}

extern "C" mlx_vector_int mlx_vector_int_from_value(const int val) {
  RETURN_MLX_C_PTR(new mlx_vector_int_({val}))
}

extern "C" void
mlx_vector_int_add_data(mlx_vector_int vec, const int* data, size_t size) {
  MLX_TRY_CATCH(
      for (size_t i = 0; i < size; i++) { vec->ctx.push_back(data[i]); }, );
}

extern "C" void mlx_vector_int_add_value(mlx_vector_int vec, const int value) {
  MLX_TRY_CATCH(vec->ctx.push_back(value);, )
}

extern "C" int mlx_vector_int_get(mlx_vector_int vec, size_t index) {
  return vec->ctx.at(index);
}

extern "C" size_t mlx_vector_int_size(mlx_vector_int vec) {
  return vec->ctx.size();
}

/**@}*/

/**
 * \defgroup mlx_vector_vector_int A vector of vector_ints
 * MLX vector of vector_int object.
 */
/**@{*/

mlx_string mlx_vector_vector_int_::tostring() {
  MLX_TRY_CATCH(std::ostringstream os;
                os << "vector of vector_ints (size=" << ctx.size() << ")";
                std::string str = os.str();
                return new mlx_string_(str);
                , return nullptr);
}

extern "C" mlx_vector_vector_int mlx_vector_vector_int_new() {
  RETURN_MLX_C_PTR(new mlx_vector_vector_int_())
}

extern "C" mlx_vector_vector_int mlx_vector_vector_int_from_data(
    const mlx_vector_int* data,
    size_t size) {
  std::vector<std::vector<int>> cpp_arrs;
  for (size_t i = 0; i < size; i++) {
    cpp_arrs.push_back(data[i]->ctx);
  }
  RETURN_MLX_C_PTR(new mlx_vector_vector_int_(cpp_arrs))
}

extern "C" mlx_vector_vector_int mlx_vector_vector_int_from_value(
    const mlx_vector_int val) {
  RETURN_MLX_C_PTR(new mlx_vector_vector_int_({val->ctx}))
}

extern "C" void mlx_vector_vector_int_add_data(
    mlx_vector_vector_int vec,
    const mlx_vector_int* data,
    size_t size) {
  MLX_TRY_CATCH(
      for (size_t i = 0; i < size;
           i++) { vec->ctx.push_back(data[i]->ctx); }, );
}

extern "C" void mlx_vector_vector_int_add_value(
    mlx_vector_vector_int vec,
    const mlx_vector_int value) {
  MLX_TRY_CATCH(vec->ctx.push_back(value->ctx);, )
}

extern "C" mlx_vector_int mlx_vector_vector_int_get(
    mlx_vector_vector_int vec,
    size_t index) {
  RETURN_MLX_C_PTR(new mlx_vector_int_(vec->ctx.at(index)));
}

extern "C" size_t mlx_vector_vector_int_size(mlx_vector_vector_int vec) {
  return vec->ctx.size();
}

/**@}*/

/**
 * \defgroup mlx_vector_string A vector of strings
 * MLX vector of string object.
 */
/**@{*/

mlx_string mlx_vector_string_::tostring() {
  MLX_TRY_CATCH(std::ostringstream os;
                os << "vector of strings (size=" << ctx.size() << ")";
                std::string str = os.str();
                return new mlx_string_(str);
                , return nullptr);
}

extern "C" mlx_vector_string mlx_vector_string_new() {
  RETURN_MLX_C_PTR(new mlx_vector_string_())
}

extern "C" mlx_vector_string mlx_vector_string_from_data(
    const mlx_string* data,
    size_t size) {
  std::vector<std::string> cpp_arrs;
  for (size_t i = 0; i < size; i++) {
    cpp_arrs.push_back(data[i]->ctx);
  }
  RETURN_MLX_C_PTR(new mlx_vector_string_(cpp_arrs))
}

extern "C" mlx_vector_string mlx_vector_string_from_value(
    const mlx_string val) {
  RETURN_MLX_C_PTR(new mlx_vector_string_({val->ctx}))
}

extern "C" void mlx_vector_string_add_data(
    mlx_vector_string vec,
    const mlx_string* data,
    size_t size) {
  MLX_TRY_CATCH(
      for (size_t i = 0; i < size;
           i++) { vec->ctx.push_back(data[i]->ctx); }, );
}

extern "C" void mlx_vector_string_add_value(
    mlx_vector_string vec,
    const mlx_string value) {
  MLX_TRY_CATCH(vec->ctx.push_back(value->ctx);, )
}

extern "C" mlx_string mlx_vector_string_get(
    mlx_vector_string vec,
    size_t index) {
  RETURN_MLX_C_PTR(new mlx_string_(vec->ctx.at(index)));
}

extern "C" size_t mlx_vector_string_size(mlx_vector_string vec) {
  return vec->ctx.size();
}

/**@}*/

/**
 * \defgroup mlx_vector_array_dtype A vector of array_dtypes
 * MLX vector of array_dtype object.
 */
/**@{*/

mlx_string mlx_vector_array_dtype_::tostring() {
  MLX_TRY_CATCH(std::ostringstream os;
                os << "vector of array_dtypes (size=" << ctx.size() << ")";
                std::string str = os.str();
                return new mlx_string_(str);
                , return nullptr);
}

extern "C" mlx_vector_array_dtype mlx_vector_array_dtype_new() {
  RETURN_MLX_C_PTR(new mlx_vector_array_dtype_())
}

extern "C" mlx_vector_array_dtype mlx_vector_array_dtype_from_data(
    const mlx_array_dtype* data,
    size_t size) {
  std::vector<mlx::core::Dtype> cpp_arrs;
  for (size_t i = 0; i < size; i++) {
    cpp_arrs.push_back(MLX_CPP_ARRAY_DTYPE(data[i]));
  }
  RETURN_MLX_C_PTR(new mlx_vector_array_dtype_(cpp_arrs))
}

extern "C" mlx_vector_array_dtype mlx_vector_array_dtype_from_value(
    const mlx_array_dtype val) {
  RETURN_MLX_C_PTR(new mlx_vector_array_dtype_({MLX_CPP_ARRAY_DTYPE(val)}))
}

extern "C" void mlx_vector_array_dtype_add_data(
    mlx_vector_array_dtype vec,
    const mlx_array_dtype* data,
    size_t size) {
  MLX_TRY_CATCH(
      for (size_t i = 0; i < size;
           i++) { vec->ctx.push_back(MLX_CPP_ARRAY_DTYPE(data[i])); }, );
}

extern "C" void mlx_vector_array_dtype_add_value(
    mlx_vector_array_dtype vec,
    const mlx_array_dtype value) {
  MLX_TRY_CATCH(vec->ctx.push_back(MLX_CPP_ARRAY_DTYPE(value));, )
}

extern "C" mlx_array_dtype mlx_vector_array_dtype_get(
    mlx_vector_array_dtype vec,
    size_t index) {
  RETURN_MLX_C_ARRAY_DTYPE(vec->ctx.at(index));
}

extern "C" size_t mlx_vector_array_dtype_size(mlx_vector_array_dtype vec) {
  return vec->ctx.size();
}

/**@}*/

/**
 * \defgroup mlx_vector_tuple_string_variant_int_bool_array_dtype A vector of
 * tuple_string_variant_int_bool_array_dtypes MLX vector of
 * tuple_string_variant_int_bool_array_dtype object.
 */
/**@{*/

mlx_string mlx_vector_tuple_string_variant_int_bool_array_dtype_::tostring() {
  MLX_TRY_CATCH(std::ostringstream os; os
                << "vector of tuple_string_variant_int_bool_array_dtypes (size="
                << ctx.size() << ")";
                std::string str = os.str();
                return new mlx_string_(str);
                , return nullptr);
}

extern "C" mlx_vector_tuple_string_variant_int_bool_array_dtype
mlx_vector_tuple_string_variant_int_bool_array_dtype_new() {
  RETURN_MLX_C_PTR(new mlx_vector_tuple_string_variant_int_bool_array_dtype_())
}

extern "C" mlx_vector_tuple_string_variant_int_bool_array_dtype
mlx_vector_tuple_string_variant_int_bool_array_dtype_from_data(
    const mlx_tuple_string_variant_int_bool_array_dtype* data,
    size_t size) {
  std::vector<std::pair<std::string, std::variant<int, bool, mlx::core::Dtype>>>
      cpp_arrs;
  for (size_t i = 0; i < size; i++) {
    cpp_arrs.push_back(data[i]->ctx);
  }
  RETURN_MLX_C_PTR(
      new mlx_vector_tuple_string_variant_int_bool_array_dtype_(cpp_arrs))
}

extern "C" mlx_vector_tuple_string_variant_int_bool_array_dtype
mlx_vector_tuple_string_variant_int_bool_array_dtype_from_value(
    const mlx_tuple_string_variant_int_bool_array_dtype val) {
  RETURN_MLX_C_PTR(
      new mlx_vector_tuple_string_variant_int_bool_array_dtype_({val->ctx}))
}

extern "C" void mlx_vector_tuple_string_variant_int_bool_array_dtype_add_data(
    mlx_vector_tuple_string_variant_int_bool_array_dtype vec,
    const mlx_tuple_string_variant_int_bool_array_dtype* data,
    size_t size) {
  MLX_TRY_CATCH(
      for (size_t i = 0; i < size;
           i++) { vec->ctx.push_back(data[i]->ctx); }, );
}

extern "C" void mlx_vector_tuple_string_variant_int_bool_array_dtype_add_value(
    mlx_vector_tuple_string_variant_int_bool_array_dtype vec,
    const mlx_tuple_string_variant_int_bool_array_dtype value) {
  MLX_TRY_CATCH(vec->ctx.push_back(value->ctx);, )
}

extern "C" mlx_tuple_string_variant_int_bool_array_dtype
mlx_vector_tuple_string_variant_int_bool_array_dtype_get(
    mlx_vector_tuple_string_variant_int_bool_array_dtype vec,
    size_t index) {
  RETURN_MLX_C_PTR(
      new mlx_tuple_string_variant_int_bool_array_dtype_(vec->ctx.at(index)));
}

extern "C" size_t mlx_vector_tuple_string_variant_int_bool_array_dtype_size(
    mlx_vector_tuple_string_variant_int_bool_array_dtype vec) {
  return vec->ctx.size();
}

/**@}*/
