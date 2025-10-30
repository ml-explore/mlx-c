/* Copyright © 2023-2024 Apple Inc. */

#include "mlx/c/io_gguf.h"
#include <variant>
#include "mlx/c/error.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/io_gguf.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/vector.h"
#include "mlx/io.h"

extern "C" mlx_gguf_metadata mlx_gguf_metadata_new_string(const char* value) {
  try {
    return mlx_gguf_metadata_new_(mlx::core::GGUFMetaData(std::string(value)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_gguf_metadata({nullptr});
  }
}

extern "C" mlx_gguf_metadata mlx_gguf_metadata_new_array(
    const mlx_array value) {
  try {
    return mlx_gguf_metadata_new_(
        mlx::core::GGUFMetaData(mlx_array_get_(value)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_gguf_metadata({nullptr});
  }
}

extern "C" mlx_gguf_metadata mlx_gguf_metadata_new_string_vector(
    const mlx_vector_string value) {
  try {
    return mlx_gguf_metadata_new_(
        mlx::core::GGUFMetaData(mlx_vector_string_get_(value)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_gguf_metadata({nullptr});
  }
}

extern "C" mlx_gguf_metadata_type mlx_gguf_metadata_get_type(
    const mlx_gguf_metadata metadata) {
  try {
    auto& variant = mlx_gguf_metadata_get_(metadata);
    return static_cast<mlx_gguf_metadata_type>(variant.index());
  } catch (std::exception& e) {
    mlx_error(e.what());
    return MLX_GGUF_METADATA_NONE;
  }
}

extern "C" int mlx_gguf_metadata_get_string(
    mlx_string* res,
    const mlx_gguf_metadata metadata) {
  try {
    auto& variant = mlx_gguf_metadata_get_(metadata);
    if (variant.index() != MLX_GGUF_METADATA_STRING) {
      mlx_error("metadata is not a string");
      return 1;
    }
    mlx_string_set_(*res, std::get<std::string>(variant));
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" int mlx_gguf_metadata_get_array(
    mlx_array* res,
    const mlx_gguf_metadata metadata) {
  try {
    auto& variant = mlx_gguf_metadata_get_(metadata);
    if (variant.index() != MLX_GGUF_METADATA_ARRAY) {
      mlx_error("metadata is not an array");
      return 1;
    }
    mlx_array_set_(*res, std::get<mlx::core::array>(variant));
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" int mlx_gguf_metadata_get_string_vector(
    mlx_vector_string* res,
    const mlx_gguf_metadata metadata) {
  try {
    auto& variant = mlx_gguf_metadata_get_(metadata);
    if (variant.index() != MLX_GGUF_METADATA_STRING_VECTOR) {
      mlx_error("metadata is not a string vector");
      return 1;
    }
    mlx_vector_string_set_(*res, std::get<std::vector<std::string>>(variant));
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" int mlx_gguf_metadata_free(mlx_gguf_metadata metadata) {
  try {
    mlx_gguf_metadata_free_(metadata);
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" mlx_map_string_to_gguf_metadata mlx_map_string_to_gguf_metadata_new(
    void) {
  try {
    return mlx_map_string_to_gguf_metadata_new_(
        std::unordered_map<std::string, mlx::core::GGUFMetaData>());
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_map_string_to_gguf_metadata({nullptr});
  }
}

extern "C" int mlx_map_string_to_gguf_metadata_set(
    mlx_map_string_to_gguf_metadata* map,
    const mlx_map_string_to_gguf_metadata src) {
  try {
    mlx_map_string_to_gguf_metadata_set_(
        *map, mlx_map_string_to_gguf_metadata_get_(src));
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" int mlx_map_string_to_gguf_metadata_insert(
    mlx_map_string_to_gguf_metadata map,
    const char* key,
    const mlx_gguf_metadata value) {
  try {
    auto& cpp_map = mlx_map_string_to_gguf_metadata_get_(map);
    cpp_map[std::string(key)] = mlx_gguf_metadata_get_(value);
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" int mlx_map_string_to_gguf_metadata_get(
    mlx_gguf_metadata* res,
    const mlx_map_string_to_gguf_metadata map,
    const char* key) {
  try {
    auto& cpp_map = mlx_map_string_to_gguf_metadata_get_(map);
    auto it = cpp_map.find(std::string(key));
    if (it == cpp_map.end()) {
      return 2;
    }
    *res = mlx_gguf_metadata_new_(it->second);
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" int mlx_map_string_to_gguf_metadata_free(
    mlx_map_string_to_gguf_metadata map) {
  try {
    mlx_map_string_to_gguf_metadata_free_(map);
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" mlx_map_string_to_gguf_metadata_iterator
mlx_map_string_to_gguf_metadata_iterator_new(
    mlx_map_string_to_gguf_metadata map) {
  try {
    auto& cpp_map = mlx_map_string_to_gguf_metadata_get_(map);
    mlx_map_string_to_gguf_metadata_iterator it;
    it.map_ctx = map.ctx;
    mlx_map_string_to_gguf_metadata_iterator_set_(it, cpp_map.begin());
    return it;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_map_string_to_gguf_metadata_iterator({nullptr, nullptr});
  }
}

extern "C" int mlx_map_string_to_gguf_metadata_iterator_free(
    mlx_map_string_to_gguf_metadata_iterator it) {
  try {
    mlx_map_string_to_gguf_metadata_iterator_free_(it);
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" int mlx_map_string_to_gguf_metadata_iterator_next(
    const char** key,
    mlx_gguf_metadata* value,
    mlx_map_string_to_gguf_metadata_iterator it) {
  try {
    auto& cpp_it = mlx_map_string_to_gguf_metadata_iterator_get_(it);
    auto& cpp_map = mlx_map_string_to_gguf_metadata_iterator_get_map_(it);
    if (cpp_it == cpp_map.end()) {
      return 1;
    }
    *key = cpp_it->first.c_str();
    *value = mlx_gguf_metadata_new_(cpp_it->second);
    ++cpp_it;
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" int mlx_load_gguf(
    mlx_map_string_to_array* res_arrays,
    mlx_map_string_to_gguf_metadata* res_metadata,
    const char* file,
    const mlx_stream s) {
  try {
    auto [arrays, metadata] =
        mlx::core::load_gguf(std::string(file), mlx_stream_get_(s));
    mlx_map_string_to_array_set_(*res_arrays, std::move(arrays));
    mlx_map_string_to_gguf_metadata_set_(*res_metadata, std::move(metadata));
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" int mlx_save_gguf(
    const char* file,
    const mlx_map_string_to_array arrays,
    const mlx_map_string_to_gguf_metadata metadata) {
  try {
    mlx::core::save_gguf(
        std::string(file),
        mlx_map_string_to_array_get_(arrays),
        mlx_map_string_to_gguf_metadata_get_(metadata));
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}
