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
  mlx_string name = mlx_string_new("myexp");
  mlx_string source = mlx_string_new(
      "uint elem = thread_position_in_grid.x;"
      "T tmp = inp[elem];"
      "out[elem] = metal::exp(tmp);");
  mlx_string header = mlx_string_new("");
  mlx_string input_name0 = mlx_string_new("inp");
  mlx_string output_name0 = mlx_string_new("out");
  mlx_vector_string input_names = mlx_vector_string_from_value(input_name0);
  mlx_vector_string output_names = mlx_vector_string_from_value(output_name0);
  mlx_closure_metal_kernel kernel = mlx_closure_metal_kernel_new();
  mlx_fast_metal_kernel(
      name, input_names, output_names, source, header, true, false, kernel);

  mlx_vector_array inputs = mlx_vector_array_from_value(input);
  mlx_closure_metal_kernel_desc desc = mlx_closure_metal_kernel_desc_new();
  mlx_closure_metal_kernel_desc_add_template_arg_dtype(desc, "T", MLX_FLOAT32);
  mlx_closure_metal_kernel_desc_set_grid(desc, mlx_array_size(input), 1, 1);
  mlx_closure_metal_kernel_desc_set_thread_group(desc, 256, 1, 1);
  mlx_closure_metal_kernel_desc_add_output_arg(
      desc,
      mlx_array_shape(input),
      mlx_array_ndim(input),
      mlx_array_get_dtype(input));

  mlx_vector_array outputs = mlx_vector_array_new();
  mlx_closure_metal_kernel_apply(kernel, inputs, desc, stream, outputs);
  mlx_vector_array_get(outputs, 0, output);

  mlx_free(name);
  mlx_free(source);
  mlx_free(header);
  mlx_free(input_name0);
  mlx_free(output_name0);
  mlx_free(input_names);
  mlx_free(output_names);
  mlx_free(kernel);
  mlx_free(inputs);
  mlx_free(desc);
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
