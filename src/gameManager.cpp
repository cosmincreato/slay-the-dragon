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

int dmg;

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

bool valid_card(const string& card, int min_range, int max_range)
{
    ///Not a number
    if (!valid_num(card))
        return false;

    int c = stoi(card);
    return (c >= min_range && c <= max_range);
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
    cout << "\nSet your difficulty: \n[0=Easy]\n[1=Medium]\n[2=Hard]\n";
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

GameManager::~GameManager() = default;

unsigned int GameManager::get_difficulty() const {
    return difficulty;
}

Player GameManager::get_player() const {
    return player;
}

Enemy GameManager::get_enemy() const {
    return enemy;
}

void GameManager::ui(int taken_damage, int gained_block, int spent_energy) {
    cout << '\n';
    int hand_index = 1;
    cout << player;
    if (taken_damage != 0)
        cout << "(-" << taken_damage << " HP.)\n";
    if (gained_block != 0)
        cout << "(+" << gained_block << " block.)\n";
    if (spent_energy != 0)
        cout << "(-" << spent_energy << " energy.)\n";
    cout << '\n';
    cout << "[Your Hand]\n";
    for (const Card& card : player.get_hand())
        cout << '(' << hand_index++ << ") " << card;
    cout <<'['<<player.get_deck().size()<<" remaining in deck]\n";
    cout << '\n' << enemy;
    cout << "The enemy intends to deal " << enemy.get_attack()<< " damage.\n";
}

void GameManager::start_round() {
    for (int i = 0; i <= 80; ++i)
        cout<<'-';
    cout << "\n[Round " << ++round << "]\n";

    /// Refresh the player's stats
    player.set_energy(player.get_max_energy());
    player.set_block(0);
    /// The player draws 5 at the start of the round
    player.draw(5);
    ui(dmg);

    ///Card choices during the round
    int played_card, hand_size, potion;
    string _played_card, _potion;
    Card card;
    while (true)
    {
        hand_size = player.get_hand().size();
        if (hand_size > 0)
            cout << "Enter a number between 1 and " << hand_size << " to play a card. ";
        cout << "Enter "<< hand_size+1 << " to drink a potion. Enter 0 to end your turn.\n";
        cin >> _played_card;
        while (!valid_card(_played_card, 0, hand_size+1))
        {
            cout << "Expected a number between 0 and "<< hand_size+1 << ". Try again.\n";
            cin >> _played_card;
        }
        played_card = stoi(_played_card);

        /// End turn
        if (played_card == 0)
            break;

        ///Drink potion
        if (played_card == hand_size + 1)
        {
            cout << "\nEnter a number between 1 and " << player.get_potions().get_count() << " to drink a potion.\n";
            for (int potion_index = 0; potion_index < player.get_potions().get_count(); ++potion_index) {
                cout << '(' << potion_index + 1 << ") " << player.get_potions().get_name(potion_index);
                cout << " [" << player.get_potions().get_info(potion_index) << "]\n";
            }
            cin >> _potion;
            while (!valid_card(_potion, 1, player.get_potions().get_count()))
            {
                cout << "Expected a number between 1 and "<< player.get_potions().get_count() << ". Try again.\n";
                cin >> _potion;
            }
            potion = stoi(_potion) - 1;
            player.drink(potion);
            ui();
        }

        /// Play the selected card
        else
        {
            card = *(player.get_hand().begin() + played_card - 1);
            if (player.get_energy() < card.get_cost())
            {
                cout << "You don't have enough energy to play this card.\n";
                ui();
            }
            else {
                player.play(card);
                /// Deal damage to the enemy
                enemy.set_hp(enemy.get_hp() - card.get_attack());
                if (enemy.get_hp() < 0)
                    enemy.set_hp(0);
                ui(0,card.get_block(),card.get_cost());
            }
        }
    }

    /// Enemy action
    // The enemy deals damage (must go through block first)
    dmg = enemy.get_attack();
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
    while (enemy.get_hp() > 0 && player.get_hp() > 0)
        start_round();

    if (enemy.get_hp() <= 0)
    {
        cout << "Congratulations! You slayed the dragon in " << round << " rounds! ";
    }
    else
    {
        cout << "You lost! Better luck next time! ";
    }
    cout << "Enter anything to quit the game.\n";
    string quit;
    cin >> quit;
    exit(0);
}