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
    std::shared_ptr<Enemy> enemy;

    void start_round();

    void init_stats();

    void ui(int action_index, int taken_damage = 0, int gained_block = 0, int spent_energy = 0);

    GameManager();

    static GameManager instance;

public:

    ~GameManager();

    static GameManager& get();

    void start();

    void gameOver(bool state);
};
