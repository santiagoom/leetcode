cmake_minimum_required(VERSION 3.14)
project(CXX)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES
        ../utils/myutils.h
        ../utils/myutils.cpp
        )

add_executable(utils_test__ utils_test.cpp ${SOURCE_FILES} ${SOURCES})
