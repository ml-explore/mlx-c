#ifndef MLX_OBJECT_H
#define MLX_OBJECT_H

#include "mlx/c/string.h"

#ifdef __cplusplus
extern "C" {
#endif

mlx_string mlx_tostring(void* obj);
void mlx_retain(void* obj);
void mlx_free(void* obj);

#ifdef __cplusplus
}
#endif

#endif
