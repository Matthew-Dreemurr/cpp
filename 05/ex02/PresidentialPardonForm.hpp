#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "Form.hpp"

class PresidentialPardonForm: public virtual Form
{
private:
	const std::string target;
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& newForm);
	PresidentialPardonForm & operator=(const PresidentialPardonForm& newForm);
	~PresidentialPardonForm();

	void execute(Bureaucrat const & executor) const;
};

#endif /* PRESIDENTIALPARDONFORM_H */
