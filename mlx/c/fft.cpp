#include "mlx/c/fft.h"

#include "mlx/c/private/array.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/utils.h"

extern "C" mlx_array mlx_fft(mlx_array a, int n, int axis, mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::fft::fft(a->ctx, n, axis, s->ctx));
}
extern "C" mlx_array mlx_fft2(
    mlx_array a,
    int* n,
    size_t num_n,
    int* axes,
    size_t num_axes,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::fft::fft2(
      a->ctx,
      MLX_CPP_INTVEC(n, num_n),
      MLX_CPP_INTVEC(axes, num_axes),
      s->ctx));
}
extern "C" mlx_array mlx_fftn(
    mlx_array a,
    int* n,
    size_t num_n,
    int* axes,
    size_t num_axes,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::fft::fftn(
      a->ctx,
      MLX_CPP_INTVEC(n, num_n),
      MLX_CPP_INTVEC(axes, num_axes),
      s->ctx));
}
extern "C" mlx_array mlx_ifft(mlx_array a, int n, int axis, mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::fft::ifft(a->ctx, n, axis, s->ctx));
}
extern "C" mlx_array mlx_ifft2(
    mlx_array a,
    int* n,
    size_t num_n,
    int* axes,
    size_t num_axes,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::fft::ifft2(
      a->ctx,
      MLX_CPP_INTVEC(n, num_n),
      MLX_CPP_INTVEC(axes, num_axes),
      s->ctx));
}
extern "C" mlx_array mlx_ifftn(
    mlx_array a,
    int* n,
    size_t num_n,
    int* axes,
    size_t num_axes,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::fft::ifftn(
      a->ctx,
      MLX_CPP_INTVEC(n, num_n),
      MLX_CPP_INTVEC(axes, num_axes),
      s->ctx));
}
extern "C" mlx_array mlx_irfft(mlx_array a, int n, int axis, mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::fft::irfft(a->ctx, n, axis, s->ctx));
}
extern "C" mlx_array mlx_irfft2(
    mlx_array a,
    int* n,
    size_t num_n,
    int* axes,
    size_t num_axes,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::fft::irfft2(
      a->ctx,
      MLX_CPP_INTVEC(n, num_n),
      MLX_CPP_INTVEC(axes, num_axes),
      s->ctx));
}
extern "C" mlx_array mlx_irfftn(
    mlx_array a,
    int* n,
    size_t num_n,
    int* axes,
    size_t num_axes,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::fft::irfftn(
      a->ctx,
      MLX_CPP_INTVEC(n, num_n),
      MLX_CPP_INTVEC(axes, num_axes),
      s->ctx));
}
extern "C" mlx_array mlx_rfft(mlx_array a, int n, int axis, mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::fft::rfft(a->ctx, n, axis, s->ctx));
}
extern "C" mlx_array mlx_rfft2(
    mlx_array a,
    int* n,
    size_t num_n,
    int* axes,
    size_t num_axes,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::fft::rfft2(
      a->ctx,
      MLX_CPP_INTVEC(n, num_n),
      MLX_CPP_INTVEC(axes, num_axes),
      s->ctx));
}
extern "C" mlx_array mlx_rfftn(
    mlx_array a,
    int* n,
    size_t num_n,
    int* axes,
    size_t num_axes,
    mlx_stream s) {
  return MLX_C_ARRAY(mlx::core::fft::rfftn(
      a->ctx,
      MLX_CPP_INTVEC(n, num_n),
      MLX_CPP_INTVEC(axes, num_axes),
      s->ctx));
}
