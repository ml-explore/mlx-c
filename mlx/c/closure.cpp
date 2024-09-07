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

mlx_string_* mlx_closure_custom_function_::tostring() {
  RETURN_MLX_C_STRING(
      "mlx_vector_array closure(mlx_vector_array, mlx_vector_array, mlx_vector_array, void*)");
}

extern "C" mlx_closure_custom_function mlx_closure_custom_function_new(
    mlx_vector_array (*fun)(
        const mlx_vector_array,
        const mlx_vector_array,
        const mlx_vector_array)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](
              const std::vector<mlx::core::array>& input1,
              const std::vector<mlx::core::array>& input2,
              const std::vector<mlx::core::array>& input3) {
            auto c_input1 = new mlx_vector_array_(input1);
            auto c_input2 = new mlx_vector_array_(input2);
            auto c_input3 = new mlx_vector_array_(input3);
            auto c_res = fun(c_input1, c_input2, c_input3);
            mlx_free(c_input1);
            mlx_free(c_input2);
            mlx_free(c_input3);
            auto res = c_res->ctx;
            mlx_free(c_res);
            return res;
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
                         const std::vector<mlx::core::array>& input1,
                         const std::vector<mlx::core::array>& input2,
                         const std::vector<mlx::core::array>& input3) {
    auto c_input1 = new mlx_vector_array_(input1);
    auto c_input2 = new mlx_vector_array_(input2);
    auto c_input3 = new mlx_vector_array_(input3);
    auto c_res = fun(c_input1, c_input2, c_input3, cpp_payload.get());
    mlx_free(c_input1);
    mlx_free(c_input2);
    mlx_free(c_input3);
    auto res = c_res->ctx;
    mlx_free(c_res);
    return res;
  };
  MLX_TRY_CATCH(return new mlx_closure_custom_function_(cpp_closure),
                       return nullptr);
}

extern "C" mlx_vector_array mlx_closure_custom_function_apply(
    mlx_closure_custom_function cls,
    const mlx_vector_array inputs1,
    const mlx_vector_array inputs2,
    const mlx_vector_array inputs3) {
  MLX_TRY_CATCH(
      auto cpp_res = cls->ctx(inputs1->ctx, inputs2->ctx, inputs3->ctx);
      return new mlx_vector_array_(cpp_res), return nullptr);
}

mlx_string_* mlx_closure_custom_function_jvp_::tostring() {
  RETURN_MLX_C_STRING(
      "mlx_vector_array closure(mlx_vector_array, mlx_vector_array, mlx_vector_array, void*)");
}

extern "C" mlx_closure_custom_function_jvp
mlx_closure_custom_function_jvp_new(mlx_vector_array (
    *fun)(const mlx_vector_array, const mlx_vector_array, const int*, size_t)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](
              const std::vector<mlx::core::array>& input1,
              const std::vector<mlx::core::array>& input2,
              const std::vector<int>& input3) {
            auto c_input1 = new mlx_vector_array_(input1);
            auto c_input2 = new mlx_vector_array_(input2);
            auto c_res = fun(c_input1, c_input2, input3.data(), input3.size());
            mlx_free(c_input1);
            mlx_free(c_input2);
            auto res = c_res->ctx;
            mlx_free(c_res);
            return res;
          };
      return new mlx_closure_custom_function_jvp_(cpp_closure), return nullptr);
}

extern "C" mlx_closure_custom_function_jvp
mlx_closure_custom_function_jvp_new_with_payload(
    mlx_vector_array (*fun)(
        const mlx_vector_array,
        const mlx_vector_array,
        const int*,
        size_t,
        void*),
    void* payload,
    void (*dtor)(void*)) {
  auto cpp_payload = std::shared_ptr<void>(payload, dtor);
  auto cpp_closure = [fun, cpp_payload, dtor](
                         const std::vector<mlx::core::array>& input1,
                         const std::vector<mlx::core::array>& input2,
                         const std::vector<int>& input3) {
    auto c_input1 = new mlx_vector_array_(input1);
    auto c_input2 = new mlx_vector_array_(input2);
    auto c_res = fun(
        c_input1, c_input2, input3.data(), input3.size(), cpp_payload.get());
    mlx_free(c_input1);
    mlx_free(c_input2);
    auto res = c_res->ctx;
    mlx_free(c_res);
    return res;
  };
  MLX_TRY_CATCH(return new mlx_closure_custom_function_jvp_(cpp_closure),
                       return nullptr);
}

extern "C" mlx_vector_array mlx_closure_custom_function_jvp_apply(
    mlx_closure_custom_function_jvp cls,
    const mlx_vector_array inputs1,
    const mlx_vector_array inputs2,
    const int* inputs3,
    size_t inputs3_size) {
  MLX_TRY_CATCH(
      std::vector<int> cpp_inputs3(inputs3, inputs3 + inputs3_size);
      auto cpp_res = cls->ctx(inputs1->ctx, inputs2->ctx, cpp_inputs3);
      return new mlx_vector_array_(cpp_res), return nullptr);
}
