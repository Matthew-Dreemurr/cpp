#include "Character.hpp"

Character::Character(std::string name) {
	this->name = name;
}

Character::~Character() {
	delete[] this->inventory;
}

	void	Character::delGround() {

	}

	/**
	 * Will delete actual inventory and copy the `src` inventory
	*/
	void	Character::overWriteInventory(Character &src) {

		// Free all inventory before overwrite
		for (int index = 0; index < INVENTORY_SLOTS; index++) {
			if (this->inventory[index]) {
				delete this->inventory[index];
			}
		}
		
		for (int index = 0; index < INVENTORY_SLOTS; index++) {
			if (src.inventory[index]) {
				// Clone will create a new IMateria
				this->inventory[index] = src.inventory[index]->clone();
			}
		}

	}

Character* Character::operator=(Character &r) {
	this->name = r.name;
	
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
	this->inventory[idx]->use(target);
}
