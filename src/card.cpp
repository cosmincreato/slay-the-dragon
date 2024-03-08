#include <iostream>
#include "../headers/card.h"

using namespace std;

const unsigned int MIN_COST = 0, MAX_COST = 3;
unsigned int Card::count = 0;

bool valid_number(string s)
{
    for (int i = 0; i<s.length(); ++i)
        if (!isdigit(s[i]))
            return false;

    return true;
}

bool valid_cost(string s)
{

    ///Not a number
    if (!valid_number(s))
        return false;

    ///Not in range
    int cost = stoi(s);
    if (cost < MIN_COST || cost > MAX_COST)
        return false;

    return true;
}

Card::Card()
:   name("None"),
    info("None"),
    cost(0),
    attack(0),
    shield(0),
    id(++count) {
    cout << "Constructor apelat (ID: " << id << ")\n";
}

Card::Card(string _name, string _info, unsigned int _cost, unsigned int _attack, unsigned int _shield)
:   name(_name),
    info(_info),
    cost(_cost),
    attack(_attack),
    shield(_shield),
    id(++count) {
    cout << "Constructor apelat (ID: " << id << ")\n";
}

Card::Card(const Card& c)
:   name(c.name),
    info(c.info),
    cost(c.cost),
    attack(c.attack),
    shield(c.shield),
    id(++count) {
    cout << "Copy constructor (ID: " << id << ")\n";
}

Card::~Card()
{
    cout << "Destructor apelat\n";
}

///Setters

void Card::set_name(string _name) {
    name = _name;
}

void Card::set_info(string _info) {
    info = _info;
}

void Card::set_cost(unsigned int _cost) {
    cost = _cost;
}

void Card::set_attack(unsigned int _attack) {
    attack = _attack;
}

void Card::set_shield(unsigned int _shield) {
    shield = _shield;
}

///Getters

string Card::get_name() const
{
    return name;
}

string Card::get_info() const
{
    return info;
}

unsigned int Card::get_cost() const
{
    return cost;
}

unsigned int Card::get_attack() const {
    return attack;
}

unsigned int Card::get_shield() const {
    return shield;
}

unsigned int Card::get_id() const
{
    return id;
}

///Operator overloading

istream& operator>>(istream& is, Card& c)
{
    string _cost, _attack, _shield;
    cout << "[Card Data]\n";
    cout << "Name: ";
    getline(cin, c.name);
    cout << "Info: ";
    getline(cin, c.info);
    cout << "Cost: "; cin >> _cost;
    while (!valid_cost(_cost))
    {
        cout << "Expected a number between " << MIN_COST << " and " << MAX_COST << ". Try again.\n";
        cout << "Cost: "; cin >> _cost;
    }
    c.cost = stoi(_cost);
    cout <<"Attack: "; cin>>_attack;
    while (!valid_number(_attack))
    {
        cout << "Expected a positive integer. Try again.\n";
        cout <<"Attack: "; cin>>_attack;
    }
    c.attack = stoi(_attack);
    cout <<"Shield: "; cin>>_shield;
    while (!valid_number(_shield))
    {
        cout << "Expected a positive integer. Try again.\n";
        cout <<"Shield: "; cin>>_shield;
    }
    c.shield = stoi(_shield);
    return is;
}

ostream& operator<<(ostream& os, const Card& c)
{
    os << '[';
    os << '"' << c.name << '"';
    os << " | ";
    os << c.cost << " Energy";
    os << " | ";
    os << c.info;
    os << "]\n";
    return os;
}

Card& Card::operator=(const Card& c)
{
    name = c.name,
    info = c.info,
    cost = c.cost;
    return *this;
}