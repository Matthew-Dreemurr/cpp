#include "ClapTrap.hpp"

int main(void) {
	ClapTrap test("Keven");

	test.attack("Jodran");
	test.takeDamage(12);
	test.beRepaired(23);
	return (0);
}