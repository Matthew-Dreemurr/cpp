#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	std::cout << "[-=+=-=+=-=+=-=+=- Animal -=+=-=+=-=+=-=+=-]" << std::endl;
	const Animal* animal = new Animal();
	std::cout << animal->getType() << " " << std::endl;
	animal->makeSound();
	delete animal;


	std::cout << "[-=+=-=+=-=+=-=+=- Dog -=+=-=+=-=+=-=+=-]" << std::endl;
	const Animal* dog = new Dog();
	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();
	delete dog;


	std::cout << "[-=+=-=+=-=+=-=+=- Cat -=+=-=+=-=+=-=+=-]" << std::endl;
	const Animal* cat = new Cat();
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	delete cat;

	return 0;
}