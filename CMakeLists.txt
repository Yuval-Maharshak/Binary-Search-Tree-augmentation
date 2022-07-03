cmake_minimum_required(VERSION 3.21)
project(bstExtension C)

set(CMAKE_C_STANDARD 11)

add_executable(bstExtension bst.c main.c head.h memory.c)
add_executable(test testMacro.c)
add_executable(test1 augmention.c augmention.h)
