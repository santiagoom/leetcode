cmake_minimum_required(VERSION 3.14)
project(CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(Backpack_IV_std Backpack_IV_std.cpp)
add_executable(Backpack_IV_std_debug Backpack_IV_std_debug.cpp)
add_executable(Backpack_IV_practise Backpack_IV_practise.cpp)
#add_executable(SolutionsBack Solutions.cpp)


add_executable(Solution_recursive_B4 Solution_recursive.cpp)
add_executable(Solutions_dp_B4 Solution_dp.cpp)
add_executable(Solution_dp_space_optimized_B4 Solution_dp_space_optimized.cpp)
