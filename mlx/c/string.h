#ifndef MLX_STRING_H
#define MLX_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mlx_string_* mlx_string;

// performs a copy
mlx_string mlx_string_new(const char* str);
const char* mlx_string_data(mlx_string str);

#ifdef __cplusplus
}
#endif

#endif
