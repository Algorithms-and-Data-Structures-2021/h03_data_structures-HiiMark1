set(ADT_LIBRARY adt)

add_library(${ADT_LIBRARY} STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/array_stack.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/linked_stack.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/linked_queue.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/linked_dequeue.cpp)

target_sources(${ADT_LIBRARY}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include/linked_stack.hpp
        ${PROJECT_SOURCE_DIR}/include/array_stack.hpp
        ${PROJECT_SOURCE_DIR}/include/linked_queue.hpp
        ${PROJECT_SOURCE_DIR}/include/linked_dequeue.hpp)

target_include_directories(${ADT_LIBRARY} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# setting up compiler options
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(ADT_COMPILE_OPTS "-pipe;-fpie;-Werror;-Wall;-Wextra;-Wpedantic;-Wshadow;-Wno-unused-parameter")
    set(ADT_DEBUG_COMPILE_OPTS "-g;${ADT_COMPILE_OPTS}")
    set(ADT_RELEASE_COMPILE_OPTS "-O2;${ADT_COMPILE_OPTS}")

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # using Visual Studio C++
endif ()

target_compile_options(${ADT_LIBRARY} PUBLIC ${ADT_DEBUG_COMPILE_OPTS})