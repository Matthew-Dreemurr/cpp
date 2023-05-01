#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(std::string newName, Weapon &newWeapon)
:
weapon(newWeapon),
name(newName)
{}

void HumanA::attack() {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
