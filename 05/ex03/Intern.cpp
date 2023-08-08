#include "Intern.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define CRESET "\e[0m"
#define RED "\e[0;31m"

Intern::Intern()
{}

Intern::~Intern() {
	std::cout << "[DEBUG] Destroy" << std::endl;
}

Intern::Intern(const Intern &newIntern) 
{
	(void)newIntern;
	std::cout << "[DEBUG] Copy " << std::endl;
}

Intern&	Intern::operator=(const Intern &newIntern) {
	(void)newIntern;
	std::cout << "[DEBUG] Copy assignation = " << std::endl;
	return *this;
}

Form* createRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

Form* createPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

Form* createShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

Form* Intern::makeForm(std::string formName, std::string target) {
	const std::string forms[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	Form* (*functionPtr[])(std::string target) = {
		createRobotomyRequestForm,
		createPresidentialPardonForm,
		createShrubberyCreationForm,
		NULL
	};

	for (size_t i = 0; functionPtr[i]; i++)
	{
		if (forms[i] == formName) {
			return (functionPtr[i])(target);
		}
	}
	throw Intern::FormDontExist(formName);
	return NULL;
}

Intern::FormDontExist::FormDontExist(std::string formName)
: std::runtime_error(RED"Form " + formName + " doesn't exist!" + CRESET)
{}
