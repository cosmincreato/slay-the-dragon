#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <random>
#include <algorithm>
#include "../headers/player.h"

using namespace std;

ifstream fin("../deck.txt");

vector<string> split_card(const string& s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

Player::Player()
:   name("Hero"),
    hp(0),
    max_hp(0),
    energy(0),
    block(0),
    deck({}),
    hand({}),
    discarded({}) {
    ///Create the Deck using the "deck.txt" file
    string card;
    while (getline(fin, card))
    {
        vector<string> sp = split_card(card, ',');
        deck.emplace_back(sp);
    }

    ///Shuffle the deck
    shuffle_deck();
    // cout << "Player Constructor\n";
}

Player::~Player() = default;

void Player::set_name(string _name) {
    name = std::move(_name);
}

void Player::set_hp(int _hp) {
    hp = _hp;
}

void Player::set_max_hp(int _max_hp) {
    max_hp = _max_hp;
}

void Player::set_energy(int _energy) {
    energy = _energy;
}

void Player::set_block(int _block) {
    block = _block;
}

string Player::get_name() const {
    return name;
}

int Player::get_hp() const {
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

int Player::get_block() const {
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

ostream& operator<<(ostream& os, const Player& player)
{
    os  << player.name << '\n';
    os << player.hp << " / " << player.max_hp << " HP (" << player.block <<" Block) \n";
    os << player.energy << " / " << player.max_energy << " Energy\n";
    os << "Potions: ";
    for (int potion_index = 0; potion_index < player.potions.get_count(); ++potion_index)
    {
        bool used = player.potions.get_used(potion_index);
        if (used)
            os << "[ ] ";
        else
            os << "[x] ";
    }
    cout <<'\n';
    return os;
}

void Player::play(const Card& card) {
    block += card.get_block();
    energy -= card.get_cost();

    discarded.emplace_back(card);

    for (auto it = hand.begin(); it != hand.end(); ++it)
        if (*it == card)
        {
            hand.erase(it);
            break;
        }
}

void Player::draw(int times) {
    while (times--)
    {
        Card top_deck = deck.back();
        hand.emplace_back(top_deck);
        deck.pop_back();

        if (deck.size() == 0)
        {
            shuffle_deck();
            discarded.clear();
        }
    }
}

void Player::discard() {
    for (const Card& card : hand)
        discarded.emplace_back(card);
    hand.clear();
}

void Player::shuffle_deck() {
    random_device rd;
    mt19937 g(rd());
    //
    for (const Card& card : discarded)
        deck.emplace_back(card);
    //
    shuffle(deck.begin(), deck.end(), g);
}

void Player::drink(unsigned int potion) {
    if (potions.get_used(potion) == false)
    {
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

    } else
    {
        cout<<"Potion already used.\n";
    }
}