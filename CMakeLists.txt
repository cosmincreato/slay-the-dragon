cmake_minimum_required(VERSION 3.26)
project(OOP_Project)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(OOP_Project
        main.cpp
        headers/card.hpp
        src/card.cpp
        src/gameManager.cpp
        headers/gameManager.hpp
        src/player.cpp
        headers/player.hpp
        src/enemies/enemy.cpp
        headers/enemies/enemy.hpp
        src/potions.cpp
        headers/potions.hpp
        src/enemies/dragon.cpp
        headers/enemies/dragon.hpp
        src/enemies/skeleton.cpp
        headers/enemies/skeleton.hpp
        src/enemies/darkElf.cpp
        headers/enemies/darkElf.hpp
)

# Specify SFML directory
set(SFML_DIR "C:/Users/Cosmin/SFML-2.6.1/lib/cmake/SFML")

# Find SFML package
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS system window graphics REQUIRED)

# Link SFML libraries
target_link_libraries(OOP_Project sfml-system sfml-window sfml-graphics)