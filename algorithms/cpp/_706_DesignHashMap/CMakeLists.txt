cmake_minimum_required(VERSION 3.14)
project(cpp-706_DesignHashMap)

set(CMAKE_CXX_STANDARD 14)


add_executable(HashTable HashTable.cpp)
add_executable(SeparateChaining SeparateChaining.cpp)
add_executable(SeparateChaining_debug SeparateChaining_debug.cpp)
add_executable(Solutions706 Solutions.cpp)
#add_executable(test cpp/_705_DesignHashSet/temp.cpp)
