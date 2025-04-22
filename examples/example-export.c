/* Copyright © 2023-2024 Apple Inc. */

#include <math.h>
#include <stdio.h>
#include "mlx/c/mlx.h"

void print_array(const char* msg, mlx_array arr) {
  mlx_string str = mlx_string_new();
  mlx_array_tostring(&str, arr);
  printf("%s\n%s\n", msg, mlx_string_data(str));
  mlx_string_free(str);
}

int inc_fun(mlx_array* res_, mlx_array in) {
  mlx_stream stream = mlx_default_gpu_stream_new();
  mlx_array value = mlx_array_new_float(1.0);
  mlx_add(res_, in, value, stream);
  mlx_stream_free(stream);
  mlx_array_free(value);
  return 0;
}

int main() {
  mlx_array x = mlx_array_new_float(1.0);
  print_array("x: ", x);

  printf("storing inc() function in inc_func.bin file\n");
  mlx_vector_array args = mlx_vector_array_new_value(x);
  mlx_closure cls = mlx_closure_new_unary(inc_fun);
  mlx_export_function("inc_func.bin", cls, args, false);
  mlx_closure_free(cls);

  printf("loading inc() function from inc_func.bin file\n");
  mlx_imported_function xfunc = mlx_imported_function_new();
  mlx_import_function(&xfunc, "inc_func.bin");

  printf("evaluating inc() over x\n");
  mlx_vector_array res = mlx_vector_array_new();
  mlx_imported_function_apply(&res, xfunc, args);

  mlx_array y = mlx_array_new();
  mlx_vector_array_get(&y, res, 0);
  print_array("+1: ", y);

  mlx_array_free(y);
  mlx_vector_array_free(res);
  mlx_vector_array_free(args);
  mlx_array_free(x);
  mlx_imported_function_free(xfunc);

  return 0;
}
