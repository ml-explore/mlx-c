/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_FFT_H
#define MLX_FFT_H

#include <stdio.h>

#include "mlx/c/array.h"
#include "mlx/c/closure.h"
#include "mlx/c/distributed_group.h"
#include "mlx/c/map.h"
#include "mlx/c/stream.h"
#include "mlx/c/string.h"
#include "mlx/c/vector.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup fft FFT operations
 */
/**@{*/
int mlx_fft_fft(
    const mlx_array a,
    int n,
    int axis,
    const mlx_stream s,
    mlx_array* res);
int mlx_fft_fft2(
    const mlx_array a,
    const int* n,
    size_t n_num,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_fft_fftn(
    const mlx_array a,
    const int* n,
    size_t n_num,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_fft_ifft(
    const mlx_array a,
    int n,
    int axis,
    const mlx_stream s,
    mlx_array* res);
int mlx_fft_ifft2(
    const mlx_array a,
    const int* n,
    size_t n_num,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_fft_ifftn(
    const mlx_array a,
    const int* n,
    size_t n_num,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_fft_irfft(
    const mlx_array a,
    int n,
    int axis,
    const mlx_stream s,
    mlx_array* res);
int mlx_fft_irfft2(
    const mlx_array a,
    const int* n,
    size_t n_num,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_fft_irfftn(
    const mlx_array a,
    const int* n,
    size_t n_num,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_fft_rfft(
    const mlx_array a,
    int n,
    int axis,
    const mlx_stream s,
    mlx_array* res);
int mlx_fft_rfft2(
    const mlx_array a,
    const int* n,
    size_t n_num,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res);
int mlx_fft_rfftn(
    const mlx_array a,
    const int* n,
    size_t n_num,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
