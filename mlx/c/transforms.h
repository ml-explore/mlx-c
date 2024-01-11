#ifndef MLX_TRANSFORMS_H
#define MLX_TRANSFORMS_H

#include <stdio.h>

#include "mlx/c/array.h"
#include "mlx/c/stream.h"

#ifdef __cplusplus
extern "C" {
#endif

void mlx_eval(const mlx_array* outputs, size_t num_outputs);
void mlx_simplify(const mlx_array* outputs, size_t num_outputs);

#ifdef __cplusplus
}
#endif

#endif
