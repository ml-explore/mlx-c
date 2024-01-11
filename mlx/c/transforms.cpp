#include "mlx/c/transforms.h"

#include "mlx/c/private/array.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/utils.h"

extern "C" void mlx_eval(const mlx_array* outputs, size_t num_outputs) {
  return MLX_C_VOID(mlx::core::eval(MLX_CPP_ARRVEC(outputs, num_outputs)));
}
extern "C" void mlx_simplify(const mlx_array* outputs, size_t num_outputs) {
  return MLX_C_VOID(mlx::core::simplify(MLX_CPP_ARRVEC(outputs, num_outputs)));
}
