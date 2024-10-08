/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_UTILS_H
#define MLX_UTILS_H

#include <iostream>
#include <optional>
#include <vector>

#include "mlx/c/array.h"
#include "mlx/c/compile.h"
#include "mlx/c/error.h"
#include "mlx/mlx.h"
#include "mlx/transforms_impl.h"

namespace {
inline mlx_compile_mode mlx_compile_mode_to_c(mlx::core::CompileMode type) {
  static mlx_compile_mode map[] = {
      MLX_COMPILE_MODE_DISABLED,
      MLX_COMPILE_MODE_NO_SIMPLIFY,
      MLX_COMPILE_MODE_NO_FUSE,
      MLX_COMPILE_MODE_ENABLED};
  return map[(int)type];
}
inline mlx::core::CompileMode mlx_compile_mode_to_cpp(mlx_compile_mode type) {
  static mlx::core::CompileMode map[] = {
      mlx::core::CompileMode::disabled,
      mlx::core::CompileMode::no_simplify,
      mlx::core::CompileMode::no_fuse,
      mlx::core::CompileMode::enabled};
  return map[(int)type];
}
inline mlx_dtype mlx_dtype_to_c(mlx::core::Dtype type) {
  static mlx_dtype map[] = {
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
  };
  return map[(int)type.val()];
}
inline mlx::core::Dtype mlx_dtype_to_cpp(mlx_dtype type) {
  static mlx::core::Dtype map[] = {
      mlx::core::bool_,
      mlx::core::uint8,
      mlx::core::uint16,
      mlx::core::uint32,
      mlx::core::uint64,
      mlx::core::int8,
      mlx::core::int16,
      mlx::core::int32,
      mlx::core::int64,
      mlx::core::float16,
      mlx::core::float32,
      mlx::core::bfloat16,
      mlx::core::complex64,
  };
  return map[(int)type];
}
} // namespace

class CFILEReader : public mlx::core::io::Reader {
 private:
  FILE* f;

 public:
  CFILEReader(FILE* f) : f(f){};
  virtual bool is_open() const override {
    return f != nullptr;
  };
  virtual bool good() const override {
    return ferror(f) == 0;
  };
  virtual size_t tell() override {
    return ftell(f);
  }
  virtual void seek(
      int64_t off,
      std::ios_base::seekdir way = std::ios_base::beg) override {
    switch (way) {
      case std::ios_base::beg:
        fseek(f, off, SEEK_SET);
        break;
      case std::ios_base::cur:
        fseek(f, off, SEEK_CUR);
        break;
      case std::ios_base::end:
        fseek(f, off, SEEK_END);
        break;
      default:
        throw std::runtime_error("FILE: invalid seek way");
    }
  }
  virtual void read(char* data, size_t n) override {
    fread(data, 1, n, f);
  };
  virtual void read(char* data, size_t n, size_t offset) override {
    fseek(f, offset, SEEK_SET);
    fread(data, 1, n, f);
  };
  virtual std::string label() const override {
    return "FILE (read mode)";
  };
};

class CFILEWriter : public mlx::core::io::Writer {
 private:
  FILE* f;

 public:
  CFILEWriter(FILE* f) : f(f){};
  virtual bool is_open() const override {
    return f != nullptr;
  };
  virtual bool good() const override {
    return ferror(f) == 0;
  };
  virtual size_t tell() override {
    return ftell(f);
  }
  virtual void seek(
      int64_t off,
      std::ios_base::seekdir way = std::ios_base::beg) override {
    switch (way) {
      case std::ios_base::beg:
        fseek(f, off, SEEK_SET);
        break;
      case std::ios_base::cur:
        fseek(f, off, SEEK_CUR);
        break;
      case std::ios_base::end:
        fseek(f, off, SEEK_END);
        break;
      default:
        throw std::runtime_error("FILE: invalid seek way");
    }
  }
  virtual void write(const char* data, size_t n) override {
    fwrite(data, 1, n, f);
  };
  virtual std::string label() const override {
    return "FILE (write mode)";
  };
};

#endif
