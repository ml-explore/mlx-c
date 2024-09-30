/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/transforms.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" int mlx_async_eval(const mlx_vector_array outputs) {
  try {
    mlx::core::async_eval(outputs->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_checkpoint(const mlx_closure fun, mlx_closure* res) {
  try {
    (*res)->ctx = mlx::core::checkpoint(fun->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_custom_function(
    const mlx_closure fun,
    const mlx_closure_custom fun_vjp /* may be null */,
    const mlx_closure_custom_jvp fun_jvp /* may be null */,
    const mlx_closure_custom_vmap fun_vmap /* may be null */,
    mlx_closure* res) {
  try {
    (*res)->ctx = mlx::core::custom_function(
        fun->ctx,
        (fun_vjp ? std::make_optional(fun_vjp->ctx) : std::nullopt),
        (fun_jvp ? std::make_optional(fun_jvp->ctx) : std::nullopt),
        (fun_vmap ? std::make_optional(fun_vmap->ctx) : std::nullopt));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_custom_vjp(
    const mlx_closure fun,
    const mlx_closure_custom fun_vjp,
    mlx_closure* res) {
  try {
    (*res)->ctx = mlx::core::custom_vjp(fun->ctx, fun_vjp->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_eval(const mlx_vector_array outputs) {
  try {
    mlx::core::eval(outputs->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_jvp(
    const mlx_closure fun,
    const mlx_vector_array primals,
    const mlx_vector_array tangents,
    mlx_vector_array* res_0,
    mlx_vector_array* res_1) {
  try {
    std::tie((*res_0)->ctx, (*res_1)->ctx) =
        mlx::core::jvp(fun->ctx, primals->ctx, tangents->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_value_and_grad(
    const mlx_closure fun,
    const int* argnums,
    size_t argnums_num,
    mlx_closure_value_and_grad* res) {
  try {
    (*res)->ctx = mlx::core::value_and_grad(
        fun->ctx, std::vector<int>(argnums, argnums + argnums_num));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_vjp(
    const mlx_closure fun,
    const mlx_vector_array primals,
    const mlx_vector_array cotangents,
    mlx_vector_array* res_0,
    mlx_vector_array* res_1) {
  try {
    std::tie((*res_0)->ctx, (*res_1)->ctx) =
        mlx::core::vjp(fun->ctx, primals->ctx, cotangents->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
