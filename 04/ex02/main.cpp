#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include <stdlib.h>

int main()
{

	// const Animal test;
	// const Animal *test_ptr = new Animal();

	std::cout << "-+=+-+=+-+= [Create Dog] =+-+=+-+=+-" << std::endl;
	const Dog *dog_ptr = new Dog();
	dog_ptr->makeSound();
	delete dog_ptr;

	std::cout << "-+=+-+=+-+= [Create Cat] =+-+=+-+=+-" << std::endl;
	const Cat *cat_ptr = new Cat();
	cat_ptr->makeSound();
	delete cat_ptr;

	std::cout << "-+=+-+=+-+= [Copy Dog] =+-+=+-+=+-" << std::endl;
	const Dog test_dog = Dog();
	test_dog.makeSound();
	std::cout << "-======-" << std::endl;
	Dog test_copy_dog = test_dog;
	test_copy_dog.makeSound();
	
	std::cout << "-+=+-+=+-+= [Copy Cat] =+-+=+-+=+-" << std::endl;
	const Cat test_cat = Cat();
	test_cat.makeSound();
	std::cout << "-======-" << std::endl;
	Cat test_copy_cat(test_cat) ;
	test_copy_cat.makeSound();

	std::cout << "-+=+-+=+-+= [END] =+-+=+-+=+-" << std::endl;
	return 0;
}
