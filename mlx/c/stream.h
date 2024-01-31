/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_STREAM_H
#define MLX_STREAM_H

#include <stdbool.h>

#include "mlx/c/device.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_stream Stream
 * MLX stream object.
 */
/**@{*/

/**
 * A MLX stream object.
 */
typedef struct mlx_stream_* mlx_stream;

/**
 * Returns a new stream, with specified `index`, on a device.
 */
mlx_stream mlx_stream_new(int index, mlx_device dev);
/**
 * Returns a new stream on a device.
 */
mlx_stream mlx_stream_new_on_device(mlx_device dev);
/**
 * Check if streams are the same.
 */
bool mlx_stream_equal(mlx_stream lhs, mlx_stream rhs);
/**
 * Returns the default stream on the given device.
 */
mlx_stream mlx_default_stream(mlx_device dev);
/**
 * Set default stream.
 */
mlx_stream mlx_set_default_stream(mlx_stream stream);

/**
 * Current default CPU stream.
 */
extern mlx_stream MLX_CPU_STREAM;
/**
 * Current default GPU stream.
 */
extern mlx_stream MLX_GPU_STREAM;

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
