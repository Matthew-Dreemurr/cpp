#include "ScavTrap.hpp"
#include <iostream>

int main(void) {

	std::cout << "-=-=-=-=-= [TEST] Attack and die =-=-=-=-=-" << std::endl;

	ScavTrap *test = new ScavTrap("Keven"); 
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

	test = new ScavTrap("Jordan");

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

	test->guardGate();

	delete test;

	return (0);
}
