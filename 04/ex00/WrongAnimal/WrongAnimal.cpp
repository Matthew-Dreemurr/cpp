#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
: type("thing")
{
	std::cout << "[WrongAnimal] And God Created the " << type << "." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
: type(type)
{
	std::cout << "[WrongAnimal] And God Created the " << type << "." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &newAnimal)
: type(newAnimal.type)
{
	std::cout << "[WrongAnimal] God multiplied the " << this->type << "." << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "[WrongAnimal] By the wrath of God, " << type << " was killed." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &newAnimal)
{
	this->type = newAnimal.type;
	std::cout << "[WrongAnimal] God made the " << this->type << " multiply." << std::endl;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "[WrongAnimal] ...." << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return this->type;
}