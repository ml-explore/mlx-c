#ifndef MLX_FFT_H
#define MLX_FFT_H

#include <stdio.h>

#include "mlx/c/array.h"
#include "mlx/c/stream.h"

#ifdef __cplusplus
extern "C" {
#endif

mlx_array mlx_fft(mlx_array a, int n, int axis, mlx_stream s);
mlx_array mlx_fft2(
    mlx_array a,
    int* n,
    size_t num_n,
    int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array mlx_fftn(
    mlx_array a,
    int* n,
    size_t num_n,
    int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array mlx_ifft(mlx_array a, int n, int axis, mlx_stream s);
mlx_array mlx_ifft2(
    mlx_array a,
    int* n,
    size_t num_n,
    int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array mlx_ifftn(
    mlx_array a,
    int* n,
    size_t num_n,
    int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array mlx_irfft(mlx_array a, int n, int axis, mlx_stream s);
mlx_array mlx_irfft2(
    mlx_array a,
    int* n,
    size_t num_n,
    int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array mlx_irfftn(
    mlx_array a,
    int* n,
    size_t num_n,
    int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array mlx_rfft(mlx_array a, int n, int axis, mlx_stream s);
mlx_array mlx_rfft2(
    mlx_array a,
    int* n,
    size_t num_n,
    int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array mlx_rfftn(
    mlx_array a,
    int* n,
    size_t num_n,
    int* axes,
    size_t num_axes,
    mlx_stream s);

#ifdef __cplusplus
}
#endif

#endif
