#pragma once

#include <iostream>
#include <vector>

class Card {
private:
    static unsigned int count;
    std::string name, info;
    unsigned int cost, attack, block;
    const unsigned int id;
public:

    ///Constructors and destructors

    Card();

    Card(std::string _name, std::string _info, unsigned int _cost, unsigned int _attack, unsigned int _block);

    explicit Card(std::vector <std::string> _card);

    Card(const Card &c);

    ~Card();

    ///Setters

    void set_name(std::string _name);

    void set_info(std::string _info);

    void set_cost(unsigned int _cost);

    void set_attack(unsigned int _attack);

    void set_block(unsigned int _block);

    ///Getters

    std::string get_name() const;

    std::string get_info() const;

    unsigned int get_cost() const;

    unsigned int get_id() const;

    unsigned int get_attack() const;

    unsigned int get_block() const;

    ///Operator overloading

    friend std::istream &operator>>(std::istream &is, Card &c);

    friend std::ostream &operator<<(std::ostream &os, const Card &c);

    Card &operator=(const Card &c);

    bool operator==(const Card &c);
};