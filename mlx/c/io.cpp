/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/io.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
//    #include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/future.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/tuple.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" int mlx_load_file(FILE* in_stream, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::load(MLX_CPP_READER(in_stream), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_load(mlx_string file, mlx_stream s, mlx_array res) {
  try {
    res->ctx = mlx::core::load(MLX_CPP_STRING(file), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_load_safetensors_file(
    FILE* in_stream,
    mlx_stream s,
    mlx_map_string_to_array res_0,
    mlx_map_string_to_string res_1) {
  try {
    std::tie(res_0->ctx, res_1->ctx) =
        mlx::core::load_safetensors(MLX_CPP_READER(in_stream), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_load_safetensors(
    mlx_string file,
    mlx_stream s,
    mlx_map_string_to_array res_0,
    mlx_map_string_to_string res_1) {
  try {
    std::tie(res_0->ctx, res_1->ctx) =
        mlx::core::load_safetensors(MLX_CPP_STRING(file), s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_save_file(FILE* out_stream, mlx_array a) {
  try {
    mlx::core::save(MLX_CPP_WRITER(out_stream), a->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_save(mlx_string file, mlx_array a) {
  try {
    mlx::core::save(MLX_CPP_STRING(file), a->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_save_safetensors_file(
    FILE* in_stream,
    mlx_map_string_to_array param,
    mlx_map_string_to_string metadata) {
  try {
    mlx::core::save_safetensors(
        MLX_CPP_WRITER(in_stream),
        MLX_CPP_MAP_STRING_TO_ARRAY(param),
        MLX_CPP_MAP_STRING_TO_STRING(metadata));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_save_safetensors(
    mlx_string file,
    mlx_map_string_to_array param,
    mlx_map_string_to_string metadata) {
  try {
    mlx::core::save_safetensors(
        MLX_CPP_STRING(file),
        MLX_CPP_MAP_STRING_TO_ARRAY(param),
        MLX_CPP_MAP_STRING_TO_STRING(metadata));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
