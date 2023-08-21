#include "Form.hpp"
#include <stdexcept>
#include <iostream>

Form::GradeTooHighException::GradeTooHighException(const Bureaucrat & user, int required_grade)
: std::runtime_error("require grade " + INT_TO_STR(required_grade) + " but has " + INT_TO_STR(user.getGrade()) + " grade")
{}

Form::GradeTooHighException::GradeTooHighException(int grade)
: std::runtime_error("Grade " + INT_TO_STR(grade) + " is too high")
{}

Form::GradeTooLowException::GradeTooLowException(const Bureaucrat & user, int required_grade)
: std::runtime_error("require grade under " + INT_TO_STR(required_grade) + " but has " + INT_TO_STR(user.getGrade()) + " grade")
{}

Form::FormNotSigned::FormNotSigned(const Form & form)
: std::runtime_error("form " + form.getName() + " is not signed")
{}

Form::GradeTooLowException::GradeTooLowException(int grade)
: std::runtime_error("Grade " + INT_TO_STR(grade) + " is too low")
{}

Form::Form(std::string name, int signed_grade, int execute_grade)
: name(name), signed_grade(signed_grade), execute_grade(execute_grade), is_signed(false)
{
	if (signed_grade < 1 || signed_grade > 150) {
		throw Form::GradeTooHighException(signed_grade);
	}
	if (execute_grade < 1 || execute_grade > 150) {
		throw Form::GradeTooLowException(execute_grade);
	}
	std::cout << "[Form] new " << this->name << " signed grade " << this->signed_grade << " execute grade " << this->execute_grade << std::endl;
}

Form::Form(const Form &newBureaucrat) 
: name(newBureaucrat.name), signed_grade(newBureaucrat.signed_grade), execute_grade(newBureaucrat.execute_grade), is_signed(false)
{
	if (signed_grade < 1 || signed_grade > 150) {
		throw Form::GradeTooHighException(signed_grade);
	}
	if (execute_grade < 1 || execute_grade > 150) {
		throw Form::GradeTooLowException(execute_grade);
	}
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
	throw Form::GradeTooLowException(bureaucrat, this->signed_grade);
}

void Form::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->execute_grade) {
		throw Form::GradeTooLowException(executor, this->execute_grade);
	}
	if (!this->is_signed) {
		throw Form::FormNotSigned(*this);
	}
}