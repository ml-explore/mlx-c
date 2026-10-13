/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_DISTRIBUTED_GROUP_H
#define MLX_DISTRIBUTED_GROUP_H

#include <stdbool.h>
#include <stddef.h>

#include "mlx/c/stream.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_distributed_group MLX distributed
 */
/**@{*/

/**
 * A MLX distributed group object.
 */
typedef struct mlx_distributed_group_ {
  void* ctx;
} mlx_distributed_group;

/**
 * Create an empty group.
 */
mlx_distributed_group mlx_distributed_group_new(void);

/**
 * Free the group.
 */
int mlx_distributed_group_free(mlx_distributed_group group);

/**
 * Initialize distributed.
 */
int mlx_distributed_init(
    mlx_distributed_group* res,
    bool strict,
    const char* bk /* may be null */);

/**
 * Get the rank.
 */
int mlx_distributed_group_rank(mlx_distributed_group group);

/**
 * Get the group size.
 */
int mlx_distributed_group_size(mlx_distributed_group group);

/**
 * Split the group.
 */
int mlx_distributed_group_split(
    mlx_distributed_group* res,
    mlx_distributed_group group,
    int color,
    int key);

/**
 * Check if distributed is available.
 */
bool mlx_distributed_is_available(const char* bk /* may be null */);

/**
 * Clears cached backends. Existing groups remain valid and may retain callbacks
 * and payloads.
 */
int mlx_distributed_clear_backends(void);

/**
 * Writes the rank to `res`. Requires a valid group and non-null output pointer.
 * Returns zero on success, nonzero on error. `res` is unchanged on failure.
 */
int mlx_distributed_group_get_rank(int* res, mlx_distributed_group group);

/**
 * Writes the group size to `res`. Requires a valid group and non-null output
 * pointer. Returns zero on success, nonzero on error. `res` is unchanged on
 * failure.
 */
int mlx_distributed_group_get_size(int* res, mlx_distributed_group group);

/**
 * Initialize JACCL with a custom metadata all-gather callback.
 *
 * `bk` must be `jaccl`. The synchronous callback reads `n_bytes` from `src`
 * and fills `size * n_bytes` in `dst`, ordered by `rank`. Buffers are borrowed.
 * The callback returns zero on success, nonzero on failure.
 *
 * If a `jaccl` group is already cached, it is returned and `all_gather` is
 * never called: the callback is dropped and, with `dtor`, `payload` is
 * destroyed before this function returns. Call
 * `mlx_distributed_clear_backends()` first to initialize with a new callback.
 *
 * With `dtor`, ownership of `payload` transfers on entry, including failure.
 * Destruction occurs once after all references are released. Cached or
 * live groups may delay it. Without `dtor`, `payload` is borrowed and must
 * remain valid while the callback is retained.
 *
 * Returns zero on success, nonzero on error. `res` is unchanged on failure.
 */
int mlx_distributed_init_with_all_gather(
    mlx_distributed_group* res,
    bool strict,
    const char* bk,
    int (*all_gather)(
        int rank,
        int size,
        const char* src,
        char* dst,
        size_t n_bytes,
        void* payload),
    void* payload,
    void (*dtor)(void*));

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
