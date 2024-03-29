#include "Animal.hpp"

Animal::Animal()
: type("thing")
{
	std::cout << "[Animal] And God Created the " << type << "." << std::endl;
}

Animal::Animal(std::string type)
: type(type)
{
	std::cout << "[Animal] And God Created the " << type << "." << std::endl;
}

Animal::Animal(const Animal &newAnimal)
: type(newAnimal.type)
{
	std::cout << "[Animal] God multiplied the " << this->type << "." << std::endl;
}

Animal::~Animal() {
	std::cout << "[Animal] By the wrath of God, " << type << " was killed." << std::endl;
}

Animal &Animal::operator=(Animal &newAnimal)
{
	this->type = newAnimal.type;
	std::cout << "[Animal] God made the " << this->type << " multiply." << std::endl;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "[Animal] ...." << std::endl;
}

std::string Animal::getType(void) const {
	return this->type;
}