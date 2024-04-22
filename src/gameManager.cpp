#include <iostream>
#include "../headers/gameManager.hpp"
#include "../headers/enemies/dragon.hpp"
#include "../headers/enemies/skeleton.hpp"
#include "../headers/enemies/darkElf.hpp"

unsigned int GameManager::round = 0;

bool valid_num(const std::string &s) {
    for (char i: s)
        if (!isdigit(i))
            return false;

    return true;
}

bool valid_difficulty(const std::string &diff) {
    ///Not a number
    if (!valid_num(diff))
        return false;

    int d = stoi(diff);
    return (d >= 0 && d <= 2);
}

bool valid_card(const std::string &card, int min_range, int max_range) {
    ///Not a number
    if (!valid_num(card))
        return false;

    int c = stoi(card);
    return (c >= min_range && c <= max_range);
}

void GameManager::init_stats() {
    /// Pointer type conversion
    if (difficulty == 0) {
        enemy = std::make_unique<Skeleton>();
        std::unique_ptr<Skeleton> deriv(dynamic_cast<Skeleton*>(enemy.release()));
        enemy = std::move(deriv);
    } else if (difficulty == 1) {
        enemy = std::make_unique<DarkElf>();
        std::unique_ptr<DarkElf> deriv(dynamic_cast<DarkElf*>(enemy.release()));
        enemy = std::move(deriv);
    }
    else {
        enemy = std::make_unique<Dragon>();
        std::unique_ptr<Dragon> deriv(dynamic_cast<Dragon*>(enemy.release()));
        enemy = std::move(deriv);
    }
    //
    player.set_max_hp(200);
    player.set_hp(player.get_max_hp());
}

GameManager::GameManager() {
    /// cout << "Game Constructor\n";

    std::string diff, name;
    std::cout << "What is your name?\n";
    getline(std::cin, name);
    player.set_name(name);
    std::cout << "\nSet your difficulty: \n[0=Easy]\n[1=Medium]\n[2=Hard]\n";
    std::cin >> diff;
    while (!valid_difficulty(diff)) {
        std::cout << "Expected a number between 0 and 2. Try again.\n";
        std::cin >> diff;
    }
    int d = stoi(diff);
    difficulty = d;
    //
    init_stats();
}

GameManager::~GameManager() = default;


void GameManager::ui(int action_index, int taken_damage, int gained_block, int spent_energy) {
    std::cout << '\n';
    int hand_index = 1;
    std::cout << player;
    if (taken_damage != 0)
        std::cout << "(-" << taken_damage << " HP.)\n";
    if (gained_block != 0)
        std::cout << "(+" << gained_block << " block.)\n";
    if (spent_energy != 0)
        std::cout << "(-" << spent_energy << " energy.)\n";
    std::cout << '\n';
    std::cout << "[Your Hand]\n";
    for (const Card &card: player.get_hand())
        std::cout << '(' << hand_index++ << ") " << card;
    std::cout << '[' << player.get_deck().size() << " remaining in deck]\n";
    std::cout << enemy << '\n';
    if (action_index == 1)
        std::cout << "The " << enemy->get_name() <<" intends to deal " << enemy->get_attack() << " damage.\n";
    else
        std::cout << enemy->get_effect_info() << '\n';

}

void GameManager::start_round() {
    unsigned int action_index = round % 2;
    for (int i = 0; i <= 80; ++i)
        std::cout << '-';
    std::cout << "\n[Round " << ++round << "]\n";

    /// Refresh the player's stats
    player.set_energy(player.get_max_energy());
    player.set_block(0);
    /// The player draws 5 at the start of the round (or all his cards)
    player.draw(5);
    ui(action_index);

    ///Card choices during the round
    int played_card, hand_size, potion;
    std::string _played_card, _potion;
    Card card;
    while (true) {
        hand_size = player.get_hand().size();
        if (hand_size > 0)
            std::cout << "Enter a number between 1 and " << hand_size << " to play a card. ";
        std::cout << "Enter " << hand_size + 1 << " to drink a potion. Enter 0 to end your turn.\n";
        std::cin >> _played_card;
        while (!valid_card(_played_card, 0, hand_size + 1)) {
            std::cout << "Expected a number between 0 and " << hand_size + 1 << ". Try again.\n";
            std::cin >> _played_card;
        }
        played_card = stoi(_played_card);

        /// End turn
        if (played_card == 0)
            break;

        ///Drink potion
        if (played_card == hand_size + 1) {
            std::cout << "\nEnter a number between 1 and " << player.get_potions().get_count()
                      << " to drink a potion.\n";
            for (int potion_index = 0; potion_index < player.get_potions().get_count(); ++potion_index) {
                std::cout << '(' << potion_index + 1 << ") " << player.get_potions().get_name(potion_index);
                std::cout << " [" << player.get_potions().get_info(potion_index) << "]\n";
            }
            std::cin >> _potion;
            while (!valid_card(_potion, 1, player.get_potions().get_count())) {
                std::cout << "Expected a number between 1 and " << player.get_potions().get_count() << ". Try again.\n";
                std::cin >> _potion;
            }
            potion = stoi(_potion) - 1;
            player.drink(potion);
            ui(action_index);
        }

            /// Play the selected card
        else {
            card = *(player.get_hand().begin() + played_card - 1);
            if (player.get_energy() < card.get_cost()) {
                std::cout << "You don't have enough energy to play this card.\n";
                ui(action_index);
            } else {
                player.play(card);
                /// Deal damage to the enemy
                enemy->set_hp(enemy->get_hp() - card.get_attack());
                if (enemy->get_hp() < 0)
                    enemy->set_hp(0);
                ui(action_index,0, card.get_block(), card.get_cost());
            }
        }
    }

    /// Enemy action
    if (action_index == 1) {
        enemy->deal_damage(player, enemy->get_attack());
    } else {
        enemy->effect(player);
    }
    /// The player discards at the end of the round
    player.discard();
}

void GameManager::start() {
    /// Start the round cycle
    while (enemy->get_hp() > 0 && player.get_hp() > 0)
        start_round();

    if (enemy->get_hp() <= 0) {
        std::cout << "Congratulations! You slayed the dragon in " << round << " rounds! ";
    } else {
        std::cout << "You lost! Better luck next time! ";
    }
    std::cout << "Enter anything to quit the game.\n";
    std::string quit;
    std::cin >> quit;
    exit(0);
}