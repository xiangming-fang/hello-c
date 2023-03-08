cmake_minimum_required(VERSION 3.24)
project(hello-c C)

set(CMAKE_C_STANDARD 11)

add_executable(hello-c main.c addtwonum.c)

add_executable(c-file file.c)

add_executable(c-macro macro.c macro.h)

add_executable(c-recursion recursion.c)

add_executable(c-memory allocatememory.c)

add_executable(c-command commandlineparam.c)
