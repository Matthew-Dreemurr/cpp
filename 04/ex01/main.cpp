#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const int nb = 100;
	const Animal *array[nb];

	std::cout << "-+=+-+=+-+= [New Animals] =+-+=+-+=+-" << std::endl;

	for (size_t i = 0; i < nb; i++)
	{
		std::cout << "[" << i << "]" << std::endl;
		if (i%2) {
			array[i] = new Cat();
			continue;
		}
		array[i] = new Dog();
	}
	
	std::cout << "-+=+-+=+-+= [Delete Animals] =+-+=+-+=+-" << std::endl;

	for (size_t i = 0; i < nb; i++)
	{
		std::cout << "[" << i << "]" << std::endl;
		delete array[i];
	}
	
	system("leaks test");
	return 0;
}