/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/random.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

extern "C" mlx_array mlx_random_bernoulli(
    mlx_array p,
    const int* shape,
    size_t num_shape,
    mlx_array key,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::random::bernoulli(
      p->ctx,
      MLX_CPP_INTVEC(shape, num_shape),
      (key ? std::make_optional(key->ctx) : std::nullopt),
      s->ctx));
}
extern "C" mlx_array mlx_random_bits(
    const int* shape,
    size_t num_shape,
    int width,
    mlx_array key,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::random::bits(
      MLX_CPP_INTVEC(shape, num_shape),
      width,
      (key ? std::make_optional(key->ctx) : std::nullopt),
      s->ctx));
}
extern "C" mlx_array mlx_random_categorical_shape(
    mlx_array logits,
    int axis,
    const int* shape,
    size_t num_shape,
    mlx_array key,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::random::categorical(
      logits->ctx,
      axis,
      MLX_CPP_INTVEC(shape, num_shape),
      (key ? std::make_optional(key->ctx) : std::nullopt),
      s->ctx));
}
extern "C" mlx_array mlx_random_categorical_num_samples(
    mlx_array logits_,
    int axis,
    int num_samples,
    mlx_array key,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::random::categorical(
      logits_->ctx,
      axis,
      num_samples,
      (key ? std::make_optional(key->ctx) : std::nullopt),
      s->ctx));
}
extern "C" mlx_array mlx_random_categorical(
    mlx_array logits,
    int axis,
    mlx_array key,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::random::categorical(
      logits->ctx,
      axis,
      (key ? std::make_optional(key->ctx) : std::nullopt),
      s->ctx));
}
extern "C" mlx_array mlx_random_gumbel(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::random::gumbel(
      MLX_CPP_INTVEC(shape, num_shape),
      MLX_CPP_ARRAY_DTYPE(dtype),
      (key ? std::make_optional(key->ctx) : std::nullopt),
      s->ctx));
}
extern "C" mlx_array mlx_random_key(uint64_t seed) {
  return MLX_C_ARRAY(mlx::core::random::key(seed));
}
extern "C" mlx_array mlx_random_normal(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    float loc,
    float scale,
    mlx_array key,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::random::normal(
      MLX_CPP_INTVEC(shape, num_shape),
      MLX_CPP_ARRAY_DTYPE(dtype),
      loc,
      scale,
      (key ? std::make_optional(key->ctx) : std::nullopt),
      s->ctx));
}
extern "C" mlx_array mlx_random_randint(
    mlx_array low,
    mlx_array high,
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::random::randint(
      low->ctx,
      high->ctx,
      MLX_CPP_INTVEC(shape, num_shape),
      MLX_CPP_ARRAY_DTYPE(dtype),
      (key ? std::make_optional(key->ctx) : std::nullopt),
      s->ctx));
}
extern "C" void mlx_random_seed(uint64_t seed) {
  return MLX_C_VOID(mlx::core::random::seed(seed));
}
extern "C" mlx_array
mlx_random_split_equal_parts(mlx_array key, int num, mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::random::split(key->ctx, num, s->ctx));
}
extern "C" mlx_vector_array mlx_random_split(mlx_array key, mlx_stream s) {
  return MLX_C_ARRAYPAIR(mlx::core::random::split(key->ctx, s->ctx));
}
extern "C" mlx_array mlx_random_truncated_normal(
    mlx_array lower,
    mlx_array upper,
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::random::truncated_normal(
      lower->ctx,
      upper->ctx,
      MLX_CPP_INTVEC(shape, num_shape),
      MLX_CPP_ARRAY_DTYPE(dtype),
      (key ? std::make_optional(key->ctx) : std::nullopt),
      s->ctx));
}
extern "C" mlx_array mlx_random_uniform(
    mlx_array low,
    mlx_array high,
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::random::uniform(
      low->ctx,
      high->ctx,
      MLX_CPP_INTVEC(shape, num_shape),
      MLX_CPP_ARRAY_DTYPE(dtype),
      (key ? std::make_optional(key->ctx) : std::nullopt),
      s->ctx));
}
