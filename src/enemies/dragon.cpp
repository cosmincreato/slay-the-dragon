#include "../../headers/enemies/dragon.hpp"

Dragon::Dragon()
        : Enemy("Dragon",
                10,
                100,
                100,
                "The Dragon is ready to engulf your deck in flames (Destroy 2 random cards from your deck).") {
    // std::cout << "Constructor dragon\n";
}

Dragon::~Dragon() {
    // std::cout << "Destructor dragon\n";
}

void Dragon::effect(Player &player) {
    player.exhaust(2);
}