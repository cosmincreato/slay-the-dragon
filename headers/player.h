#pragma once

#include <iostream>

using namespace std;

class Player {
private:
    string name;
    const unsigned int max_energy = 3;
    unsigned int max_hp;
    int hp, energy;
public:

    ///Constructors and destructors
    Player();
    ~Player();

    ///Setters
    void set_name(string _name);
    void set_hp(int _hp);
    void set_max_hp(int _max_hp);
    void set_energy(int _energy);

    ///Getters
    string get_name() const;
    int get_hp() const;
    int get_max_hp() const;
    int get_energy() const;
    int get_max_energy() const;

    ///Operator overloading

    friend ostream& operator<<(ostream& os, const Player& player);
};