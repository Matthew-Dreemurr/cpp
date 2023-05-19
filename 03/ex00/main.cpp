#include "ClapTrap.hpp"
#include <iostream>

int main(void) {

	std::cout << "-=-=-=-=-= [TEST] Attack and die =-=-=-=-=-" << std::endl;

	ClapTrap *test = new ClapTrap("Keven"); 
	test->takeDamage(2);
	test->takeDamage(2);
	test->takeDamage(2);

	test->attack("Jordan");

	test->takeDamage(2);
	test->takeDamage(2);
	test->takeDamage(2);

	test->attack("Jordan");

	test->beRepaired(12);
	
	delete test;
	
	std::cout << "-=-=-=-=-= [TEST] Attack and repair =-=-=-=-=-" << std::endl;

	test = new ClapTrap("Jordan");

	test->takeDamage(2);
	test->takeDamage(2);
	test->takeDamage(2);

	test->beRepaired(2);
	test->beRepaired(2);
	test->beRepaired(2);
	test->beRepaired(2);
	test->beRepaired(2);
	test->beRepaired(2);
	test->beRepaired(2);
	test->beRepaired(2);
	test->beRepaired(2);
	test->beRepaired(2);
	test->beRepaired(2);

	delete test;

	return (0);
}
