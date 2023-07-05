#include "Bureaucrat.hpp"
#include <iostream>

int main (void) {

try {
		Bureaucrat test("Keven", 12);

		std::cout << test << std::endl;

		Bureaucrat * test_copy = new Bureaucrat(test);
		test_copy->promote();
		std::cout << *test_copy << std::endl;

		Bureaucrat test_copy2;
		test_copy2 = *test_copy;
		test_copy2.demote();
		std::cout << test_copy2 << std::endl;

	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}

	try {
		Bureaucrat test("Keven", 0);
	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}

	try {
		Bureaucrat test("Keven", 151);
	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}

	try {
		Bureaucrat test("Keven", 150);
		test.demote();
	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}

	try {
		Bureaucrat test("Keven", 1);
		test.promote();
	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}

	return 0;
}