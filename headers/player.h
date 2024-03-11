#pragma once

#include <iostream>
#include "card.h"

using namespace std;

typedef vector<Card> Cards;

class Player {
private:
    string name;
    const unsigned int max_energy = 3;
    unsigned int max_hp, block;
    int hp, energy;
    Cards deck, hand, discarded;
public:

    ///Constructors and destructors
    Player();
    ~Player();

    ///Setters
    void set_name(string _name);
    void set_hp(int _hp);
    void set_max_hp(int _max_hp);
    void set_energy(int _energy);
    void set_block(int _block);

    ///Getters
    string get_name() const;
    int get_hp() const;
    int get_max_hp() const;
    int get_energy() const;
    int get_max_energy() const;
    int get_block() const;
    Cards get_deck() const;
    Cards get_hand() const;

    ///Operator overloading

    friend ostream& operator<<(ostream& os, const Player& player);


    ///
    void play(const Card& card);
    void draw(int times = 1);
    void discard();
    void shuffle_deck();
};