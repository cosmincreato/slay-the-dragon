#include <iostream>
#include "../headers/enemy.h"

using namespace std;

Enemy::Enemy()
:   attack(0),
    hp(0),
    max_hp(0) {
    // cout << "Enemy Constructor\n";
}

Enemy::~Enemy() = default;

void Enemy::set_attack(int _attack) {
    attack = _attack;
}

void Enemy::set_hp(int _hp) {
    hp = _hp;
}

void Enemy::set_max_hp(int _max_hp) {
    max_hp = _max_hp;
}

int Enemy::get_attack() const {
    return attack;
}

int Enemy::get_hp() const {
    return hp;
}

int Enemy::get_max_hp() const {
    return max_hp;
}

ostream& operator<<(ostream& os, const Enemy& enemy)
{
    os << enemy.name << '\n';
    os << enemy.hp << " / " << enemy.max_hp << " HP\n";
    return os;
}