# This is the top-level CMakeLists.txt file

cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(H03_data_structures)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# library (adt)
add_subdirectory(src)

# main
add_executable(main main.cpp)
target_link_libraries(main PRIVATE adt)

# dependencies
add_subdirectory(contrib)

# tests
enable_testing()
add_subdirectory(tests)
add_subdirectory(io_tests)
