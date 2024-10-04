/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/closure.h"
#include "mlx/c/object.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

mlx_string_* mlx_closure_::tostring() {
  RETURN_MLX_C_STRING(
      "void mlx_closure(const mlx_vector_array, void*, mlx_vector_array*)");
}

extern "C" mlx_closure mlx_closure_new() {
  try {
    auto cpp_closure = [](const std::vector<mlx::core::array>& cpp_input) {
      return std::vector<mlx::core::array>();
    };
    return new mlx_closure_(cpp_closure);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return nullptr;
  }
}

extern "C" mlx_closure mlx_closure_new_func(
    void (*fun)(const mlx_vector_array, mlx_vector_array*)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](const std::vector<mlx::core::array>& cpp_input) {
            auto input = new mlx_vector_array_();
            mlx_vector_array_set_(input, cpp_input);
            auto res = new mlx_vector_array_();
            fun(input, &res);
            mlx_free(input);
            auto cpp_res = mlx_vector_array_get_(res);
            mlx_free(res);
            return cpp_res;
          };
      return new mlx_closure_(cpp_closure), return nullptr);
}

extern "C" mlx_closure mlx_closure_new_func_payload(
    void (*fun)(const mlx_vector_array, void*, mlx_vector_array*),
    void* payload,
    void (*dtor)(void*)) {
  auto cpp_payload = std::shared_ptr<void>(payload, dtor);
  auto cpp_closure =
      [fun, cpp_payload, dtor](const std::vector<mlx::core::array>& cpp_input) {
        auto input = new mlx_vector_array_();
        mlx_vector_array_set_(input, cpp_input);
        auto res = new mlx_vector_array_();
        fun(input, cpp_payload.get(), &res);
        mlx_free(input);
        auto cpp_res = mlx_vector_array_get_(res);
        mlx_free(res);
        return cpp_res;
      };
  MLX_TRY_CATCH(return new mlx_closure_(cpp_closure), return nullptr);
}

extern "C" int mlx_closure_apply(
    mlx_closure cls,
    const mlx_vector_array input,
    mlx_vector_array* res) {
  try {
    mlx_vector_array_set_(res, cls->ctx(mlx_vector_array_get_(input)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" mlx_closure mlx_closure_new_unary(
    void (*fun)(const mlx_array, mlx_array*)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](const std::vector<mlx::core::array>& cpp_input) {
            if (cpp_input.size() != 1) {
              throw std::runtime_error("closure: expected unary input");
            }
            auto input = new mlx_array_(cpp_input[0]);
            auto res = new mlx_array_();
            fun(input, &res);
            mlx_free(input);
            std::vector<mlx::core::array> cpp_res = {res->ctx};
            mlx_free(res);
            return cpp_res;
          };
      return new mlx_closure_(cpp_closure), return nullptr);
}

mlx_string_* mlx_closure_value_and_grad_::tostring() {
  RETURN_MLX_C_STRING(
      "void mlx_closure(const mlx_vector_array, void*, mlx_vector_array*, mlx_vector_array*)");
}

extern "C" mlx_closure_value_and_grad mlx_closure_value_and_grad_new() {
  try {
    auto cpp_closure = [](const std::vector<mlx::core::array>& cpp_input) {
      return std::
          pair<std::vector<mlx::core::array>, std::vector<mlx::core::array>>();
    };
    return new mlx_closure_value_and_grad_(cpp_closure);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return nullptr;
  }
}

extern "C" mlx_closure_value_and_grad mlx_closure_value_and_grad_new_func(
    void (*fun)(const mlx_vector_array, mlx_vector_array*, mlx_vector_array*)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](const std::vector<mlx::core::array>& cpp_input) {
            auto input = new mlx_vector_array_();
            mlx_vector_array_set_(input, cpp_input);
            auto res_0 = new mlx_vector_array_();
            auto res_1 = new mlx_vector_array_();
            ;
            fun(input, &res_0, &res_1);
            mlx_free(input);
            auto cpp_res = std::tie(
                mlx_vector_array_get_(res_0), mlx_vector_array_get_(res_1));
            mlx_free(res_0);
            mlx_free(res_1);
            ;
            return cpp_res;
          };
      return new mlx_closure_value_and_grad_(cpp_closure), return nullptr);
}

extern "C" mlx_closure_value_and_grad
mlx_closure_value_and_grad_new_func_payload(
    void (*fun)(
        const mlx_vector_array,
        void*,
        mlx_vector_array*,
        mlx_vector_array*),
    void* payload,
    void (*dtor)(void*)) {
  auto cpp_payload = std::shared_ptr<void>(payload, dtor);
  auto cpp_closure = [fun, cpp_payload, dtor](
                         const std::vector<mlx::core::array>& cpp_input) {
    auto input = new mlx_vector_array_();
    mlx_vector_array_set_(input, cpp_input);
    auto res_0 = new mlx_vector_array_();
    auto res_1 = new mlx_vector_array_();
    ;
    fun(input, cpp_payload.get(), &res_0, &res_1);
    mlx_free(input);
    auto cpp_res =
        std::tie(mlx_vector_array_get_(res_0), mlx_vector_array_get_(res_1));
    mlx_free(res_0);
    mlx_free(res_1);
    ;
    return cpp_res;
  };
  MLX_TRY_CATCH(return new mlx_closure_value_and_grad_(cpp_closure),
                       return nullptr);
}

extern "C" int mlx_closure_value_and_grad_apply(
    mlx_closure_value_and_grad cls,
    const mlx_vector_array input,
    mlx_vector_array* res_0,
    mlx_vector_array* res_1) {
  try {
    std::tie(mlx_vector_array_get_(*res_0), mlx_vector_array_get_(*res_1)) =
        cls->ctx(mlx_vector_array_get_(input));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

mlx_string_* mlx_closure_custom_::tostring() {
  RETURN_MLX_C_STRING(
      "void mlx_closure(const mlx_vector_array, const mlx_vector_array, const mlx_vector_array, void*, mlx_vector_array*)");
}

extern "C" mlx_closure_custom mlx_closure_custom_new() {
  try {
    auto cpp_closure = [](const std::vector<mlx::core::array>& cpp_input_0,
                          const std::vector<mlx::core::array>& cpp_input_1,
                          const std::vector<mlx::core::array>& cpp_input_2) {
      return std::vector<mlx::core::array>();
    };
    return new mlx_closure_custom_(cpp_closure);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return nullptr;
  }
}

extern "C" mlx_closure_custom mlx_closure_custom_new_func(void (*fun)(
    const mlx_vector_array,
    const mlx_vector_array,
    const mlx_vector_array,
    mlx_vector_array*)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](
              const std::vector<mlx::core::array>& cpp_input_0,
              const std::vector<mlx::core::array>& cpp_input_1,
              const std::vector<mlx::core::array>& cpp_input_2) {
            auto input_0 = new mlx_vector_array_();
            mlx_vector_array_set_(input_0, cpp_input_0);
            auto input_1 = new mlx_vector_array_();
            mlx_vector_array_set_(input_1, cpp_input_1);
            auto input_2 = new mlx_vector_array_();
            mlx_vector_array_set_(input_2, cpp_input_2);
            auto res = new mlx_vector_array_();
            fun(input_0, input_1, input_2, &res);
            mlx_free(input_0);
            mlx_free(input_1);
            mlx_free(input_2);
            auto cpp_res = mlx_vector_array_get_(res);
            mlx_free(res);
            return cpp_res;
          };
      return new mlx_closure_custom_(cpp_closure), return nullptr);
}

extern "C" mlx_closure_custom mlx_closure_custom_new_func_payload(
    void (*fun)(
        const mlx_vector_array,
        const mlx_vector_array,
        const mlx_vector_array,
        void*,
        mlx_vector_array*),
    void* payload,
    void (*dtor)(void*)) {
  auto cpp_payload = std::shared_ptr<void>(payload, dtor);
  auto cpp_closure = [fun, cpp_payload, dtor](
                         const std::vector<mlx::core::array>& cpp_input_0,
                         const std::vector<mlx::core::array>& cpp_input_1,
                         const std::vector<mlx::core::array>& cpp_input_2) {
    auto input_0 = new mlx_vector_array_();
    mlx_vector_array_set_(input_0, cpp_input_0);
    auto input_1 = new mlx_vector_array_();
    mlx_vector_array_set_(input_1, cpp_input_1);
    auto input_2 = new mlx_vector_array_();
    mlx_vector_array_set_(input_2, cpp_input_2);
    auto res = new mlx_vector_array_();
    fun(input_0, input_1, input_2, cpp_payload.get(), &res);
    mlx_free(input_0);
    mlx_free(input_1);
    mlx_free(input_2);
    auto cpp_res = mlx_vector_array_get_(res);
    mlx_free(res);
    return cpp_res;
  };
  MLX_TRY_CATCH(return new mlx_closure_custom_(cpp_closure), return nullptr);
}

extern "C" int mlx_closure_custom_apply(
    mlx_closure_custom cls,
    const mlx_vector_array input_0,
    const mlx_vector_array input_1,
    const mlx_vector_array input_2,
    mlx_vector_array* res) {
  try {
    mlx_vector_array_set_(
        res,
        cls->ctx(
            mlx_vector_array_get_(input_0),
            mlx_vector_array_get_(input_1),
            mlx_vector_array_get_(input_2)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

mlx_string_* mlx_closure_custom_jvp_::tostring() {
  RETURN_MLX_C_STRING(
      "void mlx_closure(const mlx_vector_array, const mlx_vector_array, const int* , size_t _num, void*, mlx_vector_array*)");
}

extern "C" mlx_closure_custom_jvp mlx_closure_custom_jvp_new() {
  try {
    auto cpp_closure = [](const std::vector<mlx::core::array>& cpp_input_0,
                          const std::vector<mlx::core::array>& cpp_input_1,
                          const std::vector<int>& cpp_input_2) {
      return std::vector<mlx::core::array>();
    };
    return new mlx_closure_custom_jvp_(cpp_closure);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return nullptr;
  }
}

extern "C" mlx_closure_custom_jvp mlx_closure_custom_jvp_new_func(void (*fun)(
    const mlx_vector_array,
    const mlx_vector_array,
    const int*,
    size_t _num,
    mlx_vector_array*)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](
              const std::vector<mlx::core::array>& cpp_input_0,
              const std::vector<mlx::core::array>& cpp_input_1,
              const std::vector<int>& cpp_input_2) {
            auto input_0 = new mlx_vector_array_();
            mlx_vector_array_set_(input_0, cpp_input_0);
            auto input_1 = new mlx_vector_array_();
            mlx_vector_array_set_(input_1, cpp_input_1);
            const int* input_2 = nullptr;
            size_t input_2_num = 0;
            input_2 = cpp_input_2.data();
            input_2_num = cpp_input_2.size();
            auto res = new mlx_vector_array_();
            fun(input_0, input_1, input_2, input_2_num, &res);
            mlx_free(input_0);
            mlx_free(input_1);
            ;
            auto cpp_res = mlx_vector_array_get_(res);
            mlx_free(res);
            return cpp_res;
          };
      return new mlx_closure_custom_jvp_(cpp_closure), return nullptr);
}

extern "C" mlx_closure_custom_jvp mlx_closure_custom_jvp_new_func_payload(
    void (*fun)(
        const mlx_vector_array,
        const mlx_vector_array,
        const int*,
        size_t _num,
        void*,
        mlx_vector_array*),
    void* payload,
    void (*dtor)(void*)) {
  auto cpp_payload = std::shared_ptr<void>(payload, dtor);
  auto cpp_closure = [fun, cpp_payload, dtor](
                         const std::vector<mlx::core::array>& cpp_input_0,
                         const std::vector<mlx::core::array>& cpp_input_1,
                         const std::vector<int>& cpp_input_2) {
    auto input_0 = new mlx_vector_array_();
    mlx_vector_array_set_(input_0, cpp_input_0);
    auto input_1 = new mlx_vector_array_();
    mlx_vector_array_set_(input_1, cpp_input_1);
    const int* input_2 = nullptr;
    size_t input_2_num = 0;
    input_2 = cpp_input_2.data();
    input_2_num = cpp_input_2.size();
    auto res = new mlx_vector_array_();
    fun(input_0, input_1, input_2, input_2_num, cpp_payload.get(), &res);
    mlx_free(input_0);
    mlx_free(input_1);
    ;
    auto cpp_res = mlx_vector_array_get_(res);
    mlx_free(res);
    return cpp_res;
  };
  MLX_TRY_CATCH(return new mlx_closure_custom_jvp_(cpp_closure),
                       return nullptr);
}

extern "C" int mlx_closure_custom_jvp_apply(
    mlx_closure_custom_jvp cls,
    const mlx_vector_array input_0,
    const mlx_vector_array input_1,
    const int* input_2,
    size_t input_2_num,
    mlx_vector_array* res) {
  try {
    mlx_vector_array_set_(
        res,
        cls->ctx(
            mlx_vector_array_get_(input_0),
            mlx_vector_array_get_(input_1),
            std::vector<int>(input_2, input_2 + input_2_num)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

mlx_string_* mlx_closure_custom_vmap_::tostring() {
  RETURN_MLX_C_STRING(
      "void mlx_closure(const mlx_vector_array, const int* , size_t _num, void*, mlx_vector_array*, mlx_vector_int*)");
}

extern "C" mlx_closure_custom_vmap mlx_closure_custom_vmap_new() {
  try {
    auto cpp_closure = [](const std::vector<mlx::core::array>& cpp_input_0,
                          const std::vector<int>& cpp_input_1) {
      return std::pair<std::vector<mlx::core::array>, std::vector<int>>();
    };
    return new mlx_closure_custom_vmap_(cpp_closure);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return nullptr;
  }
}

extern "C" mlx_closure_custom_vmap mlx_closure_custom_vmap_new_func(void (*fun)(
    const mlx_vector_array,
    const int*,
    size_t _num,
    mlx_vector_array*,
    mlx_vector_int*)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](
              const std::vector<mlx::core::array>& cpp_input_0,
              const std::vector<int>& cpp_input_1) {
            auto input_0 = new mlx_vector_array_();
            mlx_vector_array_set_(input_0, cpp_input_0);
            const int* input_1 = nullptr;
            size_t input_1_num = 0;
            input_1 = cpp_input_1.data();
            input_1_num = cpp_input_1.size();
            auto res_0 = new mlx_vector_array_();
            auto res_1 = new mlx_vector_int_();
            ;
            fun(input_0, input_1, input_1_num, &res_0, &res_1);
            mlx_free(input_0);
            ;
            auto cpp_res = std::tie(
                mlx_vector_array_get_(res_0), mlx_vector_int_get_(res_1));
            mlx_free(res_0);
            mlx_free(res_1);
            ;
            return cpp_res;
          };
      return new mlx_closure_custom_vmap_(cpp_closure), return nullptr);
}

extern "C" mlx_closure_custom_vmap mlx_closure_custom_vmap_new_func_payload(
    void (*fun)(
        const mlx_vector_array,
        const int*,
        size_t _num,
        void*,
        mlx_vector_array*,
        mlx_vector_int*),
    void* payload,
    void (*dtor)(void*)) {
  auto cpp_payload = std::shared_ptr<void>(payload, dtor);
  auto cpp_closure = [fun, cpp_payload, dtor](
                         const std::vector<mlx::core::array>& cpp_input_0,
                         const std::vector<int>& cpp_input_1) {
    auto input_0 = new mlx_vector_array_();
    mlx_vector_array_set_(input_0, cpp_input_0);
    const int* input_1 = nullptr;
    size_t input_1_num = 0;
    input_1 = cpp_input_1.data();
    input_1_num = cpp_input_1.size();
    auto res_0 = new mlx_vector_array_();
    auto res_1 = new mlx_vector_int_();
    ;
    fun(input_0, input_1, input_1_num, cpp_payload.get(), &res_0, &res_1);
    mlx_free(input_0);
    ;
    auto cpp_res =
        std::tie(mlx_vector_array_get_(res_0), mlx_vector_int_get_(res_1));
    mlx_free(res_0);
    mlx_free(res_1);
    ;
    return cpp_res;
  };
  MLX_TRY_CATCH(return new mlx_closure_custom_vmap_(cpp_closure),
                       return nullptr);
}

extern "C" int mlx_closure_custom_vmap_apply(
    mlx_closure_custom_vmap cls,
    const mlx_vector_array input_0,
    const int* input_1,
    size_t input_1_num,
    mlx_vector_array* res_0,
    mlx_vector_int* res_1) {
  try {
    std::tie(mlx_vector_array_get_(*res_0), mlx_vector_int_get_(*res_1)) =
        cls->ctx(
            mlx_vector_array_get_(input_0),
            std::vector<int>(input_1, input_1 + input_1_num));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
