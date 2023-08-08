#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

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

	std::ofstream file(executor.getName() + "_shrubbery");
	file << "               ,@@@@@@@," << std::endl
	<< "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl
	<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl
	<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl
	<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl
	<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl
	<< "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl
	<< "       |o|        | |         | |" << std::endl
	<< "       |.|        | |         | |" << std::endl
	<< "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
	file.close();

}