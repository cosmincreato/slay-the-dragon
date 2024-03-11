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

bool valid_num(const string& s)
{
    for (char i : s)
        if (!isdigit(i))
            return false;

    return true;
}

bool valid_difficulty(const string& diff)
{
    ///Not a number
    if (!valid_num(diff))
        return false;

    int d = stoi(diff);
    return (d >= 0 && d <=2);
}

bool valid_card(const string& card, int max_range)
{
    ///Not a number
    if (!valid_num(card))
        return false;

    int c = stoi(card);
    return (c >= 0 && c <= max_range);
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

void GameManager::ui() {
    int hand_index = 1;
    cout << player << '\n';
    cout << "[Your Hand]\n";
    for (const Card& card : player.get_hand())
        cout << '(' << hand_index++ << ") " << card;
    cout << '\n' << enemy;
    cout << "The enemy intends to deal " << enemy.get_attack()<< " damage.\n";
}

void GameManager::start_round() {
    cout << "[Round " << ++round << "]\n";

    /// Refresh the player's stats
    player.set_energy(player.get_max_energy());
    player.set_block(0);
    /// The player draws 5 at the start of the round
    player.draw(5);
    ui();

    ///Card choices during the round
    int played_card, hand_size;
    string _played_card;
    Card card;
    while (true)
    {
        hand_size = player.get_hand().size();
        cout << "Enter a number between 1 and " << hand_size << " to play a card, or 0 to end your turn.\n";
        cin >> _played_card;
        while (!valid_card(_played_card, hand_size))
        {
            cout << "Expected a number between 0 and "<< hand_size << ". Try again.\n";
            cin >> _played_card;
        }
        played_card = stoi(_played_card);
        /// End turn
        if (played_card == 0)
            break;
        card = *(player.get_hand().begin() + played_card - 1);
        if (player.get_energy() < card.get_cost())
        {
            cout << "You don't have enough energy to play this card.\n";
            ui();
        }
        else
        {
            player.play(card);
            /// Deal damage to the enemy
            enemy.set_hp(enemy.get_hp() - card.get_attack());
            ui();
        }
    }

    /// Enemy action
    // The enemy deals damage (must go through block first)
    int dmg = enemy.get_attack();
    if (dmg > player.get_block())
    {
        dmg -= player.get_block();
        player.set_block(0);
    }
    player.set_hp(player.get_hp() - dmg);
    /// The player discards at the end of the round
    player.discard();
}

void GameManager::start() {
    /// Start the round cycle
    while (enemy.get_hp() > 0)
        start_round();
}