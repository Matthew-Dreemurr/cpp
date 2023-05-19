#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap( const std::string newName);
		~FragTrap();
		FragTrap( const FragTrap &newClapTrap );
		FragTrap& operator=( const FragTrap &newClapTrap );

		void highFivesGuys(void);
		void attack (const std::string& target );
};

#endif /* FRAGTRAP_HPP */
