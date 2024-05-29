#pragma once

#include <iostream>

template <class T>
class Details {
private:
    T entity;
public:
    T get_entity() const  {
        return entity;
    }

    void set_entity(T _entity) {
        entity = _entity;
    }

    void display() const {
        std::cout << entity;
    }

    void display_ptr() const {
        std::cout << entity->get_name() << '\n';
        std::cout << entity->get_hp() << " / " << entity->get_max_hp() << " HP\n";
    }
};

