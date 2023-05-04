//
// Created by fluffy on 2/23/23.
//

#include "Zombie.hpp"

int main(void) {
	Zombie *zombie = newZombie("Keven");
	zombie->announce();
	delete zombie;
	randomChump("Tristan");
}