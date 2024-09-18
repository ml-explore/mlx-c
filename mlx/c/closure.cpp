/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/closure.h"
#include "mlx/c/object.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/tuple.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

mlx_string_* mlx_closure_::tostring() {
  RETURN_MLX_C_STRING(
      "mlx_vector_array mlx_closure(const mlx_vector_array, void*)");
}

extern "C" mlx_closure mlx_closure_new(
    mlx_vector_array (*fun)(const mlx_vector_array)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](const std::vector<mlx::core::array>& cpp_input) {
            auto input = new mlx_vector_array_(cpp_input);
            auto res = fun(input);
            mlx_free(input);
            auto cpp_res = res->ctx;
            mlx_free(res);
            return cpp_res;
          };
      return new mlx_closure_(cpp_closure), return nullptr);
}

extern "C" mlx_closure mlx_closure_new_with_payload(
    mlx_vector_array (*fun)(const mlx_vector_array, void*),
    void* payload,
    void (*dtor)(void*)) {
  auto cpp_payload = std::shared_ptr<void>(payload, dtor);
  auto cpp_closure =
      [fun, cpp_payload, dtor](const std::vector<mlx::core::array>& cpp_input) {
        auto input = new mlx_vector_array_(cpp_input);
        auto res = fun(input, cpp_payload.get());
        mlx_free(input);
        auto cpp_res = res->ctx;
        mlx_free(res);
        return cpp_res;
      };
  MLX_TRY_CATCH(return new mlx_closure_(cpp_closure), return nullptr);
}

extern "C" mlx_vector_array mlx_closure_apply(
    mlx_closure cls,
    const mlx_vector_array input) {
  RETURN_MLX_C_PTR(new mlx_vector_array_(cls->ctx(input->ctx)));
}

extern "C" mlx_closure mlx_closure_new_unary(
    mlx_array (*fun)(const mlx_array)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](const std::vector<mlx::core::array>& cpp_input) {
            if (cpp_input.size() != 1) {
              throw std::runtime_error("closure: expected unary input");
            }
            auto input = new mlx_array_(cpp_input[0]);
            auto res = fun(input);
            mlx_free(input);
            std::vector<mlx::core::array> cpp_res = {res->ctx};
            mlx_free(res);
            return cpp_res;
          };
      return new mlx_closure_(cpp_closure), return nullptr);
}
