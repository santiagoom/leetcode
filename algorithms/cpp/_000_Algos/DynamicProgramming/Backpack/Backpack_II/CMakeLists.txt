cmake_minimum_required(VERSION 3.14)
project(CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(Backpack_II_std Backpack_II_std.cpp)
add_executable(Backpack_II_std_debug Backpack_II_std_debug.cpp)
add_executable(Backpack_II_practise Backpack_II_practise.cpp)
#add_executable(SolutionsBack Solutions.cpp)


add_executable(Solution_recursive_B2 Solution_recursive.cpp)
add_executable(Solutions_dp_B2 Solution_dp.cpp)
add_executable(Solution_dp_space_optimized_B2 Solution_dp_space_optimized.cpp)

