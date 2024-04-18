#include "../../headers/enemies/darkElf.hpp"

DarkElf::DarkElf()
        : Enemy("Dark Elf", 10, 100, 100) {
    // std::cout << "Constructor dragon\n";
}

DarkElf::~DarkElf() {
    // std::cout << "Destructor dragon\n";
}

void DarkElf::Effect() {
    std::cout << "Dark Elf Effect\n";
}