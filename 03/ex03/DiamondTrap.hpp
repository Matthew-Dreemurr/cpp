#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap {
	public:
		DiamondTrap( const std::string newName);
		~DiamondTrap();
		DiamondTrap( const DiamondTrap &newClapTrap );
		DiamondTrap& operator=( const DiamondTrap &newClapTrap );

		void highFivesGuys(void);
	private:
		std::string	name;
};

#endif /* DIAMONDTRAP_HPP */
