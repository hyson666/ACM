cmake_minimum_required(VERSION 3.5)
project(print_permutation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(print_permutation ${SOURCE_FILES})