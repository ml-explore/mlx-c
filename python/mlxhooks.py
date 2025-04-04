def mlx_metal_device_info(f, implementation):
    if implementation:
        print(
            """
mlx_metal_device_info_t mlx_metal_device_info() {
  auto info = mlx::core::metal::device_info();

  mlx_metal_device_info_t c_info;
  std::strncpy(
      c_info.architecture,
      std::get<std::string>(info["architecture"]).c_str(),
      256);
  c_info.max_buffer_length = std::get<size_t>(info["max_buffer_length"]);
  c_info.max_recommended_working_set_size =
      std::get<size_t>(info["max_recommended_working_set_size"]);
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
struct mlx_fast_metal_kernel_private_ {
  mlx::core::fast::MetalKernelFunction ctx;
  std::string name;
  std::vector<std::string> input_names;
  std::vector<std::string> output_names;
  std::string source;
  std::string header;
  bool contiguous_rows;
  bool atomic_outputs;

  std::vector<std::vector<int>> output_shapes;
  std::vector<mlx::core::Dtype> output_dtypes;
  std::tuple<int, int, int> grid;
  std::tuple<int, int, int> thread_group;
  std::vector<std::pair<std::string, mlx::core::fast::TemplateArg>>
      template_args;
  std::optional<float> init_value;
  bool verbose;
};

inline mlx_fast_metal_kernel mlx_fast_metal_kernel_new_() {
  return mlx_fast_metal_kernel({new mlx_fast_metal_kernel_private_()});
}

inline mlx_fast_metal_kernel_private_& mlx_fast_metal_kernel_get_(
    mlx_fast_metal_kernel d) {
  return *static_cast<mlx_fast_metal_kernel_private_*>(d.ctx);
}

inline void mlx_fast_metal_kernel_free_(mlx_fast_metal_kernel d) {
  if (d.ctx) {
    delete static_cast<mlx_fast_metal_kernel_private_*>(d.ctx);
  }
}

extern "C" void mlx_fast_metal_kernel_free(mlx_fast_metal_kernel cls) {
  mlx_fast_metal_kernel_free_(cls);
}

extern "C" int mlx_fast_metal_kernel_add_output_arg(
    mlx_fast_metal_kernel cls,
    const int* shape,
    size_t size,
    mlx_dtype dtype) {
  try {
    mlx_fast_metal_kernel_get_(cls).output_shapes.push_back(
        std::vector<int>(shape, shape + size));
    mlx_fast_metal_kernel_get_(cls).output_dtypes.push_back(
        mlx_dtype_to_cpp(dtype));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_grid(
    mlx_fast_metal_kernel cls,
    int grid1,
    int grid2,
    int grid3) {
  try {
    mlx_fast_metal_kernel_get_(cls).grid = std::make_tuple(grid1, grid2, grid3);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_thread_group(
    mlx_fast_metal_kernel cls,
    int thread1,
    int thread2,
    int thread3) {
  try {
    mlx_fast_metal_kernel_get_(cls).thread_group =
        std::make_tuple(thread1, thread2, thread3);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_init_value(
    mlx_fast_metal_kernel cls,
    float value) {
  try {
    mlx_fast_metal_kernel_get_(cls).init_value = value;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_verbose(
    mlx_fast_metal_kernel cls,
    bool verbose) {
  try {
    mlx_fast_metal_kernel_get_(cls).verbose = verbose;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_add_template_arg_dtype(
    mlx_fast_metal_kernel cls,
    const char* name,
    mlx_dtype dtype) {
  try {
    mlx_fast_metal_kernel_get_(cls).template_args.push_back(
        std::make_pair(std::string(name), mlx_dtype_to_cpp(dtype)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_add_template_arg_int(
    mlx_fast_metal_kernel cls,
    const char* name,
    int value) {
  try {
    mlx_fast_metal_kernel_get_(cls).template_args.push_back(
        std::make_pair(std::string(name), value));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_add_template_arg_bool(
    mlx_fast_metal_kernel cls,
    const char* name,
    bool value) {
  try {
    mlx_fast_metal_kernel_get_(cls).template_args.push_back(
        std::make_pair(std::string(name), value));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" mlx_fast_metal_kernel mlx_fast_metal_kernel_new(
    const char* name,
    const char* source,
    const char* header) {
  try {
    auto cls = mlx_fast_metal_kernel_new_();
    mlx_fast_metal_kernel_get_(cls).name = std::string(name);
    mlx_fast_metal_kernel_get_(cls).source = std::string(source);
    mlx_fast_metal_kernel_get_(cls).header = std::string(header);
    return cls;
  } catch (std::exception& e) {
    mlx_error(e.what());
  }
  return {nullptr};
}
extern "C" int mlx_fast_metal_kernel_add_input_name(
    mlx_fast_metal_kernel cls,
    const char* name) {
  try {
    mlx_fast_metal_kernel_get_(cls).input_names.push_back(name);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int
mlx_fast_metal_kernel_set_input_names(mlx_fast_metal_kernel cls, int num, ...) {
  try {
    va_list input_names;
    va_start(input_names, num);
    mlx_fast_metal_kernel_get_(cls).input_names.clear();
    for (int i = 0; i < num; i++) {
      mlx_fast_metal_kernel_get_(cls).input_names.push_back(
          va_arg(input_names, const char*));
    }
    va_end(input_names);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_add_output_name(
    mlx_fast_metal_kernel cls,
    const char* name) {
  try {
    mlx_fast_metal_kernel_get_(cls).output_names.push_back(name);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_output_names(
    mlx_fast_metal_kernel cls,
    int num,
    ...) {
  try {
    va_list output_names;
    va_start(output_names, num);
    mlx_fast_metal_kernel_get_(cls).output_names.clear();
    for (int i = 0; i < num; i++) {
      mlx_fast_metal_kernel_get_(cls).output_names.push_back(
          va_arg(output_names, const char*));
    }
    va_end(output_names);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_contiguous_rows(
    mlx_fast_metal_kernel cls,
    bool flag) {
  mlx_fast_metal_kernel_get_(cls).contiguous_rows = flag;
  return 0;
}
extern "C" int mlx_fast_metal_kernel_set_atomic_outputs(
    mlx_fast_metal_kernel cls,
    bool flag) {
  mlx_fast_metal_kernel_get_(cls).atomic_outputs = flag;
  return 0;
}
extern "C" int mlx_fast_metal_kernel_apply(
    mlx_vector_array* outputs,
    mlx_fast_metal_kernel cls,
    const mlx_vector_array inputs,
    const mlx_stream stream) {
  try {
    if (!mlx_fast_metal_kernel_get_(cls).ctx) {
      mlx_fast_metal_kernel_get_(cls).ctx = mlx::core::fast::metal_kernel(
          mlx_fast_metal_kernel_get_(cls).name,
          mlx_fast_metal_kernel_get_(cls).input_names,
          mlx_fast_metal_kernel_get_(cls).output_names,
          mlx_fast_metal_kernel_get_(cls).source,
          mlx_fast_metal_kernel_get_(cls).header,
          mlx_fast_metal_kernel_get_(cls).contiguous_rows,
          mlx_fast_metal_kernel_get_(cls).atomic_outputs);
    }
    mlx_vector_array_set_(
        *outputs,
        mlx_fast_metal_kernel_get_(cls).ctx(
            mlx_vector_array_get_(inputs),
            mlx_fast_metal_kernel_get_(cls).output_shapes,
            mlx_fast_metal_kernel_get_(cls).output_dtypes,
            mlx_fast_metal_kernel_get_(cls).grid,
            mlx_fast_metal_kernel_get_(cls).thread_group,
            mlx_fast_metal_kernel_get_(cls).template_args,
            mlx_fast_metal_kernel_get_(cls).init_value,
            mlx_fast_metal_kernel_get_(cls).verbose,
            mlx_stream_get_(stream)));
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
typedef struct mlx_fast_metal_kernel_ {
  void* ctx;
} mlx_fast_metal_kernel;
mlx_fast_metal_kernel mlx_fast_metal_kernel_new(
    const char* name,
    const char* source,
    const char* header);
void mlx_fast_metal_kernel_free(mlx_fast_metal_kernel cls);
int mlx_fast_metal_kernel_add_input_name(
    mlx_fast_metal_kernel cls,
    const char* name);
int mlx_fast_metal_kernel_set_input_names(
    mlx_fast_metal_kernel cls,
    int num,
    ...);
int mlx_fast_metal_kernel_add_output_name(
    mlx_fast_metal_kernel cls,
    const char* name);
int mlx_fast_metal_kernel_set_output_names(
    mlx_fast_metal_kernel cls,
    int num,
    ...);
int mlx_fast_metal_kernel_set_contiguous_rows(
    mlx_fast_metal_kernel cls,
    bool flag);
int mlx_fast_metal_kernel_set_atomic_outputs(
    mlx_fast_metal_kernel cls,
    bool flag);

int mlx_fast_metal_kernel_add_output_arg(
    mlx_fast_metal_kernel cls,
    const int* shape,
    size_t size,
    mlx_dtype dtype);
int mlx_fast_metal_kernel_set_grid(
    mlx_fast_metal_kernel cls,
    int grid1,
    int grid2,
    int grid3);
int mlx_fast_metal_kernel_set_thread_group(
    mlx_fast_metal_kernel cls,
    int thread1,
    int thread2,
    int thread3);
int mlx_fast_metal_kernel_set_init_value(
    mlx_fast_metal_kernel cls,
    float value);
int mlx_fast_metal_kernel_set_verbose(mlx_fast_metal_kernel cls, bool verbose);
int mlx_fast_metal_kernel_add_template_arg_dtype(
    mlx_fast_metal_kernel cls,
    const char* name,
    mlx_dtype dtype);
int mlx_fast_metal_kernel_add_template_arg_int(
    mlx_fast_metal_kernel cls,
    const char* name,
    int value);
int mlx_fast_metal_kernel_add_template_arg_bool(
    mlx_fast_metal_kernel cls,
    const char* name,
    bool value);
int mlx_fast_metal_kernel_clear_args(
    mlx_fast_metal_kernel cls);

int mlx_fast_metal_kernel_apply(
    mlx_vector_array* outputs,
    mlx_fast_metal_kernel cls,
    const mlx_vector_array inputs,
    const mlx_stream stream);
        """
        )
