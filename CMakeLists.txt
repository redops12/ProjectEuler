cmake_minimum_required(VERSION 3.10)

# Set project name and version
project(ProjectEulerSolutions VERSION 1.0)

# Define lib
add_library (lib SHARED
    lib/functions.cpp
    lib/prime.cpp
)

# 7
add_executable(7 solutions/7/7.cpp)
target_link_libraries(7 lib)
