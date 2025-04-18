/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/export.h"
#include "mlx/c/error.h"
#include "mlx/c/private/mlx.h"
#include "mlx/export.h"

extern "C" int mlx_export_function(
    const char* file,
    const mlx_closure fun,
    const mlx_vector_array args,
    bool shapeless) {
  try {
    mlx::core::export_function(
        std::string(file),
        mlx_closure_get_(fun),
        mlx_vector_array_get_(args),
        shapeless);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_exporter(
    mlx_function_exporter* res,
    const char* file,
    const mlx_closure fun,
    bool shapeless) {
  try {
    mlx_function_exporter_set_(
        *res,
        mlx::core::exporter(
            std::string(file), mlx_closure_get_(fun), shapeless));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_import_function(
    mlx_imported_function* res,
    const char* file) {
  try {
    mlx_imported_function_set_(
        *res, mlx::core::import_function(std::string(file)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
