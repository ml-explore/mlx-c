#include <stdio.h>
#include "mlx/c/mlx.h"

int main() {
  FILE* f = fopen("arrays.safetensors", "rb");
  if (!f) {
    printf("could not load <arrays.safetensors>\n");
    return -1;
  }

  mlx_map_string_to_array map = mlx_load_safetensors_file(f, MLX_CPU_STREAM);

  mlx_map_string_to_array_iterator it = mlx_map_string_to_array_iterate(map);
  while (!mlx_map_string_to_array_iterator_end(it)) {
    mlx_string key = mlx_map_string_to_array_iterator_key(it);
    mlx_array value = mlx_map_string_to_array_iterator_value(it);

    mlx_string str = mlx_tostring(value);
    printf("key:\n%s\n", mlx_string_data(key));
    printf("value:\n%s\n", mlx_string_data(str));
    mlx_free(str);

    mlx_free(key);
    mlx_free(value);

    mlx_map_string_to_array_iterator_next(it);
  }

  mlx_free(map);
  fclose(f);

  return 0;
}
