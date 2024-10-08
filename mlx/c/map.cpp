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
  try {
    return mlx_map_string_to_array_new_({});
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_map_string_to_array_new_();
  }
}

extern "C" int mlx_map_string_to_array_free(mlx_map_string_to_array map) {
  try {
    mlx_map_string_to_array_free_(map);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_map_string_to_array_insert(
    mlx_map_string_to_array map,
    const char* key,
    const mlx_array value) {
  try {
    auto res = mlx_map_string_to_array_get_(map).insert(
        std::make_pair(std::string(key), mlx_array_get_(value)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_map_string_to_array_get(
    mlx_map_string_to_array map,
    const char* key,
    mlx_array* value) {
  try {
    auto search = mlx_map_string_to_array_get_(map).find(std::string(key));
    if (search == mlx_map_string_to_array_get_(map).end()) {
      return 1;
    } else {
      mlx_array_set_(*value, search->second);
      return 0;
    }
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" mlx_map_string_to_array_iterator
mlx_map_string_to_array_iterator_new(mlx_map_string_to_array map) {
  auto& cpp_map = mlx_map_string_to_array_get_(map);
  try {
    return mlx_map_string_to_array_iterator{
        new std::unordered_map<std::string, mlx::core::array>::iterator(
            cpp_map.begin()),
        &cpp_map};
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_map_string_to_array_iterator{0};
  }
}

extern "C" int mlx_map_string_to_array_iterator_next(
    mlx_map_string_to_array_iterator it,
    const char** key,
    mlx_array* value) {
  try {
    if (mlx_map_string_to_array_iterator_get_(it) ==
        mlx_map_string_to_array_iterator_get_map_(it).end()) {
      return 1;
    } else {
      *key = mlx_map_string_to_array_iterator_get_(it)->first.data();
      mlx_array_set_(*value, mlx_map_string_to_array_iterator_get_(it)->second);
      mlx_map_string_to_array_iterator_get_(it)++;
      return 0;
    }
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" int mlx_map_string_to_array_iterator_free(
    mlx_map_string_to_array_iterator it) {
  try {
    mlx_map_string_to_array_iterator_free_(it);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" mlx_map_string_to_string mlx_map_string_to_string_new(void) {
  try {
    return mlx_map_string_to_string_new_({});
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_map_string_to_string_new_();
  }
}

extern "C" int mlx_map_string_to_string_free(mlx_map_string_to_string map) {
  try {
    mlx_map_string_to_string_free_(map);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_map_string_to_string_insert(
    mlx_map_string_to_string map,
    const char* key,
    const char* value) {
  try {
    auto res = mlx_map_string_to_string_get_(map).insert(
        std::make_pair(std::string(key), std::string(value)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_map_string_to_string_get(
    mlx_map_string_to_string map,
    const char* key,
    const char** value) {
  try {
    auto search = mlx_map_string_to_string_get_(map).find(std::string(key));
    if (search == mlx_map_string_to_string_get_(map).end()) {
      return 1;
    } else {
      *value = search->second.data();
      return 0;
    }
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" mlx_map_string_to_string_iterator
mlx_map_string_to_string_iterator_new(mlx_map_string_to_string map) {
  auto& cpp_map = mlx_map_string_to_string_get_(map);
  try {
    return mlx_map_string_to_string_iterator{
        new std::unordered_map<std::string, std::string>::iterator(
            cpp_map.begin()),
        &cpp_map};
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_map_string_to_string_iterator{0};
  }
}

extern "C" int mlx_map_string_to_string_iterator_next(
    mlx_map_string_to_string_iterator it,
    const char** key,
    const char** value) {
  try {
    if (mlx_map_string_to_string_iterator_get_(it) ==
        mlx_map_string_to_string_iterator_get_map_(it).end()) {
      return 1;
    } else {
      *key = mlx_map_string_to_string_iterator_get_(it)->first.data();
      *value = mlx_map_string_to_string_iterator_get_(it)->second.data();
      mlx_map_string_to_string_iterator_get_(it)++;
      return 0;
    }
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" int mlx_map_string_to_string_iterator_free(
    mlx_map_string_to_string_iterator it) {
  try {
    mlx_map_string_to_string_iterator_free_(it);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
