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
      "void mlx_closure(const mlx_vector_array, void*, mlx_vector_array)");
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

extern "C" mlx_closure mlx_closure_from_func(
    void (*fun)(const mlx_vector_array, mlx_vector_array)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](const std::vector<mlx::core::array>& cpp_input) {
            auto input = new mlx_vector_array_();
            input->ctx = cpp_input;
            auto res = new mlx_vector_array_();
            fun(input, res);
            mlx_free(input);
            auto cpp_res = res->ctx;
            mlx_free(res);
            return cpp_res;
          };
      return new mlx_closure_(cpp_closure), return nullptr);
}

extern "C" mlx_closure mlx_closure_from_func_payload(
    void (*fun)(const mlx_vector_array, void*, mlx_vector_array),
    void* payload,
    void (*dtor)(void*)) {
  auto cpp_payload = std::shared_ptr<void>(payload, dtor);
  auto cpp_closure =
      [fun, cpp_payload, dtor](const std::vector<mlx::core::array>& cpp_input) {
        auto input = new mlx_vector_array_();
        input->ctx = cpp_input;
        auto res = new mlx_vector_array_();
        fun(input, cpp_payload.get(), res);
        mlx_free(input);
        auto cpp_res = res->ctx;
        mlx_free(res);
        return cpp_res;
      };
  MLX_TRY_CATCH(return new mlx_closure_(cpp_closure), return nullptr);
}

extern "C" int mlx_closure_apply(
    mlx_closure cls,
    const mlx_vector_array input,
    mlx_vector_array res) {
  try {
    res->ctx = cls->ctx(input->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" mlx_closure mlx_closure_from_unary(
    void (*fun)(const mlx_array, mlx_array)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](const std::vector<mlx::core::array>& cpp_input) {
            if (cpp_input.size() != 1) {
              throw std::runtime_error("closure: expected unary input");
            }
            auto input = new mlx_array_(cpp_input[0]);
            auto res = new mlx_array_();
            fun(input, res);
            mlx_free(input);
            std::vector<mlx::core::array> cpp_res = {res->ctx};
            mlx_free(res);
            return cpp_res;
          };
      return new mlx_closure_(cpp_closure), return nullptr);
}

mlx_string_* mlx_closure_value_and_grad_::tostring() {
  RETURN_MLX_C_STRING(
      "void mlx_closure(const mlx_vector_array, void*, mlx_vector_array, mlx_vector_array)");
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

extern "C" mlx_closure_value_and_grad mlx_closure_value_and_grad_from_func(
    void (*fun)(const mlx_vector_array, mlx_vector_array, mlx_vector_array)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](const std::vector<mlx::core::array>& cpp_input) {
            auto input = new mlx_vector_array_();
            input->ctx = cpp_input;
            auto res_0 = new mlx_vector_array_();
            auto res_1 = new mlx_vector_array_();
            ;
            fun(input, res_0, res_1);
            mlx_free(input);
            auto cpp_res = std::tie(res_0->ctx, res_1->ctx);
            mlx_free(res_0);
            mlx_free(res_1);
            ;
            return cpp_res;
          };
      return new mlx_closure_value_and_grad_(cpp_closure), return nullptr);
}

extern "C" mlx_closure_value_and_grad
mlx_closure_value_and_grad_from_func_payload(
    void (*fun)(
        const mlx_vector_array,
        void*,
        mlx_vector_array,
        mlx_vector_array),
    void* payload,
    void (*dtor)(void*)) {
  auto cpp_payload = std::shared_ptr<void>(payload, dtor);
  auto cpp_closure =
      [fun, cpp_payload, dtor](const std::vector<mlx::core::array>& cpp_input) {
        auto input = new mlx_vector_array_();
        input->ctx = cpp_input;
        auto res_0 = new mlx_vector_array_();
        auto res_1 = new mlx_vector_array_();
        ;
        fun(input, cpp_payload.get(), res_0, res_1);
        mlx_free(input);
        auto cpp_res = std::tie(res_0->ctx, res_1->ctx);
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
    mlx_vector_array res_0,
    mlx_vector_array res_1) {
  try {
    std::tie(res_0->ctx, res_1->ctx) = cls->ctx(input->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

mlx_string_* mlx_closure_custom_::tostring() {
  RETURN_MLX_C_STRING(
      "void mlx_closure(const mlx_vector_array, const mlx_vector_array, const mlx_vector_array, void*, mlx_vector_array)");
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

extern "C" mlx_closure_custom mlx_closure_custom_from_func(void (*fun)(
    const mlx_vector_array,
    const mlx_vector_array,
    const mlx_vector_array,
    mlx_vector_array)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](
              const std::vector<mlx::core::array>& cpp_input_0,
              const std::vector<mlx::core::array>& cpp_input_1,
              const std::vector<mlx::core::array>& cpp_input_2) {
            auto input_0 = new mlx_vector_array_();
            input_0->ctx = cpp_input_0;
            auto input_1 = new mlx_vector_array_();
            input_1->ctx = cpp_input_1;
            auto input_2 = new mlx_vector_array_();
            input_2->ctx = cpp_input_2;
            auto res = new mlx_vector_array_();
            fun(input_0, input_1, input_2, res);
            mlx_free(input_0);
            mlx_free(input_1);
            mlx_free(input_2);
            auto cpp_res = res->ctx;
            mlx_free(res);
            return cpp_res;
          };
      return new mlx_closure_custom_(cpp_closure), return nullptr);
}

extern "C" mlx_closure_custom mlx_closure_custom_from_func_payload(
    void (*fun)(
        const mlx_vector_array,
        const mlx_vector_array,
        const mlx_vector_array,
        void*,
        mlx_vector_array),
    void* payload,
    void (*dtor)(void*)) {
  auto cpp_payload = std::shared_ptr<void>(payload, dtor);
  auto cpp_closure = [fun, cpp_payload, dtor](
                         const std::vector<mlx::core::array>& cpp_input_0,
                         const std::vector<mlx::core::array>& cpp_input_1,
                         const std::vector<mlx::core::array>& cpp_input_2) {
    auto input_0 = new mlx_vector_array_();
    input_0->ctx = cpp_input_0;
    auto input_1 = new mlx_vector_array_();
    input_1->ctx = cpp_input_1;
    auto input_2 = new mlx_vector_array_();
    input_2->ctx = cpp_input_2;
    auto res = new mlx_vector_array_();
    fun(input_0, input_1, input_2, cpp_payload.get(), res);
    mlx_free(input_0);
    mlx_free(input_1);
    mlx_free(input_2);
    auto cpp_res = res->ctx;
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
    mlx_vector_array res) {
  try {
    res->ctx = cls->ctx(input_0->ctx, input_1->ctx, input_2->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

mlx_string_* mlx_closure_custom_jvp_::tostring() {
  RETURN_MLX_C_STRING(
      "void mlx_closure(const mlx_vector_array, const mlx_vector_array, const int* , size_t _num, void*, mlx_vector_array)");
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

extern "C" mlx_closure_custom_jvp mlx_closure_custom_jvp_from_func(void (*fun)(
    const mlx_vector_array,
    const mlx_vector_array,
    const int*,
    size_t _num,
    mlx_vector_array)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](
              const std::vector<mlx::core::array>& cpp_input_0,
              const std::vector<mlx::core::array>& cpp_input_1,
              const std::vector<int>& cpp_input_2) {
            auto input_0 = new mlx_vector_array_();
            input_0->ctx = cpp_input_0;
            auto input_1 = new mlx_vector_array_();
            input_1->ctx = cpp_input_1;
            const int* input_2 = nullptr;
            size_t input_2_num = 0;
            input_2 = cpp_input_2.data();
            input_2_num = cpp_input_2.size();
            auto res = new mlx_vector_array_();
            fun(input_0, input_1, input_2, input_2_num, res);
            mlx_free(input_0);
            mlx_free(input_1);
            ;
            auto cpp_res = res->ctx;
            mlx_free(res);
            return cpp_res;
          };
      return new mlx_closure_custom_jvp_(cpp_closure), return nullptr);
}

extern "C" mlx_closure_custom_jvp mlx_closure_custom_jvp_from_func_payload(
    void (*fun)(
        const mlx_vector_array,
        const mlx_vector_array,
        const int*,
        size_t _num,
        void*,
        mlx_vector_array),
    void* payload,
    void (*dtor)(void*)) {
  auto cpp_payload = std::shared_ptr<void>(payload, dtor);
  auto cpp_closure = [fun, cpp_payload, dtor](
                         const std::vector<mlx::core::array>& cpp_input_0,
                         const std::vector<mlx::core::array>& cpp_input_1,
                         const std::vector<int>& cpp_input_2) {
    auto input_0 = new mlx_vector_array_();
    input_0->ctx = cpp_input_0;
    auto input_1 = new mlx_vector_array_();
    input_1->ctx = cpp_input_1;
    const int* input_2 = nullptr;
    size_t input_2_num = 0;
    input_2 = cpp_input_2.data();
    input_2_num = cpp_input_2.size();
    auto res = new mlx_vector_array_();
    fun(input_0, input_1, input_2, input_2_num, cpp_payload.get(), res);
    mlx_free(input_0);
    mlx_free(input_1);
    ;
    auto cpp_res = res->ctx;
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
    mlx_vector_array res) {
  try {
    res->ctx = cls->ctx(
        input_0->ctx,
        input_1->ctx,
        std::vector<int>(input_2, input_2 + input_2_num));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

mlx_string_* mlx_closure_custom_vmap_::tostring() {
  RETURN_MLX_C_STRING(
      "void mlx_closure(const mlx_vector_array, const int* , size_t _num, void*, mlx_vector_array, mlx_vector_int)");
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

extern "C" mlx_closure_custom_vmap mlx_closure_custom_vmap_from_func(
    void (*fun)(
        const mlx_vector_array,
        const int*,
        size_t _num,
        mlx_vector_array,
        mlx_vector_int)) {
  MLX_TRY_CATCH(
      auto cpp_closure =
          [fun](
              const std::vector<mlx::core::array>& cpp_input_0,
              const std::vector<int>& cpp_input_1) {
            auto input_0 = new mlx_vector_array_();
            input_0->ctx = cpp_input_0;
            const int* input_1 = nullptr;
            size_t input_1_num = 0;
            input_1 = cpp_input_1.data();
            input_1_num = cpp_input_1.size();
            auto res_0 = new mlx_vector_array_();
            auto res_1 = new mlx_vector_int_();
            ;
            fun(input_0, input_1, input_1_num, res_0, res_1);
            mlx_free(input_0);
            ;
            auto cpp_res = std::tie(res_0->ctx, res_1->ctx);
            mlx_free(res_0);
            mlx_free(res_1);
            ;
            return cpp_res;
          };
      return new mlx_closure_custom_vmap_(cpp_closure), return nullptr);
}

extern "C" mlx_closure_custom_vmap mlx_closure_custom_vmap_from_func_payload(
    void (*fun)(
        const mlx_vector_array,
        const int*,
        size_t _num,
        void*,
        mlx_vector_array,
        mlx_vector_int),
    void* payload,
    void (*dtor)(void*)) {
  auto cpp_payload = std::shared_ptr<void>(payload, dtor);
  auto cpp_closure = [fun, cpp_payload, dtor](
                         const std::vector<mlx::core::array>& cpp_input_0,
                         const std::vector<int>& cpp_input_1) {
    auto input_0 = new mlx_vector_array_();
    input_0->ctx = cpp_input_0;
    const int* input_1 = nullptr;
    size_t input_1_num = 0;
    input_1 = cpp_input_1.data();
    input_1_num = cpp_input_1.size();
    auto res_0 = new mlx_vector_array_();
    auto res_1 = new mlx_vector_int_();
    ;
    fun(input_0, input_1, input_1_num, cpp_payload.get(), res_0, res_1);
    mlx_free(input_0);
    ;
    auto cpp_res = std::tie(res_0->ctx, res_1->ctx);
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
    mlx_vector_array res_0,
    mlx_vector_int res_1) {
  try {
    std::tie(res_0->ctx, res_1->ctx) = cls->ctx(
        input_0->ctx, std::vector<int>(input_1, input_1 + input_1_num));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

mlx_string_* mlx_closure_metal_kernel_desc_::tostring() {
  RETURN_MLX_C_STRING("mlx_closure_metal_kernel_desc");
}

extern "C" mlx_closure_metal_kernel_desc mlx_closure_metal_kernel_desc_new() {
  try {
    return new mlx_closure_metal_kernel_desc_();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return nullptr;
  }
}

extern "C" int mlx_closure_metal_kernel_desc_add_output_arg(
    mlx_closure_metal_kernel_desc desc,
    const int* shape,
    size_t size,
    mlx_dtype dtype) {
  try {
    desc->output_shapes.push_back(std::vector<int>(shape, shape + size));
    desc->output_dtypes.push_back(mlx_dtype_to_cpp(dtype));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_closure_metal_kernel_desc_set_grid(
    mlx_closure_metal_kernel_desc desc,
    int grid1,
    int grid2,
    int grid3) {
  try {
    desc->grid = std::make_tuple(grid1, grid2, grid3);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_closure_metal_kernel_desc_set_thread_group(
    mlx_closure_metal_kernel_desc desc,
    int thread1,
    int thread2,
    int thread3) {
  try {
    desc->thread_group = std::make_tuple(thread1, thread2, thread3);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_closure_metal_kernel_desc_set_init_value(
    mlx_closure_metal_kernel_desc desc,
    float value) {
  try {
    desc->init_value = value;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_closure_metal_kernel_desc_set_verbose(
    mlx_closure_metal_kernel_desc desc,
    bool verbose) {
  try {
    desc->verbose = verbose;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_closure_metal_kernel_desc_add_template_arg_dtype(
    mlx_closure_metal_kernel_desc desc,
    const char* name,
    mlx_dtype dtype) {
  try {
    desc->template_args.push_back(
        std::make_pair(std::string(name), mlx_dtype_to_cpp(dtype)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_closure_metal_kernel_desc_add_template_arg_int(
    mlx_closure_metal_kernel_desc desc,
    const char* name,
    int value) {
  try {
    desc->template_args.push_back(std::make_pair(std::string(name), value));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_closure_metal_kernel_desc_add_template_arg_bool(
    mlx_closure_metal_kernel_desc desc,
    const char* name,
    bool value) {
  try {
    desc->template_args.push_back(std::make_pair(std::string(name), value));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

mlx_string_* mlx_closure_metal_kernel_::tostring() {
  RETURN_MLX_C_STRING("mlx_closure_metal_kernel_");
}

extern "C" mlx_closure_metal_kernel mlx_closure_metal_kernel_new() {
  try {
    return new mlx_closure_metal_kernel_();
  } catch (std::exception& e) {
    mlx_error(e.what());
  }
  return nullptr;
}
extern "C" int mlx_closure_metal_kernel_apply(
    mlx_closure_metal_kernel cls,
    const mlx_vector_array inputs,
    const mlx_closure_metal_kernel_desc desc,
    const mlx_stream stream,
    mlx_vector_array outputs) {
  try {
    outputs->ctx = cls->ctx(
        inputs->ctx,
        desc->output_shapes,
        desc->output_dtypes,
        desc->grid,
        desc->thread_group,
        desc->template_args,
        desc->init_value,
        desc->verbose,
        stream->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
