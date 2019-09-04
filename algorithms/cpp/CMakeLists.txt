cmake_minimum_required(VERSION 3.14)
project(CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(_std _std.cpp)
add_executable(_std_debug _std_debug.cpp)
add_executable(_practise _practise.cpp)
add_executable(Solutions Solutions.cpp)
