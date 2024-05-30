/* Copyright © 2023-2024 Apple Inc. */

#include <stdio.h>
#include "mlx/c/mlx.h"
#include "mlx/c/ops_try.h"
#include "mlx/c/result.h"

void print_array(const char* msg, mlx_array arr) {
  mlx_string str;
  str = mlx_tostring(arr);
  printf("%s\n%s\n", msg, mlx_string_data(str));
  mlx_free(str);
}

int main() {
  mlx_stream stream = mlx_gpu_stream();
  float data[] = {1, 2, 3, 4, 5, 6};
  int shape[] = {2, 3};
  mlx_array arr = mlx_array_from_data(data, shape, 2, MLX_FLOAT32);
  print_array("hello world!", arr);

  // The following arange is expected to succeed.
  printf("arange(0, 3, 0.5)\n");
  mlx_array_result arange_result =
      mlx_arange_try(0, 3, 0.5, MLX_FLOAT32, stream);
  mlx_result_tag tag = mlx_array_result_get_tag(&arange_result);
  if (tag == mlx_result_tag_ok) {
    mlx_array arange = mlx_array_result_get_ok(arange_result);
    print_array("arange is ok", arange);
    mlx_free(arange);
  } else {
    mlx_string error_message =
        mlx_array_result_get_error_message(arange_result);
    printf("Error: %s\n", mlx_string_data(error_message));
    mlx_free(error_message);
  }

  // The arange below is expected to fail because the step is 0.
  printf("arange(0, 3, 0)\n");
  mlx_array_result arange_result2 =
      mlx_arange_try(0, 3, 0, MLX_FLOAT32, stream);
  mlx_result_tag tag2 = mlx_array_result_get_tag(&arange_result2);
  if (tag2 == mlx_result_tag_ok) {
    mlx_array arange2 = mlx_array_result_get_ok(arange_result2);
    print_array("arange2 is ok", arange2);
    mlx_free(arange2);
  } else {
    mlx_string error_message2 =
        mlx_array_result_get_error_message(arange_result2);
    printf("Error: %s\n", mlx_string_data(error_message2));
    mlx_free(error_message2);
  }

  mlx_array two = mlx_array_from_int(2);
  mlx_array res = mlx_divide(arr, two, stream);
  print_array("divive by 2!", res);

  mlx_free(arr);
  mlx_free(res);
  mlx_free(two);
  mlx_free(stream);
  return 0;
}
