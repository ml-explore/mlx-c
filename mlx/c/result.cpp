#include "mlx/c/result.h"

mlx_array_result mlx_array_result_new_ok(mlx_array ok_array) {
    mlx_array_result result;
    result.tag = mlx_result_tag_ok;
    result.ok_array = ok_array;
    return result;
}

mlx_array_result mlx_array_result_new_runtime_error(mlx_string error_message) {
    mlx_array_result result;
    result.tag = mlx_result_tag_runtime_error;
    result.error_message = error_message;
    return result;
}

mlx_array_result mlx_array_result_new_invalid_argument(mlx_string error_message) {
    mlx_array_result result;
    result.tag = mlx_result_tag_invalid_argument;
    result.error_message = error_message;
    return result;
}

mlx_array_result mlx_array_result_new_out_of_range(mlx_string error_message) {
    mlx_array_result result;
    result.tag = mlx_result_tag_out_of_range;
    result.error_message = error_message;
    return result;
}

mlx_result_tag mlx_array_result_get_tag(mlx_array_result result) {
    return result.tag;
}

mlx_array mlx_array_result_get_ok(mlx_array_result result) {
    return result.ok_array;
}

mlx_string mlx_array_result_get_error_message(mlx_array_result result) {
    return result.error_message;
}

mlx_vector_array_result mlx_vector_array_result_new_ok(mlx_vector_array ok_vector_array) {
    mlx_vector_array_result result;
    result.tag = mlx_result_tag_ok;
    result.ok_vector_array = ok_vector_array;
    return result;
}

mlx_vector_array_result mlx_vector_array_result_new_runtime_error(mlx_string error_message) {
    mlx_vector_array_result result;
    result.tag = mlx_result_tag_runtime_error;
    result.error_message = error_message;
    return result;
}

mlx_vector_array_result mlx_vector_array_result_new_invalid_argument(mlx_string error_message) {
    mlx_vector_array_result result;
    result.tag = mlx_result_tag_invalid_argument;
    result.error_message = error_message;
    return result;
}

mlx_vector_array_result mlx_vector_array_result_new_out_of_range(mlx_string error_message) {
    mlx_vector_array_result result;
    result.tag = mlx_result_tag_out_of_range;
    result.error_message = error_message;
    return result;
}

mlx_result_tag mlx_vector_array_result_get_tag(mlx_vector_array_result result) {
    return result.tag;
}

mlx_vector_array mlx_vector_array_result_get_ok(mlx_vector_array_result result) {
    return result.ok_vector_array;
}

mlx_string mlx_vector_array_result_get_error_message(mlx_vector_array_result result) {
    return result.error_message;
}

mlx_vector_vector_array_result mlx_vector_vector_array_result_new_ok(mlx_vector_vector_array ok_vector_vector_array) {
    mlx_vector_vector_array_result result;
    result.tag = mlx_result_tag_ok;
    result.ok_vector_vector_array = ok_vector_vector_array;
    return result;
}

mlx_vector_vector_array_result mlx_vector_vector_array_result_new_runtime_error(mlx_string error_message) {
    mlx_vector_vector_array_result result;
    result.tag = mlx_result_tag_runtime_error;
    result.error_message = error_message;
    return result;
}

mlx_vector_vector_array_result mlx_vector_vector_array_result_new_invalid_argument(mlx_string error_message) {
    mlx_vector_vector_array_result result;
    result.tag = mlx_result_tag_invalid_argument;
    result.error_message = error_message;
    return result;
}

mlx_vector_vector_array_result mlx_vector_vector_array_result_new_out_of_range(mlx_string error_message) {
    mlx_vector_vector_array_result result;
    result.tag = mlx_result_tag_out_of_range;
    result.error_message = error_message;
    return result;
}

mlx_result_tag mlx_vector_vector_array_result_get_tag(mlx_vector_vector_array_result result) {
    return result.tag;
}

mlx_vector_vector_array mlx_vector_vector_array_result_get_ok(mlx_vector_vector_array_result result) {
    return result.ok_vector_vector_array;
}

mlx_string mlx_vector_vector_array_result_get_error_message(mlx_vector_vector_array_result result) {
    return result.error_message;
}
