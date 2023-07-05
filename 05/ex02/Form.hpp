#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

class Form
{
	class GradeTooHighException: public std::runtime_error {
		public:
			GradeTooHighException(const Form & data, const Bureaucrat & user);
	};
	class GradeTooLowException: public std::runtime_error {
		public:
			GradeTooLowException(const Form & data, const Bureaucrat & user);
	};

private:
	const std::string	name;
	int			signed_grade;
	int			execute_grade;
	bool		is_signed;
public:
	Form(std::string name, int signed_grade, int execute_grade);
	Form(const Form & newForm);
	Form& operator=(const Form & newForm);
	~Form();
	void beSigned(const Bureaucrat & bureaucrat);
	const std::string& getName() const;
	int getSignedGrade() const;
	int getExecuteGrade() const;
	bool isSigned() const;
	void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream &os, const Form & data);

#endif /* FORM_H */
