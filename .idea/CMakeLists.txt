cmake_minimum_required(VERSION 3.29)
project(_idea)

set(CMAKE_CXX_STANDARD 14)

add_executable(_idea
    .gitignore
    .name
    editor.xml
    Game-tDND.iml
    misc.xml
    modules.xml
    vcs.xml
    workspace.xml
        ../Game0.2.cpp
        ../Inventory.cpp
        ../Item.cpp
        ../Person.cpp
        ../Function.cpp)
