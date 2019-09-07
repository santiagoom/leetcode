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

add_executable(_334_IncreasingTripletSubsequence_std _334_IncreasingTripletSubsequence_std.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(_334_IncreasingTripletSubsequence_std_debug _334_IncreasingTripletSubsequence_std_debug.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(_334_IncreasingTripletSubsequence_practise _334_IncreasingTripletSubsequence_practise.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(Solutions_334_Inc Solutions.cpp ${SOURCE_FILES} ${SOURCES})
