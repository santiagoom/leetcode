cmake_minimum_required(VERSION 3.14)
project(CXX)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES
        ../Utilities/Array.h
        ../Utilities/Array.cpp

        ../Utilities/BinaryTree.h
        ../Utilities/BinaryTree.cpp

        ../Utilities/List.h
        ../Utilities/List.cpp

        ../Utilities/StringUtil.h
        ../Utilities/StringUtil.cpp

        ../Utilities/Tree.h
        ../Utilities/Tree.cpp


        ../utils/myListNode.h
        ../utils/myListNode.cpp

        ../utils/myTreeNode.h
        ../utils/myTreeNode.cpp
        
        ../utils/myVector.h
        ../utils/myVector.cpp
        
        ../utils/myutils.h
        ../utils/myutils.cpp
        )

add_executable(_259_3SumSmaller_std _259_3SumSmaller_std.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(_259_3SumSmaller_std_debug _259_3SumSmaller_std_debug.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(_259_3SumSmaller_practise _259_3SumSmaller_practise.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(Solutions_259_3Su Solutions.cpp ${SOURCE_FILES} ${SOURCES})
