#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
		WrongCat();
		WrongCat (const WrongCat &newDog);
		WrongCat &operator=(WrongCat &newDog);
		virtual ~WrongCat();
		void makeSound() const;
};

#endif