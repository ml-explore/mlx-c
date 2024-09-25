/* Copyright © 2023-2024 Apple Inc. */

#include <cstring>

#include "mlx/c/closure.h"
#include "mlx/c/object.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

mlx_string_* mlx_closure_::tostring() {
  RETURN_MLX_C_STRING("mlx_vector_array closure(mlx_vector_array, void*)");
}

extern "C" mlx_closure mlx_closure_new(
    mlx_vector_array (*fun)(const mlx_vector_array)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](const std::vector<mlx::core::array>& input) {
            auto c_input = new mlx_vector_array_(input);
            auto c_res = fun(c_input);
            mlx_free(c_input);
            auto res = c_res->ctx;
            mlx_free(c_res);
            return res;
          };
      return new mlx_closure_(cpp_closure), return nullptr);
}

extern "C" mlx_closure mlx_closure_new_unary(
    mlx_array (*fun)(const mlx_array)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](const std::vector<mlx::core::array>& input) {
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
      return new mlx_closure_(cpp_closure), return nullptr);
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
  MLX_TRY_CATCH(return new mlx_closure_(cpp_closure), return nullptr);
}

extern "C" mlx_vector_array mlx_closure_apply(
    mlx_closure cls,
    const mlx_vector_array inputs) {
  MLX_TRY_CATCH(auto cpp_res = cls->ctx(inputs->ctx);
                return new mlx_vector_array_(cpp_res), return nullptr);
}

extern "C" mlx_vector_vector_array mlx_closure_value_and_grad_apply(
    mlx_closure_value_and_grad cls,
    const mlx_vector_array inputs) {
  MLX_TRY_CATCH(auto cpp_res = cls->ctx(inputs->ctx);
                return new mlx_vector_vector_array_(cpp_res), return nullptr);
}

mlx_string_* mlx_closure_value_and_grad_::tostring() {
  MLX_TRY_CATCH(
      return new mlx_string_(
                 "mlx_vector_vector_array closure(mlx_vector_array, void*)"),
             return nullptr);
}

extern "C" mlx_closure mlx_fallible_closure_new_with_payload(
  mlx_vector_array_result (*fun)(const mlx_vector_array, void*),
  void* payload,
  void (*dtor)(void*)) {
    auto cpp_payload = std::shared_ptr<void>(payload, dtor);
    auto cpp_closure = 
      [fun, cpp_payload, dtor](const std::vector<mlx::core::array>& input) {
        auto c_input = new mlx_vector_array_(input);
        mlx_vector_array_result c_res = fun(c_input, cpp_payload.get());
        mlx_free(c_input);
        if (mlx_vector_array_result_is_err(&c_res)) {
          mlx_string err = mlx_vector_array_result_into_err(c_res);
          throw std::runtime_error(err->ctx);
        }
        mlx_vector_array c_ok = mlx_vector_array_result_into_ok(c_res);
        auto res = c_ok->ctx;
        mlx_free(c_ok);
        return res;
      };
    MLX_TRY_CATCH(return new mlx_closure_(cpp_closure), return nullptr);
}