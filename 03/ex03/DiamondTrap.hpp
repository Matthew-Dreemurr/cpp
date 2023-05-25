#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap :  public FragTrap,  public ScavTrap {
	public:
		DiamondTrap( const std::string newName);
		~DiamondTrap();
		DiamondTrap( const DiamondTrap &newClapTrap );
		DiamondTrap& operator=( const DiamondTrap &newClapTrap );

		void attack( const std::string& target );
		void highFivesGuys(void);
		void whoAmI();

	private:
		std::string	name;
};

#endif /* DIAMONDTRAP_HPP */
