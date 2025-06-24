cmake_minimum_required(VERSION 3.10)

# Set project name and version
project(ProjectEulerSolutions VERSION 1.0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
add_compile_options("-Wall" "-Wextra" "-Wno-stringop-overflow" "-Wno-array-bounds" "-Wno-stringop-overread")
set(CMAKE_COMPILE_WARNING_AS_ERROR off)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -g -fno-omit-frame-pointer")

add_subdirectory(lib)

# Testing
include(CTest)

add_executable( tests solutions/tests.cpp )
target_link_libraries( tests PRIVATE lib )
add_test(NAME tests COMMAND tests)

add_executable( first_prime solutions/first_prime.cpp )
target_link_libraries( first_prime  PRIVATE lib )
add_test(NAME first_prime  COMMAND first_prime )

include(solutions.cmake)
