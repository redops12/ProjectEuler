cmake_minimum_required(VERSION 3.10)

# Set project name and version
project(ProjectEulerSolutions VERSION 1.0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
add_compile_options("-Wall" "-Wextra")
set(CMAKE_COMPILE_WARNING_AS_ERROR on)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -g -fno-omit-frame-pointer")

add_subdirectory(lib)

# Testing
include(CTest)

add_executable( tests solutions/tests.cpp )
target_link_libraries( tests PRIVATE lib )
add_test(NAME tests COMMAND tests)

include(solutions.cmake)
