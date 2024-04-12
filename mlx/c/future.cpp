/* Copyright © 2023-2024 Apple Inc. */

#include "mlx/c/private/future.h"
#include "mlx/c/private/string.h"

mlx_string_* mlx_future_::tostring() {
  std::ostringstream os;
  os << "0x" << std::hex << &ctx;
  std::string str = os.str();
  return new mlx_string_(str);
}

extern "C" void mlx_future_wait(mlx_future future) {
  future->ctx.wait();
}
