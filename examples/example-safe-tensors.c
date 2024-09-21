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
  FILE* f = fopen("arrays.safetensors", "rb");
  if (!f) {
    printf("could not load <arrays.safetensors>\n");
    return -1;
  }

  mlx_stream stream = mlx_gpu_stream();
  mlx_map_string_to_array data = mlx_map_string_to_array_new();
  mlx_map_string_to_string metadata = mlx_map_string_to_string_new();
  mlx_load_safetensors_file(f, stream, data, metadata);

  mlx_map_string_to_array_iterator it = mlx_map_string_to_array_iterate(data);
  while (!mlx_map_string_to_array_iterator_end(it)) {
    mlx_string key = mlx_map_string_to_array_iterator_key(it);
    mlx_array value = mlx_map_string_to_array_iterator_value(it);

    print_array(mlx_string_data(key), value);

    mlx_free(key);
    mlx_free(value);

    mlx_map_string_to_array_iterator_next(it);
  }

  mlx_free(data);
  mlx_free(metadata);
  mlx_free(stream);
  fclose(f);

  return 0;
}
