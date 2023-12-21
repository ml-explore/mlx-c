#ifndef MLX_UTILS_H
#define MLX_UTILS_H

#include <optional>
#include <vector>

#include "mlx/c/array.h"
#include "mlx/mlx.h"

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
  virtual size_t tell() const override {
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
  virtual size_t tell() const override {
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

inline mlx_vector_array mlx_cpp_vector_array_to_c(
    const std::vector<mlx::core::array>& vec) {
  mlx_vector_array c_vec;
  c_vec.size = vec.size();
  c_vec.arrays = (mlx_array*)malloc(sizeof(mlx_array) * vec.size());
  if (c_vec.arrays) {
    for (size_t i = 0; i < vec.size(); i++) {
      c_vec.arrays[i] = new mlx_array_(vec[i]);
    }
  }
  return c_vec;
}

inline mlx_vector_array mlx_cpp_pair_array_to_c(
    const std::pair<mlx::core::array, mlx::core::array>& vec) {
  mlx_vector_array c_vec;
  c_vec.size = 2;
  c_vec.arrays = (mlx_array*)malloc(sizeof(mlx_array) * 2);
  if (c_vec.arrays) {
    c_vec.arrays[0] = new mlx_array_(vec.first);
    c_vec.arrays[0] = new mlx_array_(vec.second);
  }
  return c_vec;
}

inline mlx_vector_array mlx_cpp_tuple3_array_to_c(
    const std::tuple<mlx::core::array, mlx::core::array, mlx::core::array>&
        vec) {
  mlx_vector_array c_vec;
  c_vec.size = 3;
  c_vec.arrays = (mlx_array*)malloc(sizeof(mlx_array) * 3);
  if (c_vec.arrays) {
    for (int i = 0; i < 3; i++) {
      c_vec.arrays[0] = new mlx_array_(std::get<0>(vec));
      c_vec.arrays[1] = new mlx_array_(std::get<1>(vec));
      c_vec.arrays[2] = new mlx_array_(std::get<2>(vec));
    }
  }
  return c_vec;
}

inline std::vector<mlx::core::array> mlx_c_vector_array_to_cpp(
    mlx_array* vec,
    size_t n) {
  std::vector<mlx::core::array> cpp_vec;
  for (size_t i = 0; i < n; i++) {
    cpp_vec.push_back(vec[i]->ctx);
  }
  return cpp_vec;
}

#define MLX_CPP_ARRAY(arr) ((arr)->ctx)
#define MLX_C_ARRAY(arr) (new mlx_array_(arr))
#define MLX_CPP_ARRAY_DTYPE(dtype) (mlx_cpp_dtypes[dtype])
#define MLX_C_ARRAY_DTYPE(dtype) (mlx_c_dtypes[(int)((dtype).val)])
#define MLX_CPP_INTVEC(vals, size) (std::vector<int>((vals), (vals) + (size)))
#define MLX_CPP_SIZEVEC(vals, size) \
  (std::vector<size_t>((vals), (vals) + (size)))
#define MLX_C_ARRAYS(vec) (mlx_cpp_vector_array_to_c(vec))
#define MLX_C_ARRAYPAIR(apair) (mlx_cpp_pair_array_to_c(apair))
#define MLX_C_ARRAYTUPLE3(atuple) (mlx_cpp_tuple3_array_to_c(atuple))
#define MLX_CPP_ARRVEC(vec, size) (mlx_c_vector_array_to_cpp((vec), (size)))
#define MLX_CPP_INTPAIR(f, s) (std::pair<int, int>((f), (s)))
#define MLX_CPP_READER(f) (std::make_shared<CFILEReader>(f))
#define MLX_CPP_WRITER(f) (std::make_shared<CFILEWriter>(f))
#define MLX_C_VOID(f) (f)

#endif
