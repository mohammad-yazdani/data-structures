cmake_minimum_required(VERSION 3.13)
project(bptree)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(bptree STATIC
        src/BPTree.cc include/BPTree.h include/KV.h src/Vertex.cc include/Vertex.h)

add_subdirectory(test)
