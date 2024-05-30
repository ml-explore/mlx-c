#ifndef MLX_RESULT_H
#define MLX_RESULT_H

#include "mlx/c/array.h"
#include "mlx/c/string.h"

#ifdef __cplusplus
#include <stdexcept>

extern "C" {
#endif

enum mlx_result_tag {
    mlx_result_tag_ok_array,
    mlx_result_tag_ok_vector_array,
    mlx_result_tag_ok_vector_vector_array,
    mlx_result_tag_runtime_error,
    mlx_result_tag_invalid_argument,
    mlx_result_tag_out_of_range,
};

typedef struct {
    mlx_result_tag tag;
    union {
        mlx_array ok_array;
        mlx_vector_array ok_vector_array;
        mlx_vector_vector_array ok_vector_vector_array;
        mlx_string error_message;
    };
} mlx_result;

mlx_result mlx_result_new_ok_array(mlx_array ok_array);
mlx_result mlx_result_new_ok_vector_array(mlx_vector_array ok_vector_array);
mlx_result mlx_result_new_ok_vector_vector_array(mlx_vector_vector_array ok_vector_vector_array);
mlx_result mlx_result_new_runtime_error(mlx_string error_message);
mlx_result mlx_result_new_invalid_argument(mlx_string error_message);
mlx_result mlx_result_new_out_of_range(mlx_string error_message);

#ifdef __cplusplus
#define TRY(function, ...) \
    mlx_result try_ ## function(__VA_ARGS__); \

// #define TRY_ARRAY_IMPL(fn_name, ...) \
//     mlx_result try_ ## fn_name(__VA_ARGS__) { \
//         try {
//             mlx_array a = fn_name(__VA_ARGS__); \
//             return mlx_result_new_ok_array(a); \
//         } catch (std::runtime_error e) { \
//             return mlx_result_new_runtime_error(mlx_string_new(e.what())); \
//         } catch (std::invalid_argument e) { \
//             return mlx_result_new_invalid_argument(mlx_string_new(e.what())); \
//         } catch (std::out_of_range e) { \
//             return mlx_result_new_out_of_range(mlx_string_new(e.what())); \
//         } \
//     }

// #define MACROFOO(function, ...)  (function)(__VA_ARGS__)

#endif

#ifdef __cplusplus
}
#endif

#endif