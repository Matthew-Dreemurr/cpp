//
// Created by fluffy on 2/23/23.
//

#include "Zombie.hpp"

Zombie *newZombie( std::string name )
{
	Zombie *zombie = new Zombie(name);
	// std::cout << "[DEBUG] Create " << name << " zombie" << std::endl;
	return zombie;
}