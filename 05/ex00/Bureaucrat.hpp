#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
	class GradeTooHighException: public std::runtime_error {
		public:
			GradeTooHighException(const int grade);

			GradeTooHighException(const std::string & grade);

			GradeTooHighException(const Bureaucrat & data);
	};
	class GradeTooLowException: public std::runtime_error {
		public:
			GradeTooLowException(const int grade);

			GradeTooLowException(const std::string & grade);

			GradeTooLowException(const Bureaucrat & data);
	};

private:
	const std::string	name;
	int					grade;

public:
	Bureaucrat();
	Bureaucrat(std::string newName, int newGrade);
	Bureaucrat(const Bureaucrat &newBureaucrat);
	Bureaucrat&	operator=(const Bureaucrat &);

	const std::string& getName() const;
	const int& getGrade() const;

	void promote();
	void demote();

	~Bureaucrat();
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &data);

#endif /* BUREAUCRAT_H */
