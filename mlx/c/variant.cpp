/* Copyright © 2023-2024 Apple Inc. */

#include "mlx/c/private/variant.h"
#include "mlx/c/object.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/string.h"
#include "mlx/c/variant.h"

mlx_string mlx_string_size_t_variant_::tostring() {
  std::ostringstream os;
  if (std::holds_alternative<size_t>(ctx)) {
    os << std::get<size_t>(ctx);
  } else if (std::holds_alternative<std::string>(ctx)) {
    os << std::get<std::string>(ctx);
  } else {
    os << "mlx_string_size_variant";
  }
  std::string str = os.str();
  RETURN_MLX_C_STRING(str);
}

/**
 * Returns a variant from a string.
 */
extern "C" mlx_string_size_t_variant mlx_string_size_t_variant_new_with_string(
    mlx_string str) {
  MLX_TRY_CATCH(return new mlx_string_size_t_variant_(str->ctx),
                       return nullptr);
}

/**
 * Returns a variant from a size_t.
 */
extern "C" mlx_string_size_t_variant mlx_string_size_t_variant_new_with_size_t(
    size_t val) {
  MLX_TRY_CATCH(return new mlx_string_size_t_variant_(val), return nullptr);
}

/**
 * Returns string value from variant.
 */
extern "C" mlx_string mlx_string_size_t_variant_get_string(
    mlx_string_size_t_variant var) {
  MLX_TRY_CATCH(return new mlx_string_(std::get<std::string>(var->ctx)),
                       return nullptr);
}

/**
 * Returns size_t value from variant.
 */
extern "C" size_t mlx_string_size_t_variant_get_size_t(
    mlx_string_size_t_variant var) {
  MLX_TRY_CATCH(return std::get<size_t>(var->ctx), return 0);
}

/**
 * Returns whether variant holds a string value or not.
 */
extern "C" bool mlx_string_size_t_variant_holds_string(
    mlx_string_size_t_variant var) {
  return std::holds_alternative<std::string>(var->ctx);
}

/**
 * Returns whether variant holds a size_t value or not.
 */
extern "C" bool mlx_string_size_t_variant_holds_size_t(
    mlx_string_size_t_variant var) {
  return std::holds_alternative<size_t>(var->ctx);
}
