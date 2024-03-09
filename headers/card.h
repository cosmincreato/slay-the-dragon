#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Card {
private:
    static unsigned int count;
    string name, info;
    unsigned int cost, attack, shield;
    const unsigned int id;
public:

    ///Constructors and destructors

    Card();
    Card(string _name, string _info, unsigned int _cost, unsigned int _attack, unsigned int _shield);
    Card(vector<string> _card);
    Card(const Card& c);
    ~Card();

    ///Setters

    void set_name(string _name);
    void set_info(string _info);
    void set_cost(unsigned int _cost);
    void set_attack(unsigned int _attack);
    void set_shield(unsigned int _shield);

    ///Getters

    string get_name() const;
    string get_info() const;
    unsigned int get_cost() const;
    unsigned int get_id() const;
    unsigned int get_attack() const;
    unsigned int get_shield() const;

    ///Operator overloading

    friend istream& operator>>(istream& is, Card& c);
    friend ostream& operator<<(ostream& os, const Card& c);
    Card& operator=(const Card& c);
};