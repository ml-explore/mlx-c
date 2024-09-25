/* Copyright © 2023-2024 Apple Inc. */

#include <stdio.h>
#include "mlx/c/mlx.h"

void print_array(const char* msg, mlx_array arr) {
  mlx_string str;
  str = mlx_tostring(arr);
  printf("%s\n%s\n", msg, mlx_string_data(str));
  mlx_free(str);
}

void exp_elemwise(const mlx_array input, mlx_stream stream, mlx_array output) {
  const char* source =
      "uint elem = thread_position_in_grid.x;"
      "T tmp = inp[elem];"
      "out[elem] = metal::exp(tmp);";
  mlx_vector_string input_names = mlx_vector_string_new_value("inp");
  mlx_vector_string output_names = mlx_vector_string_new_value("out");
  mlx_closure_metal_kernel kernel = mlx_closure_metal_kernel_new();
  mlx_fast_metal_kernel(
      "myexp", input_names, output_names, source, "", true, false, kernel);

  mlx_vector_array inputs = mlx_vector_array_new_value(input);
  mlx_closure_metal_kernel_add_template_arg_dtype(kernel, "T", MLX_FLOAT32);
  mlx_closure_metal_kernel_set_grid(kernel, mlx_array_size(input), 1, 1);
  mlx_closure_metal_kernel_set_thread_group(kernel, 256, 1, 1);
  mlx_closure_metal_kernel_add_output_arg(
      kernel,
      mlx_array_shape(input),
      mlx_array_ndim(input),
      mlx_array_dtype(input));

  mlx_vector_array outputs = mlx_vector_array_new();
  mlx_closure_metal_kernel_apply(kernel, inputs, stream, outputs);
  mlx_vector_array_get(outputs, 0, output);

  mlx_free(input_names);
  mlx_free(output_names);
  mlx_free(kernel);
  mlx_free(inputs);
  mlx_free(outputs);
}
int main() {
  mlx_stream stream = mlx_gpu_stream();
  mlx_array input = mlx_array_new();
  mlx_array output = mlx_array_new();

  int dims[2] = {4, 16};
  mlx_random_normal(dims, 2, MLX_FLOAT32, 0, 1, NULL, stream, input);

  exp_elemwise(input, stream, output);

  print_array("input", input);
  print_array("output", output);

  mlx_free(input);
  mlx_free(output);
  mlx_free(stream);

  return 0;
}
