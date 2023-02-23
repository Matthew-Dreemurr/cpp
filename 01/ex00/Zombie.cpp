//
// Created by fluffy on 2/23/23.
//

#include "Zombie.hpp"

Zombie::Zombie() {
    this->name = "No name";
}

Zombie::Zombie(const Zombie &newZombie) {
    *this = newZombie;
}

Zombie &Zombie::operator=(const Zombie &newZombie) {
    this->name = newZombie.name;
    return *this;
}

Zombie::~Zombie() {
    std::cout << "Kill " << this->name << " Zombie" << std::endl;
}

void Zombie::announce() {
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
