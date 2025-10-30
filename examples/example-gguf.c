/* Copyright © 2023-2024 Apple Inc. */

#include <stdio.h>
#include "mlx/c/mlx.h"

void print_array(const char* msg, mlx_array arr) {
  mlx_string str = mlx_string_new();
  mlx_array_tostring(&str, arr);
  printf("%s\n%s\n", msg, mlx_string_data(str));
  mlx_string_free(str);
}

int main(void) {
  mlx_stream stream = mlx_default_cpu_stream_new();

  printf("=== GGUF Save Example ===\n\n");

  // Create some test arrays
  mlx_map_string_to_array arrays = mlx_map_string_to_array_new();

  // Create a simple array
  float data1[] = {1.0f, 2.0f, 3.0f, 4.0f};
  int shape1[] = {2, 2};
  mlx_array arr1 = mlx_array_new_data(data1, shape1, 2, MLX_FLOAT32);
  mlx_map_string_to_array_insert(arrays, "weights", arr1);

  float data2[] = {0.5f, 0.5f};
  int shape2[] = {2};
  mlx_array arr2 = mlx_array_new_data(data2, shape2, 1, MLX_FLOAT32);
  mlx_map_string_to_array_insert(arrays, "bias", arr2);

  // Create metadata
  mlx_map_string_to_gguf_metadata metadata =
      mlx_map_string_to_gguf_metadata_new();

  // Add string metadata
  mlx_gguf_metadata meta_str = mlx_gguf_metadata_new_string("test model");
  mlx_map_string_to_gguf_metadata_insert(metadata, "model.name", meta_str);

  mlx_gguf_metadata meta_version = mlx_gguf_metadata_new_string("1.0");
  mlx_map_string_to_gguf_metadata_insert(
      metadata, "model.version", meta_version);

  // Add array metadata
  float meta_data[] = {1.0f, 2.0f, 3.0f};
  int meta_shape[] = {3};
  mlx_array meta_arr =
      mlx_array_new_data(meta_data, meta_shape, 1, MLX_FLOAT32);
  mlx_gguf_metadata meta_array = mlx_gguf_metadata_new_array(meta_arr);
  mlx_map_string_to_gguf_metadata_insert(metadata, "model.params", meta_array);

  // Add string vector metadata
  const char* layers[] = {"layer1", "layer2", "layer3"};
  mlx_vector_string str_vec = mlx_vector_string_new_data(layers, 3);
  mlx_gguf_metadata meta_vec = mlx_gguf_metadata_new_string_vector(str_vec);
  mlx_map_string_to_gguf_metadata_insert(metadata, "model.layers", meta_vec);

  // Save GGUF file
  printf("Saving GGUF file...\n");
  int err = mlx_save_gguf("test_model.gguf", arrays, metadata);
  if (err != 0) {
    printf("Error saving GGUF file\n");
    return 1;
  }
  printf("Saved successfully!\n\n");

  // Clean up
  mlx_gguf_metadata_free(meta_str);
  mlx_gguf_metadata_free(meta_version);
  mlx_gguf_metadata_free(meta_array);
  mlx_gguf_metadata_free(meta_vec);
  mlx_array_free(arr1);
  mlx_array_free(arr2);
  mlx_array_free(meta_arr);
  mlx_vector_string_free(str_vec);
  mlx_map_string_to_array_free(arrays);
  mlx_map_string_to_gguf_metadata_free(metadata);

  printf("=== GGUF Load Example ===\n\n");

  // Load GGUF file
  mlx_map_string_to_array loaded_arrays = mlx_map_string_to_array_new();
  mlx_map_string_to_gguf_metadata loaded_metadata =
      mlx_map_string_to_gguf_metadata_new();

  printf("Loading GGUF file...\n");
  err = mlx_load_gguf(
      &loaded_arrays, &loaded_metadata, "test_model.gguf", stream);
  if (err != 0) {
    printf("Error loading GGUF file\n");
    return 1;
  }
  printf("Loaded successfully!\n\n");

  // Print loaded arrays
  printf("Loaded arrays:\n");
  mlx_map_string_to_array_iterator arr_it =
      mlx_map_string_to_array_iterator_new(loaded_arrays);
  const char* arr_key;
  mlx_array arr_value = mlx_array_new();
  while (!mlx_map_string_to_array_iterator_next(&arr_key, &arr_value, arr_it)) {
    print_array(arr_key, arr_value);
  }

  // Print loaded metadata
  printf("\nLoaded metadata:\n");
  mlx_map_string_to_gguf_metadata_iterator meta_it =
      mlx_map_string_to_gguf_metadata_iterator_new(loaded_metadata);
  const char* meta_key;
  mlx_gguf_metadata meta_value = {NULL};
  while (!mlx_map_string_to_gguf_metadata_iterator_next(
      &meta_key, &meta_value, meta_it)) {
    mlx_gguf_metadata_type type = mlx_gguf_metadata_get_type(meta_value);
    printf("  %s: ", meta_key);

    if (type == MLX_GGUF_METADATA_STRING) {
      mlx_string str = mlx_string_new();
      if (mlx_gguf_metadata_get_string(&str, meta_value) == 0) {
        printf("(string) %s\n", mlx_string_data(str));
        mlx_string_free(str);
      }
    } else if (type == MLX_GGUF_METADATA_ARRAY) {
      mlx_array arr = mlx_array_new();
      if (mlx_gguf_metadata_get_array(&arr, meta_value) == 0) {
        printf("(array) ");
        mlx_string str = mlx_string_new();
        mlx_array_tostring(&str, arr);
        printf("%s\n", mlx_string_data(str));
        mlx_string_free(str);
        mlx_array_free(arr);
      }
    } else if (type == MLX_GGUF_METADATA_STRING_VECTOR) {
      mlx_vector_string vec = mlx_vector_string_new();
      if (mlx_gguf_metadata_get_string_vector(&vec, meta_value) == 0) {
        printf("(string vector) [");
        size_t size = mlx_vector_string_size(vec);
        for (size_t i = 0; i < size; i++) {
          char* s;
          mlx_vector_string_get(&s, vec, i);
          printf("%s%s", s, i < size - 1 ? ", " : "");
        }
        printf("]\n");
        mlx_vector_string_free(vec);
      }
    } else {
      printf("(unknown type)\n");
    }

    mlx_gguf_metadata_free(meta_value);
  }

  // Clean up
  mlx_array_free(arr_value);
  mlx_map_string_to_array_iterator_free(arr_it);
  mlx_map_string_to_gguf_metadata_iterator_free(meta_it);
  mlx_map_string_to_array_free(loaded_arrays);
  mlx_map_string_to_gguf_metadata_free(loaded_metadata);
  mlx_stream_free(stream);

  printf("\nExample completed successfully!\n");
  return 0;
}
