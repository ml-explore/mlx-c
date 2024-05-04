/* Copyright © 2023-2024 Apple Inc. */

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

/**
 * \defgroup mlx_array Array
 * MLX N-dimensional array object.
 */
/**@{*/

/**
 * An N-dimensional array object.
 */
typedef struct mlx_array_* mlx_array;

/**
 * Array element type.
 */
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

/**
 * New array from a bool scalar.
 */
mlx_array mlx_array_from_bool(bool val);
/**
 * New array from a int scalar.
 */
mlx_array mlx_array_from_int(int val);
/**
 * New array from a float scalar.
 */
mlx_array mlx_array_from_float(float val);
/**
 * New array from a complex scalar.
 */
mlx_array mlx_array_from_complex(float real_val, float imag_val);
/**
 * New array from existing buffer.
 * @param data A buffer which will be copied.
 * @param shape Shape of the array.
 * @param dim Number of dimensions (size of `shape`).
 * @param dtype Type of array elements.
 */
mlx_array mlx_array_from_data(
    const void* data,
    const int* shape,
    int dim,
    mlx_array_dtype dtype);

/**
 * The size of the array's datatype in bytes.
 */
size_t mlx_array_itemsize(mlx_array arr);
/**
 * Number of elements in the array.
 */
size_t mlx_array_size(mlx_array arr);
/**
 * The strides of the array.
 */
size_t* mlx_array_strides(mlx_array arr);
/**
 * The number of bytes in the array.
 */
size_t mlx_array_nbytes(mlx_array arr);
/**
 * The array's dimension.
 */
size_t mlx_array_ndim(mlx_array arr);
/**
 * The shape of the array.
 * Returns: a pointer to the sizes of each dimension.
 */
int* mlx_array_shape(mlx_array arr);
/**
 * The strides of the array.
 * Returns: a pointer to the sizes of each dimension.
 */
size_t* mlx_array_strides(mlx_array arr);
/**
 * The shape of the array in a particular dimension.
 */
int mlx_array_dim(mlx_array arr, int dim);
/**
 * The array element type.
 */
mlx_array_dtype mlx_array_get_dtype(mlx_array arr);
/**
 * Evaluate the array.
 */
void mlx_array_eval(mlx_array arr);

/**
 * Access the value of a scalar array.
 */
bool mlx_array_item_bool(mlx_array arr);
/**
 * Access the value of a scalar array.
 */
uint8_t mlx_array_item_uint8(mlx_array arr);
/**
 * Access the value of a scalar array.
 */
uint16_t mlx_array_item_uint16(mlx_array arr);
/**
 * Access the value of a scalar array.
 */
uint32_t mlx_array_item_uint32(mlx_array arr);
/**
 * Access the value of a scalar array.
 */
uint64_t mlx_array_item_uint64(mlx_array arr);
/**
 * Access the value of a scalar array.
 */
int8_t mlx_array_item_int8(mlx_array arr);
/**
 * Access the value of a scalar array.
 */
int16_t mlx_array_item_int16(mlx_array arr);
/**
 * Access the value of a scalar array.
 */
int32_t mlx_array_item_int32(mlx_array arr);
/**
 * Access the value of a scalar array.
 */
int64_t mlx_array_item_int64(mlx_array arr);
/**
 * Access the value of a scalar array.
 */
float mlx_array_item_float32(mlx_array arr);
/**
 * Access the value of a scalar array.
 */
float _Complex mlx_array_item_complex64(mlx_array arr);

#ifdef HAS_FLOAT16
/**
 * Access the value of a scalar array.
 */
float16_t mlx_array_item_float16(mlx_array arr);
#endif

#ifdef HAS_BFLOAT16
/**
 * Access the value of a scalar array.
 */
bfloat16_t mlx_array_item_bfloat16(mlx_array arr);
#endif

/**
 * Returns a pointer to the array data, cast to `bool*`.
 * Array must be evaluated, otherwise returns NULL.
 */
const bool* mlx_array_data_bool(mlx_array arr);
/**
 * Returns a pointer to the array data, cast to `uint8_t*`.
 * Array must be evaluated, otherwise returns NULL.
 */
const uint8_t* mlx_array_data_uint8(mlx_array arr);
/**
 * Returns a pointer to the array data, cast to `uint16_t*`.
 * Array must be evaluated, otherwise returns NULL.
 */
const uint16_t* mlx_array_data_uint16(mlx_array arr);
/**
 * Returns a pointer to the array data, cast to `uint32_t*`.
 * Array must be evaluated, otherwise returns NULL.
 */
const uint32_t* mlx_array_data_uint32(mlx_array arr);
/**
 * Returns a pointer to the array data, cast to `uint64_t*`.
 * Array must be evaluated, otherwise returns NULL.
 */
const uint64_t* mlx_array_data_uint64(mlx_array arr);
/**
 * Returns a pointer to the array data, cast to `int8_t*`.
 * Array must be evaluated, otherwise returns NULL.
 */
const int8_t* mlx_array_data_int8(mlx_array arr);
/**
 * Returns a pointer to the array data, cast to `int16_t*`.
 * Array must be evaluated, otherwise returns NULL.
 */
const int16_t* mlx_array_data_int16(mlx_array arr);
/**
 * Returns a pointer to the array data, cast to `int32_t*`.
 * Array must be evaluated, otherwise returns NULL.
 */
const int32_t* mlx_array_data_int32(mlx_array arr);
/**
 * Returns a pointer to the array data, cast to `int64_t*`.
 * Array must be evaluated, otherwise returns NULL.
 */
const int64_t* mlx_array_data_int64(mlx_array arr);
/**
 * Returns a pointer to the array data, cast to `float32*`.
 * Array must be evaluated, otherwise returns NULL.
 */
const float* mlx_array_data_float32(mlx_array arr);
/**
 * Returns a pointer to the array data, cast to `_Complex*`.
 * Array must be evaluated, otherwise returns NULL.
 */
const float _Complex* mlx_array_data_complex64(mlx_array arr);

#ifdef HAS_FLOAT16
/**
 * Returns a pointer to the array data, cast to `float16_t*`.
 * Array must be evaluated, otherwise returns NULL.
 */
const float16_t* mlx_array_data_float16(mlx_array arr);
#endif

#ifdef HAS_BFLOAT16
/**
 * Returns a pointer to the array data, cast to `bfloat16_t*`.
 * Array must be evaluated, otherwise returns NULL.
 */
const bfloat16_t* mlx_array_data_bfloat16(mlx_array arr);
#endif

/**
 * Replaces the array descriptor with that of another array.
 */
void mlx_overwrite_descriptor(mlx_array arr, mlx_array other);

/**@}*/

/**
 * \defgroup mlx_vector_array A vector of arrays
 * MLX vector of array object.
 */
/**@{*/

/**
 * A vector of arrays.
 */
typedef struct mlx_vector_array_* mlx_vector_array;

/**
 * Returns a new empty vector of arrays
 */
mlx_vector_array mlx_vector_array_new();
/**
 * Returns a new vector of arrays, from specified arrays.
 * The reference count of the given arrays will be increased.
 */
mlx_vector_array mlx_vector_array_from_arrays(mlx_array* arrs, size_t num_arrs);
/**
 * Returns a new vector of array, containing a single specified array.
 * The reference count of the given array will be increased.
 */
mlx_vector_array mlx_vector_array_from_array(const mlx_array arr);
/**
 * Add an array to the vector of arrays.
 * The reference count of the given array will be increased.
 */
void mlx_vector_array_add(mlx_vector_array vec, const mlx_array arr);
/**
 * Add several arrays to the vector of arrays.
 * The reference count of the given arrays will be increased.
 */
void mlx_vector_array_add_arrays(
    mlx_vector_array vec,
    const mlx_array* arrs,
    size_t num_arrs);
/**
 * Get the array at `index` in the vector of arrays.
 */
mlx_array mlx_vector_array_get(mlx_vector_array vec, size_t index);
/**
 * Size of the vector of arrays.
 */
size_t mlx_vector_array_size(mlx_vector_array vec);
/**@}*/

/**
 * \defgroup mlx_vector_vector_array Vector of array vectors
 * MLX vector of vector array object.
 */
/**@{*/

/**
 * A vector of array vectors.
 */
typedef struct mlx_vector_vector_array_* mlx_vector_vector_array;

/**
 * New empty vector of array vectors.
 */
mlx_vector_vector_array mlx_vector_vector_array_new();
/**
 * Add an array vector to the vector of array vectors.
 * Reference count of the array vector will be increased.
 */
void mlx_vector_vector_array_add(
    mlx_vector_vector_array vec2,
    const mlx_vector_array vec);
/**
 * Get the array vector at specified `index` in the vector of array vectors.
 */
mlx_vector_array mlx_vector_vector_array_get(
    mlx_vector_vector_array vec2,
    size_t index);
/**
 * Get the array at specified (`index`, `arr_index`) in the vector of array
 * vectors.
 */
mlx_array mlx_vector_vector_array_get2d(
    mlx_vector_vector_array vec2,
    size_t index,
    size_t arr_index);
size_t mlx_vector_vector_array_size(mlx_vector_vector_array vec2);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
