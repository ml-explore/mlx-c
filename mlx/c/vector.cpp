/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/vector.h"
#include "mlx/c/object.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

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

extern "C" mlx_vector_array mlx_vector_array_new_data(
    const mlx_array* data,
    size_t size) {
  std::vector<mlx::core::array> cpp_arrs;
  for (size_t i = 0; i < size; i++) {
    cpp_arrs.push_back(data[i]->ctx);
  }
  RETURN_MLX_C_PTR(new mlx_vector_array_(cpp_arrs))
}

extern "C" mlx_vector_array mlx_vector_array_new_value(const mlx_array val) {
  RETURN_MLX_C_PTR(new mlx_vector_array_({val->ctx}))
}

extern "C" int mlx_vector_array_set_data(
    mlx_vector_array vec,
    const mlx_array* data,
    size_t size) {
  try {
    std::vector<mlx::core::array> cpp_arrs;
    for (size_t i = 0; i < size; i++) {
      cpp_arrs.push_back(data[i]->ctx);
    }
    vec->ctx = cpp_arrs;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_vector_array_set_value(
    mlx_vector_array vec,
    const mlx_array val) {
  try {
    vec->ctx = std::vector<mlx::core::array>({val->ctx});
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
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

extern "C" int
mlx_vector_array_get(mlx_vector_array vec, size_t index, mlx_array res) {
  try {
    res->ctx = vec->ctx.at(index);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" size_t mlx_vector_array_size(mlx_vector_array vec) {
  return vec->ctx.size();
}

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

extern "C" mlx_vector_vector_array mlx_vector_vector_array_new_data(
    const mlx_vector_array* data,
    size_t size) {
  std::vector<std::vector<mlx::core::array>> cpp_arrs;
  for (size_t i = 0; i < size; i++) {
    cpp_arrs.push_back(data[i]->ctx);
  }
  RETURN_MLX_C_PTR(new mlx_vector_vector_array_(cpp_arrs))
}

extern "C" mlx_vector_vector_array mlx_vector_vector_array_new_value(
    const mlx_vector_array val) {
  RETURN_MLX_C_PTR(new mlx_vector_vector_array_({val->ctx}))
}

extern "C" int mlx_vector_vector_array_set_data(
    mlx_vector_vector_array vec,
    const mlx_vector_array* data,
    size_t size) {
  try {
    std::vector<std::vector<mlx::core::array>> cpp_arrs;
    for (size_t i = 0; i < size; i++) {
      cpp_arrs.push_back(data[i]->ctx);
    }
    vec->ctx = cpp_arrs;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_vector_vector_array_set_value(
    mlx_vector_vector_array vec,
    const mlx_vector_array val) {
  try {
    vec->ctx = std::vector<std::vector<mlx::core::array>>({val->ctx});
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
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

extern "C" int mlx_vector_vector_array_get(
    mlx_vector_vector_array vec,
    size_t index,
    mlx_vector_array res) {
  try {
    res->ctx = vec->ctx.at(index);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" size_t mlx_vector_vector_array_size(mlx_vector_vector_array vec) {
  return vec->ctx.size();
}

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

extern "C" mlx_vector_int mlx_vector_int_new_data(
    const int* data,
    size_t size) {
  std::vector<int> cpp_arrs;
  for (size_t i = 0; i < size; i++) {
    cpp_arrs.push_back(data[i]);
  }
  RETURN_MLX_C_PTR(new mlx_vector_int_(cpp_arrs))
}

extern "C" mlx_vector_int mlx_vector_int_new_value(const int val) {
  RETURN_MLX_C_PTR(new mlx_vector_int_({val}))
}

extern "C" int
mlx_vector_int_set_data(mlx_vector_int vec, const int* data, size_t size) {
  try {
    std::vector<int> cpp_arrs;
    for (size_t i = 0; i < size; i++) {
      cpp_arrs.push_back(data[i]);
    }
    vec->ctx = cpp_arrs;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_vector_int_set_value(mlx_vector_int vec, const int val) {
  try {
    vec->ctx = std::vector<int>({val});
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" void
mlx_vector_int_add_data(mlx_vector_int vec, const int* data, size_t size) {
  MLX_TRY_CATCH(
      for (size_t i = 0; i < size; i++) { vec->ctx.push_back(data[i]); }, );
}

extern "C" void mlx_vector_int_add_value(mlx_vector_int vec, const int value) {
  MLX_TRY_CATCH(vec->ctx.push_back(value);, )
}

extern "C" int mlx_vector_int_get(mlx_vector_int vec, size_t index, int* res) {
  try {
    *res = vec->ctx.at(index);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" size_t mlx_vector_int_size(mlx_vector_int vec) {
  return vec->ctx.size();
}

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

extern "C" mlx_vector_vector_int mlx_vector_vector_int_new_data(
    const mlx_vector_int* data,
    size_t size) {
  std::vector<std::vector<int>> cpp_arrs;
  for (size_t i = 0; i < size; i++) {
    cpp_arrs.push_back(data[i]->ctx);
  }
  RETURN_MLX_C_PTR(new mlx_vector_vector_int_(cpp_arrs))
}

extern "C" mlx_vector_vector_int mlx_vector_vector_int_new_value(
    const mlx_vector_int val) {
  RETURN_MLX_C_PTR(new mlx_vector_vector_int_({val->ctx}))
}

extern "C" int mlx_vector_vector_int_set_data(
    mlx_vector_vector_int vec,
    const mlx_vector_int* data,
    size_t size) {
  try {
    std::vector<std::vector<int>> cpp_arrs;
    for (size_t i = 0; i < size; i++) {
      cpp_arrs.push_back(data[i]->ctx);
    }
    vec->ctx = cpp_arrs;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_vector_vector_int_set_value(
    mlx_vector_vector_int vec,
    const mlx_vector_int val) {
  try {
    vec->ctx = std::vector<std::vector<int>>({val->ctx});
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
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

extern "C" int mlx_vector_vector_int_get(
    mlx_vector_vector_int vec,
    size_t index,
    mlx_vector_int res) {
  try {
    res->ctx = vec->ctx.at(index);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" size_t mlx_vector_vector_int_size(mlx_vector_vector_int vec) {
  return vec->ctx.size();
}

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

extern "C" mlx_vector_string mlx_vector_string_new_data(
    const mlx_string* data,
    size_t size) {
  std::vector<std::string> cpp_arrs;
  for (size_t i = 0; i < size; i++) {
    cpp_arrs.push_back(data[i]->ctx);
  }
  RETURN_MLX_C_PTR(new mlx_vector_string_(cpp_arrs))
}

extern "C" mlx_vector_string mlx_vector_string_new_value(const mlx_string val) {
  RETURN_MLX_C_PTR(new mlx_vector_string_({val->ctx}))
}

extern "C" int mlx_vector_string_set_data(
    mlx_vector_string vec,
    const mlx_string* data,
    size_t size) {
  try {
    std::vector<std::string> cpp_arrs;
    for (size_t i = 0; i < size; i++) {
      cpp_arrs.push_back(data[i]->ctx);
    }
    vec->ctx = cpp_arrs;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_vector_string_set_value(
    mlx_vector_string vec,
    const mlx_string val) {
  try {
    vec->ctx = std::vector<std::string>({val->ctx});
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
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

extern "C" int
mlx_vector_string_get(mlx_vector_string vec, size_t index, mlx_string res) {
  try {
    res->ctx = vec->ctx.at(index);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" size_t mlx_vector_string_size(mlx_vector_string vec) {
  return vec->ctx.size();
}
