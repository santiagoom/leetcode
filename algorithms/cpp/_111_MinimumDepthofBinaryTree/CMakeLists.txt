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
        )

add_executable(_111_MinimumDepthofBinaryTree_std _111_MinimumDepthofBinaryTree_std.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(_111_MinimumDepthofBinaryTree_std_debug _111_MinimumDepthofBinaryTree_std_debug.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(_111_MinimumDepthofBinaryTree_practise _111_MinimumDepthofBinaryTree_practise.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(Solutions_111_Min Solutions.cpp ${SOURCE_FILES} ${SOURCES})
