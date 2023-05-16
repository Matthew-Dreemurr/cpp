#include "ClapTrap.hpp"

#include <iostream>
ClapTrap::ClapTrap ()
: name("NoName"), hp(10), ep(10), ad(0)
{
	std::cout << "[ClapTrap] A new Hero is born, we call it " << name << ", he as " << hp << " hit points, " << ep << " energy points and " << ad << " attack damage" << std::endl;
}

ClapTrap::ClapTrap ( const std::string newName )
: name(newName), hp(10), ep(10), ad(0)
{
	std::cout << "[ClapTrap] A new Hero is born, we call it " << name << ", he as " << hp << " hit points, " << ep << " energy points and " << ad << " attack damage" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "[ClapTrap] " << name << " has fallen on the battlefield, may valhalla welcome him as a hero! " << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &newClapTrap )
:	name(newClapTrap.name),
	hp(newClapTrap.hp),
	ep(newClapTrap.ep),
	ad(newClapTrap.ad)
{
	std::cout << "[ClapTrap] We have cloned one of our best warrior, he is called " << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &newClapTrap )
{
	name = newClapTrap.name;
	hp = newClapTrap.hp; ep = newClapTrap.ep;
	ad = newClapTrap.ad;
	std::cout << "[ClapTrap] We have cloned one of our best warrior, he is called " << name << std::endl;
	return *this;
}


void ClapTrap::attack( const std::string& target ) {
	if (!hp) {
		std::cout << "[ClapTrap] " << this->name << " is death, death cannot figth..." << std::endl;
		return;
	}
	// Attacking and repairing cost 1 energy point
	if (removePoints(this->ep, 1)) {
		std::cout << "[ClapTrap] " << this->name << " attacks " << target << ", causing " << this->ad << " points of damage! " << ep << " energie points left" << std::endl;
		return;
	}
	std::cout << "[ClapTrap] " << this->name << " doesn't have enough energy to attack" << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount ) {
	// Check if is death
	if (removePoints(this->hp, amount)) {
		std::cout << "[ClapTrap] " << this->name << " loses " << amount << " of hp after the hit, it only has " << this->hp << " left" << std::endl;
		return ;
	}
	std::cout << "[ClapTrap] The lifeless body of " << this->name << " takes a hit of " << amount << " damage, it is at 0 hp" << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (!hp) {
		std::cout << "[ClapTrap] " << this->name << " is death, death cannot repaire it's self..." << std::endl;
		return;
	}
// Attacking and repairing cost 1 energy point
	if (removePoints(this->ep, 1)) {
		this->hp += amount;
		std::cout << "[ClapTrap] " << this->name << " repairs itself and have " << this->hp << " now, only " << this->ep << " energie points left" << std::endl;
		return;
	}
	std::cout << "[ClapTrap] " << this->name << " don't have enough energy to repairs itself" << std::endl;
}

unsigned int ClapTrap::removePoints(unsigned int &ref, const unsigned int amount) {
	if (amount > ref) {
		ref = 0;
		return 0;
	}
	ref -= amount;
	return ref;
}
