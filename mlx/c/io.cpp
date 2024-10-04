/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/io.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" int
mlx_load_file(FILE* in_stream, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::load(
            std::make_shared<CFILEReader>(in_stream), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_load(const char* file, const mlx_stream s, mlx_array* res) {
  try {
    mlx_array_set_(res, mlx::core::load(std::string(file), mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_load_safetensors_file(
    FILE* in_stream,
    const mlx_stream s,
    mlx_map_string_to_array* res_0,
    mlx_map_string_to_string* res_1) {
  try {
    std::tie(
        mlx_map_string_to_array_get_(*res_0),
        mlx_map_string_to_string_get_(*res_1)) =
        mlx::core::load_safetensors(
            std::make_shared<CFILEReader>(in_stream), mlx_stream_get_(s));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_load_safetensors(
    const char* file,
    const mlx_stream s,
    mlx_map_string_to_array* res_0,
    mlx_map_string_to_string* res_1) {
  try {
    std::tie(
        mlx_map_string_to_array_get_(*res_0),
        mlx_map_string_to_string_get_(*res_1)) =
        mlx::core::load_safetensors(std::string(file), mlx_stream_get_(s));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_save_file(FILE* out_stream, const mlx_array a) {
  try {
    mlx::core::save(
        std::make_shared<CFILEWriter>(out_stream), mlx_array_get_(a));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_save(const char* file, const mlx_array a) {
  try {
    mlx::core::save(std::string(file), mlx_array_get_(a));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_save_safetensors_file(
    FILE* in_stream,
    const mlx_map_string_to_array param,
    const mlx_map_string_to_string metadata) {
  try {
    mlx::core::save_safetensors(
        std::make_shared<CFILEWriter>(in_stream),
        mlx_map_string_to_array_get_(param),
        mlx_map_string_to_string_get_(metadata));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_save_safetensors(
    const char* file,
    const mlx_map_string_to_array param,
    const mlx_map_string_to_string metadata) {
  try {
    mlx::core::save_safetensors(
        std::string(file),
        mlx_map_string_to_array_get_(param),
        mlx_map_string_to_string_get_(metadata));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
