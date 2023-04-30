#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include "HumanB.hpp"

class HumanA {
	public:
		HumanA(std::string newName, Weapon &newWeapon);
		void attack();
		void setWeapon(Weapon &newWeapon);
	private:
		Weapon &weapon;
		std::string name;
};


#endif /* HUMANA_H */
