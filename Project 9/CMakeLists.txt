cmake_minimum_required(VERSION 3.8)
project(EE_312___Project_9)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        EvilHangmanGame.cpp
        EvilHangmanGame.h
        RunEvilHangman.cpp)

add_executable(EvilHangman ${SOURCE_FILES})