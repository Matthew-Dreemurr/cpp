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