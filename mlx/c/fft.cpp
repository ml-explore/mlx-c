/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/fft.h"

#include "mlx/c/mlx.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/closure.h"
#include "mlx/c/private/distributed_group.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
#include "mlx/c/private/vector.h"

extern "C" int mlx_fft_fft(
    const mlx_array a,
    int n,
    int axis,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::fft::fft(mlx_array_get_(a), n, axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fft_fft2(
    const mlx_array a,
    const int* n,
    size_t n_num,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::fft::fft2(
            mlx_array_get_(a),
            std::vector<int>(n, n + n_num),
            std::vector<int>(axes, axes + axes_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fft_fftn(
    const mlx_array a,
    const int* n,
    size_t n_num,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::fft::fftn(
            mlx_array_get_(a),
            std::vector<int>(n, n + n_num),
            std::vector<int>(axes, axes + axes_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fft_ifft(
    const mlx_array a,
    int n,
    int axis,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::fft::ifft(mlx_array_get_(a), n, axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fft_ifft2(
    const mlx_array a,
    const int* n,
    size_t n_num,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::fft::ifft2(
            mlx_array_get_(a),
            std::vector<int>(n, n + n_num),
            std::vector<int>(axes, axes + axes_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fft_ifftn(
    const mlx_array a,
    const int* n,
    size_t n_num,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::fft::ifftn(
            mlx_array_get_(a),
            std::vector<int>(n, n + n_num),
            std::vector<int>(axes, axes + axes_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fft_irfft(
    const mlx_array a,
    int n,
    int axis,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::fft::irfft(mlx_array_get_(a), n, axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fft_irfft2(
    const mlx_array a,
    const int* n,
    size_t n_num,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::fft::irfft2(
            mlx_array_get_(a),
            std::vector<int>(n, n + n_num),
            std::vector<int>(axes, axes + axes_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fft_irfftn(
    const mlx_array a,
    const int* n,
    size_t n_num,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::fft::irfftn(
            mlx_array_get_(a),
            std::vector<int>(n, n + n_num),
            std::vector<int>(axes, axes + axes_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fft_rfft(
    const mlx_array a,
    int n,
    int axis,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::fft::rfft(mlx_array_get_(a), n, axis, mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fft_rfft2(
    const mlx_array a,
    const int* n,
    size_t n_num,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::fft::rfft2(
            mlx_array_get_(a),
            std::vector<int>(n, n + n_num),
            std::vector<int>(axes, axes + axes_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fft_rfftn(
    const mlx_array a,
    const int* n,
    size_t n_num,
    const int* axes,
    size_t axes_num,
    const mlx_stream s,
    mlx_array* res) {
  try {
    mlx_array_set_(
        res,
        mlx::core::fft::rfftn(
            mlx_array_get_(a),
            std::vector<int>(n, n + n_num),
            std::vector<int>(axes, axes + axes_num),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
