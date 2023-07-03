#ifndef FORM_H
#define FORM_H

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
public:
	Form();
	~Form();
};

#endif /* FORM_H */
