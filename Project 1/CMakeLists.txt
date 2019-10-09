cmake_minimum_required(VERSION 3.8)
project(EE_312___Project_1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        CodeCamp.c
        CodeCampTester.c)

add_executable(EE_312___Project_1 ${SOURCE_FILES})