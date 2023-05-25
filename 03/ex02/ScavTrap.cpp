#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap ( const std::string newName )
:	ClapTrap(newName)
{
	this->name = newName;
	this->hp = ClapTrap::hp;
	this->ep = 100;
	this->ad = 30;
	std::cout << "[ScavTrap] A new Hero is born, we call it " << name << ", he as " << hp << " hit points, " << ep << " energy points and " << ad << " attack damage" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "[ScavTrap] " << name << " has fallen on the battlefield, may valhalla welcome him as a hero! " << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &newClapTrap )
:	ClapTrap(newClapTrap)
{
	this->name = newClapTrap.name;
	this->hp = newClapTrap.hp;
	this->ep = newClapTrap.ep;
	this->ad = newClapTrap.ad;
	std::cout << "[ScavTrap] We have cloned one of our best warrior, he is called " << name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &newClapTrap )
{
	name = newClapTrap.name;
	hp = newClapTrap.hp; ep = newClapTrap.ep;
	ad = newClapTrap.ad;
	std::cout << "[ScavTrap] We have cloned one of our best warrior, he is called " << name << std::endl;
	return *this;
}

void ScavTrap::guardGate() {
	std::cout << "[ScavTrap] " << this->name << " is now in Gate keeper mode." << std::endl;
};
