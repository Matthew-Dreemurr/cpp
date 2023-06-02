#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
}

MateriaSource::~MateriaSource() {
	for (int index = 0; index < INVENTORY_SLOTS; index++) {
		if (this->materia_slots[index]) {
			delete this->materia_slots[index];
		}
	}
}

void MateriaSource::learnMateria(AMateria* newMateria) {
	// Find a free slot on the ground
	int index = 0;
	while (index < INVENTORY_SLOTS) {
		if (!this->materia_slots[index]) {
			this->materia_slots[index] = newMateria;
			break;
		}
		index++;
	}

	if (index > INVENTORY_SLOTS) {
		std::cout << "[MateriaSrouce] The slots is full!" << std::endl;
		return;
	}

}

AMateria* MateriaSource::createMateria(std::string const & type) {

	int index = 0;

	while (index < INVENTORY_SLOTS) {

			if (this->materia_slots[index] &&
				!this->materia_slots[index]->getType().compare(type)) {
					return materia_slots[index]->clone();
			}

			index++;
		}
		return 0;
}
