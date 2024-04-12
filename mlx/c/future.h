/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_FUTURE_H
#define MLX_FUTURE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_future Futures
 * MLX future objects.
 */
/**@{*/

/**
 * A MLX future object (pointing to a void).
 */
typedef struct mlx_future_* mlx_future;

void mlx_future_wait(mlx_future future);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
