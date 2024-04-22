#pragma once

#include "enemy.hpp"

class DarkElf : public Enemy {
public:
    DarkElf();

    ~DarkElf();

    void effect(Player &player) override;
};