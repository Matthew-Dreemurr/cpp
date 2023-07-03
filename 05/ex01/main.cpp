#include "Bureaucrat.hpp"
#include <iostream>

int main (void) {

try {
		Bureaucrat test("Keven", 12);
		std::cout << test << std::endl;
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