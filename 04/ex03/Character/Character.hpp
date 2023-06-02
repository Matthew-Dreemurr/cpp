#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "../AMateria/AMateria.hpp"
#include "../ICharacter/ICharacter.hpp"

#define INVENTORY_SLOTS 4

class Character: public ICharacter
{
private:
	AMateria	*inventory[INVENTORY_SLOTS] = {nullptr};
	AMateria	*ground[INVENTORY_SLOTS] = {nullptr};
	std::string	name;
	void		delGround();
	void		overWriteInventory(Character &src);
public:
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	Character* operator=(Character &r);

	Character(std::string name);
	~Character();
};

#endif /* CHARACTER_H */
