#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form
{
	class GradeTooHighException: public std::runtime_error {
		public:
			GradeTooHighException(const int grade);

			GradeTooHighException(const std::string & grade);

			GradeTooHighException(const Form & data);
	};
	class GradeTooLowException: public std::runtime_error {
		public:
			GradeTooLowException(const int grade);

			GradeTooLowException(const std::string & grade);

			GradeTooLowException(const Form & data);
	};

private:
	std::string	name;
	bool		is_signed;
	int			signed_grade;
	int			execute_grade;
public:
	Form();
	~Form();
	void	beSigned(const Bureaucrat & bureaucrat);
	const std::string& getName() const;
	const int getSignedGrade() const;
	const int getExecuteGrade() const;
	const bool isSigned() const;
};

std::ostream& operator<<(std::ostream &os, const Form & data);

#endif /* FORM_H */
