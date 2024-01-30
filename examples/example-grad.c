/* Copyright © 2023-2024 Apple Inc. */

#include <stdio.h>
#include <stdlib.h>

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

mlx_vector_array inc_fun_value(mlx_vector_array in, void* payload) {
  if (mlx_vector_array_size(in) != 1) {
    fprintf(stderr, "inc_func_value: expected 1 argument");
    exit(EXIT_FAILURE);
  }
  mlx_array value = (mlx_array)payload;
  mlx_array res = mlx_add(mlx_vector_array_get(in, 0), value, MLX_GPU_STREAM);
  mlx_vector_array vres = mlx_vector_array_from_array(res);
  mlx_free(res);
  return vres;
}

int main() {
  mlx_array x = mlx_array_from_float(1.0);
  mlx_array y = mlx_array_from_float(1.0);
  mlx_closure cls = mlx_closure_new_unary(inc_fun);
  mlx_closure cls_with_value =
      mlx_closure_new_with_payload(inc_fun_value, y, mlx_free);

  // jvp
  {
    printf("jvp:\n");
    mlx_array one = mlx_array_from_float(1.0);
    mlx_vector_array primals = mlx_vector_array_from_array(x);
    mlx_vector_array tangents = mlx_vector_array_from_array(one);
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
    mlx_vector_array inputs = mlx_vector_array_from_array(x);
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

  // value_and_grad with payload
  {
    printf("value_and_grad with payload:\n");
    int garg = 0;
    mlx_closure_value_and_grad vag =
        mlx_value_and_grad(cls_with_value, &garg, 1);
    mlx_vector_array inputs = mlx_vector_array_from_array(x);
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

  mlx_free(cls_with_value);
  mlx_free(cls);
  mlx_free(x);

  return 0;
}
