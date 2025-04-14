/* Copyright © 2023-2024 Apple Inc. */

#include <stdio.h>
#include "mlx/c/mlx.h"

void print_array(const char* msg, mlx_array arr) {
  mlx_string str = mlx_string_new();
  mlx_array_tostring(&str, arr);
  printf("%s\n%s\n", msg, mlx_string_data(str));
  mlx_string_free(str);
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
  mlx_string version = mlx_string_new();
  mlx_version(&version);
  printf("MLX version: %s\n", mlx_string_data(version));

  gpu_info();

  mlx_stream stream = mlx_default_gpu_stream_new();
  float data[] = {1, 2, 3, 4, 5, 6};
  int shape[] = {2, 3};
  mlx_array arr = mlx_array_new_data(data, shape, 2, MLX_FLOAT32);
  print_array("hello world!", arr);

  mlx_array two = mlx_array_new_int(2);
  mlx_divide(&arr, arr, two, stream);
  print_array("divive by 2!", arr);

  mlx_arange(&arr, 0, 3, 0.5, MLX_FLOAT32, stream);
  print_array("arange", arr);

  mlx_array_free(arr);
  mlx_array_free(two);
  mlx_stream_free(stream);
  mlx_string_free(version);
  return 0;
}
