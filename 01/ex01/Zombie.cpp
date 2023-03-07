//
// Created by fluffy on 2/23/23.
//

#include "Zombie.hpp"

Zombie::Zombie() {
    this->name = "No name";
    this->hordeSize = 0;
}

Zombie::Zombie(const Zombie &newZombie) {
    *this = newZombie;
}

Zombie &Zombie::operator=(const Zombie &newZombie) {
    this->name = newZombie.name;
    return *this;
}

Zombie::~Zombie() {
//    if (this->hordeSize)
//        for (int i = 0; i < this->hordeSize; ++i) {
//            delete this->horde;
//        }
    std::cout << "Kill " << this->name << " Zombie" << std::endl;
}

void Zombie::announce() {
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
