#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	private:
		std::string type;
		std::string sound;
	public:
		Animal();
		Animal(std::string type);
		Animal (const Animal &newAnimal);
		Animal &operator=(Animal &newAnimal);
		~Animal();

		void makeSound();
		std::string getType(void);
};

#endif