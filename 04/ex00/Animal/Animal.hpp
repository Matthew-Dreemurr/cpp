#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		virtual ~Animal();
		Animal(std::string type);
		Animal (const Animal &newAnimal);
		Animal &operator=(Animal &newAnimal);
		
		virtual void makeSound() const;
		std::string getType(void) const;
};

#endif