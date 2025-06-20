cmake_minimum_required(VERSION 3.10)

set(SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/prime.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/prime_iterator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/factorized.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/factorization_iterator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/strint.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/combinatorics.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/number_theory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/graph.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/roman_numeral.cpp
)

add_library (lib ${SRC_FILES})

target_include_directories( lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
