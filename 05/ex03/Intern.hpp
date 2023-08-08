#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <stdexcept>

class Form;

class Intern
{
	class FormDontExist: public std::runtime_error {
		public:
			FormDontExist(std::string formName);
	};
private:

public:
	Intern();
	Intern(const Intern &newIntern);
	Intern&	operator=(const Intern &);

	~Intern();

	Form*	makeForm(std::string formName, std::string target);
};


#endif /* INTERN_HPP */
