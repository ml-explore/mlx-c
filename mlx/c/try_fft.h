/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include <stdio.h>

#ifndef MLX_TRY_FFT_H
#define MLX_TRY_FFT_H
#include "mlx/c/result.h"

#include "mlx/c/array.h"
#include "mlx/c/closure.h"
#include "mlx/c/future.h"
#include "mlx/c/ioutils.h"
#include "mlx/c/map.h"
#include "mlx/c/stream.h"
#include "mlx/c/string.h"

#ifdef __cplusplus
extern "C" {
#endif

mlx_array_result mlx_fft_try_fft(mlx_array a, int n, int axis, mlx_stream s);
mlx_array_result mlx_fft_try_fft2(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_fft_try_fftn(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_fft_try_ifft(mlx_array a, int n, int axis, mlx_stream s);
mlx_array_result mlx_fft_try_ifft2(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_fft_try_ifftn(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_fft_try_irfft(mlx_array a, int n, int axis, mlx_stream s);
mlx_array_result mlx_fft_try_irfft2(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_fft_try_irfftn(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_fft_try_rfft(mlx_array a, int n, int axis, mlx_stream s);
mlx_array_result mlx_fft_try_rfft2(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_fft_try_rfftn(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s);

#ifdef __cplusplus
}
#endif

#endif
