#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "../IMateriaSource/IMateriaSource.hpp"
#include "../AMateria/AMateria.hpp"

#define INVENTORY_SLOTS 4

class MateriaSource: public IMateriaSource
{
private:
	AMateria	*materia_slots[INVENTORY_SLOTS];
public:
	void learnMateria(AMateria* newMateria);
	AMateria* createMateria(std::string const & type);
	MateriaSource();
	~MateriaSource();
};

#endif /* MATERIASOURCE_H */
