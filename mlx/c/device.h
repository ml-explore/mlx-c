/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_DEVICE_H
#define MLX_DEVICE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_device Device
 * MLX device object.
 */
/**@{*/

/**
 * A MLX device object.
 */
typedef struct mlx_device_* mlx_device;

/**
 * Device type.
 */
typedef enum mlx_device_type_ { MLX_CPU, MLX_GPU } mlx_device_type;

/**
 * Returns a new device of specified `type`, with specified `index`.
 */
mlx_device mlx_device_new(mlx_device_type type, int index);
/**
 * Returns the type of the device.
 */
mlx_device_type mlx_device_get_type(mlx_device dev);
/**
 * Returns the default MLX device.
 */
mlx_device mlx_default_device(void);
/**
 * Set the default MLX device.
 */
mlx_device mlx_set_default_device(mlx_device dev);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
