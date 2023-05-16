#ifndef SCRAVTRAP_HPP
#define SCRAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {
	public:
		ScavTrap( const std::string newName );
		~ScavTrap();
		ScavTrap( const ScavTrap &newClapTrap );
		ScavTrap& operator=( const ScavTrap &newClapTrap );

		void ScavTrap::guardGate();
	private:
		std::string		name;
		// Hit points
		unsigned int	hp;
		// Energy points
		unsigned int	ep;
		// Attack damage
		unsigned int	ad;

		unsigned int removePoints(unsigned int &ref, const unsigned int amount);
};

#endif /* SCRAVTRAP_HPP */
