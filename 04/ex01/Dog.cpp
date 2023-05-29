#include "Dog.hpp"

Dog::Dog()
: Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "[Dog] And God Created the " << type << "." << std::endl;
}

Dog::Dog (const Dog &newDog)
: Animal()
{
	type = newDog.type;
	std::cout << "[Dog] God multiplied the " << this->type << "." << std::endl;
}

Dog &Dog::operator=(Dog &newDog) {
	this->type = newDog.type;
	this->brain = new Brain(*newDog.brain);
	std::cout << "[Dog] God made the " << this->type << " multiply." << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "[Dog] By the wrath of God, " << type << " was killed." << std::endl;
}

void Dog::makeSound() const {
	std::cout << "[Dog] Bark Bark !" << std::endl;
}
