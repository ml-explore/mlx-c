/* Copyright © 2023-2024 Apple Inc. */

#include "mlx/c/private/tuple.h"
#include "mlx/c/object.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

mlx_string mlx_tuple_vector_array_vector_int_::tostring() {
  RETURN_MLX_C_STRING("mlx_tuple(mlx_vector_array, mlx_vector_int)");
}

extern "C" mlx_tuple_vector_array_vector_int
mlx_tuple_vector_array_vector_int_new(mlx_vector_array va, mlx_vector_int vi) {
  RETURN_MLX_C_PTR(
      new mlx_tuple_vector_array_vector_int_(std::make_pair(va->ctx, vi->ctx)));
}

extern "C" mlx_vector_array mlx_tuple_vector_array_vector_int_get_0(
    mlx_tuple_vector_array_vector_int tuple) {
  RETURN_MLX_C_PTR(new mlx_vector_array_(std::get<0>(tuple->ctx)));
}

extern "C" mlx_vector_int mlx_tuple_vector_array_vector_int_get_1(
    mlx_tuple_vector_array_vector_int tuple) {
  RETURN_MLX_C_PTR(new mlx_vector_int_(std::get<1>(tuple->ctx)));
}
