/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/vector.h"
#include "mlx/c/object.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" mlx_vector_array mlx_vector_array_new() {
  return mlx_vector_array_new_({});
}

extern "C" mlx_vector_array mlx_vector_array_new_data(
    const mlx_array* data,
    size_t size) {
  auto vec = mlx_vector_array_new();
  for (size_t i = 0; i < size; i++) {
    mlx_vector_array_get_(vec).push_back(mlx_array_get_(data[i]));
  }
  return vec;
}

extern "C" mlx_vector_array mlx_vector_array_new_value(const mlx_array val) {
  return mlx_vector_array_new_({mlx_array_get_(val)});
}

extern "C" int mlx_vector_array_set_data(
    mlx_vector_array vec,
    const mlx_array* data,
    size_t size) {
  try {
    std::vector<mlx::core::array> cpp_arrs;
    for (size_t i = 0; i < size; i++) {
      cpp_arrs.push_back(mlx_array_get_(data[i]));
    }
    mlx_vector_array_get_(vec) = cpp_arrs;
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
    mlx_vector_array_get_(vec) =
        std::vector<mlx::core::array>({mlx_array_get_(val)});
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" void mlx_vector_array_append_data(
    mlx_vector_array vec,
    const mlx_array* data,
    size_t size) {
  MLX_TRY_CATCH(
      for (size_t i = 0; i < size; i++) {
        mlx_vector_array_get_(vec).push_back(mlx_array_get_(data[i]));
      }, );
}

extern "C" void mlx_vector_array_append_value(
    mlx_vector_array vec,
    const mlx_array value) {
  MLX_TRY_CATCH(mlx_vector_array_get_(vec).push_back(mlx_array_get_(value));, )
}

extern "C" int
mlx_vector_array_get(mlx_vector_array vec, size_t index, mlx_array* res) {
  try {
    mlx_array_set_(res, mlx_vector_array_get_(vec).at(index));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" size_t mlx_vector_array_size(mlx_vector_array vec) {
  return mlx_vector_array_get_(vec).size();
}

extern "C" mlx_vector_vector_array mlx_vector_vector_array_new() {
  return mlx_vector_vector_array_new_({});
}

extern "C" mlx_vector_vector_array mlx_vector_vector_array_new_data(
    const mlx_vector_array* data,
    size_t size) {
  auto vec = mlx_vector_vector_array_new();
  for (size_t i = 0; i < size; i++) {
    mlx_vector_vector_array_get_(vec).push_back(mlx_vector_array_get_(data[i]));
  }
  return vec;
}

extern "C" mlx_vector_vector_array mlx_vector_vector_array_new_value(
    const mlx_vector_array val) {
  return mlx_vector_vector_array_new_({mlx_vector_array_get_(val)});
}

extern "C" int mlx_vector_vector_array_set_data(
    mlx_vector_vector_array vec,
    const mlx_vector_array* data,
    size_t size) {
  try {
    std::vector<std::vector<mlx::core::array>> cpp_arrs;
    for (size_t i = 0; i < size; i++) {
      cpp_arrs.push_back(mlx_vector_array_get_(data[i]));
    }
    mlx_vector_vector_array_get_(vec) = cpp_arrs;
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
    mlx_vector_vector_array_get_(vec) =
        std::vector<std::vector<mlx::core::array>>(
            {mlx_vector_array_get_(val)});
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" void mlx_vector_vector_array_append_data(
    mlx_vector_vector_array vec,
    const mlx_vector_array* data,
    size_t size) {
  MLX_TRY_CATCH(
      for (size_t i = 0; i < size; i++) {
        mlx_vector_vector_array_get_(vec).push_back(
            mlx_vector_array_get_(data[i]));
      }, );
}

extern "C" void mlx_vector_vector_array_append_value(
    mlx_vector_vector_array vec,
    const mlx_vector_array value) {
  MLX_TRY_CATCH(
      mlx_vector_vector_array_get_(vec).push_back(mlx_vector_array_get_(value));
      , )
}

extern "C" int mlx_vector_vector_array_get(
    mlx_vector_vector_array vec,
    size_t index,
    mlx_vector_array* res) {
  try {
    mlx_vector_array_set_(res, mlx_vector_vector_array_get_(vec).at(index));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" size_t mlx_vector_vector_array_size(mlx_vector_vector_array vec) {
  return mlx_vector_vector_array_get_(vec).size();
}

extern "C" mlx_vector_int mlx_vector_int_new() {
  return mlx_vector_int_new_({});
}

extern "C" mlx_vector_int mlx_vector_int_new_data(int* data, size_t size) {
  auto vec = mlx_vector_int_new();
  for (size_t i = 0; i < size; i++) {
    mlx_vector_int_get_(vec).push_back(data[i]);
  }
  return vec;
}

extern "C" mlx_vector_int mlx_vector_int_new_value(int val) {
  return mlx_vector_int_new_({val});
}

extern "C" int
mlx_vector_int_set_data(mlx_vector_int vec, int* data, size_t size) {
  try {
    std::vector<int> cpp_arrs;
    for (size_t i = 0; i < size; i++) {
      cpp_arrs.push_back(data[i]);
    }
    mlx_vector_int_get_(vec) = cpp_arrs;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_vector_int_set_value(mlx_vector_int vec, int val) {
  try {
    mlx_vector_int_get_(vec) = std::vector<int>({val});
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" void
mlx_vector_int_append_data(mlx_vector_int vec, int* data, size_t size) {
  MLX_TRY_CATCH(
      for (size_t i = 0; i < size;
           i++) { mlx_vector_int_get_(vec).push_back(data[i]); }, );
}

extern "C" void mlx_vector_int_append_value(mlx_vector_int vec, int value) {
  MLX_TRY_CATCH(mlx_vector_int_get_(vec).push_back(value);, )
}

extern "C" int mlx_vector_int_get(mlx_vector_int vec, size_t index, int* res) {
  try {
    *res = mlx_vector_int_get_(vec).at(index);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" size_t mlx_vector_int_size(mlx_vector_int vec) {
  return mlx_vector_int_get_(vec).size();
}

extern "C" mlx_vector_string mlx_vector_string_new() {
  return mlx_vector_string_new_({});
}

extern "C" mlx_vector_string mlx_vector_string_new_data(
    const char** data,
    size_t size) {
  auto vec = mlx_vector_string_new();
  for (size_t i = 0; i < size; i++) {
    mlx_vector_string_get_(vec).push_back(data[i]);
  }
  return vec;
}

extern "C" mlx_vector_string mlx_vector_string_new_value(const char* val) {
  return mlx_vector_string_new_({val});
}

extern "C" int mlx_vector_string_set_data(
    mlx_vector_string vec,
    const char** data,
    size_t size) {
  try {
    std::vector<std::string> cpp_arrs;
    for (size_t i = 0; i < size; i++) {
      cpp_arrs.push_back(data[i]);
    }
    mlx_vector_string_get_(vec) = cpp_arrs;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_vector_string_set_value(
    mlx_vector_string vec,
    const char* val) {
  try {
    mlx_vector_string_get_(vec) = std::vector<std::string>({val});
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" void mlx_vector_string_append_data(
    mlx_vector_string vec,
    const char** data,
    size_t size) {
  MLX_TRY_CATCH(
      for (size_t i = 0; i < size;
           i++) { mlx_vector_string_get_(vec).push_back(data[i]); }, );
}

extern "C" void mlx_vector_string_append_value(
    mlx_vector_string vec,
    const char* value) {
  MLX_TRY_CATCH(mlx_vector_string_get_(vec).push_back(value);, )
}

extern "C" int
mlx_vector_string_get(mlx_vector_string vec, size_t index, char** res) {
  try {
    *res = mlx_vector_string_get_(vec).at(index).data();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" size_t mlx_vector_string_size(mlx_vector_string vec) {
  return mlx_vector_string_get_(vec).size();
}
