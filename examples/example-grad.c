/* Copyright © 2023-2024 Apple Inc. */

#include <stdio.h>
#include <stdlib.h>

#include "mlx/c/mlx.h"

void print_array(const char* msg, mlx_array arr) {
  mlx_string str = mlx_array_tostring(arr);
  printf("%s\n%s\n", msg, mlx_string_data(str));
  mlx_string_free(str);
}

void inc_fun(mlx_array in, mlx_array* res_) {
  mlx_stream stream = mlx_gpu_stream();
  mlx_array value = mlx_array_new_float(1.0);
  mlx_add(in, value, stream, res_);
  mlx_stream_free(stream);
  mlx_array_free(value);
}

void inc_fun_value(mlx_vector_array in, void* payload, mlx_vector_array* vres) {
  mlx_stream stream = mlx_gpu_stream();
  if (mlx_vector_array_size(in) != 1) {
    fprintf(stderr, "inc_func_value: expected 1 argument");
    exit(EXIT_FAILURE);
  }
  mlx_array res = mlx_array_new();
  mlx_vector_array_get(in, 0, &res);
  mlx_add(res, *((mlx_array*)payload), stream, &res);
  mlx_vector_array_set_value(*vres, res);
  mlx_array_free(res);
  mlx_stream_free(stream);
}

void closure_dtor(void* ptr_) {
  mlx_array* arr = ptr_;
  mlx_array_free(*arr);
}

int main() {
  mlx_array x = mlx_array_new_float(1.0);
  mlx_array y = mlx_array_new_float(1.0);
  mlx_closure cls = mlx_closure_new_unary(inc_fun);
  mlx_closure cls_with_value =
      mlx_closure_new_func_payload(inc_fun_value, &y, closure_dtor);

  // jvp
  {
    printf("jvp:\n");
    mlx_array one = mlx_array_new_float(1.0);
    mlx_vector_array primals = mlx_vector_array_new_value(x);
    mlx_vector_array tangents = mlx_vector_array_new_value(one);
    mlx_vector_array vout = mlx_vector_array_new();
    mlx_vector_array vdout = mlx_vector_array_new();
    mlx_jvp(cls, primals, tangents, &vout, &vdout);
    mlx_array out = mlx_array_new();
    mlx_array dout = mlx_array_new();
    mlx_vector_array_get(vout, 0, &out);
    mlx_vector_array_get(vdout, 0, &dout);

    print_array("out", out);
    print_array("dout", dout);

    mlx_array_free(dout);
    mlx_array_free(out);
    mlx_vector_array_free(vdout);
    mlx_vector_array_free(vout);
    mlx_vector_array_free(tangents);
    mlx_vector_array_free(primals);
    mlx_array_free(one);
  }

  // value_and_grad
  {
    printf("value_and_grad:\n");
    int garg = 0;
    mlx_closure_value_and_grad vag = mlx_closure_value_and_grad_new();
    mlx_value_and_grad(cls, &garg, 1, &vag);
    mlx_vector_array inputs = mlx_vector_array_new_value(x);
    mlx_vector_array vout = mlx_vector_array_new();
    mlx_vector_array vdout = mlx_vector_array_new();
    mlx_closure_value_and_grad_apply(vag, inputs, &vout, &vdout);
    mlx_array out = mlx_array_new();
    mlx_array dout = mlx_array_new();
    mlx_vector_array_get(vout, 0, &out);
    mlx_vector_array_get(vdout, 0, &dout);

    print_array("out", out);
    print_array("dout", dout);

    mlx_array_free(dout);
    mlx_array_free(out);
    mlx_vector_array_free(inputs);
    mlx_vector_array_free(vdout);
    mlx_vector_array_free(vout);
    mlx_closure_value_and_grad_free(vag);
  }

  // value_and_grad with payload
  {
    printf("value_and_grad with payload:\n");
    int garg = 0;
    mlx_closure_value_and_grad vag = mlx_closure_value_and_grad_new();
    mlx_value_and_grad(cls_with_value, &garg, 1, &vag);
    mlx_vector_array inputs = mlx_vector_array_new_value(x);
    mlx_vector_array vout = mlx_vector_array_new();
    mlx_vector_array vdout = mlx_vector_array_new();
    mlx_closure_value_and_grad_apply(vag, inputs, &vout, &vdout);
    mlx_array out = mlx_array_new();
    mlx_array dout = mlx_array_new();
    mlx_vector_array_get(vout, 0, &out);
    mlx_vector_array_get(vdout, 0, &dout);

    print_array("out", out);
    print_array("dout", dout);

    mlx_array_free(dout);
    mlx_array_free(out);
    mlx_vector_array_free(inputs);
    mlx_vector_array_free(vdout);
    mlx_vector_array_free(vout);
    mlx_closure_value_and_grad_free(vag);
  }

  mlx_closure_free(cls_with_value);
  mlx_closure_free(cls);
  mlx_array_free(x);

  return 0;
}
