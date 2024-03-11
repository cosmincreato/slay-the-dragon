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

inline bool valid_difficulty(const string& diff)
{
    ///Not a number
    for (char i : diff)
        if (!isdigit(i))
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

void GameManager::start_round() {
    cout << "[Round " << ++round << "]\n";

    /// Refresh the player's energy
    player.set_energy(player.get_max_energy());

    cout << player;
    cout << '\n';

    /// The player draws 5 at the start of the round
    player.draw(5);
    cout << "[Your Hand]\n";
    for (const Card& card : player.get_hand())
        cout << card;

    ///

    cout << enemy;
    cout << '\n';

    /// The player discards at the end of the round
    player.discard();

    cout << endl;
}

void GameManager::start() {
    /// Start the round cycle
    //start_round();
    start_round();
}