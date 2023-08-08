#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "Form.hpp"

class ShrubberyCreationForm: public virtual Form
{
private:
	const std::string target;
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm & newForm);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm & newForm);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const & executor) const;
};

#endif /* SHRUBBERYCREATIONFORM_H */
