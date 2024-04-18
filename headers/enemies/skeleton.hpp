#pragma once

#include "enemy.hpp"

class Skeleton : public Enemy {
public:
    Skeleton();

    ~Skeleton();

    void Effect() override;
};