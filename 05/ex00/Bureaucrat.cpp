#include "Bureaucrat.hpp"
#include <stdexcept>
#include <limits>
#include <iostream>

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

	std::cout << "[DEBUG] Bureaucrat::Bureaucrat(std::string, int) " << *this << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "[DEBUG] Bureaucrat::~Bureaucrat() " << *this << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &newBureaucrat) 
: name(newBureaucrat.name), grade(newBureaucrat.grade)
{
	std::cout << this->name << " copy constructor" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &newBureaucrat) {
	this->grade = newBureaucrat.grade;
	std::cout << this->name << " operator= constructor" << std::endl;
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &data) {
	return os << data.getName() << ", bureaucrat grade " << data.getGrade() << std::endl;
}

const std::string& Bureaucrat::getName() const {
	return this->name;
}

const int& Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::promote() {

	std::cout << "Try to promote [" << this->name << "]" << std::endl;

	const int newGrade = this->grade - 1;
	if (newGrade < 1) {
		throw Bureaucrat::GradeTooHighException(newGrade);
	}
	this->grade = newGrade;
}

void Bureaucrat::demote() {

	std::cout << "Try to demote [" << this->name << "]" << std::endl;

	const int newGrade = this->grade + 1;
	if (newGrade > 150) {
		throw Bureaucrat::GradeTooLowException(newGrade);
	}
	this->grade = newGrade;
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