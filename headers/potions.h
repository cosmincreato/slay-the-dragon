#pragma once

#include <iostream>

using namespace std;

class Potions {
private:
    static const int count = 3;
    bool used[count];
    const string name[count] = {"Blood Potion", "Energy Potion", "Swift Potion"},
                info[count] = {"Heal 10% of your max HP.", "Refresh your energy.", "Draw 3 cards."};

public:
    Potions();

    int get_count() const;
    string get_name(unsigned int potion) const;
    string get_info(unsigned int potion) const;

    void set_used(unsigned int potion, bool _used);
    bool get_used(unsigned int potion) const;

};

