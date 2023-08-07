#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <stdexcept>
#include <limits>
#include <iostream>

#define CRESET "\e[0m"
#define RED "\e[0;31m"

Bureaucrat::Bureaucrat()
: name("No name"), grade(150)
{}

Bureaucrat::Bureaucrat(std::string newName, int newGrade)
: name(newName.empty() ? "No name" : newName), grade(newGrade)
{
	if (newGrade < 1) {
		throw Bureaucrat::GradeTooHighException(*this);
	}
	if (newGrade > 150) {
		throw Bureaucrat::GradeTooLowException(*this);
	}
	this->grade = newGrade;

	std::cout << "[DEBUG] Create " << *this << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "[DEBUG] Destroy " << *this << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &newBureaucrat) 
: name(newBureaucrat.name), grade(newBureaucrat.grade)
{
	std::cout << "[DEBUG] Copy " << this->name << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &newBureaucrat) {
	this->grade = newBureaucrat.grade;
	std::cout << "[DEBUG] Copy assignation = " << newBureaucrat.name << " on " << this->name << std::endl;
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &data) {
	return os << data.getName() << ", bureaucrat grade " << data.getGrade();
}

const std::string& Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::promote() {

	std::cout << "[DEBUG] Try to promote " << *this << std::endl;

	const int newGrade = this->grade - 1;
	if (newGrade < 1) {
		throw Bureaucrat::GradeTooHighException(newGrade);
	}
	std::cout << *this << " promoted to " << newGrade << std::endl;
	this->grade = newGrade;
}

void Bureaucrat::demote() {

	std::cout << "[DEBUG] Try to demote " << *this << std::endl;

	const int newGrade = this->grade + 1;
	if (newGrade > 150) {
		throw Bureaucrat::GradeTooLowException(newGrade);
	}
	std::cout << *this << " demoted to " << newGrade << std::endl;
	this->grade = newGrade;
}

void Bureaucrat::signForm(Form & form) {
	std::cout << "[DEBUG] Try to sign " << form.getName() << " by " << *this << std::endl;
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << this->name << " couldn't sign " << form.getName() << " because " << e.what() << CRESET << std::endl;
	}
}


void Bureaucrat::executeForm(Form const & form) {
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << this->name << " couldn't executed" << form.getName() << " because " << e.what() << CRESET << std::endl;
	}

}

Bureaucrat::GradeTooHighException::GradeTooHighException(const int grade)
: std::runtime_error("Grade too high: " + std::to_string(grade) + " < 1")
{}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string & grade)
: std::runtime_error("Grade too high: " + grade + " < 1")
{}

Bureaucrat::GradeTooHighException::GradeTooHighException(const Bureaucrat & data)
: std::runtime_error("Grade too high: [" + data.getName() + "] : " + std::to_string(data.getGrade()) + " < 1")
{}


Bureaucrat::GradeTooLowException::GradeTooLowException(const int grade)
: std::runtime_error("Grade too low: " + std::to_string(grade) + " < 150")
{}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string & grade)
: std::runtime_error("Grade too low: " + grade + " < 150")
{}

Bureaucrat::GradeTooLowException::GradeTooLowException(const Bureaucrat & data)
: std::runtime_error("Grade too low [" + data.getName() + "] : " + std::to_string(data.getGrade()) + " < 150")
{}