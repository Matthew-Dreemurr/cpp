#include "Form.hpp"
#include <stdexcept>
#include <iostream>

Form::GradeTooHighException::GradeTooHighException(const Form & data, const Bureaucrat & user)
: std::runtime_error("require grade " + INT_TO_STR(data.signed_grade) + " but has " + INT_TO_STR(user.getGrade()) + " grade")
{}

Form::GradeTooHighException::GradeTooHighException(int grade)
: std::runtime_error("Grade " + INT_TO_STR(grade) + " is too high")
{}

Form::GradeTooLowException::GradeTooLowException(const Form & data, const Bureaucrat & user)
: std::runtime_error("require grade under " + INT_TO_STR(data.signed_grade) + " but has " + INT_TO_STR(user.getGrade()) + " grade")
{}

Form::GradeTooLowException::GradeTooLowException(int grade)
: std::runtime_error("Grade " + INT_TO_STR(grade) + " is too low")
{}


Form::Form(std::string name, int signed_grade, int execute_grade)
: name(name), signed_grade(signed_grade), execute_grade(execute_grade), is_signed(false)
{
	signed_grade < 1 ? throw Form::GradeTooHighException(signed_grade) : 0;
	signed_grade > 150 ? throw Form::GradeTooLowException(signed_grade) : 0;
	execute_grade < 1 ? throw Form::GradeTooHighException(execute_grade) : 0;
	execute_grade > 150 ? throw Form::GradeTooLowException(execute_grade) : 0;
	std::cout << "[Form] new " << this->name << " signed grade " << this->signed_grade << " execute grade " << this->execute_grade << std::endl;
}

Form::Form(const Form &newBureaucrat) 
: name(newBureaucrat.name), signed_grade(newBureaucrat.signed_grade), execute_grade(newBureaucrat.execute_grade), is_signed(false)
{
	signed_grade < 1 ? throw Form::GradeTooHighException(signed_grade) : 0;
	signed_grade > 150 ? throw Form::GradeTooLowException(signed_grade) : 0;
	execute_grade < 1 ? throw Form::GradeTooHighException(execute_grade) : 0;
	execute_grade > 150 ? throw Form::GradeTooLowException(execute_grade) : 0;
	std::cout << this->name << " copy constructor" << std::endl;
}

Form&	Form::operator=(const Form &newBureaucrat) {
	this->is_signed = newBureaucrat.is_signed;
	std::cout << this->name << " operator= constructor" << std::endl;
	return *this;
}

Form::~Form() {
	std::cout << "[Form] destroy " << this->name << std::endl;
}

const std::string& Form::getName() const {
	return this->name;
}

int Form::getSignedGrade() const {
	return this->signed_grade;
}

int Form::getExecuteGrade() const {
	return this->execute_grade;
}

bool Form::isSigned() const {
	return this->is_signed;
}

std::ostream& operator<<(std::ostream &os, const Form & data) {
	return os << "[Form] " << data.getName() << " require grade " << data.getSignedGrade() << " to sign and require grade " << data.getExecuteGrade() << " to execute" << std::endl;
}

void	Form::beSigned(const Bureaucrat & bureaucrat) {
	if (bureaucrat.getGrade() <= this->signed_grade) {
		this->is_signed = true;
		return;
	}
	throw Form::GradeTooLowException(*this, bureaucrat);
}
