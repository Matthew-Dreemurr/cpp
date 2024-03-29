#include "Cat.hpp"

Cat::Cat()
: Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "[Cat] And God Created the " << type << "." << std::endl;
}

Cat::Cat (const Cat &newDog)
: Animal()
{
	this->brain = new Brain();
	type = newDog.type;
	std::cout << "[Cat] God multiplied the " << this->type << "." << std::endl;
}

Cat &Cat::operator=(Cat &newDog) 
{
	this->type = newDog.type;
	this->brain = new Brain(*newDog.brain);
	std::cout << "[Cat] God made the " << this->type << " multiply." << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "[Cat] By the wrath of God, " << type << " was killed." << std::endl;
}

void Cat::makeSound() const {
	std::cout << "[Cat] Miaouuu~~~" << std::endl;
}
