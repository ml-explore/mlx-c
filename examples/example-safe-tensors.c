/* Copyright © 2023-2024 Apple Inc. */

#include <stdio.h>
#include <unistd.h>
#include "mlx/c/mlx.h"

void print_array(const char* msg, mlx_array arr) {
  mlx_string str;
  str = mlx_tostring(arr);
  printf("%s\n%s\n", msg, mlx_string_data(str));
  mlx_free(str);
}

int main() {
  char cwd[1024];
  if (getcwd(cwd, sizeof(cwd)) != 0) {
    printf("Current working directory: %s\n", cwd);
  } else {
    perror("getcwd() error");
  }
  FILE* f = fopen("arrays.safetensors", "rb");
  if (!f) {
    printf("could not load <arrays.safetensors>\n");
    return -1;
  }

  mlx_stream stream = mlx_gpu_stream();
  mlx_safetensors st = mlx_load_safetensors_file(f, stream);
  mlx_map_string_to_array map = mlx_safetensors_data(st);

  mlx_map_string_to_array_iterator it = mlx_map_string_to_array_iterate(map);
  while (!mlx_map_string_to_array_iterator_end(it)) {
    mlx_string key = mlx_map_string_to_array_iterator_key(it);
    mlx_array value = mlx_map_string_to_array_iterator_value(it);

    print_array(mlx_string_data(key), value);

    mlx_free(key);
    mlx_free(value);

    mlx_map_string_to_array_iterator_next(it);
  }

  mlx_free(map);
  mlx_free(st);
  mlx_free(stream);
  fclose(f);

  return 0;
}
