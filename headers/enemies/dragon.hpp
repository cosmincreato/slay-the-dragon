#pragma once

#include "enemy.hpp"

class Dragon : public Enemy {
public:
    Dragon();

    ~Dragon();

    void effect(Player &player) override;
};