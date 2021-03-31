add_library(io_definitions INTERFACE)
target_compile_definitions(io_definitions INTERFACE CURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(stack_io_test stack_io_test.cpp cmd_reader.hpp)
target_link_libraries(stack_io_test PRIVATE adt io_definitions)

add_executable(queue_io_test queue_io_test.cpp cmd_reader.hpp)
target_link_libraries(queue_io_test PRIVATE adt io_definitions)

add_executable(deque_io_test deque_io_test.cpp cmd_reader.hpp)
target_link_libraries(deque_io_test PRIVATE adt io_definitions)

