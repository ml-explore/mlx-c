#ifndef MLX_ARRAY_H
#define MLX_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>

#include "half.h"

#ifdef __cplusplus
extern "C" {
#endif

#define __STDC_WANT_IEC_60559_TYPES_EXT__
#include <float.h>

typedef struct mlx_array_* mlx_array;
typedef struct mlx_vector_array_* mlx_vector_array;
typedef struct mlx_vector_vector_array_* mlx_vector_vector_array;

typedef enum mlx_array_dtype_ {
  MLX_BOOL,
  MLX_UINT8,
  MLX_UINT16,
  MLX_UINT32,
  MLX_UINT64,
  MLX_INT8,
  MLX_INT16,
  MLX_INT32,
  MLX_INT64,
  MLX_FLOAT16,
  MLX_FLOAT32,
  MLX_BFLOAT16,
  MLX_COMPLEX64,
} mlx_array_dtype;

mlx_array mlx_array_from_bool(bool val);
mlx_array mlx_array_from_int(int val);
mlx_array mlx_array_from_float(float val);
mlx_array mlx_array_from_complex(float real_val, float imag_val);
mlx_array mlx_array_from_data(
    const void* data,
    const int* shape,
    int dim,
    mlx_array_dtype dtype);

size_t mlx_array_itemsize(mlx_array arr);
size_t mlx_array_size(mlx_array arr);
size_t* mlx_array_strides(mlx_array arr);
size_t mlx_array_nbytes(mlx_array arr);
size_t mlx_array_ndim(mlx_array arr);
int* mlx_array_shape(mlx_array arr);
size_t* mlx_array_strides(mlx_array arr);
int mlx_array_dim(mlx_array arr, int dim);
mlx_array_dtype mlx_array_get_dtype(mlx_array arr);
void mlx_array_eval(mlx_array arr);

bool mlx_array_item_bool(mlx_array arr);
uint8_t mlx_array_item_uint8(mlx_array arr);
uint16_t mlx_array_item_uint16(mlx_array arr);
uint32_t mlx_array_item_uint32(mlx_array arr);
uint64_t mlx_array_item_uint64(mlx_array arr);
int8_t mlx_array_item_int8(mlx_array arr);
int16_t mlx_array_item_int16(mlx_array arr);
int32_t mlx_array_item_int32(mlx_array arr);
int64_t mlx_array_item_int64(mlx_array arr);
float mlx_array_item_float32(mlx_array arr);
float _Complex mlx_array_item_complex64(mlx_array arr);

#ifdef HAS_FLOAT16
float16_t mlx_array_item_float16(mlx_array arr);
#endif

#ifdef HAS_BFLOAT16
bfloat16_t mlx_array_item_bfloat16(mlx_array arr);
#endif

const bool* mlx_array_data_bool(mlx_array arr);
const uint8_t* mlx_array_data_uint8(mlx_array arr);
const uint16_t* mlx_array_data_uint16(mlx_array arr);
const uint32_t* mlx_array_data_uint32(mlx_array arr);
const uint64_t* mlx_array_data_uint64(mlx_array arr);
const int8_t* mlx_array_data_int8(mlx_array arr);
const int16_t* mlx_array_data_int16(mlx_array arr);
const int32_t* mlx_array_data_int32(mlx_array arr);
const int64_t* mlx_array_data_int64(mlx_array arr);
const float* mlx_array_data_float32(mlx_array arr);
const float _Complex* mlx_array_data_complex64(mlx_array arr);

#ifdef HAS_FLOAT16
const float16_t* mlx_array_data_float16(mlx_array arr);
#endif

#ifdef HAS_BFLOAT16
const bfloat16_t* mlx_array_data_bfloat16(mlx_array arr);
#endif

mlx_vector_array mlx_vector_array_new();
mlx_vector_array mlx_vector_array_from_arrays(mlx_array* arrs, size_t num_arrs);
mlx_vector_array mlx_vector_array_from_array(const mlx_array arr);
void mlx_vector_array_add(mlx_vector_array vec, const mlx_array arr);
void mlx_vector_array_add_arrays(
    mlx_vector_array vec,
    const mlx_array* arrs,
    size_t num_arrs);
mlx_array mlx_vector_array_get(mlx_vector_array vec, size_t index);
size_t mlx_vector_array_size(mlx_vector_array vec);

mlx_vector_vector_array mlx_vector_vector_array_new();
void mlx_vector_vector_array_add(
    mlx_vector_vector_array vec2,
    const mlx_vector_array vec);
mlx_vector_array mlx_vector_vector_array_get(
    mlx_vector_vector_array vec2,
    size_t index);
mlx_array mlx_vector_vector_array_get2d(
    mlx_vector_vector_array vec2,
    size_t index,
    size_t arr_index);
size_t mlx_vector_vector_array_size(mlx_vector_vector_array vec2);

#ifdef __cplusplus
}
#endif

#endif
