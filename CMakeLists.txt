cmake_minimum_required(VERSION 3.10)

# Set project name and version
project(ProjectEulerSolutions VERSION 1.0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

add_subdirectory(lib)

# Testing
include(CTest)


# Solutions
add_executable( sol7 solutions/7.cpp )
target_include_directories( sol7 PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/lib/include"
)
target_link_libraries( sol7 PRIVATE lib )
add_test(NAME test7 COMMAND sol7)

add_executable( sol8 solutions/8.cpp )

add_executable( sol10 solutions/10.cpp )
target_link_libraries( sol10 PRIVATE lib )
add_test(NAME test10 COMMAND sol10)


add_executable( sol11 solutions/11.cpp )

add_executable( sol12 solutions/12.cpp )

add_executable( sol13 solutions/13.cpp )

add_executable( sol14 solutions/14.cpp )

add_executable( sol15 solutions/15.cpp )
target_link_libraries( sol15 PRIVATE lib )
add_test(NAME test15 COMMAND sol15)

add_executable( sol16 solutions/16.cpp )

add_executable( sol60 solutions/60.cpp )
target_link_libraries( sol60 PRIVATE lib )
add_test(NAME test60 COMMAND sol60)

