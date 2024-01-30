/* Copyright © 2023-2024 Apple Inc. */

#include <cstring>

#include "mlx/c/closure.h"
#include "mlx/c/object.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

mlx_string_* mlx_closure_::tostring() {
  return new mlx_string_("mlx_vector_array closure(mlx_vector_array, void*)");
}

extern "C" mlx_closure mlx_closure_new(
    mlx_vector_array (*fun)(const mlx_vector_array)) {
  auto cpp_closure = [fun](const std::vector<mlx::core::array>& input) {
    auto c_input = new mlx_vector_array_(input);
    auto c_res = fun(c_input);
    mlx_free(c_input);
    auto res = c_res->ctx;
    mlx_free(c_res);
    return res;
  };
  return new mlx_closure_(cpp_closure);
}

extern "C" mlx_closure mlx_closure_new_unary(
    mlx_array (*fun)(const mlx_array)) {
  auto cpp_closure = [fun](const std::vector<mlx::core::array>& input) {
    if (input.size() != 1) {
      throw std::runtime_error("closure: expected unary input");
    }
    auto c_input = new mlx_array_(input[0]);
    auto c_res = fun(c_input);
    mlx_free(c_input);
    std::vector<mlx::core::array> res = {c_res->ctx};
    mlx_free(c_res);
    return res;
  };
  return new mlx_closure_(cpp_closure);
}

extern "C" mlx_closure mlx_closure_new_with_payload(
    mlx_vector_array (*fun)(const mlx_vector_array, void*),
    void* payload,
    void (*dtor)(void*)) {
  auto cpp_payload = std::shared_ptr<void>(payload, dtor);
  auto cpp_closure =
      [fun, cpp_payload, dtor](const std::vector<mlx::core::array>& input) {
        auto c_input = new mlx_vector_array_(input);
        auto c_res = fun(c_input, cpp_payload.get());
        mlx_free(c_input);
        auto res = c_res->ctx;
        mlx_free(c_res);
        return res;
      };
  return new mlx_closure_(cpp_closure);
}

extern "C" mlx_vector_array mlx_closure_apply(
    mlx_closure cls,
    const mlx_vector_array inputs) {
  auto cpp_res = cls->ctx(inputs->ctx);
  return new mlx_vector_array_(cpp_res);
}

extern "C" mlx_vector_vector_array mlx_closure_value_and_grad_apply(
    mlx_closure_value_and_grad cls,
    const mlx_vector_array inputs) {
  auto cpp_res = cls->ctx(inputs->ctx);
  return new mlx_vector_vector_array_(cpp_res);
}

mlx_string_* mlx_closure_value_and_grad_::tostring() {
  return new mlx_string_(
      "mlx_vector_vector_array closure(mlx_vector_array, void*)");
}
