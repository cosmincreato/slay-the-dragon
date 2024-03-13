#include "../headers/potions.h"

using namespace std;

Potions::Potions()
    :used{false, false, false}
    {}


bool Potions::get_used(unsigned int potion) const {
    return used[potion];
}

void Potions::set_used(unsigned int potion, bool _used) {
    used[potion] = _used;
}

int Potions::get_count() {
    return count;
}

string Potions::get_name(unsigned int potion) const {
    return name[potion];
}

string Potions::get_info(unsigned int potion) const {
    return info[potion];
}