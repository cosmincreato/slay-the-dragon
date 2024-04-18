#pragma once

#include <iostream>
#include <memory>

class Enemy {
private:
    std::string name;
    int attack, hp, max_hp;
public:
    ///Constructors and destructors

    Enemy();

    Enemy(std::string _name, int _attack, int _hp, int _max_hp);

    ~Enemy();

    ///Setters

    void set_attack(int _attack);

    void set_hp(int _hp);

    void set_max_hp(int _max_hp);


    ///Getters

    int get_attack() const;

    int get_hp() const;

    ///Operator overloading

    friend std::ostream &operator<<(std::ostream &os, const Enemy &enemy);

    friend std::ostream &operator<<(std::ostream &os, const std::unique_ptr<Enemy>& enemyPtr);

    /// Pure virtual function

    virtual void Effect() = 0;
};