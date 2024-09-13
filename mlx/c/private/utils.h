/* Copyright © 2023-2024 Apple Inc. */

#ifndef MLX_UTILS_H
#define MLX_UTILS_H

#include <iostream>
#include <optional>
#include <vector>

#include "mlx/c/array.h"
#include "mlx/c/error.h"
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

#define MLX_TRY_CATCH(scope, fallback) \
  {                                    \
    try {                              \
      scope;                           \
    } catch (std::exception & e) {     \
      mlx_error(e.what());             \
      fallback;                        \
    }                                  \
  }

#define RETURN_MLX_C_PTR(ptr) MLX_TRY_CATCH(return (ptr), return nullptr)

#define MLX_CPP_ARRAY(arr) ((arr)->ctx)
#define MLX_CPP_ARRAY_DTYPE(dtype) (mlx_cpp_dtypes[dtype])
#define MLX_CPP_INTVEC(vals, size) (std::vector<int>((vals), (vals) + (size)))
#define MLX_CPP_UINT64VEC(vals, size) \
  (std::vector<uint64_t>((vals), (vals) + (size)))
#define MLX_CPP_OPT_INTVEC(vals, size)                                    \
  ((vals) ? std::make_optional(std::vector<int>((vals), (vals) + (size))) \
          : std::nullopt)
#define MLX_CPP_SIZEVEC(vals, size) \
  (std::vector<size_t>((vals), (vals) + (size)))
#define MLX_CPP_ARRVEC(vec) ((vec)->ctx)
#define MLX_CPP_STRINGVEC(vec) ((vec)->ctx)
#define MLX_CPP_INTPAIR(f, s) (std::pair<int, int>((f), (s)))
#define MLX_CPP_INTTUPLE3(i0, i1, i2) \
  (std::tuple<int, int, int>((i0), (i1), (i2)))
#define MLX_CPP_READER(f) (std::make_shared<CFILEReader>(f))
#define MLX_CPP_WRITER(f) (std::make_shared<CFILEWriter>(f))
#define MLX_CPP_MAP_STRING_TO_ARRAY(map) ((map)->ctx)
#define MLX_CPP_MAP_STRING_TO_STRING(map) ((map)->ctx)
#define MLX_CPP_STRING(str) ((str)->ctx)

#define RETURN_MLX_C_VOID(scope) MLX_TRY_CATCH(scope, return)
#define RETURN_MLX_C_ARRAY_DTYPE(dtype) return mlx_c_dtypes[(int)((dtype).val)]
#define RETURN_MLX_C_ARRAY(arr) RETURN_MLX_C_PTR(new mlx_array_(arr))
#define RETURN_MLX_C_STREAM(stream) RETURN_MLX_C_PTR(new mlx_stream_(stream))
#define RETURN_MLX_C_DEVICE(device) RETURN_MLX_C_PTR(new mlx_device_(device))
#define RETURN_MLX_C_VECTOR_ARRAY(vec) \
  RETURN_MLX_C_PTR(new mlx_vector_array_(vec))
#define RETURN_MLX_C_VECTOR_VECTOR_ARRAY(vec) \
  RETURN_MLX_C_PTR(new mlx_vector_vector_array_(vec))
#define RETURN_MLX_C_ARRAYPAIR(apair) \
  RETURN_MLX_C_PTR(new mlx_tuple_array_array_(apair))
#define RETURN_MLX_C_ARRAYTUPLE3(atuple) \
  RETURN_MLX_C_PTR(new mlx_tuple_array_array_array_(atuple))
#define RETURN_MLX_C_CLOSURE(closure) \
  RETURN_MLX_C_PTR(new mlx_closure_(closure))
#define RETURN_MLX_C_VECTORARRAYPAIR(apair) \
  RETURN_MLX_C_PTR(new mlx_tuple_vector_array_vector_array_(apair))
#define RETURN_MLX_C_CLOSURE_VALUE_AND_GRAD(f) \
  RETURN_MLX_C_PTR(new mlx_closure_value_and_grad_(f))
#define RETURN_MLX_C_CLOSURE_METAL_KERNEL_FUNCTION(f) \
  RETURN_MLX_C_PTR(new mlx_closure_metal_kernel_function_(f))
#define RETURN_MLX_C_CLOSURE_CUSTOM_FUNCTION(closure) \
  RETURN_MLX_C_PTR(new mlx_closure_custom_function_(closure))
#define RETURN_MLX_C_MAP_STRING_TO_ARRAY(map) \
  RETURN_MLX_C_PTR(new mlx_map_string_to_array_(map))
#define RETURN_MLX_C_MAP_STRING_TO_STRING(map) \
  RETURN_MLX_C_PTR(new mlx_map_string_to_string_(map))
#define RETURN_MLX_C_MAP_STRING_TO_STRING_SIZE_T_VARIANT(map) \
  RETURN_MLX_C_PTR(new mlx_map_string_to_variant_string_size_t_(map))
#define RETURN_MLX_C_STRING(str) RETURN_MLX_C_PTR(new mlx_string_(str))
#define RETURN_MLX_C_SAFETENSORS(st) RETURN_MLX_C_PTR(new mlx_safetensors_(st))
#define RETURN_MLX_C_FUTURE(f) RETURN_MLX_C_PTR(new mlx_future_(f))
#define RETURN_MLX_C_DISTRIBUTED_GROUP(group) \
  RETURN_MLX_C_PTR(new mlx_distributed_group_(group))

#endif
