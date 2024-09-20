/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/random.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" int mlx_random_bernoulli(
    mlx_array p,
    const int* shape,
    size_t num_shape,
    mlx_array key,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::random::bernoulli(
        p->ctx,
        MLX_CPP_INTVEC(shape, num_shape),
        (key ? std::make_optional(key->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_bits(
    const int* shape,
    size_t num_shape,
    int width,
    mlx_array key,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::random::bits(
        MLX_CPP_INTVEC(shape, num_shape),
        width,
        (key ? std::make_optional(key->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_categorical_shape(
    mlx_array logits,
    int axis,
    const int* shape,
    size_t num_shape,
    mlx_array key,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::random::categorical(
        logits->ctx,
        axis,
        MLX_CPP_INTVEC(shape, num_shape),
        (key ? std::make_optional(key->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_categorical_num_samples(
    mlx_array logits_,
    int axis,
    int num_samples,
    mlx_array key,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::random::categorical(
        logits_->ctx,
        axis,
        num_samples,
        (key ? std::make_optional(key->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_categorical(
    mlx_array logits,
    int axis,
    mlx_array key,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::random::categorical(
        logits->ctx,
        axis,
        (key ? std::make_optional(key->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_gumbel(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::random::gumbel(
        MLX_CPP_INTVEC(shape, num_shape),
        MLX_CPP_ARRAY_DTYPE(dtype),
        (key ? std::make_optional(key->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_key(uint64_t seed, mlx_array res) {
  try {
    res->ctx = mlx::core::random::key(seed);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_laplace(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    float loc,
    float scale,
    mlx_array key,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::random::laplace(
        MLX_CPP_INTVEC(shape, num_shape),
        MLX_CPP_ARRAY_DTYPE(dtype),
        loc,
        scale,
        (key ? std::make_optional(key->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_multivariate_normal(
    mlx_array mean,
    mlx_array cov,
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::random::multivariate_normal(
        mean->ctx,
        cov->ctx,
        MLX_CPP_INTVEC(shape, num_shape),
        MLX_CPP_ARRAY_DTYPE(dtype),
        (key ? std::make_optional(key->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_normal(
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    float loc,
    float scale,
    mlx_array key,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::random::normal(
        MLX_CPP_INTVEC(shape, num_shape),
        MLX_CPP_ARRAY_DTYPE(dtype),
        loc,
        scale,
        (key ? std::make_optional(key->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_randint(
    mlx_array low,
    mlx_array high,
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::random::randint(
        low->ctx,
        high->ctx,
        MLX_CPP_INTVEC(shape, num_shape),
        MLX_CPP_ARRAY_DTYPE(dtype),
        (key ? std::make_optional(key->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_seed(uint64_t seed) {
  try {
    mlx::core::random::seed(seed);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_split_equal_parts(
    mlx_array key,
    int num,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::random::split(key->ctx, num, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_split(
    mlx_array key,
    mlx_stream s,
    mlx_array res_0,
    mlx_array res_1) {
  try {
    std::tie(res_0->ctx, res_1->ctx) =
        mlx::core::random::split(key->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_truncated_normal(
    mlx_array lower,
    mlx_array upper,
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::random::truncated_normal(
        lower->ctx,
        upper->ctx,
        MLX_CPP_INTVEC(shape, num_shape),
        MLX_CPP_ARRAY_DTYPE(dtype),
        (key ? std::make_optional(key->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_uniform(
    mlx_array low,
    mlx_array high,
    const int* shape,
    size_t num_shape,
    mlx_array_dtype dtype,
    mlx_array key,
    mlx_stream s,
    mlx_array res) {
  try {
    res->ctx = mlx::core::random::uniform(
        low->ctx,
        high->ctx,
        MLX_CPP_INTVEC(shape, num_shape),
        MLX_CPP_ARRAY_DTYPE(dtype),
        (key ? std::make_optional(key->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
