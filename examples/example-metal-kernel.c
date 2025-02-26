/* Copyright © 2023-2024 Apple Inc. */

#include <stdio.h>
#include "mlx/c/mlx.h"

void print_array(const char* msg, mlx_array arr) {
  mlx_string str = mlx_string_new();
  mlx_array_tostring(&str, arr);
  printf("%s\n%s\n", msg, mlx_string_data(str));
  mlx_string_free(str);
}

void exp_elemwise(
    mlx_array* output_,
    const mlx_array input,
    mlx_stream stream) {
  const char* source =
      "uint elem = thread_position_in_grid.x;"
      "T tmp = inp[elem];"
      "out[elem] = metal::exp(tmp);";
  mlx_fast_metal_kernel kernel = mlx_fast_metal_kernel_new("myexp", source, "");
  mlx_fast_metal_kernel_set_input_names(kernel, 1, "inp");
  mlx_fast_metal_kernel_set_output_names(kernel, 1, "out");

  mlx_vector_array inputs = mlx_vector_array_new_value(input);
  mlx_fast_metal_kernel_add_template_arg_dtype(kernel, "T", MLX_FLOAT32);
  mlx_fast_metal_kernel_set_grid(kernel, mlx_array_size(input), 1, 1);
  mlx_fast_metal_kernel_set_thread_group(kernel, 256, 1, 1);
  mlx_fast_metal_kernel_add_output_arg(
      kernel,
      mlx_array_shape(input),
      mlx_array_ndim(input),
      mlx_array_dtype(input));

  mlx_vector_array outputs = mlx_vector_array_new();
  mlx_fast_metal_kernel_apply(&outputs, kernel, inputs, stream);
  mlx_vector_array_get(output_, outputs, 0);

  mlx_fast_metal_kernel_free(kernel);
  mlx_vector_array_free(inputs);
  mlx_vector_array_free(outputs);
}
int main() {
  mlx_stream stream = mlx_default_gpu_stream_new();
  mlx_array input = mlx_array_new();
  mlx_array output = mlx_array_new();

  int dims[2] = {4, 16};
  mlx_random_normal(
      &input, dims, 2, MLX_FLOAT32, 0, 1, mlx_array_empty, stream);

  exp_elemwise(&output, input, stream);

  print_array("input", input);
  print_array("output", output);

  mlx_array_free(input);
  mlx_array_free(output);
  mlx_stream_free(stream);

  return 0;
}
