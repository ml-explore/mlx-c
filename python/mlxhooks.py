def mlx_metal_device_info(f, implementation):
    if implementation:
        print(
            """
mlx_metal_device_info_t mlx_metal_device_info() {
  auto info = mlx::core::metal::device_info();

  mlx_metal_device_info_t c_info;
  std::strncpy(c_info.architecture, std::get<std::string>(info["architecture"]).c_str(), 256);
  c_info.max_buffer_length = std::get<size_t>(info["max_buffer_length"]);
  c_info.max_recommended_working_set_size = std::get<size_t>(info["max_recommended_working_set_size"]);
  c_info.memory_size = std::get<size_t>(info["memory_size"]);
  return c_info;
}
        """
        )
    else:
        print(
            """
typedef struct mlx_metal_device_info_t_ {
  char architecture[256];
  size_t max_buffer_length;
  size_t max_recommended_working_set_size;
  size_t memory_size;
} mlx_metal_device_info_t;
mlx_metal_device_info_t mlx_metal_device_info();
        """
        )


def mlx_fast_metal_kernel(f, implementation):
    if implementation:
        print(
            """
extern "C" int mlx_fast_metal_kernel_add_output_arg(mlx_fast_metal_kernel cls, const int* shape, size_t size, mlx_dtype dtype) {
  try {
    cls->output_shapes.push_back(std::vector<int>(shape, shape+size));
    cls->output_dtypes.push_back(mlx_dtype_to_cpp(dtype));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_grid(mlx_fast_metal_kernel cls, int grid1, int grid2, int grid3) {
  try {
    cls->grid = std::make_tuple(grid1, grid2, grid3);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_thread_group(mlx_fast_metal_kernel cls, int thread1, int thread2, int thread3) {
  try {
    cls->thread_group = std::make_tuple(thread1, thread2, thread3);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_init_value(mlx_fast_metal_kernel cls, float value){
  try {
    cls->init_value = value;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_verbose(mlx_fast_metal_kernel cls, bool verbose) {
  try {
    cls->verbose = verbose;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_add_template_arg_dtype(mlx_fast_metal_kernel cls, const char* name, mlx_dtype dtype) {
  try {
    cls->template_args.push_back(std::make_pair(std::string(name), mlx_dtype_to_cpp(dtype)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_add_template_arg_int(mlx_fast_metal_kernel cls, const char *name, int value) {
  try {
    cls->template_args.push_back(std::make_pair(std::string(name), value));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_add_template_arg_bool(mlx_fast_metal_kernel cls, const char* name, bool value)  {
  try {
    cls->template_args.push_back(std::make_pair(std::string(name), value));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

mlx_string_* mlx_fast_metal_kernel_::tostring() {
  RETURN_MLX_C_STRING(
      "mlx_fast_metal_kernel_");
}

extern "C" mlx_fast_metal_kernel mlx_fast_metal_kernel_new(const char* name, const char* source, const char* header) {
  try {
    return new mlx_fast_metal_kernel_(name, source, header);
  } catch (std::exception& e) {
    mlx_error(e.what());
  }
  return nullptr;
}
extern "C" int mlx_fast_metal_kernel_set_input_names(mlx_fast_metal_kernel cls, int num, ...) {
  try {
    va_list input_names;
    va_start(input_names, num);
    cls->input_names.clear();
    for(int i = 0; i < num; i++) {
      cls->input_names.push_back(va_arg(input_names, const char*));
    }
    va_end(input_names);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_output_names(mlx_fast_metal_kernel cls, int num, ...) {
  try {
    va_list output_names;
    va_start(output_names, num);
    cls->output_names.clear();
    for(int i = 0; i < num; i++) {
      cls->output_names.push_back(va_arg(output_names, const char*));
    }
    va_end(output_names);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_contiguous_rows(mlx_fast_metal_kernel cls, bool flag) {
  cls->contiguous_rows = flag;
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_atomic_outputs(mlx_fast_metal_kernel cls, bool flag) {
  cls->atomic_outputs = flag;
  return 0;
}
extern "C" int mlx_fast_metal_kernel_apply(mlx_fast_metal_kernel cls, const mlx_vector_array inputs, const mlx_stream stream, mlx_vector_array outputs) {
  try {
    if(!cls->ctx) {
      cls->ctx = mlx::core::fast::metal_kernel(cls->name, cls->input_names, cls->output_names, cls->source, cls->header, cls->contiguous_rows, cls->atomic_outputs);
    }
    outputs->ctx = cls->ctx(inputs->ctx, cls->output_shapes, cls->output_dtypes, cls->grid, cls->thread_group, cls->template_args, cls->init_value, cls->verbose, stream->ctx);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
        """
        )
    else:
        print(
            """
typedef struct mlx_fast_metal_kernel_* mlx_fast_metal_kernel;
mlx_fast_metal_kernel mlx_fast_metal_kernel_new(const char* name, const char* source, const char* header);
int mlx_fast_metal_kernel_set_input_names(mlx_fast_metal_kernel cls, int num, ...);
int mlx_fast_metal_kernel_set_output_names(mlx_fast_metal_kernel cls, int num, ...);
int mlx_fast_metal_kernel_set_contiguous_rows(mlx_fast_metal_kernel cls, bool flag);
int mlx_fast_metal_kernel_set_atomic_outputs(mlx_fast_metal_kernel cls, bool flag);

int mlx_fast_metal_kernel_add_output_arg(mlx_fast_metal_kernel cls, const int* shape, size_t size, mlx_dtype dtype);
int mlx_fast_metal_kernel_set_grid(mlx_fast_metal_kernel cls, int grid1, int grid2, int grid3);
int mlx_fast_metal_kernel_set_thread_group(mlx_fast_metal_kernel cls, int thread1, int thread2, int thread3);
int mlx_fast_metal_kernel_set_init_value(mlx_fast_metal_kernel cls, float value);
int mlx_fast_metal_kernel_set_verbose(mlx_fast_metal_kernel cls, bool verbose);
int mlx_fast_metal_kernel_add_template_arg_dtype(mlx_fast_metal_kernel cls, const char* name, mlx_dtype dtype);
int mlx_fast_metal_kernel_add_template_arg_int(mlx_fast_metal_kernel cls, const char* name, int value);
int mlx_fast_metal_kernel_add_template_arg_bool(mlx_fast_metal_kernel cls, const char* name, bool value);

int mlx_fast_metal_kernel_apply(mlx_fast_metal_kernel cls, const mlx_vector_array inputs, const mlx_stream stream, mlx_vector_array outputs);
        """
        )
