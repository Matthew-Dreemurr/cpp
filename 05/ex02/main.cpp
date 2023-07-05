#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main (void) {

try {
		Bureaucrat test("Keven", 150);
		std::cout << test << std::endl;

		ShrubberyCreationForm form;
		std::cout << test << std::endl;

		test.signForm(form);
		test.executeForm(form);
	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}
	

	return 0;
}