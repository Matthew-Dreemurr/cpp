#include "Intern.hpp"
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

void test(int grade, Form * form, std::string test_name) {
	std::cout << BLU << "<======================================================>" << CRESET << std::endl;
	std::cout << BLU << "<===== Test " << test_name << CRESET << std::endl;
	std::cout << BLU << "<======================================================>" << CRESET << std::endl;

try {

		std::cout << std::endl << std::endl;

		std::cout << YEL << "===== Test constructor =====" << CRESET << std::endl;

		Bureaucrat test("Keven", grade);
		std::cout << test << std::endl;

		std::cout << YEL << "===== Test Shrubbery creation from constructor =====" << CRESET << std::endl;

		std::cout << *form << std::endl;

		std::cout << YEL << "===== Test executeForm befor singed =====" << CRESET << std::endl;

		test.executeForm(*form);

		std::cout << YEL << "===== Test signForm =====" << CRESET << std::endl;

		test.signForm(*form);

		std::cout << YEL << "===== Test executeForm =====" << CRESET << std::endl;

		test.executeForm(*form);

	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
}

int main (void) {
	Intern intern;

// ShrubberyCreationForm
// Échelons requis : signature 145, exécution 137
	// ShrubberyCreationForm shrubbery("The target");
	Form *shrubbery = intern.makeForm("shrubbery creation", "The target");
	test(137, shrubbery, "ShrubberyCreationForm");
	delete shrubbery;

// RobotomyRequestForm
// Échelons requis : signature 72, exécution 45
	// RobotomyRequestForm robotomy("The target");
	Form *robotomy = intern.makeForm("robotomy request", "The target");
	test(45, robotomy, "RobotomyRequestForm");
	delete robotomy;

// PresidentialPardonForm
// Échelons requis : signature 25, exécution 5
	// PresidentialPardonForm presidential("The target");
	Form *presidential = intern.makeForm("presidential pardon", "The target");
	test(5, presidential, "PresidentialPardonForm");
	delete presidential;

	try
	{
		Form *presidential = intern.makeForm("asdfadfadf", "The target");
		delete presidential;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

}