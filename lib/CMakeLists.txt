cmake_minimum_required(VERSION 3.10)

set(SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/functions.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/prime.cpp
)

add_library (lib ${SRC_FILES})

target_include_directories( lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
