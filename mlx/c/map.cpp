/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/map.h"
#include "mlx/c/object.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

mlx_string_* mlx_map_string_to_array_::tostring() {
  MLX_TRY_CATCH(return new mlx_string_("mlx_map_string_to_array"),
                       return nullptr);
}

mlx_string_* mlx_map_string_to_array_iterator_::tostring() {
  MLX_TRY_CATCH(return new mlx_string_("mlx_map_string_to_array_iterator"),
                       return nullptr);
}

extern "C" mlx_map_string_to_array mlx_map_string_to_array_new(void) {
  MLX_TRY_CATCH(return new mlx_map_string_to_array_(), return nullptr);
}

extern "C" bool mlx_map_string_to_array_insert(
    mlx_map_string_to_array map,
    const char* key,
    const mlx_array value) {
  MLX_TRY_CATCH(
      auto res = map->ctx.insert(std::make_pair(std::string(key), value->ctx));
      return res.second, return false);
}

extern "C" bool mlx_map_string_to_array_get(
    mlx_map_string_to_array map,
    const char* key,
    mlx_array* value) {
  auto search = map->ctx.find(std::string(key));
  if (search == map->ctx.end()) {
    return false;
  } else {
    (*value)->ctx = search->second;
    return true;
  }
}

extern "C" mlx_map_string_to_array_iterator mlx_map_string_to_array_iterate(
    mlx_map_string_to_array map) {
  MLX_TRY_CATCH(return new mlx_map_string_to_array_iterator_(map),
                       return nullptr);
}

extern "C" bool mlx_map_string_to_array_iterator_next(
    mlx_map_string_to_array_iterator it,
    const char** key,
    mlx_array* value) {
  if (it->ctx == it->map->ctx.end()) {
    return false;
  } else {
    *key = it->ctx->first.data();
    (*value)->ctx = it->ctx->second;
    it->ctx++;
    return true;
  }
}

mlx_string_* mlx_map_string_to_string_::tostring() {
  MLX_TRY_CATCH(return new mlx_string_("mlx_map_string_to_string"),
                       return nullptr);
}

mlx_string_* mlx_map_string_to_string_iterator_::tostring() {
  MLX_TRY_CATCH(return new mlx_string_("mlx_map_string_to_string_iterator"),
                       return nullptr);
}

extern "C" mlx_map_string_to_string mlx_map_string_to_string_new(void) {
  MLX_TRY_CATCH(return new mlx_map_string_to_string_(), return nullptr);
}

extern "C" bool mlx_map_string_to_string_insert(
    mlx_map_string_to_string map,
    const char* key,
    const char* value) {
  MLX_TRY_CATCH(auto res = map->ctx.insert(
                    std::make_pair(std::string(key), std::string(value)));
                return res.second, return false);
}

extern "C" bool mlx_map_string_to_string_get(
    mlx_map_string_to_string map,
    const char* key,
    const char** value) {
  auto search = map->ctx.find(std::string(key));
  if (search == map->ctx.end()) {
    return false;
  } else {
    *value = search->second.data();
    return true;
  }
}

extern "C" mlx_map_string_to_string_iterator mlx_map_string_to_string_iterate(
    mlx_map_string_to_string map) {
  MLX_TRY_CATCH(return new mlx_map_string_to_string_iterator_(map),
                       return nullptr);
}

extern "C" bool mlx_map_string_to_string_iterator_next(
    mlx_map_string_to_string_iterator it,
    const char** key,
    const char** value) {
  if (it->ctx == it->map->ctx.end()) {
    return false;
  } else {
    *key = it->ctx->first.data();
    *value = it->ctx->second.data();
    it->ctx++;
    return true;
  }
}
