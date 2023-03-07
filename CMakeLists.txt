cmake_minimum_required(VERSION 3.24)
project(hello-c C)

set(CMAKE_C_STANDARD 11)

add_executable(hello-c main.c addtwonum.c)
