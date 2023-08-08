#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
: Form("Robotomy", 72, 45)
{
	std::cout << "[" << this->getName() << "] new form" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & newForm)
: Form(newForm)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm & newForm) {
	Form::operator=(newForm);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "[" << this->getName() << "] delete form" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	Form::execute(executor);

	std::srand(std::time(NULL));
	std::cout << "Bzzzzzzzzzzzzzzz" << std::endl;
	if (rand() % 2)
		std::cout << executor.getName() << " has been successfully robotomized" << std::endl;
	else
		std::cout << executor.getName() << " robotomy failed!" << std::endl;
}