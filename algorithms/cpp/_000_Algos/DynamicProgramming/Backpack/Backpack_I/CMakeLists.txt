cmake_minimum_required(VERSION 3.14)
project(CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(Backpack_I_std Backpack_I_std.cpp)
add_executable(Backpack_I_std_debug Backpack_I_std_debug.cpp)
add_executable(Backpack_I_practise Backpack_I_practise.cpp)
add_executable(SolutionsBack Solutions.cpp)


add_executable(Solution_recursive_B1 Solution_recursive.cpp)
add_executable(Solutions_dp_B1 Solution_dp.cpp)
add_executable(Solution_dp_space_optimized_B1 Solution_dp_space_optimized.cpp)

