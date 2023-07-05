#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main (void) {

try {
		Bureaucrat test("Keven", 12);
		std::cout << test << std::endl;

		Form form("test1", 15, 10);
		test.signForm(form);
	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}

try {
		Bureaucrat test("Keven", 50);
		std::cout << test << std::endl;

		Form form("test1", 15, 10);
		test.signForm(form);
	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}

	try {
		Bureaucrat test("Keven", 30);
		std::cout << test << std::endl;

		Form form("test1", 15, 10);

		for (size_t i = 30; i > 0; i--)
		{
			test.signForm(form);
			test.promote();
		}

	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}
	

	return 0;
}