/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/io.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

extern "C" mlx_array mlx_load_file(FILE* in_stream, mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::load(MLX_CPP_READER(in_stream), s->ctx));
}
extern "C" mlx_array mlx_load(mlx_string file, mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::load(MLX_CPP_STRING(file), s->ctx));
}
extern "C" mlx_safetensors mlx_load_safetensors_file(
    FILE* in_stream,
    mlx_stream s) {
  return MLX_C_SAFETENSORS(
      mlx::core::load_safetensors(MLX_CPP_READER(in_stream), s->ctx));
}
extern "C" mlx_safetensors mlx_load_safetensors(mlx_string file, mlx_stream s) {
  return MLX_C_SAFETENSORS(
      mlx::core::load_safetensors(MLX_CPP_STRING(file), s->ctx));
}
extern "C" void mlx_save_file(FILE* out_stream, mlx_array a) {
  return MLX_C_VOID(mlx::core::save(MLX_CPP_WRITER(out_stream), a->ctx));
}
extern "C" void mlx_save(mlx_string file, mlx_array a) {
  return MLX_C_VOID(mlx::core::save(MLX_CPP_STRING(file), a->ctx));
}
extern "C" void mlx_save_safetensors_file(
    FILE* in_stream,
    mlx_map_string_to_array param,
    mlx_map_string_to_string metadata) {
  return MLX_C_VOID(mlx::core::save_safetensors(
      MLX_CPP_WRITER(in_stream),
      MLX_CPP_MAP_STRING_TO_ARRAY(param),
      MLX_CPP_MAP_STRING_TO_STRING(metadata)));
}
extern "C" void mlx_save_safetensors(
    mlx_string file,
    mlx_map_string_to_array param,
    mlx_map_string_to_string metadata) {
  return MLX_C_VOID(mlx::core::save_safetensors(
      MLX_CPP_STRING(file),
      MLX_CPP_MAP_STRING_TO_ARRAY(param),
      MLX_CPP_MAP_STRING_TO_STRING(metadata)));
}
