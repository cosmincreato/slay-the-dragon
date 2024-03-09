#include <iostream>
#include "../headers/cardList.h"

using namespace std;

CardList::CardList() {
    // cout << "CardList Constructor\n";

    ///Create the Deck
    deck.emplace_back("Strike", "Deal 6 damage", 1, 6, 0);
    deck.emplace_back("Strike", "Deal 6 damage", 1, 6, 0);
    deck.emplace_back("Strike", "Deal 6 damage", 1, 6, 0);
    deck.emplace_back("Strike", "Deal 6 damage", 1, 6, 0);
    deck.emplace_back("Strike", "Deal 6 damage", 1, 6, 0);
    deck.emplace_back("Defend", "Gain 5 block", 1, 0, 5);
    deck.emplace_back("Defend", "Gain 5 block", 1, 0, 5);
    deck.emplace_back("Defend", "Gain 5 block", 1, 0, 5);
    deck.emplace_back("Defend", "Gain 5 block", 1, 0, 5);
    deck.emplace_back("Defend", "Gain 5 block", 1, 0, 5);
    deck.emplace_back("Iron Wave","Deal 5 damage. Gain 5 block.",2,5,5);
    deck.emplace_back("Iron Wave","Deal 5 damage. Gain 5 block.",2,5,5);
    deck.emplace_back("Iron Wave","Deal 5 damage. Gain 5 block.",2,5,5);
}
CardList::~CardList() {
    // cout << "CardList Destructor\n";
}

Cards CardList::get_deck() const {
    return deck;
}

void show(const Cards& cards) {
    cout << '[' << cards.size() << " Cards]\n";
    for (auto it = cards.begin(); it!=cards.end(); ++it)
        cout << *it;
}

void CardList::show_hand() {
    show(hand);
    cout << "\n["<<deck.size()<<" left in deck]";
}

void CardList::show_deck() {
    show(deck);
}