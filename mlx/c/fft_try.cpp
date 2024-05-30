/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/fft_try.h"
#include "mlx/c/fft.h"
#include "mlx/c/result.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/future.h"
#include "mlx/c/private/io.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

extern "C" mlx_array_result
mlx_fft_fft_try(mlx_array a, int n, int axis, mlx_stream s) {
  MLX_C_ARRAY_TRY(mlx::core::fft::fft(a->ctx, n, axis, s->ctx))
}
extern "C" mlx_array_result mlx_fft_fft2_try(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s) {
  MLX_C_ARRAY_TRY(mlx::core::fft::fft2(
      a->ctx, MLX_CPP_INTVEC(n, num_n), MLX_CPP_INTVEC(axes, num_axes), s->ctx))
}
extern "C" mlx_array_result mlx_fft_fftn_try(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s) {
  MLX_C_ARRAY_TRY(mlx::core::fft::fftn(
      a->ctx, MLX_CPP_INTVEC(n, num_n), MLX_CPP_INTVEC(axes, num_axes), s->ctx))
}
extern "C" mlx_array_result
mlx_fft_ifft_try(mlx_array a, int n, int axis, mlx_stream s) {
  MLX_C_ARRAY_TRY(mlx::core::fft::ifft(a->ctx, n, axis, s->ctx))
}
extern "C" mlx_array_result mlx_fft_ifft2_try(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s) {
  MLX_C_ARRAY_TRY(mlx::core::fft::ifft2(
      a->ctx, MLX_CPP_INTVEC(n, num_n), MLX_CPP_INTVEC(axes, num_axes), s->ctx))
}
extern "C" mlx_array_result mlx_fft_ifftn_try(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s) {
  MLX_C_ARRAY_TRY(mlx::core::fft::ifftn(
      a->ctx, MLX_CPP_INTVEC(n, num_n), MLX_CPP_INTVEC(axes, num_axes), s->ctx))
}
extern "C" mlx_array_result
mlx_fft_irfft_try(mlx_array a, int n, int axis, mlx_stream s) {
  MLX_C_ARRAY_TRY(mlx::core::fft::irfft(a->ctx, n, axis, s->ctx))
}
extern "C" mlx_array_result mlx_fft_irfft2_try(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s) {
  MLX_C_ARRAY_TRY(mlx::core::fft::irfft2(
      a->ctx, MLX_CPP_INTVEC(n, num_n), MLX_CPP_INTVEC(axes, num_axes), s->ctx))
}
extern "C" mlx_array_result mlx_fft_irfftn_try(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s) {
  MLX_C_ARRAY_TRY(mlx::core::fft::irfftn(
      a->ctx, MLX_CPP_INTVEC(n, num_n), MLX_CPP_INTVEC(axes, num_axes), s->ctx))
}
extern "C" mlx_array_result
mlx_fft_rfft_try(mlx_array a, int n, int axis, mlx_stream s) {
  MLX_C_ARRAY_TRY(mlx::core::fft::rfft(a->ctx, n, axis, s->ctx))
}
extern "C" mlx_array_result mlx_fft_rfft2_try(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s) {
  MLX_C_ARRAY_TRY(mlx::core::fft::rfft2(
      a->ctx, MLX_CPP_INTVEC(n, num_n), MLX_CPP_INTVEC(axes, num_axes), s->ctx))
}
extern "C" mlx_array_result mlx_fft_rfftn_try(
    mlx_array a,
    const int* n,
    size_t num_n,
    const int* axes,
    size_t num_axes,
    mlx_stream s) {
  MLX_C_ARRAY_TRY(mlx::core::fft::rfftn(
      a->ctx, MLX_CPP_INTVEC(n, num_n), MLX_CPP_INTVEC(axes, num_axes), s->ctx))
}
