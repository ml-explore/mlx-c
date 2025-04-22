#include "mlx/c/export_impl.h"
#include "mlx/c/error.h"
#include "mlx/c/private/mlx.h"

extern "C" mlx_function_exporter mlx_function_exporter_new() {
  return mlx_function_exporter_new_();
}
extern "C" int mlx_function_exporter_free(mlx_function_exporter xfunc) {
  try {
    mlx_function_exporter_free_(xfunc);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_function_exporter_call(
    const mlx_function_exporter xfunc,
    const mlx_vector_array args) {
  try {
    mlx_function_exporter_get_(xfunc)(mlx_vector_array_get_(args));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_function_exporter_call_kwargs(
    const mlx_function_exporter xfunc,
    const mlx_map_string_to_array kwargs) {
  try {
    mlx_function_exporter_get_(xfunc)(mlx_map_string_to_array_get_(kwargs));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" mlx_imported_function mlx_imported_function_new() {
  return mlx_imported_function_new_();
}
extern "C" int mlx_imported_function_free(mlx_imported_function xfunc) {
  try {
    mlx_imported_function_free_(xfunc);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_imported_function_call(
    mlx_vector_array* res,
    const mlx_imported_function xfunc,
    mlx_vector_array args) {
  try {
    mlx_vector_array_set_(
        *res, mlx_imported_function_get_(xfunc)(mlx_vector_array_get_(args)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_imported_function_call_kwargs(
    mlx_vector_array* res,
    const mlx_imported_function xfunc,
    mlx_map_string_to_array kwargs) {
  try {
    mlx_vector_array_set_(
        *res,
        mlx_imported_function_get_(xfunc)(
            mlx_map_string_to_array_get_(kwargs)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
