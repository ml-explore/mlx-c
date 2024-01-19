#include "mlx/c/map.h"
#include "mlx.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/utils.h"

char* mlx_map_string_to_array_::tostring() {
  std::string str = "mlx_map_string_to_array";
  char* c_str = (char*)malloc(str.size() + 1);
  memcpy(c_str, str.data(), str.size());
  c_str[str.size()] = '\0';
  return c_str;
}

char* mlx_map_string_to_array_iterator_::tostring() {
  std::string str = "mlx_map_string_to_array_iterator";
  char* c_str = (char*)malloc(str.size() + 1);
  memcpy(c_str, str.data(), str.size());
  c_str[str.size()] = '\0';
  return c_str;
}

extern "C" mlx_map_string_to_array mlx_map_string_to_array_new(void) {
  return new mlx_map_string_to_array_();
}

extern "C" bool mlx_map_string_to_array_insert(
    mlx_map_string_to_array map,
    const char* key,
    const mlx_array value) {
  std::string key_cpp(key);
  mlx::core::array arr_cpp = value->ctx;
  auto res = map->ctx.insert(std::make_pair(key_cpp, arr_cpp));
  return res.second;
}

extern "C" mlx_array mlx_map_string_to_array_get(
    mlx_map_string_to_array map,
    const char* key) {
  std::string key_cpp(key);
  auto search = map->ctx.find(key_cpp);
  if (search == map->ctx.end()) {
    return nullptr;
  } else {
    return new mlx_array_(search->second);
  }
}

extern "C" mlx_map_string_to_array_iterator mlx_map_string_to_array_iterate(
    mlx_map_string_to_array map) {
  return new mlx_map_string_to_array_iterator_(map);
}

extern "C" bool mlx_map_string_to_array_iterator_next(
    mlx_map_string_to_array_iterator it) {
  it->ctx++;
  if (it->ctx == it->map->ctx.end()) {
    return false;
  } else {
    return true;
  }
}

extern "C" bool mlx_map_string_to_array_iterator_end(
    mlx_map_string_to_array_iterator it) {
  if (it->ctx == it->map->ctx.end()) {
    return true;
  } else {
    return false;
  }
}

extern "C" const char* mlx_map_string_to_array_iterator_key(
    mlx_map_string_to_array_iterator it) {
  if (it->ctx == it->map->ctx.end()) {
    return nullptr;
  } else {
    return it->ctx->first.c_str();
  }
}

extern "C" mlx_array mlx_map_string_to_array_iterator_value(
    mlx_map_string_to_array_iterator it) {
  if (it->ctx == it->map->ctx.end()) {
    return nullptr;
  } else {
    return new mlx_array_(it->ctx->second);
  }
}
