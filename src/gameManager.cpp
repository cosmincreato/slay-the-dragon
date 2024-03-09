#include <iostream>
#include "../headers/gameManager.h"

using namespace std;

const unsigned int PLAYER_MAX_HP[3] = {
        300,
        200,
        100
},
    ENEMY_MAX_HP[3] = {
        100,
        150,
        200
},
    ENEMY_ATTACK[3] = {
        15,
        20,
        25
};

unsigned int GameManager::round = 0;

inline bool valid_difficulty(string diff)
{
    ///Not a number
    for (int i = 0; i<diff.length(); ++i)
        if (!isdigit(diff[i]))
            return false;

    int d = stoi(diff);
    return (d >= 0 && d <=2);
}

void GameManager::init_stats() {
    player.set_max_hp(PLAYER_MAX_HP[difficulty]);
    player.set_hp(player.get_max_hp());
    enemy.set_max_hp(ENEMY_MAX_HP[difficulty]);
    enemy.set_hp(enemy.get_max_hp());
    enemy.set_attack(ENEMY_ATTACK[difficulty]);
}

GameManager::GameManager() {
    // cout << "Game Constructor\n";
    string diff, name;
    cout << "What is your name?\n";
    getline(cin, name);
    player.set_name(name);
    cout << "Set your difficulty: \n[0=Easy]\n[1=Medium]\n[2=Hard]\n";
    cin >> diff;
    while (!valid_difficulty(diff))
    {
        cout << "Expected a number between 0 and 2. Try again.\n";
        cin >> diff;
    }
    int d = stoi(diff);
    difficulty = d;
    //
    init_stats();
}

GameManager::~GameManager() {
    // cout<<"Game Destructor\n";
}

unsigned int GameManager::get_difficulty() const {
    return difficulty;
}

Player GameManager::get_player() const {
    return player;
}

Enemy GameManager::get_enemy() const {
    return enemy;
}


void GameManager::start() {
    cout << "[Round " << ++round << "]\n";
    player.set_energy(player.get_max_energy());
    cout << player;
    cout << '\n';
    cout << enemy;
    cout << '\n';
    player.get_card_list().show_hand();
}