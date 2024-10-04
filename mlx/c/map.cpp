/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/map.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

extern "C" mlx_map_string_to_array mlx_map_string_to_array_new(void) {
  return mlx_map_string_to_array{
      new std::unordered_map<std::string, mlx::core::array>()};
}

extern "C" void mlx_map_string_to_array_free(mlx_map_string_to_array map) {
  mlx_map_string_to_array_free_(map);
}

extern "C" bool mlx_map_string_to_array_insert(
    mlx_map_string_to_array map,
    const char* key,
    const mlx_array value) {
  MLX_TRY_CATCH(auto res = mlx_map_string_to_array_get_(map).insert(
                    std::make_pair(std::string(key), mlx_array_get_(value)));
                return true, return false);
}

extern "C" bool mlx_map_string_to_array_get(
    mlx_map_string_to_array map,
    const char* key,
    mlx_array* value) {
  auto search = mlx_map_string_to_array_get_(map).find(std::string(key));
  if (search == mlx_map_string_to_array_get_(map).end()) {
    return false;
  } else {
    mlx_array_set_(*value, search->second);
    return true;
  }
}

extern "C" mlx_map_string_to_array_iterator
mlx_map_string_to_array_iterator_new(mlx_map_string_to_array map) {
  auto& cpp_map = mlx_map_string_to_array_get_(map);
  return mlx_map_string_to_array_iterator{
      new std::unordered_map<std::string, mlx::core::array>::iterator(
          cpp_map.begin()),
      &cpp_map};
}

extern "C" bool mlx_map_string_to_array_iterator_next(
    mlx_map_string_to_array_iterator it,
    const char** key,
    mlx_array* value) {
  if (mlx_map_string_to_array_iterator_get_(it) ==
      mlx_map_string_to_array_iterator_get_map_(it).end()) {
    return false;
  } else {
    *key = mlx_map_string_to_array_iterator_get_(it)->first.data();
    mlx_array_set_(*value, mlx_map_string_to_array_iterator_get_(it)->second);
    mlx_map_string_to_array_iterator_get_(it)++;
    return true;
  }
}

extern "C" void mlx_map_string_to_array_iterator_free(
    mlx_map_string_to_array_iterator it) {
  mlx_map_string_to_array_iterator_free_(it);
}

extern "C" mlx_map_string_to_string mlx_map_string_to_string_new(void) {
  return mlx_map_string_to_string{
      new std::unordered_map<std::string, std::string>()};
}

extern "C" void mlx_map_string_to_string_free(mlx_map_string_to_string map) {
  mlx_map_string_to_string_free_(map);
}

extern "C" bool mlx_map_string_to_string_insert(
    mlx_map_string_to_string map,
    const char* key,
    const char* value) {
  MLX_TRY_CATCH(auto res = mlx_map_string_to_string_get_(map).insert(
                    std::make_pair(std::string(key), std::string(value)));
                return true, return false);
}

extern "C" bool mlx_map_string_to_string_get(
    mlx_map_string_to_string map,
    const char* key,
    const char** value) {
  auto search = mlx_map_string_to_string_get_(map).find(std::string(key));
  if (search == mlx_map_string_to_string_get_(map).end()) {
    return false;
  } else {
    *value = search->second.data();
    return true;
  }
}

extern "C" mlx_map_string_to_string_iterator
mlx_map_string_to_string_iterator_new(mlx_map_string_to_string map) {
  auto& cpp_map = mlx_map_string_to_string_get_(map);
  return mlx_map_string_to_string_iterator{
      new std::unordered_map<std::string, std::string>::iterator(
          cpp_map.begin()),
      &cpp_map};
}

extern "C" bool mlx_map_string_to_string_iterator_next(
    mlx_map_string_to_string_iterator it,
    const char** key,
    const char** value) {
  if (mlx_map_string_to_string_iterator_get_(it) ==
      mlx_map_string_to_string_iterator_get_map_(it).end()) {
    return false;
  } else {
    *key = mlx_map_string_to_string_iterator_get_(it)->first.data();
    *value = mlx_map_string_to_string_iterator_get_(it)->second.data();
    mlx_map_string_to_string_iterator_get_(it)++;
    return true;
  }
}

extern "C" void mlx_map_string_to_string_iterator_free(
    mlx_map_string_to_string_iterator it) {
  mlx_map_string_to_string_iterator_free_(it);
}
