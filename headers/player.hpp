#pragma once

#include <iostream>
#include "card.hpp"
#include "potions.hpp"

typedef std::vector<Card> Cards;

class Player {
private:
    std::string name;
    const unsigned int max_energy = 3;
    unsigned int max_hp, block;
    int hp, energy;
    Cards deck, hand, discarded;
    Potions potions;
public:

    ///Constructors and destructors
    Player();

    ~Player();

    ///Setters
    void set_name(std::string _name);

    void set_hp(int _hp);

    void set_max_hp(int _max_hp);

    void set_energy(int _energy);

    void set_block(int _block);

    ///Getters
    std::string get_name() const;

    int get_hp() const;

    int get_max_hp() const;

    int get_energy() const;

    int get_max_energy() const;

    int get_block() const;

    Cards get_deck() const;

    Cards get_hand() const;

    Potions get_potions() const;

    ///Operator overloading

    friend std::ostream &operator<<(std::ostream &os, const Player &player);


    ///
    void play(const Card &card);

    void draw(int times = 1);

    void discard();

    void shuffle_deck();

    void drink(unsigned int potion);
};