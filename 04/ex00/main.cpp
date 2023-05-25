#include "Animal.hpp"
#include <iostream>
int main(void) {
	Animal *animal = new Animal();
	std::cout << animal->getType() << std::endl;
	animal->makeSound();
	return (0);
}