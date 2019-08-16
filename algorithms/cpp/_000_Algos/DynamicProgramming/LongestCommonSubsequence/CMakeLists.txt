cmake_minimum_required(VERSION 3.14)
project(CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(Naive_recursive Naive_recursive.cpp)
add_executable(DynamicProgramming DynamicProgramming.cpp)
add_executable(PrintingLCS PrintingLCS.cpp)
add_executable(SpaceOptimized SpaceOptimized.cpp)
add_executable(DynamicProgramming_debug DynamicProgramming_debug.cpp)