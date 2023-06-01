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

	// Find a free slot on the ground
	int index = 0;
	while (index < INVENTORY_SLOTS) {
		if (!this->ground[index]) {
			this->ground[index] = this->inventory[idx];
			break;
		}
		index++;
	}

	if (index > INVENTORY_SLOTS) {
		std::cout << "[Character] The ground is full!" << std::endl;
		return;
	}

	this->inventory[idx] = nullptr;

}

void Character::use(int idx, ICharacter& target) {
	if (!this->inventory[idx]) {
		std::cout << "[Character] This slot is empty [" << idx << "]" << std::endl;
		return;
	}
	this->inventory[idx]->use(*this);
}
