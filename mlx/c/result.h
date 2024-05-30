#ifndef MLX_RESULT_H
#define MLX_RESULT_H

#include "mlx/c/array.h"
#include "mlx/c/string.h"

#ifdef __cplusplus
#include <stdexcept>

extern "C" {
#endif

enum mlx_result_tag {
    mlx_result_tag_ok,
    mlx_result_tag_runtime_error,
    mlx_result_tag_invalid_argument,
    mlx_result_tag_out_of_range,
};

typedef struct {
    mlx_result_tag tag;
    union {
        mlx_array ok_array;
        mlx_string error_message;
    };
} mlx_array_result;

mlx_array_result mlx_array_result_new_ok(mlx_array ok_array);
mlx_array_result mlx_array_result_new_runtime_error(mlx_string error_message);
mlx_array_result mlx_array_result_new_invalid_argument(mlx_string error_message);
mlx_array_result mlx_array_result_new_out_of_range(mlx_string error_message);

mlx_result_tag mlx_array_result_get_tag(mlx_array_result result);
mlx_array mlx_array_result_get_ok(mlx_array_result result);
mlx_string mlx_array_result_get_error_message(mlx_array_result result);

typedef struct {
    mlx_result_tag tag;
    union {
        mlx_vector_array ok_vector_array;
        mlx_string error_message;
    };
} mlx_vector_array_result;

mlx_vector_array_result mlx_vector_array_result_new_ok(mlx_vector_array ok_vector_array);
mlx_vector_array_result mlx_vector_array_result_new_runtime_error(mlx_string error_message);
mlx_vector_array_result mlx_vector_array_result_new_invalid_argument(mlx_string error_message);
mlx_vector_array_result mlx_vector_array_result_new_out_of_range(mlx_string error_message);

mlx_result_tag mlx_vector_array_result_get_tag(mlx_vector_array_result result);
mlx_vector_array mlx_vector_array_result_get_ok(mlx_vector_array_result result);
mlx_string mlx_vector_array_result_get_error_message(mlx_vector_array_result result);

typedef struct {
    mlx_result_tag tag;
    union {
        mlx_vector_vector_array ok_vector_vector_array;
        mlx_string error_message;
    };
} mlx_vector_vector_array_result;

mlx_vector_vector_array_result mlx_vector_vector_array_result_new_ok(mlx_vector_vector_array ok_vector_vector_array);
mlx_vector_vector_array_result mlx_vector_vector_array_result_new_runtime_error(mlx_string error_message);
mlx_vector_vector_array_result mlx_vector_vector_array_result_new_invalid_argument(mlx_string error_message);
mlx_vector_vector_array_result mlx_vector_vector_array_result_new_out_of_range(mlx_string error_message);

mlx_result_tag mlx_vector_vector_array_result_get_tag(mlx_vector_vector_array_result result);
mlx_vector_vector_array mlx_vector_vector_array_result_get_ok(mlx_vector_vector_array_result result);
mlx_string mlx_vector_vector_array_result_get_error_message(mlx_vector_vector_array_result result);

#ifdef __cplusplus
}
#endif

#endif