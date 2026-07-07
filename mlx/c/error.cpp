/* Copyright © 2023-2024 Apple Inc. */

#include "mlx/c/error.h"

#include <memory>
#include <string>
#include <vector>

#include <cstdarg>
#include <cstdio>
#include <cstdlib>

/* ---------------------------------------------------------------------------
 * Legacy handler (unchanged behaviour).
 * ------------------------------------------------------------------------- */

static void mlx_error_handler_default_(const char* msg, void* data) {
  printf("MLX error: %s\n", msg);
  exit(-1);
}

static std::shared_ptr<void> mlx_error_handler_data_ = nullptr;
static mlx_error_handler_func mlx_error_handler_ = mlx_error_handler_default_;

extern "C" void mlx_set_error_handler(
    mlx_error_handler_func handler,
    void* data,
    void (*dtor)(void*)) {
  if (dtor) {
    mlx_error_handler_data_ = std::shared_ptr<void>(data, dtor);
  } else {
    mlx_error_handler_data_ = nullptr;
  }
  if (handler) {
    mlx_error_handler_ = handler;
  } else {
    mlx_error_handler_ = mlx_error_handler_default_;
  }
}

/* ---------------------------------------------------------------------------
 * Thread-local structured error state.
 * ------------------------------------------------------------------------- */

namespace {

struct mlx_thread_error_state {
  mlx_error_code code = MLX_ERROR_NONE;
  std::string message;
};

// Each thread owns its slot: an error raised while evaluating on a Metal
// completion thread or a DispatchQueue worker is stored on *that* thread and
// read back through the status code by whoever synchronizes on it.
thread_local mlx_thread_error_state g_last_error;

// Until mx::core exposes typed exceptions, a raw std::runtime_error may still
// be an allocation or I/O failure. Refine the classification from the message
// so callers can distinguish recoverable OOM from a programmer shape bug.
mlx_error_code refine_code(mlx_error_code code, const std::string& msg) {
  if (code != MLX_ERROR_RUNTIME) {
    return code;
  }
  if (msg.find("[metal::malloc]") != std::string::npos ||
      msg.find("out of memory") != std::string::npos ||
      msg.find("Out of memory") != std::string::npos ||
      msg.find("bad_alloc") != std::string::npos) {
    return MLX_ERROR_OUT_OF_MEMORY;
  }
  if (msg.find("[load]") != std::string::npos ||
      msg.find("[save]") != std::string::npos ||
      msg.find("Failed to open") != std::string::npos ||
      msg.find("safetensors") != std::string::npos ||
      msg.find("GGUF") != std::string::npos) {
    return MLX_ERROR_IO;
  }
  return code;
}

} // namespace

extern "C" mlx_error_code mlx_last_error_code(void) {
  return g_last_error.code;
}

extern "C" const char* mlx_last_error_message(void) {
  return g_last_error.message.c_str();
}

extern "C" void mlx_clear_last_error(void) {
  g_last_error.code = MLX_ERROR_NONE;
  g_last_error.message.clear();
}

/* ---------------------------------------------------------------------------
 * Emitters. _mlx_error is the legacy entry point; _mlx_error_with_code is the
 * classified entry point generated bindings now call. Both format identically
 * and both record the thread-local slot before invoking the legacy handler, so
 * existing handler-based code keeps working while new bindings pull structured
 * state.
 * ------------------------------------------------------------------------- */

static std::string mlx_format_message(
    const char* file,
    const int line,
    const char* fmt,
    va_list args) {
  va_list args_copy;
  va_copy(args_copy, args);
  int size = vsnprintf(nullptr, 0, fmt, args_copy);
  va_end(args_copy);
  int size_loc = snprintf(nullptr, 0, " at %s:%d", file, line);

  std::vector<char> msg(size + size_loc + 1); // \0 at the end
  size = vsnprintf(msg.data(), size + 1, fmt, args);
  snprintf(msg.data() + size, size_loc + 1, " at %s:%d", file, line);
  return std::string(msg.data());
}

extern "C" void
_mlx_error(const char* file, const int line, const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  std::string msg = mlx_format_message(file, line, fmt, args);
  va_end(args);

  g_last_error.code = MLX_ERROR_RUNTIME;
  g_last_error.message = msg;
  mlx_error_handler_(msg.c_str(), mlx_error_handler_data_.get());
}

extern "C" void _mlx_error_with_code(
    mlx_error_code code,
    const char* file,
    const int line,
    const char* fmt,
    ...) {
  va_list args;
  va_start(args, fmt);
  std::string msg = mlx_format_message(file, line, fmt, args);
  va_end(args);

  g_last_error.code = refine_code(code, msg);
  g_last_error.message = msg;
  mlx_error_handler_(msg.c_str(), mlx_error_handler_data_.get());
}
