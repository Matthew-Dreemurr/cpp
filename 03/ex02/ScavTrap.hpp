#ifndef SCRAVTRAP_HPP
#define SCRAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap( const std::string newName);
		~ScavTrap();
		ScavTrap( const ScavTrap &newClapTrap );
		ScavTrap& operator=( const ScavTrap &newClapTrap );

		void guardGate();
		void attack (const std::string& target );
};

#endif /* SCRAVTRAP_HPP */
