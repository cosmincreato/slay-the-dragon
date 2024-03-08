cmake_minimum_required(VERSION 3.26)
project(OOP_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOP_Project
        main.cpp
        headers/card.h
        src/card.cpp
        src/gameManager.cpp
        headers/gameManager.h
        src/player.cpp
        headers/player.h
        src/enemy.cpp
        headers/enemy.h)
