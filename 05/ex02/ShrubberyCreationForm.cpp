#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: Form("Shrubbery", 145, 137)
{
	std::cout << "[" << this->getName() << "] new form" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & newForm)
: Form(newForm)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm & newForm) {
	Form::operator=(newForm);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "[" << this->getName() << "] delete form" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	Form::execute(executor);
	std::cout << "[" << this->getName() << "] execute suff" << std::endl;
}