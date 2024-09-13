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

mlx_string_* mlx_closure_value_and_grad_::tostring() {
  RETURN_MLX_C_STRING(
      "mlx_tuple_vector_array_vector_array mlx_closure(const mlx_vector_array, void*)");
}

extern "C" mlx_closure_value_and_grad mlx_closure_value_and_grad_new(
    mlx_tuple_vector_array_vector_array (*fun)(const mlx_vector_array)) {
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
      return new mlx_closure_value_and_grad_(cpp_closure), return nullptr);
}

extern "C" mlx_closure_value_and_grad
mlx_closure_value_and_grad_new_with_payload(
    mlx_tuple_vector_array_vector_array (*fun)(const mlx_vector_array, void*),
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
  MLX_TRY_CATCH(return new mlx_closure_value_and_grad_(cpp_closure),
                       return nullptr);
}

extern "C" mlx_tuple_vector_array_vector_array mlx_closure_value_and_grad_apply(
    mlx_closure_value_and_grad cls,
    const mlx_vector_array input) {
  RETURN_MLX_C_PTR(
      new mlx_tuple_vector_array_vector_array_(cls->ctx(input->ctx)));
}

mlx_string_* mlx_closure_custom_function_::tostring() {
  RETURN_MLX_C_STRING(
      "mlx_vector_array mlx_closure(const mlx_vector_array, const mlx_vector_array, const mlx_vector_array, void*)");
}

extern "C" mlx_closure_custom_function mlx_closure_custom_function_new(
    mlx_vector_array (*fun)(
        const mlx_vector_array,
        const mlx_vector_array,
        const mlx_vector_array)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](
              const std::vector<mlx::core::array>& cpp_input_0,
              const std::vector<mlx::core::array>& cpp_input_1,
              const std::vector<mlx::core::array>& cpp_input_2) {
            auto input_0 = new mlx_vector_array_(cpp_input_0);
            auto input_1 = new mlx_vector_array_(cpp_input_1);
            auto input_2 = new mlx_vector_array_(cpp_input_2);
            auto res = fun(input_0, input_1, input_2);
            mlx_free(input_0);
            mlx_free(input_1);
            mlx_free(input_2);
            auto cpp_res = res->ctx;
            mlx_free(res);
            return cpp_res;
          };
      return new mlx_closure_custom_function_(cpp_closure), return nullptr);
}

extern "C" mlx_closure_custom_function
mlx_closure_custom_function_new_with_payload(
    mlx_vector_array (*fun)(
        const mlx_vector_array,
        const mlx_vector_array,
        const mlx_vector_array,
        void*),
    void* payload,
    void (*dtor)(void*)) {
  auto cpp_payload = std::shared_ptr<void>(payload, dtor);
  auto cpp_closure = [fun, cpp_payload, dtor](
                         const std::vector<mlx::core::array>& cpp_input_0,
                         const std::vector<mlx::core::array>& cpp_input_1,
                         const std::vector<mlx::core::array>& cpp_input_2) {
    auto input_0 = new mlx_vector_array_(cpp_input_0);
    auto input_1 = new mlx_vector_array_(cpp_input_1);
    auto input_2 = new mlx_vector_array_(cpp_input_2);
    auto res = fun(input_0, input_1, input_2, cpp_payload.get());
    mlx_free(input_0);
    mlx_free(input_1);
    mlx_free(input_2);
    auto cpp_res = res->ctx;
    mlx_free(res);
    return cpp_res;
  };
  MLX_TRY_CATCH(return new mlx_closure_custom_function_(cpp_closure),
                       return nullptr);
}

extern "C" mlx_vector_array mlx_closure_custom_function_apply(
    mlx_closure_custom_function cls,
    const mlx_vector_array input_0,
    const mlx_vector_array input_1,
    const mlx_vector_array input_2) {
  RETURN_MLX_C_PTR(new mlx_vector_array_(
      cls->ctx(input_0->ctx, input_1->ctx, input_2->ctx)));
}

mlx_string_* mlx_closure_custom_function_jvp_::tostring() {
  RETURN_MLX_C_STRING(
      "mlx_vector_array mlx_closure(const mlx_vector_array, const mlx_vector_array, const mlx_vector_int, void*)");
}

extern "C" mlx_closure_custom_function_jvp mlx_closure_custom_function_jvp_new(
    mlx_vector_array (*fun)(
        const mlx_vector_array,
        const mlx_vector_array,
        const mlx_vector_int)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](
              const std::vector<mlx::core::array>& cpp_input_0,
              const std::vector<mlx::core::array>& cpp_input_1,
              const std::vector<int>& cpp_input_2) {
            auto input_0 = new mlx_vector_array_(cpp_input_0);
            auto input_1 = new mlx_vector_array_(cpp_input_1);
            auto input_2 = new mlx_vector_int_(cpp_input_2);
            auto res = fun(input_0, input_1, input_2);
            mlx_free(input_0);
            mlx_free(input_1);
            mlx_free(input_2);
            auto cpp_res = res->ctx;
            mlx_free(res);
            return cpp_res;
          };
      return new mlx_closure_custom_function_jvp_(cpp_closure), return nullptr);
}

extern "C" mlx_closure_custom_function_jvp
mlx_closure_custom_function_jvp_new_with_payload(
    mlx_vector_array (*fun)(
        const mlx_vector_array,
        const mlx_vector_array,
        const mlx_vector_int,
        void*),
    void* payload,
    void (*dtor)(void*)) {
  auto cpp_payload = std::shared_ptr<void>(payload, dtor);
  auto cpp_closure = [fun, cpp_payload, dtor](
                         const std::vector<mlx::core::array>& cpp_input_0,
                         const std::vector<mlx::core::array>& cpp_input_1,
                         const std::vector<int>& cpp_input_2) {
    auto input_0 = new mlx_vector_array_(cpp_input_0);
    auto input_1 = new mlx_vector_array_(cpp_input_1);
    auto input_2 = new mlx_vector_int_(cpp_input_2);
    auto res = fun(input_0, input_1, input_2, cpp_payload.get());
    mlx_free(input_0);
    mlx_free(input_1);
    mlx_free(input_2);
    auto cpp_res = res->ctx;
    mlx_free(res);
    return cpp_res;
  };
  MLX_TRY_CATCH(return new mlx_closure_custom_function_jvp_(cpp_closure),
                       return nullptr);
}

extern "C" mlx_vector_array mlx_closure_custom_function_jvp_apply(
    mlx_closure_custom_function_jvp cls,
    const mlx_vector_array input_0,
    const mlx_vector_array input_1,
    const mlx_vector_int input_2) {
  RETURN_MLX_C_PTR(new mlx_vector_array_(
      cls->ctx(input_0->ctx, input_1->ctx, input_2->ctx)));
}

mlx_string_* mlx_closure_custom_function_vmap_::tostring() {
  RETURN_MLX_C_STRING(
      "mlx_tuple_vector_array_vector_int mlx_closure(const mlx_vector_array, const mlx_vector_int, void*)");
}

extern "C" mlx_closure_custom_function_vmap
mlx_closure_custom_function_vmap_new(mlx_tuple_vector_array_vector_int (
    *fun)(const mlx_vector_array, const mlx_vector_int)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](
              const std::vector<mlx::core::array>& cpp_input_0,
              const std::vector<int>& cpp_input_1) {
            auto input_0 = new mlx_vector_array_(cpp_input_0);
            auto input_1 = new mlx_vector_int_(cpp_input_1);
            auto res = fun(input_0, input_1);
            mlx_free(input_0);
            mlx_free(input_1);
            auto cpp_res = res->ctx;
            mlx_free(res);
            return cpp_res;
          };
      return new mlx_closure_custom_function_vmap_(cpp_closure),
             return nullptr);
}

extern "C" mlx_closure_custom_function_vmap
mlx_closure_custom_function_vmap_new_with_payload(
    mlx_tuple_vector_array_vector_int (
        *fun)(const mlx_vector_array, const mlx_vector_int, void*),
    void* payload,
    void (*dtor)(void*)) {
  auto cpp_payload = std::shared_ptr<void>(payload, dtor);
  auto cpp_closure = [fun, cpp_payload, dtor](
                         const std::vector<mlx::core::array>& cpp_input_0,
                         const std::vector<int>& cpp_input_1) {
    auto input_0 = new mlx_vector_array_(cpp_input_0);
    auto input_1 = new mlx_vector_int_(cpp_input_1);
    auto res = fun(input_0, input_1, cpp_payload.get());
    mlx_free(input_0);
    mlx_free(input_1);
    auto cpp_res = res->ctx;
    mlx_free(res);
    return cpp_res;
  };
  MLX_TRY_CATCH(return new mlx_closure_custom_function_vmap_(cpp_closure),
                       return nullptr);
}

extern "C" mlx_tuple_vector_array_vector_int
mlx_closure_custom_function_vmap_apply(
    mlx_closure_custom_function_vmap cls,
    const mlx_vector_array input_0,
    const mlx_vector_int input_1) {
  RETURN_MLX_C_PTR(new mlx_tuple_vector_array_vector_int_(
      cls->ctx(input_0->ctx, input_1->ctx)));
}
