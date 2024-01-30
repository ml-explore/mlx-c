/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_STREAM_H
#define MLX_STREAM_H

#include <stdbool.h>

#include "mlx/c/device.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mlx_stream_* mlx_stream;

mlx_stream mlx_stream_new(int index, mlx_device dev);
mlx_stream mlx_stream_new_on_device(mlx_device dev);
bool mlx_stream_equal(mlx_stream lhs, mlx_stream rhs);
mlx_stream mlx_default_stream(mlx_device dev);
mlx_stream mlx_set_default_stream(mlx_stream stream);

extern mlx_stream MLX_CPU_STREAM;
extern mlx_stream MLX_GPU_STREAM;

#ifdef __cplusplus
}
#endif

#endif
