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
    (*res)->ctx = mlx::core::fft::fft(a->ctx, n, axis, s->ctx);
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
    (*res)->ctx = mlx::core::fft::fft2(
        a->ctx,
        std::vector<int>(n, n + n_num),
        std::vector<int>(axes, axes + axes_num),
        s->ctx);
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
    (*res)->ctx = mlx::core::fft::fftn(
        a->ctx,
        std::vector<int>(n, n + n_num),
        std::vector<int>(axes, axes + axes_num),
        s->ctx);
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
    (*res)->ctx = mlx::core::fft::ifft(a->ctx, n, axis, s->ctx);
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
    (*res)->ctx = mlx::core::fft::ifft2(
        a->ctx,
        std::vector<int>(n, n + n_num),
        std::vector<int>(axes, axes + axes_num),
        s->ctx);
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
    (*res)->ctx = mlx::core::fft::ifftn(
        a->ctx,
        std::vector<int>(n, n + n_num),
        std::vector<int>(axes, axes + axes_num),
        s->ctx);
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
    (*res)->ctx = mlx::core::fft::irfft(a->ctx, n, axis, s->ctx);
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
    (*res)->ctx = mlx::core::fft::irfft2(
        a->ctx,
        std::vector<int>(n, n + n_num),
        std::vector<int>(axes, axes + axes_num),
        s->ctx);
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
    (*res)->ctx = mlx::core::fft::irfftn(
        a->ctx,
        std::vector<int>(n, n + n_num),
        std::vector<int>(axes, axes + axes_num),
        s->ctx);
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
    (*res)->ctx = mlx::core::fft::rfft(a->ctx, n, axis, s->ctx);
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
    (*res)->ctx = mlx::core::fft::rfft2(
        a->ctx,
        std::vector<int>(n, n + n_num),
        std::vector<int>(axes, axes + axes_num),
        s->ctx);
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
    (*res)->ctx = mlx::core::fft::rfftn(
        a->ctx,
        std::vector<int>(n, n + n_num),
        std::vector<int>(axes, axes + axes_num),
        s->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
