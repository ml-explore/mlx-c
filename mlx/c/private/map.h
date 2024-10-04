/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_MAP_PRIVATE_H
#define MLX_MAP_PRIVATE_H

#include "mlx/c/map.h"
#include "mlx/mlx.h"

inline mlx_map_string_to_array mlx_map_string_to_array_new_(
    std::unordered_map<std::string, mlx::core::array> s) {
  return mlx_map_string_to_array(
      {new std::unordered_map<std::string, mlx::core::array>(s)});
}

inline mlx_map_string_to_array mlx_map_string_to_array_set_(
    mlx_map_string_to_array* d,
    std::unordered_map<std::string, mlx::core::array> s) {
  if (d->ctx) {
    *static_cast<std::unordered_map<std::string, mlx::core::array>*>(d->ctx) =
        s;
  } else {
    d->ctx = new std::unordered_map<std::string, mlx::core::array>(s);
  }
  return *d;
}

inline std::unordered_map<std::string, mlx::core::array>&
mlx_map_string_to_array_get_(mlx_map_string_to_array d) {
  return *static_cast<std::unordered_map<std::string, mlx::core::array>*>(
      d.ctx);
}

inline mlx_map_string_to_array_iterator mlx_map_string_to_array_iterator_new_(
    std::unordered_map<std::string, mlx::core::array>::iterator&& s) {
  return mlx_map_string_to_array_iterator(
      {new std::unordered_map<std::string, mlx::core::array>::iterator(
          std::move(s))});
}

inline mlx_map_string_to_array_iterator mlx_map_string_to_array_iterator_set_(
    mlx_map_string_to_array_iterator* d,
    std::unordered_map<std::string, mlx::core::array>::iterator s) {
  if (d->ctx) {
    *static_cast<std::unordered_map<std::string, mlx::core::array>::iterator*>(
        d->ctx) = s;
  } else {
    d->ctx = new std::unordered_map<std::string, mlx::core::array>::iterator(s);
  }
  return *d;
}

inline std::unordered_map<std::string, mlx::core::array>::iterator&
mlx_map_string_to_array_iterator_get_(mlx_map_string_to_array_iterator d) {
  return *static_cast<
      std::unordered_map<std::string, mlx::core::array>::iterator*>(d.ctx);
}
inline std::unordered_map<std::string, mlx::core::array>&
mlx_map_string_to_array_iterator_get_map_(mlx_map_string_to_array_iterator d) {
  return *static_cast<std::unordered_map<std::string, mlx::core::array>*>(
      d.map_ctx);
}

inline mlx_map_string_to_string mlx_map_string_to_string_new_(
    std::unordered_map<std::string, std::string> s) {
  return mlx_map_string_to_string(
      {new std::unordered_map<std::string, std::string>(s)});
}

inline mlx_map_string_to_string mlx_map_string_to_string_set_(
    mlx_map_string_to_string* d,
    std::unordered_map<std::string, std::string> s) {
  if (d->ctx) {
    *static_cast<std::unordered_map<std::string, std::string>*>(d->ctx) = s;
  } else {
    d->ctx = new std::unordered_map<std::string, std::string>(s);
  }
  return *d;
}

inline std::unordered_map<std::string, std::string>&
mlx_map_string_to_string_get_(mlx_map_string_to_string d) {
  return *static_cast<std::unordered_map<std::string, std::string>*>(d.ctx);
}

inline mlx_map_string_to_string_iterator mlx_map_string_to_string_iterator_new_(
    std::unordered_map<std::string, std::string>::iterator&& s) {
  return mlx_map_string_to_string_iterator(
      {new std::unordered_map<std::string, std::string>::iterator(
          std::move(s))});
}

inline mlx_map_string_to_string_iterator mlx_map_string_to_string_iterator_set_(
    mlx_map_string_to_string_iterator* d,
    std::unordered_map<std::string, std::string>::iterator s) {
  if (d->ctx) {
    *static_cast<std::unordered_map<std::string, std::string>::iterator*>(
        d->ctx) = s;
  } else {
    d->ctx = new std::unordered_map<std::string, std::string>::iterator(s);
  }
  return *d;
}

inline std::unordered_map<std::string, std::string>::iterator&
mlx_map_string_to_string_iterator_get_(mlx_map_string_to_string_iterator d) {
  return *static_cast<std::unordered_map<std::string, std::string>::iterator*>(
      d.ctx);
}
inline std::unordered_map<std::string, std::string>&
mlx_map_string_to_string_iterator_get_map_(
    mlx_map_string_to_string_iterator d) {
  return *static_cast<std::unordered_map<std::string, std::string>*>(d.map_ctx);
}

#endif
