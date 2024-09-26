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
mlx_load_file(FILE* in_stream, const mlx_stream s, mlx_array res) {
  try {
    res->ctx =
        mlx::core::load(std::make_shared<CFILEReader>(in_stream), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_load(const char* file, const mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::load(std::string(file), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_load_safetensors_file(
    FILE* in_stream,
    const mlx_stream s,
    mlx_map_string_to_array res_0,
    mlx_map_string_to_string res_1) {
  try {
    std::tie(res_0->ctx, res_1->ctx) = mlx::core::load_safetensors(
        std::make_shared<CFILEReader>(in_stream), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_load_safetensors(
    const char* file,
    const mlx_stream s,
    mlx_map_string_to_array res_0,
    mlx_map_string_to_string res_1) {
  try {
    std::tie(res_0->ctx, res_1->ctx) =
        mlx::core::load_safetensors(std::string(file), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_save_file(FILE* out_stream, const mlx_array a) {
  try {
    mlx::core::save(std::make_shared<CFILEWriter>(out_stream), a->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_save(const char* file, const mlx_array a) {
  try {
    mlx::core::save(std::string(file), a->ctx);
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
        std::make_shared<CFILEWriter>(in_stream), param->ctx, metadata->ctx);
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
    mlx::core::save_safetensors(std::string(file), param->ctx, metadata->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
