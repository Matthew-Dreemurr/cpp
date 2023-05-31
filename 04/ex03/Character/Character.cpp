#include "Character.hpp"

Character::Character() {
}

Character::~Character() {
}

std::string const & Character::getName() const {
	return this->name;
}

void Character::equip(AMateria* m) {

	if (!m) {
		return ;
	}

	int index = 0;
	while (index < INVENTORY_SLOTS) {
		if (!this->inventory[index]) {
			this->inventory[index] = m;
			break;
		}
		index++;
	}
}

void Character::unequip(int idx) {
	if (idx < 0 && idx > INVENTORY_SLOTS) {
		return;
	}

	if (!this->inventory[idx]) {
		return;
	}
	//WIP
	//TODO choose a behaviour
	delete this->inventory[idx];
	this->inventory[idx] = nullptr;

}

void Character::use(int idx, ICharacter& target) {
}
