#include "mlx/c/transforms.h"

#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/utils.h"

extern "C" void mlx_eval(const mlx_array* outputs, size_t num_outputs) {
  return MLX_C_VOID(mlx::core::eval(MLX_CPP_ARRVEC(outputs, num_outputs)));
}
extern "C" mlx_vector_vector_array mlx_jvp(
    mlx_closure fun,
    const mlx_array* primals,
    size_t num_primals,
    const mlx_array* tangents,
    size_t num_tangents) {
  return MLX_C_VECTORARRAYPAIR(mlx::core::jvp(
      MLX_CPP_CLOSURE(fun),
      MLX_CPP_ARRVEC(primals, num_primals),
      MLX_CPP_ARRVEC(tangents, num_tangents)));
}
extern "C" void mlx_simplify(const mlx_array* outputs, size_t num_outputs) {
  return MLX_C_VOID(mlx::core::simplify(MLX_CPP_ARRVEC(outputs, num_outputs)));
}
extern "C" mlx_closure_value_and_grad
mlx_value_and_grad(mlx_closure fun, const int* argnums, size_t num_argnums) {
  return MLX_C_CLOSURE_VALUE_AND_GRAD(mlx::core::value_and_grad(
      MLX_CPP_CLOSURE(fun), MLX_CPP_INTVEC(argnums, num_argnums)));
}
extern "C" mlx_vector_vector_array mlx_vjp(
    mlx_closure fun,
    const mlx_array* primals,
    size_t num_primals,
    const mlx_array* cotangents,
    size_t num_cotangents) {
  return MLX_C_VECTORARRAYPAIR(mlx::core::vjp(
      MLX_CPP_CLOSURE(fun),
      MLX_CPP_ARRVEC(primals, num_primals),
      MLX_CPP_ARRVEC(cotangents, num_cotangents)));
}
