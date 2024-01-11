#include <cstring>

#include "mlx/c/closure.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/utils.h"

char* mlx_closure_::tostring() {
  std::string str = "mlx_vector_array closure(mlx_vector_array, void*)";
  char* c_str = (char*)malloc(str.size() + 1);
  memcpy(c_str, str.data(), str.size());
  c_str[str.size()] = '\0';
  return c_str;
}

extern "C" mlx_closure mlx_closure_new(
    mlx_vector_array (*fun)(const mlx_array*, size_t)) {
  auto cpp_closure = [fun](const std::vector<mlx::core::array>& input) {
    auto c_input = mlx_cpp_vector_array_to_c(input);
    auto c_res = fun(c_input.arrays, c_input.size);
    mlx_vector_array_free(c_input);
    auto res = mlx_c_vector_array_to_cpp(c_res.arrays, c_res.size);
    mlx_vector_array_free(c_res);
    return res;
  };
  return new mlx_closure_(cpp_closure);
}

extern "C" mlx_closure mlx_closure_new_with_payload(
    mlx_vector_array (*fun)(const mlx_array*, size_t, void*),
    void* payload,
    void (*dtor)(void*)) {
  auto cpp_closure =
      [fun, payload, dtor](const std::vector<mlx::core::array>& input) {
        auto c_input = mlx_cpp_vector_array_to_c(input);
        auto c_res = fun(c_input.arrays, c_input.size, payload);
        mlx_vector_array_free(c_input);
        auto res = mlx_c_vector_array_to_cpp(c_res.arrays, c_res.size);
        mlx_vector_array_free(c_res);
        return res;
      };
  return new mlx_closure_(cpp_closure, payload, dtor);
}

extern "C" mlx_vector_array
mlx_closure_apply(mlx_closure cls, const mlx_array* inputs, size_t num_inputs) {
  auto cpp_input = mlx_c_vector_array_to_cpp(inputs, num_inputs);
  auto cpp_res = cls->ctx(cpp_input);
  auto c_res = mlx_cpp_vector_array_to_c(cpp_res);
  return c_res;
}
