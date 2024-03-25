/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_UTILS_H
#define MLX_UTILS_H

#include <optional>
#include <vector>

#include "mlx/c/array.h"
#include "mlx/c/private/array.h"
#include "mlx/mlx.h"
#include "mlx/transforms_impl.h"

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

static mlx::core::Dtype mlx_cpp_dtypes[] = {
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

static mlx_array_dtype mlx_c_dtypes[] = {
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

#define MLX_CPP_ARRAY(arr) ((arr)->ctx)
#define MLX_C_ARRAY(arr) (new mlx_array_(arr))
#define MLX_CPP_ARRAY_DTYPE(dtype) (mlx_cpp_dtypes[dtype])
#define MLX_C_ARRAY_DTYPE(dtype) (mlx_c_dtypes[(int)((dtype).val)])
#define MLX_CPP_INTVEC(vals, size) (std::vector<int>((vals), (vals) + (size)))
#define MLX_CPP_UINT64VEC(vals, size) \
  (std::vector<uint64_t>((vals), (vals) + (size)))
#define MLX_CPP_OPT_INTVEC(vals, size)                                    \
  ((vals) ? std::make_optional(std::vector<int>((vals), (vals) + (size))) \
          : std::nullopt)
#define MLX_CPP_SIZEVEC(vals, size) \
  (std::vector<size_t>((vals), (vals) + (size)))
#define MLX_C_ARRAYS(vec) (new mlx_vector_array_(vec))
#define MLX_C_ARRAYPAIR(apair) (new mlx_vector_array_(apair))
#define MLX_C_ARRAYTUPLE3(atuple) (new mlx_vector_array_(atuple))
#define MLX_CPP_ARRVEC(vec) ((vec)->ctx)
#define MLX_CPP_INTPAIR(f, s) (std::pair<int, int>((f), (s)))
#define MLX_CPP_READER(f) (std::make_shared<CFILEReader>(f))
#define MLX_CPP_WRITER(f) (std::make_shared<CFILEWriter>(f))
#define MLX_C_CLOSURE(f) (new mlx_closure_(f))
#define MLX_CPP_CLOSURE(f) ((f)->ctx)
#define MLX_C_VECTORARRAYPAIR(apair) (new mlx_vector_vector_array_(apair))
#define MLX_C_VOID(f) (f)
#define MLX_C_CLOSURE_VALUE_AND_GRAD(f) (new mlx_closure_value_and_grad_(f))
#define MLX_CPP_MAP_STRING_TO_ARRAY(map) ((map)->ctx)
#define MLX_C_MAP_STRING_TO_ARRAY(map) (new mlx_map_string_to_array_(map))
#define MLX_CPP_MAP_STRING_TO_STRING(map) ((map)->ctx)
#define MLX_C_MAP_STRING_TO_STRING(map) (new mlx_map_string_to_string_(map))
#define MLX_CPP_STRING(str) ((str)->ctx)
#define MLX_C_STRING(str) (new mlx_string_(str))
#define MLX_C_SAFETENSORS(st) (new mlx_safetensors_(st))

#endif
