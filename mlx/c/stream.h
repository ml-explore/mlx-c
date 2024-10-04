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
typedef struct mlx_stream_ {
  void* ctx;
} mlx_stream;

/**
 * Returns a new stream, with specified `index`, on a device.
 */
mlx_stream mlx_stream_new(int index, mlx_device dev);
/**
 * Returns a new stream on a device.
 */
mlx_stream mlx_stream_new_on_device(mlx_device dev);
/**
 * Free a stream.
 */
void mlx_stream_free(mlx_stream stream);
/**
 * Get stream description.
 */
mlx_string mlx_stream_tostring(mlx_device stream);
/**
 * Check if streams are the same.
 */
bool mlx_stream_equal(mlx_stream lhs, mlx_stream rhs);
/**
 * Return the device of the stream.
 */
mlx_device mlx_stream_get_device(mlx_stream stream);
/**
 * Synchronize with the provided stream.
 */
void mlx_synchronize(mlx_stream stream);
/**
 * Returns the default stream on the given device.
 */
mlx_stream mlx_default_stream(mlx_device dev);
/**
 * Set default stream.
 */
void mlx_set_default_stream(mlx_stream stream);
/**
 * Returns the current default CPU stream.
 */
mlx_stream mlx_cpu_stream();

/**
 * Returns the current default GPU stream.
 */
mlx_stream mlx_gpu_stream();

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
