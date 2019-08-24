cmake_minimum_required(VERSION 3.14)
project(CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(Backpack_V_std Backpack_V_std.cpp)
add_executable(Backpack_V_std_debug Backpack_V_std_debug.cpp)
add_executable(Backpack_V_practise Backpack_V_practise.cpp)
#add_executable(SolutionsBack Solutions.cpp)


add_executable(Solution_recursive_B5 Solution_recursive.cpp)
add_executable(Solutions_dp_B5 Solution_dp.cpp)
add_executable(Solution_dp_space_optimized_B5 Solution_dp_space_optimized.cpp)

