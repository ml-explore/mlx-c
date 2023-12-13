#ifndef MLX_OBJECT_PRIVATE_H
#define MLX_OBJECT_PRIVATE_H

#include <atomic>

struct mlx_object_ {
  mlx_object_() : refcount(1){};
  virtual char* tostring() = 0;
  virtual ~mlx_object_(){};
  std::atomic<std::uint64_t> refcount;
};

#endif
