cmake_minimum_required(VERSION 3.29)
project(Game_tDND)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -static") #релиз без этого не работает

include_directories(Include)

add_executable(Game_tDND
        src/Game0.2.cpp
        src/Inventory.cpp
        src/Item.cpp
        src/Person.cpp
)