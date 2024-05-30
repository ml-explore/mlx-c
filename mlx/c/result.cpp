#include "mlx/c/result.h"

mlx_result mlx_result_new_ok_array(mlx_array ok_array) {
    mlx_result result;
    result.tag = mlx_result_tag_ok_array;
    result.ok_array = ok_array;
    return result;
}

mlx_result mlx_result_new_ok_vector_array(mlx_vector_array ok_vector_array) {
    mlx_result result;
    result.tag = mlx_result_tag_ok_vector_array;
    result.ok_vector_array = ok_vector_array;
    return result;
}

mlx_result mlx_result_new_ok_vector_vector_array(mlx_vector_vector_array ok_vector_vector_array) {
    mlx_result result;
    result.tag = mlx_result_tag_ok_vector_vector_array;
    result.ok_vector_vector_array = ok_vector_vector_array;
    return result;
}

mlx_result mlx_result_new_runtime_error(mlx_string error_message) {
    mlx_result result;
    result.tag = mlx_result_tag_runtime_error;
    result.error_message = error_message;
    return result;
}

mlx_result mlx_result_new_invalid_argument(mlx_string error_message) {
    mlx_result result;
    result.tag = mlx_result_tag_invalid_argument;
    result.error_message = error_message;
    return result;
}

mlx_result mlx_result_new_out_of_range(mlx_string error_message) {
    mlx_result result;
    result.tag = mlx_result_tag_out_of_range;
    result.error_message = error_message;
    return result;
}