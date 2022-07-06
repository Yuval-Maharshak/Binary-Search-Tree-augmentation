cmake_minimum_required(VERSION 3.21)
project(bstExtension C)

set(CMAKE_C_STANDARD 11)
add_executable(main endResult/main.c endResult/implQueriesBST.c endResult/memory.c)
