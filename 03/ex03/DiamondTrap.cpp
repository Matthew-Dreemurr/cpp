#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap ()
{
	this->name = "test";
	ClapTrap::name = "test_clap_name";
	this->hp = FragTrap::hp;
	this->ep = ScavTrap::ep;
	this->ad = FragTrap::ad;
	std::cout << "[DiamondTrap] A new Hero is born, we call it " << name << ", he as " << hp << " hit points, " << ep << " energy points and " << ad << " attack damage" << std::endl;
}

DiamondTrap::DiamondTrap ( const std::string newName )
{
	this->name = newName;
	ClapTrap::name = newName + "_clap_name";
	this->hp = FragTrap::hp;
	this->ep = ScavTrap::ep;
	this->ad = FragTrap::ad;
	std::cout << &(FragTrap::ad) << " " << &(ScavTrap::ad) << " " << &this->ad << std::endl;
	std::cout << "[DiamondTrap] A new Hero is born, we call it " << name << ", he as " << hp << " hit points, " << ep << " energy points and " << ad << " attack damage" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "[DiamondTrap] " << name << " has fallen on the battlefield, may valhalla welcome him as a hero! " << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &newClapTrap )
: ClapTrap(), FragTrap(), ScavTrap()
{
	this->name = newClapTrap.name;
	this->hp = newClapTrap.hp;
	this->ep = newClapTrap.ep;
	this->ad = newClapTrap.ad;
	std::cout << "[DiamondTrap] We have cloned one of our best warrior, he is called " << name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &newClapTrap )
{
	name = newClapTrap.name;
	hp = newClapTrap.hp; ep = newClapTrap.ep;
	ad = newClapTrap.ad;
	std::cout << "[DiamondTrap] We have cloned one of our best warrior, he is called " << name << std::endl;
	return *this;
}

void DiamondTrap::highFivesGuys() {
	std::cout << "[DiamondTrap] " << this->name << " make a high fives request ?!" << std::endl;
};

void DiamondTrap::attack( const std::string& target ) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "[WHOAMI] " << this->name << " " << ClapTrap::name << std::endl;
}