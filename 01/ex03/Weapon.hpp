#ifndef WEAPON_H
#define WEAPON_H

#include "iostream"

class Weapon {
public:
	Weapon(std::string newType);
	~Weapon();
	std::string getType();
	void setType(std::string type);
private:
	std::string type;
};

#endif /* WEAPON_H */
