#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <random>
#include <algorithm>
#include "../headers/player.hpp"

std::ifstream fin("../deck.txt");

std::vector<std::string> split_card(const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}

void Player::recycle_deck() {
    if (deck.empty() && !discarded.empty()) {
        shuffle_deck();
        discarded.clear();
    }
}

Player::Player()
        : name("Hero"),
          hp(0),
          max_hp(0),
          energy(0),
          block(0),
          deck({}),
          hand({}),
          discarded({}) {
    ///Create the Deck using the "deck.txt" file
    std::string card;
    while (getline(fin, card)) {
        std::vector<std::string> sp = split_card(card, ',');
        deck.emplace_back(sp);
    }

    ///Shuffle the deck
    shuffle_deck();
    // cout << "Player Constructor\n";
}

void Player::set_name(std::string _name) {
    name = std::move(_name);
}

void Player::set_hp(float _hp) {
    hp = _hp;
    if (hp > max_hp)
        hp = max_hp;
}

void Player::set_max_hp(int _max_hp) {
    max_hp = _max_hp;
}

void Player::set_block(float _block) {
    block = _block;
}

void Player::set_energy(int _energy) {
    energy = _energy;
}

std::string Player::get_name() const {
    return name;
}

float Player::get_hp() const {
    return hp;
}

int Player::get_max_hp() const {
    return max_hp;
}

int Player::get_energy() const {
    return energy;
}

int Player::get_max_energy() const {
    return max_energy;
}

float Player::get_block() const {
    return block;
}

Cards Player::get_deck() const {
    return deck;
}

Cards Player::get_hand() const {
    return hand;
}

Potions Player::get_potions() const {
    return potions;
}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << player.name << '\n';
    os << player.hp << " / " << player.max_hp << " HP (" << player.block << " Block) \n";
    os << player.energy << " / " << player.max_energy << " Energy\n";
    os << "Potions: ";
    for (int potion_index = 0; potion_index < player.potions.get_count(); ++potion_index) {
        bool used = player.potions.get_used(potion_index);
        if (used)
            os << "[ ] ";
        else
            os << "[x] ";
    }
    std::cout << '\n';
    return os;
}

void Player::operator=(Player &p) {
    name = p.name;
    max_hp = p.max_hp;
    energy = p.energy;
    hp = p.hp;
    block = p.block;
}

void Player::play(const Card &card) {
    block += card.get_block();
    energy -= card.get_cost();

    discarded.emplace_back(card);

    for (auto it = hand.begin(); it != hand.end(); ++it)
        if (*it == card) {
            hand.erase(it);
            break;
        }
}

void Player::draw(int times) {
    while (times--) {
        if (!deck.empty()) {
            Card top_deck = deck.back();
            hand.emplace_back(top_deck);
            deck.pop_back();
        } else if (!discarded.empty()) {
            recycle_deck();
            Card top_deck = deck.back();
            hand.emplace_back(top_deck);
            deck.pop_back();
        }
    }
}

void Player::discard() {
    for (const Card &card: hand)
        discarded.emplace_back(card);
    hand.clear();
}

void Player::discard(const Card &card) {
    discarded.emplace_back(card);

    for (auto it = hand.begin(); it != hand.end(); ++it)
        if (*it == card) {
            hand.erase(it);
            break;
        }
}

void Player::shuffle_deck() {
    std::random_device rd;
    std::mt19937 g(rd());
    //
    for (const Card &card: discarded)
        deck.emplace_back(card);
    //
    shuffle(deck.begin(), deck.end(), g);
}

void Player::exhaust(int times) {
    while (times--) {
        if (!deck.empty()) {
            deck.pop_back();
        }
        else if (!discarded.empty()) {
            recycle_deck();
            deck.pop_back();
        }
    }
}

void Player::drink(unsigned int potion) {
    if (!potions.get_used(potion)) {
        potions.set_used(potion, true);
        if (potion == 0) /// Blood Potion (Heal)
        {
            hp += max_hp * 0.1;
            if (hp > max_hp)
                hp = max_hp;

        } else if (potion == 1) /// Energy Potions (Refresh)
        {
            energy = max_energy;
        } else {
            draw(3);
        }

    } else {
        std::cout << "Potion already used.\n";
    }
}

Player::~Player() = default;