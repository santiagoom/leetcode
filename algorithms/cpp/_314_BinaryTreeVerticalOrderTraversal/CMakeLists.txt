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

add_executable(_314_BinaryTreeVerticalOrderTraversal_std _314_BinaryTreeVerticalOrderTraversal_std.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(_314_BinaryTreeVerticalOrderTraversal_std_debug _314_BinaryTreeVerticalOrderTraversal_std_debug.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(_314_BinaryTreeVerticalOrderTraversal_practise _314_BinaryTreeVerticalOrderTraversal_practise.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(Solutions_314_Bin Solutions.cpp ${SOURCE_FILES} ${SOURCES})
