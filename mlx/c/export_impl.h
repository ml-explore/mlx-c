#ifndef MLX_EXPORT_IMPL_H
#define MLX_EXPORT_IMPL_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "mlx/c/array.h"
#include "mlx/c/closure.h"
#include "mlx/c/distributed_group.h"
#include "mlx/c/io_types.h"
#include "mlx/c/map.h"
#include "mlx/c/stream.h"
#include "mlx/c/string.h"
#include "mlx/c/vector.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup export Function serialization interfaces.
 */
/**@{*/
typedef struct mlx_function_exporter_ {
  void* ctx;
} mlx_function_exporter;

mlx_function_exporter mlx_function_exporter_new();
int mlx_function_exporter_free(mlx_function_exporter xfunc);
int mlx_function_exporter_call(
    const mlx_function_exporter xfunc,
    const mlx_vector_array args);

typedef struct mlx_imported_function_ {
  void* ctx;
} mlx_imported_function;

mlx_imported_function mlx_imported_function_new();
int mlx_imported_function_free(mlx_imported_function xfunc);
int mlx_imported_function_call(
    mlx_vector_array* res,
    const mlx_imported_function xfunc,
    mlx_vector_array args);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
