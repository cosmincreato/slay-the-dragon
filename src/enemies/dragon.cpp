#include "../../headers/enemies/dragon.hpp"

Dragon::Dragon()
        : Enemy("Dragon", 10, 100, 100) {
    // std::cout << "Constructor dragon\n";
}

Dragon::~Dragon() {
    // std::cout << "Destructor dragon\n";
}

void Dragon::Effect() {
    std::cout << "Dragon Effect\n";
}