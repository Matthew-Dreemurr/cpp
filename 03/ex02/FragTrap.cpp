#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap ( const std::string newName )
:	ClapTrap(newName)
{
	this->name = newName;
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
	std::cout << "[FragTrap] A new Hero is born, we call it " << name << ", he as " << hp << " hit points, " << ep << " energy points and " << ad << " attack damage" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "[FragTrap] " << name << " has fallen on the battlefield, may valhalla welcome him as a hero! " << std::endl;
}

FragTrap::FragTrap(const FragTrap &newClapTrap )
:	ClapTrap(newClapTrap)
{
	this->name = newClapTrap.name;
	this->hp = newClapTrap.hp;
	this->ep = newClapTrap.ep;
	this->ad = newClapTrap.ad;
	std::cout << "[FragTrap] We have cloned one of our best warrior, he is called " << name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &newClapTrap )
{
	name = newClapTrap.name;
	hp = newClapTrap.hp; ep = newClapTrap.ep;
	ad = newClapTrap.ad;
	std::cout << "[FragTrap] We have cloned one of our best warrior, he is called " << name << std::endl;
	return *this;
}

void FragTrap::highFivesGuys() {
	std::cout << "[FragTrap] " << this->name << " make a high fives request ?!" << std::endl;
};
