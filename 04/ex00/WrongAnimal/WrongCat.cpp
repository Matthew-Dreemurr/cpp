#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "[WrongCat] And God Created the " << type << "." << std::endl;
}

WrongCat::WrongCat (const WrongCat &newDog)
{
	type = newDog.type;
	std::cout << "[WrongCat] God multiplied the " << this->type << "." << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat &newDog) {
	this->type = newDog.type;
	std::cout << "[WrongCat] God made the " << this->type << " multiply." << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] By the wrath of God, " << type << " was killed." << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "[WrongCat] Miaouuu~~~" << std::endl;
}