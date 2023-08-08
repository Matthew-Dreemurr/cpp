#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#define GRN "\e[0;32m"
#define CRESET "\e[0m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"

void test(int grade, Form & form, std::string test_name) {
	std::cout << BLU << "<======================================================>" << CRESET << std::endl;
	std::cout << BLU << "<===== Test " << test_name << CRESET << std::endl;
	std::cout << BLU << "<======================================================>" << CRESET << std::endl;

try {

		std::cout << std::endl << std::endl;

		std::cout << YEL << "===== Test constructor =====" << CRESET << std::endl;

		Bureaucrat test("Keven", grade);
		std::cout << test << std::endl;

		std::cout << YEL << "===== Test Shrubbery creation from constructor =====" << CRESET << std::endl;

		std::cout << form << std::endl;

		std::cout << YEL << "===== Test executeForm befor singed =====" << CRESET << std::endl;

		test.executeForm(form);

		std::cout << YEL << "===== Test signForm =====" << CRESET << std::endl;

		test.signForm(form);

		std::cout << YEL << "===== Test executeForm =====" << CRESET << std::endl;

		test.executeForm(form);

	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
}

int main (void) {
// ShrubberyCreationForm
// Échelons requis : signature 145, exécution 137
	ShrubberyCreationForm shrubbery;
	test(137, shrubbery, "ShrubberyCreationForm");

// RobotomyRequestForm
// Échelons requis : signature 72, exécution 45
	RobotomyRequestForm robotomy;
	test(45, robotomy, "RobotomyRequestForm");

// PresidentialPardonForm
// Échelons requis : signature 25, exécution 5
	PresidentialPardonForm presidential;
	test(5, presidential, "PresidentialPardonForm");
}