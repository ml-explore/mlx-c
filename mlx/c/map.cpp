/* Copyright © 2023-2024 Apple Inc. */

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
    const mlx_string key,
    const mlx_array value) {
  MLX_TRY_CATCH(
      auto res = map->ctx.insert(std::make_pair(key->ctx, value->ctx));
      return res.second, return false);
}

extern "C" mlx_array mlx_map_string_to_array_get(
    mlx_map_string_to_array map,
    const mlx_string key) {
  auto search = map->ctx.find(key->ctx);
  if (search == map->ctx.end()) {
    return nullptr;
  } else {
    return new mlx_array_(search->second);
  }
}

extern "C" mlx_map_string_to_array_iterator mlx_map_string_to_array_iterate(
    mlx_map_string_to_array map) {
  MLX_TRY_CATCH(return new mlx_map_string_to_array_iterator_(map),
                       return nullptr);
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

extern "C" mlx_string mlx_map_string_to_array_iterator_key(
    mlx_map_string_to_array_iterator it) {
  if (it->ctx == it->map->ctx.end()) {
    return nullptr;
  } else {
    return new mlx_string_(it->ctx->first);
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
    const mlx_string key,
    const mlx_string value) {
  MLX_TRY_CATCH(
      auto res = map->ctx.insert(std::make_pair(key->ctx, value->ctx));
      return res.second, return false);
}

extern "C" mlx_string mlx_map_string_to_string_get(
    mlx_map_string_to_string map,
    const mlx_string key) {
  auto search = map->ctx.find(key->ctx);
  if (search == map->ctx.end()) {
    return nullptr;
  } else {
    return new mlx_string_(search->second);
  }
}

extern "C" mlx_map_string_to_string_iterator mlx_map_string_to_string_iterate(
    mlx_map_string_to_string map) {
  MLX_TRY_CATCH(return new mlx_map_string_to_string_iterator_(map),
                       return nullptr);
}

extern "C" bool mlx_map_string_to_string_iterator_next(
    mlx_map_string_to_string_iterator it) {
  it->ctx++;
  if (it->ctx == it->map->ctx.end()) {
    return false;
  } else {
    return true;
  }
}

extern "C" bool mlx_map_string_to_string_iterator_end(
    mlx_map_string_to_string_iterator it) {
  if (it->ctx == it->map->ctx.end()) {
    return true;
  } else {
    return false;
  }
}

extern "C" mlx_string mlx_map_string_to_string_iterator_key(
    mlx_map_string_to_string_iterator it) {
  if (it->ctx == it->map->ctx.end()) {
    return nullptr;
  } else {
    return new mlx_string_(it->ctx->first);
  }
}

extern "C" mlx_string mlx_map_string_to_string_iterator_value(
    mlx_map_string_to_string_iterator it) {
  if (it->ctx == it->map->ctx.end()) {
    return nullptr;
  } else {
    return new mlx_string_(it->ctx->second);
  }
}
