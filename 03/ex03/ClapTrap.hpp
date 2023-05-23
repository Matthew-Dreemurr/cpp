#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
	public:
		ClapTrap ();
		ClapTrap( const std::string);
		~ClapTrap();
		ClapTrap( const ClapTrap &newClapTrap );
		ClapTrap& operator=( const ClapTrap &newClapTrap );

		void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );

	protected:
		std::string		name;
		// Hit points
		unsigned int	hp;
		// Energy points
		unsigned int	ep;
		// Attack damage
		unsigned int	ad;

		unsigned int removePoints(unsigned int &ref, const unsigned int amount);
};

#endif /* CLAPTRAP_HPP */