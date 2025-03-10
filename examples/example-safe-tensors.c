/* Copyright © 2023-2024 Apple Inc. */

#include <stdio.h>
#include "mlx/c/mlx.h"

void print_array(const char* msg, mlx_array arr) {
  mlx_string str = mlx_string_new();
  mlx_array_tostring(&str, arr);
  printf("%s\n%s\n", msg, mlx_string_data(str));
  mlx_string_free(str);
}

int main() {
  FILE* f = fopen("arrays.safetensors", "rb");
  if (!f) {
    printf("could not load <arrays.safetensors>\n");
    return -1;
  }

  mlx_map_string_to_array data = mlx_map_string_to_array_new();
  mlx_map_string_to_string metadata = mlx_map_string_to_string_new();
  mlx_load_safetensors_file(&data, &metadata, f);

  mlx_map_string_to_array_iterator it =
      mlx_map_string_to_array_iterator_new(data);
  const char* key;
  mlx_array value = mlx_array_new();
  while (!mlx_map_string_to_array_iterator_next(&key, &value, it)) {
    print_array(key, value);
  }

  mlx_array_free(value);
  mlx_map_string_to_array_free(data);
  mlx_map_string_to_string_free(metadata);
  mlx_map_string_to_array_iterator_free(it);
  fclose(f);

  return 0;
}
