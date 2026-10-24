/* Copyright © 2023-2024 Apple Inc. */

#include <cstring>

#include "mlx/c/distributed_group.h"
#include "mlx/c/error.h"
#include "mlx/c/private/mlx.h"

extern "C" mlx_distributed_group mlx_distributed_group_new(void) {
  try {
    return mlx_distributed_group_new_();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return {nullptr};
  }
}

extern "C" int mlx_distributed_group_free(mlx_distributed_group group) {
  try {
    mlx_distributed_group_free_(group);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int
mlx_distributed_init(mlx_distributed_group* res, bool strict, const char* bk) {
  try {
    if (bk) {
      mlx_distributed_group_set_(
          *res, mlx::core::distributed::init(strict, bk));
    } else {
      mlx_distributed_group_set_(*res, mlx::core::distributed::init(strict));
    }
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" int mlx_distributed_init_with_all_gather(
    mlx_distributed_group* res,
    bool strict,
    const char* bk,
    mlx_distributed_all_gather_fn all_gather,
    void* payload,
    void (*dtor)(void*)) {
  try {
    // Take ownership before validation so failures release the payload.
    std::shared_ptr<void> owner;
    if (dtor) {
      owner = std::shared_ptr<void>(payload, dtor);
    } else {
      owner = std::shared_ptr<void>(payload, [](void*) {});
    }

    if (!res) {
      throw std::invalid_argument("group output must not be null");
    }
    if (!bk) {
      throw std::invalid_argument("backend must not be null");
    }
    if (!all_gather) {
      throw std::invalid_argument("all-gather callback must not be null");
    }

    mlx::core::distributed::AllGatherFactory factory =
        [all_gather, owner](
            int rank, int size) -> mlx::core::distributed::AllGatherFn {
      return [all_gather, owner, rank, size](
                 const char* src, char* dst, size_t n_bytes) {
        if (all_gather(rank, size, src, dst, n_bytes, owner.get()) != 0) {
          throw std::runtime_error("all-gather callback returned an error");
        }
      };
    };

    mlx_distributed_group_set_(
        *res, mlx::core::distributed::init(strict, bk, std::move(factory)));

    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" int mlx_distributed_clear_backends(void) {
  try {
    mlx::core::distributed::clear_backends();
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" int mlx_distributed_group_get_rank(
    int* res,
    mlx_distributed_group group) {
  try {
    if (!res) {
      throw std::invalid_argument("rank output must not be null");
    }
    *res = mlx_distributed_group_get_(group).rank();
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" int mlx_distributed_group_get_size(
    int* res,
    mlx_distributed_group group) {
  try {
    if (!res) {
      throw std::invalid_argument("size output must not be null");
    }
    *res = mlx_distributed_group_get_(group).size();
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" int mlx_distributed_group_split(
    mlx_distributed_group* res,
    mlx_distributed_group group,
    int color,
    int key) {
  try {
    mlx_distributed_group_set_(
        *res, mlx_distributed_group_get_(group).split(color, key));
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" bool mlx_distributed_is_available(const char* bk) {
  try {
    if (bk) {
      return mlx::core::distributed::is_available(bk);
    } else {
      return mlx::core::distributed::is_available();
    }
  } catch (std::exception& e) {
    mlx_error(e.what());
    return false;
  }
}
