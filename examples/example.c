#include <stdio.h>
#include "mlx/c/mlx.h"

int main() {
  float data[] = {1, 2, 3, 4, 5, 6};
  int shape[] = {2, 3};
  mlx_array arr = mlx_array_from_data(data, shape, 2, MLX_FLOAT32);
  mlx_string str = mlx_tostring(arr);
  printf("hello world!\n%s\n", mlx_string_data(str));
  mlx_free(str);

  mlx_array two = mlx_array_from_int(2);
  mlx_array res = mlx_divide(arr, two, MLX_GPU_STREAM);
  str = mlx_tostring(res);
  printf("divive by 2!\n%s\n", mlx_string_data(str));
  mlx_free(str);

  mlx_array arange = mlx_arange(0, 3, 0.5, MLX_FLOAT32, MLX_GPU_STREAM);
  str = mlx_tostring(arange);
  printf("arange\n%s\n", mlx_string_data(str));
  mlx_free(str);

  mlx_free(arange);
  mlx_free(arr);
  mlx_free(res);
  mlx_free(two);
  return 0;
}
