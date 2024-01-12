#include <stdio.h>
#include "mlx/c/mlx.h"

mlx_array inc_fun(mlx_array in) {
  mlx_array y = mlx_array_from_float(1.0);
  mlx_array res = mlx_add(in, y, MLX_GPU_STREAM);
  mlx_free(y);
  return res;
}

int main() {
  mlx_array x = mlx_array_from_float(1.0);
  mlx_array one = mlx_array_from_float(1.0);
  mlx_closure cls = mlx_closure_new_unary(inc_fun);
  mlx_vector_vector_array res = mlx_jvp(cls, &x, 1, &one, 1);

  char* str;
  str = mlx_tostring(res.vectors[0].arrays[0]);
  printf("out\n%s\n", str);
  free(str);

  str = mlx_tostring(res.vectors[1].arrays[0]);
  printf("dout\n%s\n", str);
  free(str);

  mlx_vector_vector_array_free(res);
  mlx_free(one);
  mlx_free(x);
  mlx_free(cls);
  return 0;
}
