/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/private/tuple.h"
#include "mlx/c/object.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/variant.h"
#include "mlx/c/private/vector.h"

mlx_string mlx_tuple_array_array_::tostring() {
  RETURN_MLX_C_STRING("mlx_tuple(const mlx_array, const mlx_array)");
}

extern "C" mlx_tuple_array_array mlx_tuple_array_array_new(
    const mlx_array input_0,
    const mlx_array input_1) {
  RETURN_MLX_C_PTR(
      new mlx_tuple_array_array_(std::make_pair(input_0->ctx, input_1->ctx)));
}

extern "C" mlx_array mlx_tuple_array_array_get_0(mlx_tuple_array_array tuple) {
  RETURN_MLX_C_PTR(new mlx_array_(std::get<0>(tuple->ctx)));
}

extern "C" mlx_array mlx_tuple_array_array_get_1(mlx_tuple_array_array tuple) {
  RETURN_MLX_C_PTR(new mlx_array_(std::get<1>(tuple->ctx)));
}

mlx_string mlx_tuple_array_array_array_::tostring() {
  RETURN_MLX_C_STRING(
      "mlx_tuple(const mlx_array, const mlx_array, const mlx_array)");
}

extern "C" mlx_tuple_array_array_array mlx_tuple_array_array_array_new(
    const mlx_array input_0,
    const mlx_array input_1,
    const mlx_array input_2) {
  RETURN_MLX_C_PTR(new mlx_tuple_array_array_array_(
      std::make_tuple(input_0->ctx, input_1->ctx, input_2->ctx)));
}

extern "C" mlx_array mlx_tuple_array_array_array_get_0(
    mlx_tuple_array_array_array tuple) {
  RETURN_MLX_C_PTR(new mlx_array_(std::get<0>(tuple->ctx)));
}

extern "C" mlx_array mlx_tuple_array_array_array_get_1(
    mlx_tuple_array_array_array tuple) {
  RETURN_MLX_C_PTR(new mlx_array_(std::get<1>(tuple->ctx)));
}

extern "C" mlx_array mlx_tuple_array_array_array_get_2(
    mlx_tuple_array_array_array tuple) {
  RETURN_MLX_C_PTR(new mlx_array_(std::get<2>(tuple->ctx)));
}

mlx_string mlx_tuple_vector_array_vector_array_::tostring() {
  RETURN_MLX_C_STRING(
      "mlx_tuple(const mlx_vector_array, const mlx_vector_array)");
}

extern "C" mlx_tuple_vector_array_vector_array
mlx_tuple_vector_array_vector_array_new(
    const mlx_vector_array input_0,
    const mlx_vector_array input_1) {
  RETURN_MLX_C_PTR(new mlx_tuple_vector_array_vector_array_(
      std::make_pair(input_0->ctx, input_1->ctx)));
}

extern "C" mlx_vector_array mlx_tuple_vector_array_vector_array_get_0(
    mlx_tuple_vector_array_vector_array tuple) {
  RETURN_MLX_C_PTR(new mlx_vector_array_(std::get<0>(tuple->ctx)));
}

extern "C" mlx_vector_array mlx_tuple_vector_array_vector_array_get_1(
    mlx_tuple_vector_array_vector_array tuple) {
  RETURN_MLX_C_PTR(new mlx_vector_array_(std::get<1>(tuple->ctx)));
}

mlx_string mlx_tuple_vector_array_vector_int_::tostring() {
  RETURN_MLX_C_STRING(
      "mlx_tuple(const mlx_vector_array, const mlx_vector_int)");
}

extern "C" mlx_tuple_vector_array_vector_int
mlx_tuple_vector_array_vector_int_new(
    const mlx_vector_array input_0,
    const mlx_vector_int input_1) {
  RETURN_MLX_C_PTR(new mlx_tuple_vector_array_vector_int_(
      std::make_pair(input_0->ctx, input_1->ctx)));
}

extern "C" mlx_vector_array mlx_tuple_vector_array_vector_int_get_0(
    mlx_tuple_vector_array_vector_int tuple) {
  RETURN_MLX_C_PTR(new mlx_vector_array_(std::get<0>(tuple->ctx)));
}

extern "C" mlx_vector_int mlx_tuple_vector_array_vector_int_get_1(
    mlx_tuple_vector_array_vector_int tuple) {
  RETURN_MLX_C_PTR(new mlx_vector_int_(std::get<1>(tuple->ctx)));
}

mlx_string mlx_tuple_int_int_int_::tostring() {
  RETURN_MLX_C_STRING("mlx_tuple(const int, const int, const int)");
}

extern "C" mlx_tuple_int_int_int mlx_tuple_int_int_int_new(
    const int input_0,
    const int input_1,
    const int input_2) {
  RETURN_MLX_C_PTR(
      new mlx_tuple_int_int_int_(std::make_tuple(input_0, input_1, input_2)));
}

extern "C" int mlx_tuple_int_int_int_get_0(mlx_tuple_int_int_int tuple) {
  return std::get<0>(tuple->ctx);
}

extern "C" int mlx_tuple_int_int_int_get_1(mlx_tuple_int_int_int tuple) {
  return std::get<1>(tuple->ctx);
}

extern "C" int mlx_tuple_int_int_int_get_2(mlx_tuple_int_int_int tuple) {
  return std::get<2>(tuple->ctx);
}

mlx_string mlx_tuple_string_variant_int_bool_array_dtype_::tostring() {
  RETURN_MLX_C_STRING(
      "mlx_tuple(const mlx_string, const mlx_variant_int_bool_array_dtype)");
}

extern "C" mlx_tuple_string_variant_int_bool_array_dtype
mlx_tuple_string_variant_int_bool_array_dtype_new(
    const mlx_string input_0,
    const mlx_variant_int_bool_array_dtype input_1) {
  RETURN_MLX_C_PTR(new mlx_tuple_string_variant_int_bool_array_dtype_(
      std::make_pair(input_0->ctx, input_1->ctx)));
}

extern "C" mlx_string mlx_tuple_string_variant_int_bool_array_dtype_get_0(
    mlx_tuple_string_variant_int_bool_array_dtype tuple) {
  RETURN_MLX_C_PTR(new mlx_string_(std::get<0>(tuple->ctx)));
}

extern "C" mlx_variant_int_bool_array_dtype
mlx_tuple_string_variant_int_bool_array_dtype_get_1(
    mlx_tuple_string_variant_int_bool_array_dtype tuple) {
  RETURN_MLX_C_PTR(
      new mlx_variant_int_bool_array_dtype_(std::get<1>(tuple->ctx)));
}

mlx_string mlx_tuple_map_string_to_array_map_string_to_string_::tostring() {
  RETURN_MLX_C_STRING(
      "mlx_tuple(const mlx_map_string_to_array, const mlx_map_string_to_string)");
}

extern "C" mlx_tuple_map_string_to_array_map_string_to_string
mlx_tuple_map_string_to_array_map_string_to_string_new(
    const mlx_map_string_to_array input_0,
    const mlx_map_string_to_string input_1) {
  RETURN_MLX_C_PTR(new mlx_tuple_map_string_to_array_map_string_to_string_(
      std::make_pair(input_0->ctx, input_1->ctx)));
}

extern "C" mlx_map_string_to_array
mlx_tuple_map_string_to_array_map_string_to_string_get_0(
    mlx_tuple_map_string_to_array_map_string_to_string tuple) {
  RETURN_MLX_C_PTR(new mlx_map_string_to_array_(std::get<0>(tuple->ctx)));
}

extern "C" mlx_map_string_to_string
mlx_tuple_map_string_to_array_map_string_to_string_get_1(
    mlx_tuple_map_string_to_array_map_string_to_string tuple) {
  RETURN_MLX_C_PTR(new mlx_map_string_to_string_(std::get<1>(tuple->ctx)));
}
