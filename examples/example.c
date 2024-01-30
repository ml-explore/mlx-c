/* Copyright © 2023-2024 Apple Inc. */

#include <stdio.h>
#include "mlx/c/mlx.h"

void print_array(const char* msg, mlx_array arr) {
  mlx_string str;
  str = mlx_tostring(arr);
  printf("%s\n%s\n", msg, mlx_string_data(str));
  mlx_free(str);
}

int main() {
  float data[] = {1, 2, 3, 4, 5, 6};
  int shape[] = {2, 3};
  mlx_array arr = mlx_array_from_data(data, shape, 2, MLX_FLOAT32);
  print_array("hello world!", arr);

  mlx_array two = mlx_array_from_int(2);
  mlx_array res = mlx_divide(arr, two, MLX_GPU_STREAM);
  print_array("divive by 2!", res);

  mlx_array arange = mlx_arange(0, 3, 0.5, MLX_FLOAT32, MLX_GPU_STREAM);
  print_array("arange", arange);

  mlx_free(arange);
  mlx_free(arr);
  mlx_free(res);
  mlx_free(two);
  return 0;
}
