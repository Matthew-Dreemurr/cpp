#include "Form.hpp"
#include <stdexcept>
#include <iostream>

Form::GradeTooHighException::GradeTooHighException(const int grade)
: std::runtime_error("Grade too high: " + std::to_string(grade) + " < 1")
{}

Form::GradeTooHighException::GradeTooHighException(const std::string & grade)
: std::runtime_error("Grade too high: " + grade + " < 1")
{}

Form::GradeTooHighException::GradeTooHighException(const Form & data)
: std::runtime_error("Grade too high: [" + data.getName() + "] : " + std::to_string(data.getGrade()) + " < 1")
{}


Form::GradeTooLowException::GradeTooLowException(const int grade)
: std::runtime_error("Grade too low: " + std::to_string(grade) + " < 150")
{}

Form::GradeTooLowException::GradeTooLowException(const std::string & grade)
: std::runtime_error("Grade too low: " + grade + " < 150")
{}

Form::GradeTooLowException::GradeTooLowException(const Form & data)
: std::runtime_error("Grade too low [" + data.getName() + "] : " + std::to_string(data.getGrade()) + " < 150")
{}

const std::string& Form::getName() const {
	return this->name;
}

const int Form::getSignedGrade() const {
	return this->signed_grade;
}

const int Form::getExecuteGrade() const {
	return this->execute_grade;
}

std::ostream& operator<<(std::ostream &os, const Form & data) {
	return os << "[Form] " << data.getName() << " require grade " << data.getSignedGrade() << " to sign and require grade " << data.getExecuteGrade() << " to execute" << std::endl;
}

void	Form::beSigned(const Bureaucrat & bureaucrat) {
	if (bureaucrat.getGrade() <= this->signed_grade) {
		//TODO 
		return;
	}
	//TODO
}
