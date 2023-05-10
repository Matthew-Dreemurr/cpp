#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
	public:
		ClapTrap(std::string newName);

		void attack( const std::string& target );
		void takeDamage( unsigned int amount );

	private:
		str::string	name;
	unsigned	 int			hp;
	unsigned	 int			ep;
	unsigned	 int			ad;
}

#endif /* CLAPTRAP_HPP */
