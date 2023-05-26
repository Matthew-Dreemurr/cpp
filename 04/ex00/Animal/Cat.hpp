#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal {
	public:
		Cat();
		Cat (const Cat &newDog);
		Cat &operator=(Cat &newDog);
		virtual ~Cat();
		void makeSound() const;
};

#endif