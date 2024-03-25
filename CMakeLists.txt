# Copyright © 2023-2024 Apple Inc.

cmake_minimum_required(VERSION 3.16)

# ----------------------------- Setup -----------------------------
project(mlx.data LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 17)

# ----------------------------- Configuration -----------------------------
if(NOT MLX_C_VERSION)
  set(MLX_C_VERSION 0.0.5)
endif()

option(MLX_C_BUILD_EXAMPLES "Build examples for mlx C" ON)

# ----------------------------- mlx -----------------------------

include(FetchContent)
# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24:
if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

# mlx
set(MLX_BUILD_TESTS OFF)
set(MLX_BUILD_EXAMPLES OFF)
set(MLX_BUILD_BENCHMARKS "Build benchmarks for mlx" OFF)
set(MLX_BUILD_PYTHON_BINDINGS OFF)
set(MLX_BUILD_METAL ON)
FetchContent_Declare(
  mlx
  GIT_REPOSITORY "https://github.com/ml-explore/mlx.git"
  GIT_TAG v0.8.1)
FetchContent_MakeAvailable(mlx)

# ----------------------------- lib -----------------------------

set(mlxc-src
    ${CMAKE_CURRENT_LIST_DIR}/mlx/c/array.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mlx/c/closure.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mlx/c/compile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mlx/c/device.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mlx/c/fast.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mlx/c/fft.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mlx/c/io.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mlx/c/ioutils.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mlx/c/linalg.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mlx/c/map.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mlx/c/metal.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mlx/c/object.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mlx/c/ops.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mlx/c/random.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mlx/c/stream.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mlx/c/string.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mlx/c/transforms.cpp
    ${CMAKE_CURRENT_LIST_DIR}/mlx/c/transforms_impl.cpp)

add_library(mlxc STATIC ${mlxc-src})

target_link_libraries(mlxc PRIVATE mlx)
target_include_directories(mlxc
                           PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>)
set_property(TARGET mlxc PROPERTY POSITION_INDEPENDENT_CODE ON)

if(MLX_C_BUILD_EXAMPLES)
  add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/examples)
endif()

# ----------------------------- Installation -----------------------------
include(GNUInstallDirs)

# Install library
install(
  TARGETS mlxc
  EXPORT MLXCTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Install headers
install(
  DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/mlx
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  COMPONENT headers
  FILES_MATCHING
  PATTERN "*.h"
  PATTERN "private" EXCLUDE)

# Install cmake config
set(MLX_C_CMAKE_BUILD_CONFIG ${CMAKE_BINARY_DIR}/MLXCConfig.cmake)
set(MLX_C_CMAKE_BUILD_VERSION_CONFIG
    ${CMAKE_BINARY_DIR}/MLXCConfigVersion.cmake)
set(MLX_C_CMAKE_INSTALL_MODULE_DIR share/cmake/MLXC)

install(
  EXPORT MLXCTargets
  FILE MLXCTargets.cmake
  DESTINATION ${MLX_C_CMAKE_INSTALL_MODULE_DIR})

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
  ${MLX_C_CMAKE_BUILD_VERSION_CONFIG}
  COMPATIBILITY SameMajorVersion
  VERSION ${MLX_C_VERSION})

configure_package_config_file(
  ${CMAKE_CURRENT_LIST_DIR}/mlx-c.pc.in ${MLX_C_CMAKE_BUILD_CONFIG}
  INSTALL_DESTINATION ${MLX_C_CMAKE_INSTALL_MODULE_DIR}
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
  PATH_VARS CMAKE_INSTALL_LIBDIR CMAKE_INSTALL_INCLUDEDIR
            MLX_C_CMAKE_INSTALL_MODULE_DIR)

install(FILES ${MLX_C_CMAKE_BUILD_CONFIG} ${MLX_C_CMAKE_BUILD_VERSION_CONFIG}
        DESTINATION ${MLX_C_CMAKE_INSTALL_MODULE_DIR})
