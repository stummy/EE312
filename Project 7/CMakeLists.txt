cmake_minimum_required(VERSION 3.8)
project(EE_312___Project_7)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES Recursive.c Recursive.h RecursiveTester.c)
add_executable(EE_312___Project_7 ${SOURCE_FILES})