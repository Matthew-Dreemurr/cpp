#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "Form.hpp"

class ShrubberyCreationForm: public virtual Form
{
private:
	/* data */
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm & newForm);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm & newForm);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const & executor) const;
};

#endif /* SHRUBBERYCREATIONFORM_H */
