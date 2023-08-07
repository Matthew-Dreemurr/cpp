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

void test(int grade, std::string test_name) {
	int nb_test = 0;

	std::cout << BLU << "<======================================================>" << CRESET << std::endl;
	std::cout << BLU << "<===== Test " << test_name << CRESET << std::endl;
	std::cout << BLU << "<======================================================>" << CRESET << std::endl;

try {

		std::cout << std::endl << std::endl;
		std::cout << GRN << "===== Test " << ++nb_test << " =====" << CRESET << std::endl;

		std::cout << YEL << "===== Test constructor =====" << CRESET << std::endl;

		Bureaucrat test("Keven", grade);
		std::cout << test << std::endl;

		std::cout << YEL << "===== Test Shrubbery creation from constructor =====" << CRESET << std::endl;

		ShrubberyCreationForm form;
		std::cout << test << std::endl;

		std::cout << YEL << "===== Test signForm =====" << CRESET << std::endl;

		test.signForm(form);

		std::cout << YEL << "===== Test executeForm =====" << CRESET << std::endl;

		test.executeForm(form);

	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}

	try {

		std::cout << std::endl << std::endl;
		std::cout << GRN << "===== Test " << ++nb_test << " =====" << CRESET << std::endl;

		Bureaucrat test("Keven", grade);
		std::cout << test << std::endl;

		std::cout << YEL << "===== Test Robotomy request from constructor =====" << CRESET << std::endl;

		RobotomyRequestForm form;
		std::cout << test << std::endl;

		std::cout << YEL << "===== Test signForm =====" << CRESET << std::endl;

		test.signForm(form);

		std::cout << YEL << "===== Test executeForm =====" << CRESET << std::endl;

		test.executeForm(form);

	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}

	try {

		std::cout << std::endl << std::endl;
		std::cout << GRN << "===== Test " << ++nb_test << " =====" << CRESET << std::endl;

		Bureaucrat test("Keven", grade);
		std::cout << test << std::endl;

		std::cout << YEL << "===== Test Presidential pardon from constructor =====" << CRESET << std::endl;

		PresidentialPardonForm form;
		std::cout << test << std::endl;

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
	test(1, "Good grade");
	test(150, "Grade too low to sign or execute");
	test(0, "Grade higher than 1");
	test(151, "Grade lower than 150");
}