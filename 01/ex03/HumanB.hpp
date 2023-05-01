#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string newName);
		void attack();
		void setWeapon(Weapon &newWeapon);
	private:
		Weapon *weapon;
		std::string name;
};


#endif /* HUMANB_H */
