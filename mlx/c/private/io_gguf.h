/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_IO_GGUF_PRIVATE_H
#define MLX_IO_GGUF_PRIVATE_H

#include "mlx/c/io_gguf.h"
#include "mlx/mlx.h"

// Internal C++ wrapper for GGUF metadata (wraps std::variant)
struct mlx_gguf_metadata_cpp_ {
  mlx::core::GGUFMetaData metadata;
};

inline mlx_gguf_metadata mlx_gguf_metadata_new_(
    mlx::core::GGUFMetaData metadata) {
  return mlx_gguf_metadata({new mlx_gguf_metadata_cpp_{std::move(metadata)}});
}

inline mlx::core::GGUFMetaData& mlx_gguf_metadata_get_(mlx_gguf_metadata d) {
  if (!d.ctx) {
    throw std::runtime_error("expected a non-empty mlx_gguf_metadata");
  }
  return static_cast<mlx_gguf_metadata_cpp_*>(d.ctx)->metadata;
}

inline void mlx_gguf_metadata_free_(mlx_gguf_metadata d) {
  if (d.ctx) {
    delete static_cast<mlx_gguf_metadata_cpp_*>(d.ctx);
  }
}

// Map helpers
inline mlx_map_string_to_gguf_metadata mlx_map_string_to_gguf_metadata_new_() {
  return mlx_map_string_to_gguf_metadata({nullptr});
}

inline mlx_map_string_to_gguf_metadata mlx_map_string_to_gguf_metadata_new_(
    const std::unordered_map<std::string, mlx::core::GGUFMetaData>& s) {
  return mlx_map_string_to_gguf_metadata(
      {new std::unordered_map<std::string, mlx::core::GGUFMetaData>(s)});
}

inline mlx_map_string_to_gguf_metadata mlx_map_string_to_gguf_metadata_new_(
    std::unordered_map<std::string, mlx::core::GGUFMetaData>&& s) {
  return mlx_map_string_to_gguf_metadata(
      {new std::unordered_map<std::string, mlx::core::GGUFMetaData>(
          std::move(s))});
}

inline mlx_map_string_to_gguf_metadata& mlx_map_string_to_gguf_metadata_set_(
    mlx_map_string_to_gguf_metadata& d,
    const std::unordered_map<std::string, mlx::core::GGUFMetaData>& s) {
  if (d.ctx) {
    *static_cast<std::unordered_map<std::string, mlx::core::GGUFMetaData>*>(
        d.ctx) = s;
  } else {
    d.ctx = new std::unordered_map<std::string, mlx::core::GGUFMetaData>(s);
  }
  return d;
}

inline mlx_map_string_to_gguf_metadata& mlx_map_string_to_gguf_metadata_set_(
    mlx_map_string_to_gguf_metadata& d,
    std::unordered_map<std::string, mlx::core::GGUFMetaData>&& s) {
  if (d.ctx) {
    *static_cast<std::unordered_map<std::string, mlx::core::GGUFMetaData>*>(
        d.ctx) = std::move(s);
  } else {
    d.ctx = new std::unordered_map<std::string, mlx::core::GGUFMetaData>(
        std::move(s));
  }
  return d;
}

inline std::unordered_map<std::string, mlx::core::GGUFMetaData>&
mlx_map_string_to_gguf_metadata_get_(mlx_map_string_to_gguf_metadata d) {
  if (!d.ctx) {
    throw std::runtime_error(
        "expected a non-empty mlx_map_string_to_gguf_metadata");
  }
  return *static_cast<
      std::unordered_map<std::string, mlx::core::GGUFMetaData>*>(d.ctx);
}

inline void mlx_map_string_to_gguf_metadata_free_(
    mlx_map_string_to_gguf_metadata d) {
  if (d.ctx) {
    delete static_cast<
        std::unordered_map<std::string, mlx::core::GGUFMetaData>*>(d.ctx);
  }
}

// Iterator helpers
inline mlx_map_string_to_gguf_metadata_iterator&
mlx_map_string_to_gguf_metadata_iterator_set_(
    mlx_map_string_to_gguf_metadata_iterator& d,
    const std::unordered_map<std::string, mlx::core::GGUFMetaData>::iterator&
        s) {
  if (d.ctx) {
    *static_cast<
        std::unordered_map<std::string, mlx::core::GGUFMetaData>::iterator*>(
        d.ctx) = s;
  } else {
    d.ctx =
        new std::unordered_map<std::string, mlx::core::GGUFMetaData>::iterator(
            s);
  }
  return d;
}

inline mlx_map_string_to_gguf_metadata_iterator&
mlx_map_string_to_gguf_metadata_iterator_set_(
    mlx_map_string_to_gguf_metadata_iterator& d,
    std::unordered_map<std::string, mlx::core::GGUFMetaData>::iterator&& s) {
  if (d.ctx) {
    *static_cast<
        std::unordered_map<std::string, mlx::core::GGUFMetaData>::iterator*>(
        d.ctx) = std::move(s);
  } else {
    d.ctx =
        new std::unordered_map<std::string, mlx::core::GGUFMetaData>::iterator(
            std::move(s));
  }
  return d;
}

inline std::unordered_map<std::string, mlx::core::GGUFMetaData>::iterator&
mlx_map_string_to_gguf_metadata_iterator_get_(
    mlx_map_string_to_gguf_metadata_iterator d) {
  if (!d.ctx) {
    throw std::runtime_error(
        "expected a non-empty mlx_map_string_to_gguf_metadata_iterator");
  }
  return *static_cast<
      std::unordered_map<std::string, mlx::core::GGUFMetaData>::iterator*>(
      d.ctx);
}

inline void mlx_map_string_to_gguf_metadata_iterator_free_(
    mlx_map_string_to_gguf_metadata_iterator d) {
  if (d.ctx) {
    delete static_cast<
        std::unordered_map<std::string, mlx::core::GGUFMetaData>::iterator*>(
        d.ctx);
  }
}

inline std::unordered_map<std::string, mlx::core::GGUFMetaData>&
mlx_map_string_to_gguf_metadata_iterator_get_map_(
    mlx_map_string_to_gguf_metadata_iterator d) {
  return *static_cast<
      std::unordered_map<std::string, mlx::core::GGUFMetaData>*>(d.map_ctx);
}

#endif
