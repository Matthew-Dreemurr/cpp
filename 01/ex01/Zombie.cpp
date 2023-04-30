//
// Created by fluffy on 2/23/23.
//

#include "Zombie.hpp"

Zombie::Zombie(const std::string &name) 
: name(name)
{}

Zombie::Zombie(const Zombie& newZombie) {
	*this = newZombie;
}

Zombie::Zombie()
: name("Zombie")
{}

Zombie &Zombie::operator=(const Zombie &newZombie) {
    this->name = newZombie.name;
    return *this;
}

Zombie::~Zombie() {
    std::cout << "Kill " << this->name << " Zombie" << std::endl;
}

void Zombie::announce() const {
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &name) {
	this->name = name;
}
