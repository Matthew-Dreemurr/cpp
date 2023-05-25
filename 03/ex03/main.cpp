#include "DiamondTrap.hpp"
#include <iostream>

int main(void) {

	std::cout << "-=-=-=-=-= [TEST] Attack and die =-=-=-=-=-" << std::endl;

	DiamondTrap *test = new DiamondTrap("Keven"); 
	test->whoAmI();
	test->takeDamage(2);
	test->takeDamage(2);
	test->takeDamage(2);

	test->attack("Jordan");

	test->takeDamage(2);
	test->takeDamage(2);
	test->takeDamage(90);

	test->attack("Jordan");

	test->beRepaired(12);
	
	delete test;
	
	std::cout << "-=-=-=-=-= [TEST] Attack and repair =-=-=-=-=-" << std::endl;

	test = new DiamondTrap("Jordan");

	test->whoAmI();
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

	test->highFivesGuys();

	delete test;

	return (0);
}
