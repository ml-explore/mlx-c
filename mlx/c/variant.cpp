/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/private/variant.h"
#include "mlx/c/object.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

mlx_string mlx_variant_string_size_t_::tostring() {
  RETURN_MLX_C_STRING("mlx_variant(mlx_string, size_t)");
}

extern "C" mlx_variant_string_size_t mlx_variant_string_size_t_new_with_string(
    mlx_string val) {
  RETURN_MLX_C_PTR(new mlx_variant_string_size_t_(val->ctx));
}

extern "C" mlx_variant_string_size_t mlx_variant_string_size_t_new_with_size_t(
    size_t val) {
  RETURN_MLX_C_PTR(new mlx_variant_string_size_t_(val));
}

extern "C" mlx_string mlx_variant_string_size_t_get_string(
    mlx_variant_string_size_t var) {
  RETURN_MLX_C_PTR(new mlx_string_(std::get<std::string>(var->ctx)));
}

extern "C" size_t mlx_variant_string_size_t_get_size_t(
    mlx_variant_string_size_t var) {
  return std::get<size_t>(var->ctx);
}

extern "C" bool mlx_variant_string_size_t_holds_string(
    mlx_variant_string_size_t var) {
  return std::holds_alternative<std::string>(var->ctx);
}

extern "C" bool mlx_variant_string_size_t_holds_size_t(
    mlx_variant_string_size_t var) {
  return std::holds_alternative<size_t>(var->ctx);
}
