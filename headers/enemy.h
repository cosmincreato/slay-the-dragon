#pragma once

#include <iostream>

using namespace std;

class Enemy {
private:
    const string name = "Pizdoiu";
    int attack, hp, max_hp;
public:
    ///Constructors and destructors

    Enemy();
    ~Enemy();

    ///Setters

    void set_attack(int _attack);
    void set_hp(int _hp);
    void set_max_hp(int _max_hp);


    ///Getters

    int get_attack() const;
    int get_hp() const;
    int get_max_hp() const;

    ///Operator overloading

    friend ostream& operator<<(ostream& os, const Enemy& enemy);
};