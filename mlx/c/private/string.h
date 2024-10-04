/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_STRING_PRIVATE_H
#define MLX_STRING_PRIVATE_H

#include <string>
#include "mlx/c/string.h"

inline mlx_string mlx_string_new_(std::string&& s) {
  return mlx_string({new std::string(std::move(s))});
}
inline mlx_string mlx_string_new_(const std::string& s) {
  return mlx_string({new std::string(s)});
}

inline mlx_string mlx_string_set_(mlx_string* d, std::string s) {
  if (d->ctx) {
    *static_cast<std::string*>(d->ctx) = s;
  } else {
    d->ctx = new std::string(s);
  }
  return *d;
}

inline std::string& mlx_string_get_(mlx_string d) {
  return *static_cast<std::string*>(d.ctx);
}

inline void mlx_string_free_(mlx_string d) {
  if (d.ctx) {
    delete static_cast<std::string*>(d.ctx);
  }
}

#endif
