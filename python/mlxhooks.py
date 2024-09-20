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
