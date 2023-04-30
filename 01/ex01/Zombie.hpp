//
// Created by fluffy on 2/23/23.
//

#ifndef CPP_ZOMBIE_HPP
#define CPP_ZOMBIE_HPP

#include "iostream"


class Zombie {
public:
	Zombie(const std::string &name);
	Zombie(const Zombie&);
	Zombie();
	~Zombie();

	Zombie &operator=(const Zombie&);
	void announce( void ) const;
	void setName(const std::string &name);
private:
	std::string name;
};

Zombie *zombieHorde(int N, std::string name);

#endif //CPP_ZOMBIE_HPP
