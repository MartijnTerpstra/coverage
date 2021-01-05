cmake_minimum_required (VERSION 3.13)

project (coverage CXX)

add_library(mtmath STATIC mtmath/algorithm.cpp)
add_library(mtmath::mtmath ALIAS mtmath)

target_include_directories(mtmath INTERFACE "${CMAKE_SOURCE_DIR}/mtmath")

add_subdirectory(tests)