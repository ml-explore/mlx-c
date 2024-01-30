/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_DEVICE_H
#define MLX_DEVICE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mlx_device_* mlx_device;

typedef enum mlx_device_type_ { MLX_CPU, MLX_GPU } mlx_device_type;

mlx_device mlx_device_new(mlx_device_type type, int index);
mlx_device_type mlx_device_get_type(mlx_device dev);
mlx_device mlx_default_device(void);
mlx_device mlx_set_default_device(mlx_device dev);

#ifdef __cplusplus
}
#endif

#endif
