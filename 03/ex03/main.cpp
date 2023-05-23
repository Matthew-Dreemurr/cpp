#include "FragTrap.hpp"
#include <iostream>

int main(void) {

	std::cout << "-=-=-=-=-= [TEST] Attack and die =-=-=-=-=-" << std::endl;

	FragTrap *test = new FragTrap("Keven"); 
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

	test = new FragTrap("Jordan");

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
