#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string newName)
:
weapon(NULL),
name(newName)
{}

void HumanB::attack() {
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
	this->weapon = &newWeapon;
}
