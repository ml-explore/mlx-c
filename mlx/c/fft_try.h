/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include <stdio.h>

#ifndef MLX_FFT_TRY_H
#define MLX_FFT_TRY_H
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

mlx_array_result mlx_fft_fft_try(mlx_array a, int n, int axis, mlx_stream s);
mlx_array_result mlx_fft_fft2_try(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_fft_fftn_try(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_fft_ifft_try(mlx_array a, int n, int axis, mlx_stream s);
mlx_array_result mlx_fft_ifft2_try(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_fft_ifftn_try(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_fft_irfft_try(mlx_array a, int n, int axis, mlx_stream s);
mlx_array_result mlx_fft_irfft2_try(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_fft_irfftn_try(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_fft_rfft_try(mlx_array a, int n, int axis, mlx_stream s);
mlx_array_result mlx_fft_rfft2_try(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s);
mlx_array_result mlx_fft_rfftn_try(
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
