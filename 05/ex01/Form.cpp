#include "Form.hpp"
#include <stdexcept>
#include <iostream>

Form::GradeTooHighException::GradeTooHighException(const Form & data, const Bureaucrat & user)
: std::runtime_error("require grade under " + std::to_string(data.signed_grade) + " but has " + std::to_string(user.getGrade()) + " grade")
{}

Form::GradeTooLowException::GradeTooLowException(const Form & data, const Bureaucrat & user)
: std::runtime_error("require grade " + std::to_string(data.signed_grade) + " but has " + std::to_string(user.getGrade()) + " grade")
{}

Form::Form(std::string name, int signed_grade, int execute_grade)
: name(name), signed_grade(signed_grade), execute_grade(execute_grade), is_signed(false)
{
	std::cout << "[Form] new " << this->name << " signed grade " << this->signed_grade << " execute grade " << this->execute_grade << std::endl;
}

Form::~Form() {
	std::cout << "[Form] destroy " << this->name << std::endl;
}

const std::string& Form::getName() const {
	return this->name;
}

const int Form::getSignedGrade() const {
	return this->signed_grade;
}

const int Form::getExecuteGrade() const {
	return this->execute_grade;
}

const bool Form::isSigned() const {
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
