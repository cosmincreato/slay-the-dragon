#pragma once
#include <iostream>
#include "player.h"
#include "enemy.h"

using namespace std;

class GameManager {
private:
    unsigned int difficulty;
    static unsigned int round;
    Player player;
    Enemy enemy;

public:
    /// Constructors and destructors
    GameManager();
    ~GameManager();

    /// Setters


    /// Getters
    unsigned int get_difficulty() const;
    Player get_player() const;
    Enemy get_enemy() const;

    /// Operator overloading


    ///

    void start();
    void init_stats();
};
