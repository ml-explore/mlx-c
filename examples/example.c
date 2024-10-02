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
  mlx_map_string_to_variant_string_size_t info = mlx_metal_device_info();
  mlx_map_string_to_variant_string_size_t_iterator it =
      mlx_map_string_to_variant_string_size_t_iterate(info);
  while (mlx_map_string_to_variant_string_size_t_iterator_next(it)) {
    mlx_string key = mlx_map_string_to_variant_string_size_t_iterator_key(it);
    mlx_variant_string_size_t val =
        mlx_map_string_to_variant_string_size_t_iterator_value(it);
    size_t val_size_t = mlx_variant_string_size_t_get_size_t(val);
    printf("  %s: %ld\n", mlx_string_data(key), val_size_t);
    mlx_free(key);
    mlx_free(val);
  }
  mlx_free(it);
  mlx_free(info);
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
  mlx_array res = mlx_divide(arr, two, stream);
  print_array("divive by 2!", res);

  mlx_array arange = mlx_arange(0, 3, 0.5, MLX_FLOAT32, stream);
  print_array("arange", arange);

  mlx_free(arange);
  mlx_free(arr);
  mlx_free(res);
  mlx_free(two);
  mlx_free(stream);
  return 0;
}
