#include <iostream>
#include "../../headers/enemies/enemy.hpp"

Enemy::Enemy()
        : attack(1),
          hp(1),
          max_hp(1) {
    // std::cout << "Enemy Constructor\n";
}

Enemy::Enemy(std::string _name, int _attack, int _hp, int _max_hp, std::string _effect_info)
        : name(_name),
          attack(_attack),
          hp(_hp),
          max_hp(_max_hp),
          effect_info(_effect_info) {
}

Enemy::~Enemy() = default;

void Enemy::set_attack(float _attack) {
    attack = _attack;
}

void Enemy::set_hp(int _hp) {
    hp = _hp;
    if (hp > max_hp)
        hp = max_hp;
}

void Enemy::set_max_hp(int _max_hp) {
    max_hp = _max_hp;
}

std::string Enemy::get_name() const {
    return name;
}

float Enemy::get_attack() const {
    return attack;
}

int Enemy::get_hp() const {
    return hp;
}

std::string Enemy::get_effect_info() const {
    return effect_info;
}

int Enemy::get_max_hp() const {
    return max_hp;
}


std::ostream &operator<<(std::ostream &os, const Enemy &enemy) {
    os << enemy.name << '\n';
    os << enemy.hp << " / " << enemy.max_hp << " HP\n";
    return os;
}

void Enemy::operator=(Enemy &e) {
    name = e.name;
    effect_info = e.effect_info;
    hp = e.hp;
    max_hp = e.max_hp;
    attack = e.attack;
}


// The enemy deals damage (must go through block first)
template<class T>
void Enemy::deal_damage(Player &player, T value) {
    if (player.get_block() > 0) {
        T crt_block = player.get_block();
        //
        if (player.get_block() - value < 0)
            player.set_block(player.get_block() - value);
        else
            player.set_block(0);
        value -= crt_block;
        if (value < 0)
            value = 0;
    }
    player.set_hp((player.get_hp() - value));
}

/// Template specialization
template<>
void Enemy::deal_damage<std::vector<float>>(Player &player, const std::vector<float> values) {
    int value = 0;
    for (auto val : values)
        value += val;
    std::cout<<'\n';
    if (player.get_block() > 0) {
        int crt_block = player.get_block();
        //
        if (player.get_block() - value < 0)
            player.set_block(player.get_block() - value);
        else
            player.set_block(0);
        value -= crt_block;
        if (value < 0)
            value = 0;
    }
    player.set_hp((player.get_hp() - value));
}

template void Enemy::deal_damage<int>(Player& player, int value);
template void Enemy::deal_damage<float>(Player& player, float value);
