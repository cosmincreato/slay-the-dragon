#include "../../headers/enemies/enemyFactory.hpp"
#include "../../headers/enemies/skeleton.hpp"
#include "../../headers/enemies/darkElf.hpp"
#include "../../headers/enemies/dragon.hpp"

std::shared_ptr<Enemy> EnemyFactory::create(EnemyFactory::Type t) {
    switch (t) {
        case SKELETON:
            return std::make_shared<Skeleton>();
        case DARK_ELF:
            return std::make_shared<DarkElf>();
        case DRAGON:
            return std::make_shared<Dragon>();
        default:
            exit(0);
    }
}