cmake_minimum_required(VERSION 3.10)

# Set project name and version
project(ProjectEulerSolutions VERSION 1.0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -g -fno-omit-frame-pointer")

add_subdirectory(lib)

# Testing
include(CTest)

add_executable( tests solutions/tests.cpp )
target_link_libraries( tests PRIVATE lib )
add_test(NAME tests COMMAND tests)

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

add_executable( sol17 solutions/17.cpp )

add_executable( sol18 solutions/18.cpp )

add_executable( sol19 solutions/19.cpp )

add_executable( sol20 solutions/20.cpp )
target_link_libraries( sol20 PRIVATE lib )
add_test(NAME test20 COMMAND sol20)

add_executable( sol21 solutions/21.cpp )

add_executable( sol22 solutions/22.cpp )

add_executable( sol23 solutions/23.cpp )

add_executable( sol25 solutions/25.cpp )

add_executable( sol26 solutions/26.cpp )
target_link_libraries( sol26 PRIVATE lib )
add_test(NAME test26 COMMAND sol26)

add_executable( sol27 solutions/27.cpp )
target_link_libraries( sol27 PRIVATE lib )
add_test(NAME test27 COMMAND sol27)

add_executable( sol28 solutions/28.cpp )

add_executable( sol29 solutions/29.cpp )
target_link_libraries( sol29 PRIVATE lib )
add_test(NAME test29 COMMAND sol29)

add_executable( sol30 solutions/30.cpp )
target_link_libraries( sol30 PRIVATE lib )
add_test(NAME test30 COMMAND sol30)

add_executable( sol31 solutions/31.cpp )

add_executable( sol32 solutions/32.cpp )

add_executable( sol33 solutions/33.cpp )
target_link_libraries( sol33 PRIVATE lib )
add_test(NAME test33 COMMAND sol33)

add_executable( sol34 solutions/34.cpp )
target_link_libraries( sol34 PRIVATE lib )
add_test(NAME test34 COMMAND sol34)

add_executable( sol35 solutions/35.cpp )
target_link_libraries( sol35 PRIVATE lib )
add_test(NAME test35 COMMAND sol35)

add_executable( sol36 solutions/36.cpp )
target_link_libraries( sol36 PRIVATE lib )
add_test(NAME test36 COMMAND sol36)

add_executable( sol37 solutions/37.cpp )
target_link_libraries( sol37 PRIVATE lib )
add_test(NAME test37 COMMAND sol37)

add_executable( sol38 solutions/38.cpp )
target_link_libraries( sol38 PRIVATE lib )
add_test(NAME test38 COMMAND sol38)

add_executable( sol39 solutions/39.cpp )

add_executable( sol40 solutions/40.cpp )

add_executable( sol41 solutions/41.cpp )
target_link_libraries( sol41 PRIVATE lib )
add_test(NAME test41 COMMAND sol41)

add_executable( sol60 solutions/60.cpp )
target_link_libraries( sol60 PRIVATE lib )
add_test(NAME test60 COMMAND sol60)

add_executable( sol64 solutions/64.cpp )
target_link_libraries( sol64 PRIVATE lib )
add_test(NAME test64 COMMAND sol64)

add_executable( sol65 solutions/65.cpp )
target_link_libraries( sol65 PRIVATE lib )
add_test(NAME test65 COMMAND sol65)

add_executable( sol66 solutions/66.cpp )
target_link_libraries( sol66 PRIVATE lib )
add_test(NAME test66 COMMAND sol66)

add_executable( sol67 solutions/67.cpp )

add_executable( sol193 solutions/193.cpp )
target_link_libraries( sol193 PRIVATE lib )
add_test(NAME test193 COMMAND sol193)

add_executable( sol206 solutions/206.cpp )
