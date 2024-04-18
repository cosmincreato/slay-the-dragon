#include "../../headers/enemies/skeleton.hpp"

Skeleton::Skeleton()
        : Enemy("Skeleton", 10, 100, 100) {
    // std::cout << "Constructor dragon\n";
}

Skeleton::~Skeleton() {
    // std::cout << "Destructor dragon\n";
}

void Skeleton::Effect() {
    std::cout << "Skeleton Effect\n";
}