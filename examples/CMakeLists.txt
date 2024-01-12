add_executable(example ${CMAKE_CURRENT_LIST_DIR}/example.c)
target_link_libraries(example PUBLIC mlxc)

add_executable(example-jvp ${CMAKE_CURRENT_LIST_DIR}/example-jvp.c)
target_link_libraries(example-jvp PUBLIC mlxc)
