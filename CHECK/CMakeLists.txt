cmake_minimum_required(VERSION 3.5)
project(check)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(check ${SOURCE_FILES})