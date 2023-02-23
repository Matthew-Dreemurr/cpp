//
// Created by fluffy on 2/23/23.
//

#include "Zombie.hpp"

void Zombie::randomChump( std::string name ) {
    this->newZombie(name);
    this->announce();
}