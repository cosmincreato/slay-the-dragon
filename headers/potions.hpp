#pragma once

#include <iostream>

class Potions {
private:
    static const int count = 3;
    bool used[count];
    const std::string name[count] = {"Blood Potion", "Energy Potion", "Swift Potion"},
            info[count] = {"Heal 10% of your max HP.", "Refresh your energy.", "Draw 3 cards."};

public:
    Potions();

    static int get_count();

    std::string get_name(unsigned int potion) const;

    std::string get_info(unsigned int potion) const;

    void set_used(unsigned int potion, bool _used);

    bool get_used(unsigned int potion) const;

};

