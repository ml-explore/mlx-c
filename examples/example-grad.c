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

void inc_fun(mlx_array in, mlx_array res) {
  mlx_stream stream = mlx_gpu_stream();
  mlx_array value = mlx_array_new_float(1.0);
  mlx_add(in, value, stream, res);
  mlx_free(stream);
  mlx_free(value);
}

void inc_fun_value(mlx_vector_array in, void* payload, mlx_vector_array vres) {
  mlx_stream stream = mlx_gpu_stream();
  if (mlx_vector_array_size(in) != 1) {
    fprintf(stderr, "inc_func_value: expected 1 argument");
    exit(EXIT_FAILURE);
  }
  mlx_array value = (mlx_array)payload;
  mlx_array res = mlx_array_new();
  mlx_vector_array_get(in, 0, res);
  mlx_add(res, value, stream, res); // DEBUG
  mlx_vector_array_set_value(vres, res);
  mlx_free(res);
  mlx_free(stream);
}

int main() {
  mlx_array x = mlx_array_new_float(1.0);
  mlx_array y = mlx_array_new_float(1.0);
  mlx_closure cls = mlx_closure_new_unary(inc_fun);
  mlx_closure cls_with_value =
      mlx_closure_new_func_payload(inc_fun_value, y, mlx_free);

  // jvp
  {
    printf("jvp:\n");
    mlx_array one = mlx_array_new_float(1.0);
    mlx_vector_array primals = mlx_vector_array_new_value(x);
    mlx_vector_array tangents = mlx_vector_array_new_value(one);
    mlx_vector_array vout = mlx_vector_array_new();
    mlx_vector_array vdout = mlx_vector_array_new();
    mlx_jvp(cls, primals, tangents, vout, vdout);
    mlx_array out = mlx_array_new();
    mlx_array dout = mlx_array_new();
    mlx_vector_array_get(vout, 0, out);
    mlx_vector_array_get(vdout, 0, dout);

    print_array("out", out);
    print_array("dout", dout);

    mlx_free(dout);
    mlx_free(out);
    mlx_free(vdout);
    mlx_free(vout);
    mlx_free(tangents);
    mlx_free(primals);
    mlx_free(one);
  }

  // value_and_grad
  {
    printf("value_and_grad:\n");
    int garg = 0;
    mlx_closure_value_and_grad vag = mlx_closure_value_and_grad_new();
    mlx_value_and_grad(cls, &garg, 1, vag);
    mlx_vector_array inputs = mlx_vector_array_new_value(x);
    mlx_vector_array vout = mlx_vector_array_new();
    mlx_vector_array vdout = mlx_vector_array_new();
    mlx_closure_value_and_grad_apply(vag, inputs, vout, vdout);
    mlx_array out = mlx_array_new();
    mlx_array dout = mlx_array_new();
    mlx_vector_array_get(vout, 0, out);
    mlx_vector_array_get(vdout, 0, dout);

    print_array("out", out);
    print_array("dout", dout);

    mlx_free(dout);
    mlx_free(out);
    mlx_free(inputs);
    mlx_free(vdout);
    mlx_free(vout);
    mlx_free(vag);
  }

  // value_and_grad with payload
  {
    printf("value_and_grad with payload:\n");
    int garg = 0;
    mlx_closure_value_and_grad vag = mlx_closure_value_and_grad_new();
    mlx_value_and_grad(cls_with_value, &garg, 1, vag);
    mlx_vector_array inputs = mlx_vector_array_new_value(x);
    mlx_vector_array vout = mlx_vector_array_new();
    mlx_vector_array vdout = mlx_vector_array_new();
    mlx_closure_value_and_grad_apply(vag, inputs, vout, vdout);
    mlx_array out = mlx_array_new();
    mlx_array dout = mlx_array_new();
    mlx_vector_array_get(vout, 0, out);
    mlx_vector_array_get(vdout, 0, dout);

    print_array("out", out);
    print_array("dout", dout);

    mlx_free(dout);
    mlx_free(out);
    mlx_free(inputs);
    mlx_free(vdout);
    mlx_free(vout);
    mlx_free(vag);
  }

  mlx_free(cls_with_value);
  mlx_free(cls);
  mlx_free(x);

  return 0;
}
