#include <iostream>
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "[-=+=-=+=-=+=-=+=- WrongAnimal -=+=-=+=-=+=-=+=-]" << std::endl;
	const WrongAnimal* animal = new WrongAnimal();
	std::cout << animal->getType() << " " << std::endl;
	animal->makeSound();
	delete animal;

	std::cout << "[-=+=-=+=-=+=-=+=- WrongCat -=+=-=+=-=+=-=+=-]" << std::endl;
	const WrongAnimal* cat = new WrongCat();
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	delete cat;

	return 0;
}