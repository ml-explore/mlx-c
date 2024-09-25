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
	const char* key;
	mlx_array value = mlx_array_new();
  while (mlx_map_string_to_array_iterator_next(it, &key, value)) {
    print_array(key, value);
  }

	mlx_free(value);
  mlx_free(data);
  mlx_free(metadata);
  mlx_free(stream);
  fclose(f);

  return 0;
}
