cmake_minimum_required(VERSION 3.29)
project(Game_tDND)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Game_tDND
    Function.cpp
    Game0.2.cpp
    Item.cpp
    Item.h
    Person.cpp
    Person.h)
