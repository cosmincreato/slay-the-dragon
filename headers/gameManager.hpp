#pragma once

#include <iostream>
#include <memory>
#include "player.hpp"
#include "enemies/enemy.hpp"

class GameManager {
private:
    unsigned int difficulty;
    static unsigned int round;
    Player player;
    std::unique_ptr<Enemy> enemy;

    void start_round();

    void init_stats();

    void ui(int action_index, int taken_damage = 0, int gained_block = 0, int spent_energy = 0);

public:
    /// Constructors and destructors
    GameManager();

    ~GameManager();

    void start();
};
