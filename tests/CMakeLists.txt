# ctest -VV
include(CTest)

# Catch2 cmake helper functions
include(${PROJECT_SOURCE_DIR}/contrib/Catch2/contrib/Catch.cmake)

set(TARGET_NAME run_tests)

# add test sources here ... 
add_executable(${TARGET_NAME}
        runner_tests.cpp
        linked_stack_tests.cpp
        array_stack_tests.cpp
        linked_queue_tests.cpp
        linked_dequeue_tests.cpp)

target_sources(${TARGET_NAME} PRIVATE utils.hpp)

target_link_libraries(${TARGET_NAME} PRIVATE adt)
target_link_libraries(${TARGET_NAME} PRIVATE Catch2::Catch2)

# FakeIt
target_include_directories(${TARGET_NAME} PRIVATE
        ${PROJECT_SOURCE_DIR}/contrib/FakeIt/single_header/catch)

# discover tests for CTest
catch_discover_tests(${TARGET_NAME} EXTRA_ARGS -r console --abort)
