#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string newName, Weapon &newWeapon);
		void attack();
	private:
		Weapon &weapon;
		std::string name;
};


#endif /* HUMANA_H */
