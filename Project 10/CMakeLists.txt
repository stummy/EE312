cmake_minimum_required(VERSION 3.8)
project(EE_312___Project_10)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Card.cpp
        Card.h
        Deck.cpp
        Deck.h
        Hand.cpp
        Hand.h
        playWar.cpp)

add_executable(War ${SOURCE_FILES})