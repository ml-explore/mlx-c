#include <stdio.h>
#include "mlx/c/mlx.h"

void print_array(const char* msg, mlx_array arr) {
  mlx_string str;
  str = mlx_tostring(arr);
  printf("%s\n%s\n", msg, mlx_string_data(str));
  mlx_free(str);
}

mlx_array inc_fun(mlx_array in) {
  mlx_array y = mlx_array_from_float(1.0);
  mlx_array res = mlx_add(in, y, MLX_GPU_STREAM);
  mlx_free(y);
  return res;
}

int main() {
  mlx_array x = mlx_array_from_float(1.0);
  mlx_closure cls = mlx_closure_new_unary(inc_fun);

  // jvp
  {
    printf("jvp:\n");
    mlx_array one = mlx_array_from_float(1.0);
    mlx_vector_array primals = mlx_vector_array_new_unary(x);
    mlx_vector_array tangents = mlx_vector_array_new_unary(one);
    mlx_vector_vector_array res = mlx_jvp(cls, primals, tangents);
    mlx_array out = mlx_vector_vector_array_get2d(res, 0, 0);
    mlx_array dout = mlx_vector_vector_array_get2d(res, 1, 0);

    print_array("out", out);
    print_array("dout", dout);

    mlx_free(dout);
    mlx_free(out);
    mlx_free(res);
    mlx_free(tangents);
    mlx_free(primals);
    mlx_free(one);
  }

  // value_and_grad
  {
    printf("value_and_grad:\n");
    int garg = 0;
    mlx_closure_value_and_grad vag = mlx_value_and_grad(cls, &garg, 1);
    mlx_vector_array inputs = mlx_vector_array_new_unary(x);
    mlx_vector_vector_array res = mlx_closure_value_and_grad_apply(vag, inputs);
    mlx_array out = mlx_vector_vector_array_get2d(res, 0, 0);
    mlx_array dout = mlx_vector_vector_array_get2d(res, 1, 0);

    print_array("out", out);
    print_array("dout", dout);

    mlx_free(dout);
    mlx_free(out);
    mlx_free(inputs);
    mlx_free(res);
    mlx_free(vag);
  }
  mlx_free(cls);
  mlx_free(x);

  return 0;
}
