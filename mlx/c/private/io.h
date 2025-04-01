#ifndef MLX_IO_PRIVATE_H
#define MLX_IO_PRIVATE_H

#include <iostream>
#include "mlx/mlx.h"

struct mlx_io_vtable_file : public mlx_io_vtable {
 private:
  static bool is_open_impl(void* desc) {
    return desc != nullptr;
  };
  static bool good_impl(void* desc) {
    return ferror(static_cast<FILE*>(desc)) == 0;
  }
  static size_t tell_impl(void* desc) {
    return ftell(static_cast<FILE*>(desc));
  }
  static void seek_impl(void* desc, int64_t off, int whence) {
    fseek(static_cast<FILE*>(desc), off, whence);
  }
  static void read_impl(void* desc, char* data, size_t n) {
    fread(data, 1, n, static_cast<FILE*>(desc));
  }
  static void
  read_at_offset_impl(void* desc, char* data, size_t n, size_t off) {
    seek_impl(desc, off, SEEK_SET);
    fread(data, 1, n, static_cast<FILE*>(desc));
  }
  static void write_impl(void* desc, const char* data, size_t n) {
    fwrite(data, 1, n, static_cast<FILE*>(desc));
  }
  static const char* label_impl(void* desc) {
    return "FILE";
  };

 public:
  mlx_io_vtable_file()
      : mlx_io_vtable(
            {&mlx_io_vtable_file::is_open_impl,
             &mlx_io_vtable_file::good_impl,
             &mlx_io_vtable_file::tell_impl,
             &mlx_io_vtable_file::seek_impl,
             &mlx_io_vtable_file::read_impl,
             &mlx_io_vtable_file::read_at_offset_impl,
             &mlx_io_vtable_file::write_impl,
             &mlx_io_vtable_file::label_impl}) {};
};

class CReader : public mlx::core::io::Reader {
 public:
  void* desc;
  mlx_io_vtable vtable;

  CReader(void* desc, mlx_io_vtable vtable) : desc(desc), vtable(vtable) {};
  virtual bool is_open() const override {
    return vtable.is_open(desc);
  };
  CReader(FILE* desc) : desc(desc), vtable(mlx_io_vtable_file()) {};
  virtual bool good() const override {
    return vtable.good(desc);
  };
  virtual size_t tell() override {
    return vtable.tell(desc);
  }
  virtual void seek(
      int64_t off,
      std::ios_base::seekdir way = std::ios_base::beg) override {
    switch (way) {
      case std::ios_base::beg:
        return vtable.seek(desc, off, SEEK_SET);
        break;
      case std::ios_base::cur:
        return vtable.seek(desc, off, SEEK_CUR);
        break;
      case std::ios_base::end:
        return vtable.seek(desc, off, SEEK_END);
        break;
      default:
        throw std::runtime_error("mlx_io_reader: invalid seek way");
    }
  }
  virtual void read(char* data, size_t n) override {
    return vtable.read(desc, data, n);
  };
  virtual void read(char* data, size_t n, size_t offset) override {
    return vtable.read_at_offset(desc, data, n, offset);
  };
  virtual std::string label() const override {
    return vtable.label(desc);
  };
};

class CWriter : public mlx::core::io::Writer {
 public:
  void* desc;
  mlx_io_vtable vtable;

  CWriter(void* desc, mlx_io_vtable vtable) : desc(desc), vtable(vtable) {};
  CWriter(FILE* desc) : desc(desc), vtable(mlx_io_vtable_file()) {};
  virtual bool is_open() const override {
    return vtable.is_open(desc);
  };
  virtual bool good() const override {
    return vtable.good(desc);
  };
  virtual size_t tell() override {
    return vtable.tell(desc);
  }
  virtual void seek(
      int64_t off,
      std::ios_base::seekdir way = std::ios_base::beg) override {
    switch (way) {
      case std::ios_base::beg:
        return vtable.seek(desc, off, SEEK_SET);
        break;
      case std::ios_base::cur:
        return vtable.seek(desc, off, SEEK_CUR);
        break;
      case std::ios_base::end:
        return vtable.seek(desc, off, SEEK_END);
        break;
      default:
        throw std::runtime_error("mlx_io_writer: invalid seek way");
    }
  }
  virtual void write(const char* data, size_t n) override {
    return vtable.write(desc, data, n);
  };
  virtual std::string label() const override {
    return vtable.label(desc);
  };
};

struct creader_holder {
  std::shared_ptr<CReader> ptr;
};

inline mlx_io_reader mlx_io_reader_new_(void* uctx, mlx_io_vtable vtable) {
  return mlx_io_reader(
      {new creader_holder({std::make_shared<CReader>(uctx, vtable)})});
}

inline std::shared_ptr<CReader> mlx_io_reader_get_(mlx_io_reader d) {
  if (!d.ctx) {
    throw std::runtime_error("expected a non-empty mlx_io_reader");
  }
  return static_cast<creader_holder*>(d.ctx)->ptr;
}

inline void mlx_io_reader_free_(mlx_io_reader io) {
  if (io.ctx) {
    delete static_cast<creader_holder*>(io.ctx);
  }
}

class CFILEReader : public mlx::core::io::Reader {
 private:
  FILE* f;

 public:
  CFILEReader(FILE* f) : f(f) {};
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

inline std::shared_ptr<CWriter> mlx_io_writer_get_(mlx_io_writer d) {
  if (!d.ctx) {
    throw std::runtime_error("expected a non-empty mlx_io_writer");
  }
  return *static_cast<std::shared_ptr<CWriter>*>(d.ctx);
}

class CFILEWriter : public mlx::core::io::Writer {
 private:
  FILE* f;

 public:
  CFILEWriter(FILE* f) : f(f) {};
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
