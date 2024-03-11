#include <iostream>
#include <utility>
#include "../headers/card.h"

using namespace std;

const unsigned int MIN_COST = 0, MAX_COST = 3;

unsigned int Card::count = 0;

bool valid_number(const string& s)
{
    for (char i : s)
        if (!isdigit(i))
            return false;

    return true;
}

bool valid_cost(const string& s)
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
    block(0),
    id(++count) {
    // cout << "Card constructor (ID: " << id << ")\n";
}

Card::Card(string _name, string _info, unsigned int _cost, unsigned int _attack, unsigned int _block)
:   name(std::move(_name)),
    info(std::move(_info)),
    cost(_cost),
    attack(_attack),
    block(_block),
    id(++count) {
    // cout << "Card constructor (ID: " << id << ")\n";
}

Card::Card(vector<std::string> _card): id(++count) {
    unsigned int index = 0;
    /// Catch card format exception
    try
    {
        if (_card.size() != 5)
            throw (_card.size());
    }
    catch (size_t err_size) {
        cout << "Wrong card format. Expected 5 values, only received " << err_size << ".\n";
        exit(1);
    }

    /// Catch card number exception
    for (auto it = _card.begin(); it != _card.end(); ++it, ++index)
    {
        try {
            if ((*it).empty())
                throw (index + 1);
        }
        catch (unsigned int err_null_ind) {
            cout << "Received a null value while parsing card data (Pos: " << err_null_ind << ").\n";
            exit(1);
        }
        //
        if (index >= 2 && index <= 4)
        {
            try {
                if (!valid_number(*it))
                    throw (*it);
            }
            catch (string err_int) {
                cout << "Expected a number while parsing card data. Received a string (" << err_int << ").\n";
                exit(1);
            }
        }

        if (index == 0)
            name = *it;
        else if (index == 1)
            info = *it;
        else if (index == 2)
            cost = stoi(*it);
        else if (index == 3)
            attack = stoi(*it);
        else if (index == 4)
            block = stoi(*it);
    }
}


Card::Card(const Card& c)
:   name(c.name),
    info(c.info),
    cost(c.cost),
    attack(c.attack),
    block(c.block),
    id(++count) {
    // cout << "Card Copy constructor (ID: " << id << ")\n";
}

Card::~Card() = default;

///Setters

void Card::set_name(string _name) {
    name = std::move(_name);
}

void Card::set_info(string _info) {
    info = std::move(_info);
}

void Card::set_cost(unsigned int _cost) {
    cost = _cost;
}

void Card::set_attack(unsigned int _attack) {
    attack = _attack;
}

void Card::set_block(unsigned int _block) {
    block = _block;
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

unsigned int Card::get_block() const {
    return block;
}

unsigned int Card::get_id() const
{
    return id;
}

///Operator overloading

istream& operator>>(istream& is, Card& c)
{
    string _cost, _attack, _block;
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
    cout <<"Block: "; cin>>_block;
    while (!valid_number(_block))
    {
        cout << "Expected a positive integer. Try again.\n";
        cout <<"Block: "; cin>>_block;
    }
    c.block = stoi(_block);
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
    attack = c.attack;
    block = c.block;
    return *this;
}

bool Card::operator==(const Card &c) {
    if (name != c.name)
        return false;
    if (info != c.info)
        return false;
    if (cost != c.cost)
        return false;
    if (attack != c.attack)
        return false;
    if (block != c.block)
        return false;
    return true;
}