#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: Form("PresidentialPardon", 25, 5)
{
	std::cout << "[" << this->getName() << "] new form" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & newForm)
: Form(newForm)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm & newForm) {
	Form::operator=(newForm);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "[" << this->getName() << "] delete form" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	Form::execute(executor);

	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}