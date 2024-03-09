#pragma once

#include <iostream>
#include <vector>
#include "card.h"

using namespace std;

typedef vector<Card> Cards;

class CardList {
private:
    Cards hand, deck;

public:
    CardList();
    ~CardList();

    Cards get_deck() const;
    Cards get_hand() const;

    void show_hand();
    void show_deck();
    void draw();

    friend void show(const Cards &cards);
};
