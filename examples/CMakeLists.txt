add_executable(example ${CMAKE_CURRENT_LIST_DIR}/example.c)
target_link_libraries(example PUBLIC mlxc)

add_executable(example-grad ${CMAKE_CURRENT_LIST_DIR}/example-grad.c)
target_link_libraries(example-grad PUBLIC mlxc)

add_executable(example-safe-tensors
               ${CMAKE_CURRENT_LIST_DIR}/example-safe-tensors.c)
target_link_libraries(example-safe-tensors PUBLIC mlxc)
