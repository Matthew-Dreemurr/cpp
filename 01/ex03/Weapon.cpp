#include "Weapon.hpp"

Weapon::Weapon(std::string newType)
: type(newType)
{}

Weapon::~Weapon()
{
}

std::string Weapon::getType() {
	return this->type;
}

void Weapon::setType(std::string type) {
	this->type = type;
}
