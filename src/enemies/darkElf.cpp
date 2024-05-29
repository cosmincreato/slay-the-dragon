#include "../../headers/enemies/darkElf.hpp"

DarkElf::DarkElf()
        : Enemy("Dark Elf",
                10,
                100,
                100,
                "The Dark elf prepares an incantation (+2 Attack Damage).") {
    // std::cout << "Constructor dragon\n";
}

DarkElf::~DarkElf() {
    // std::cout << "Destructor dragon\n";
}

void DarkElf::effect(Player &player) {
    set_attack(get_attack() + 2.5);
}