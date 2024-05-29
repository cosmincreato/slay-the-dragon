#pragma once

#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include "../player.hpp"

class Enemy {
protected:
    std::string name, effect_info;
    int hp, max_hp;
    float attack;
public:
    ///Constructors and destructors

    Enemy();

    Enemy(std::string _name, int _attack, int _hp, int _max_hp, std::string _effect_info);

    ~Enemy();

    ///Setters

    void set_attack(float _attack);

    void set_hp(int _hp);

    void set_max_hp(int _max_hp);

    /// Template function
    template<class T>
    void deal_damage(Player& player, T value);

    ///Getters

    std::string get_name() const;

    float get_attack() const;

    int get_hp() const;

    int get_max_hp() const;

    std::string get_effect_info() const;

    ///Operator overloading

    friend std::ostream& operator<<(std::ostream &os, const Enemy &enemy);

    void operator=(Enemy& e);

    /// Pure virtual function

    virtual void effect(Player& player) = 0;
};

