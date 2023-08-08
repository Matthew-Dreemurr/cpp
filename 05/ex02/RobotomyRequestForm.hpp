#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "Form.hpp"

class RobotomyRequestForm: public virtual Form
{
private:
	const std::string target;
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm & newForm);
	RobotomyRequestForm& operator=(const RobotomyRequestForm & newForm);
	~RobotomyRequestForm();

	void execute(Bureaucrat const & executor) const;
};

#endif /* ROBOTOMYREQUESTFORM_H */
