#pragma once

#include <iostream>
#include <memory>
#include "../player.hpp"

class Enemy {
private:
    std::string name, effect_info;
    int attack, hp, max_hp;
public:
    ///Constructors and destructors

    Enemy();

    Enemy(std::string _name, int _attack, int _hp, int _max_hp, std::string _effect_info);

    ~Enemy();

    ///Setters

    void set_attack(int _attack);

    void set_hp(int _hp);

    void set_max_hp(int _max_hp);

    void deal_damage(Player& player, int value);


    ///Getters

    std::string get_name() const;

    int get_attack() const;

    int get_hp() const;

    std::string get_effect_info() const;

    ///Operator overloading

    friend std::ostream &operator<<(std::ostream &os, const Enemy &enemy);

    friend std::ostream &operator<<(std::ostream &os, const std::unique_ptr<Enemy>& enemyPtr);

    /// Pure virtual function

    virtual void effect(Player& player) = 0;
};