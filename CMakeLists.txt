cmake_minimum_required(VERSION 3.10)

# Set project name and version
project(ProjectEulerSolutions VERSION 1.0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(lib)

# Solutions
add_executable( sol7 solutions/7.cpp )
target_link_libraries( sol7 PRIVATE lib )
target_include_directories( sol7 PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/lib/include"
)
add_test(NAME PrimeTester COMMAND sol7)
