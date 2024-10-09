#ifndef MLX_IO_PRIVATE_H
#define MLX_IO_PRIVATE_H

#include <iostream>
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
