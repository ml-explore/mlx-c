/* Copyright © 2023-2024 Apple Inc. */

#include <stdio.h>
#include "mlx/c/mlx.h"

void print_array(const char* msg, mlx_array arr) {
  mlx_string str;
  str = mlx_tostring(arr);
  printf("%s\n%s\n", msg, mlx_string_data(str));
  mlx_free(str);
}

void gpu_info() {
  printf("==================================================\n");
  printf("GPU info:\n");
  mlx_metal_device_info_t info = mlx_metal_device_info();
  printf("architecture: %s\n", info.architecture);
  printf("max_buffer_length: %ld\n", info.max_buffer_length);
  printf(
      "max_recommended_working_set_size: %ld\n",
      info.max_recommended_working_set_size);
  printf("memory_size: %ld\n", info.memory_size);

  printf("==================================================\n");
}
int main() {
  gpu_info();

  mlx_stream stream = mlx_gpu_stream();
  float data[] = {1, 2, 3, 4, 5, 6};
  int shape[] = {2, 3};
  mlx_array arr = mlx_array_from_data(data, shape, 2, MLX_FLOAT32);
  print_array("hello world!", arr);

  mlx_array two = mlx_array_from_int(2);
  mlx_divide(arr, two, stream, arr);
  print_array("divive by 2!", arr);

  mlx_arange(0, 3, 0.5, MLX_FLOAT32, stream, arr);
  print_array("arange", arr);

  mlx_free(arr);
  mlx_free(two);
  mlx_free(stream);
  return 0;
}
