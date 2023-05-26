#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal (const WrongAnimal &newAnimal);
		WrongAnimal &operator=(WrongAnimal &newAnimal);
		
		void makeSound() const;
		std::string getType(void) const;
};

#endif