/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/random.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" int mlx_random_bernoulli(
    const mlx_array p,
    const int* shape,
    size_t shape_num,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::random::bernoulli(
        p->ctx,
        std::vector<int>(shape, shape + shape_num),
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
    size_t shape_num,
    int width,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::random::bits(
        std::vector<int>(shape, shape + shape_num),
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
    const mlx_array logits,
    int axis,
    const int* shape,
    size_t shape_num,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::random::categorical(
        logits->ctx,
        axis,
        std::vector<int>(shape, shape + shape_num),
        (key ? std::make_optional(key->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_categorical_num_samples(
    const mlx_array logits_,
    int axis,
    int num_samples,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::random::categorical(
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
    const mlx_array logits,
    int axis,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::random::categorical(
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
    size_t shape_num,
    mlx_dtype dtype,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::random::gumbel(
        std::vector<int>(shape, shape + shape_num),
        mlx_dtype_to_cpp(dtype),
        (key ? std::make_optional(key->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_key(uint64_t seed, mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::random::key(seed);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_laplace(
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    float loc,
    float scale,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::random::laplace(
        std::vector<int>(shape, shape + shape_num),
        mlx_dtype_to_cpp(dtype),
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
    const mlx_array mean,
    const mlx_array cov,
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::random::multivariate_normal(
        mean->ctx,
        cov->ctx,
        std::vector<int>(shape, shape + shape_num),
        mlx_dtype_to_cpp(dtype),
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
    size_t shape_num,
    mlx_dtype dtype,
    float loc,
    float scale,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::random::normal(
        std::vector<int>(shape, shape + shape_num),
        mlx_dtype_to_cpp(dtype),
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
    const mlx_array low,
    const mlx_array high,
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::random::randint(
        low->ctx,
        high->ctx,
        std::vector<int>(shape, shape + shape_num),
        mlx_dtype_to_cpp(dtype),
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
    const mlx_array key,
    int num,
    const mlx_stream s,
    mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::random::split(key->ctx, num, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_split(
    const mlx_array key,
    const mlx_stream s,
    mlx_array* res_0,
    mlx_array* res_1) {
  try {
    std::tie((*res_0)->ctx, (*res_1)->ctx) =
        mlx::core::random::split(key->ctx, s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_truncated_normal(
    const mlx_array lower,
    const mlx_array upper,
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::random::truncated_normal(
        lower->ctx,
        upper->ctx,
        std::vector<int>(shape, shape + shape_num),
        mlx_dtype_to_cpp(dtype),
        (key ? std::make_optional(key->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_random_uniform(
    const mlx_array low,
    const mlx_array high,
    const int* shape,
    size_t shape_num,
    mlx_dtype dtype,
    const mlx_array key /* may be null */,
    const mlx_stream s,
    mlx_array* res) {
  try {
    (*res)->ctx = mlx::core::random::uniform(
        low->ctx,
        high->ctx,
        std::vector<int>(shape, shape + shape_num),
        mlx_dtype_to_cpp(dtype),
        (key ? std::make_optional(key->ctx) : std::nullopt),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
