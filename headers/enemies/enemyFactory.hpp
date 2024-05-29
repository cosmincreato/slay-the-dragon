#pragma once

#include <memory>
#include "enemy.hpp"

class EnemyFactory {
public:
    enum Type {SKELETON, DARK_ELF, DRAGON};
    std::shared_ptr<Enemy> create(Type t);
};