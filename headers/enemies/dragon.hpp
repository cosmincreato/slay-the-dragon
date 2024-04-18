#pragma once

#include "enemy.hpp"

class Dragon : public Enemy {
public:
    Dragon();

    ~Dragon();

    void Effect() override;
};