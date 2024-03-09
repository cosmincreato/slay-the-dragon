#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../headers/cardList.h"

using namespace std;
ifstream fin("../deck.txt");

vector<string> split_card(const string& s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

CardList::CardList() {
     //cout << "CardList Constructor\n";

    ///Create the Deck using the "deck.txt" file
    string card;
    while (getline(fin, card))
    {
        vector<string> sp = split_card(card, ',');
        deck.emplace_back(sp);
    }
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