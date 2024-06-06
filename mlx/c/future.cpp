/* Copyright © 2023-2024 Apple Inc. */

#include "mlx/c/private/future.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"

mlx_string_* mlx_future_::tostring() {
  MLX_TRY_CATCH(std::ostringstream os; os << "0x" << std::hex << &ctx;
                std::string str = os.str();
                return new mlx_string_(str), return nullptr);
}

extern "C" void mlx_future_wait(mlx_future future) {
  MLX_TRY_CATCH(future->ctx.wait(), );
}
