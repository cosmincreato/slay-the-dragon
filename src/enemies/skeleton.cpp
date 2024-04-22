#include "../../headers/enemies/skeleton.hpp"

Skeleton::Skeleton()
        : Enemy("Skeleton",
                10,
                100,
                100,
                "The Skeleton prepares his bow and shield. (Deal 5 damage and restore 5 HP).") {
    // std::cout << "Constructor dragon\n";
}

Skeleton::~Skeleton() {
    // std::cout << "Destructor dragon\n";
}

void Skeleton::effect(Player &player) {
    deal_damage(player, 5);
    set_hp(get_hp() + 5);
}