#include <iostream>
#include "../../headers/enemies/enemy.hpp"

Enemy::Enemy()
        : attack(1),
          hp(1),
          max_hp(1) {
    // std::cout << "Enemy Constructor\n";
}

Enemy::Enemy(std::string _name, int _attack, int _hp, int _max_hp)
        : name(_name),
          attack(_attack),
          hp(_hp),
          max_hp(_max_hp) {
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

std::ostream &operator<<(std::ostream &os, const Enemy &enemy) {
    os << enemy.name << '\n';
    os << enemy.hp << " / " << enemy.max_hp << " HP\n";
    return os;
}

std::ostream &operator<<(std::ostream &os, const std::unique_ptr<Enemy> &enemyPtr) {
    os << (*enemyPtr).name << '\n';
    os << (*enemyPtr).hp << " / " << (*enemyPtr).max_hp << " HP\n";
    return os;
}