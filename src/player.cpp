#include <iostream>
#include "../headers/player.h"

using namespace std;

Player::Player()
:   name("Player"),
    hp(0),
    max_hp(0),
    energy(0) {
    cout << "Player Constructor\n";
}

Player::~Player() {
    cout<< "Player Destructor\n";
}

void Player::set_name(string _name) {
    name = _name;
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

ostream& operator<<(ostream& os, const Player& player)
{
    os  << player.name << '\n';
    os << player.hp << " / " << player.max_hp << " HP\n";
    os << player.energy << " / " << player.max_energy << " Energy\n";
    return os;
}
