#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#define GRN "\e[0;32m"
#define CRESET "\e[0m"
#define YEL "\e[0;33m"

int main (void) {

	int nb_test = 0;

try {
		std::cout << GRN << "===== Test " << ++nb_test << " =====" << CRESET << std::endl;

		std::cout << YEL << "===== Test constructor =====" << CRESET << std::endl;

		Bureaucrat test("Keven", 12);
		std::cout << test << std::endl;

		std::cout << YEL << "===== Test form constructor =====" << CRESET << std::endl;

		Form form("test1", 15, 10);
		std::cout << form << std::endl; 
		
		std::cout << YEL << "===== Test signForm with good grade =====" << CRESET << std::endl;

		test.signForm(form);

	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}

try {
		std::cout << GRN << "===== Test " << ++nb_test << " =====" << CRESET << std::endl;

		std::cout << YEL << "===== Test constructor =====" << CRESET << std::endl;

		Bureaucrat test("Keven", 50);
		std::cout << test << std::endl;

		std::cout << YEL << "===== Test form constructor =====" << CRESET << std::endl;

		Form form("test1", 15, 10);
		std::cout << form << std::endl;

		std::cout << YEL << "===== Test signForm with too low grade =====" << CRESET << std::endl;

		test.signForm(form);

	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}

	try {
		std::cout << GRN << "===== Test " << ++nb_test << " =====" << CRESET << std::endl;

		std::cout << YEL << "===== Test constructor =====" << CRESET << std::endl;

		Bureaucrat test("Keven", 5);
		std::cout << test << std::endl;

		std::cout << YEL << "===== Test form constructor =====" << CRESET << std::endl;

		Form form("test1", 15, 10);
		std::cout << form << std::endl;

		std::cout << YEL << "===== Test signForm in loop to a failed sign =====" << CRESET << std::endl;

		for (size_t i = 5; i > 0; i--)
		{
			std::cout << YEL << "Try to sign " << form.getName() << " with grade " << i  << CRESET << std::endl;
			test.signForm(form);
			std::cout << YEL << "Try to promote " << test.getName() << CRESET << std::endl;
			test.promote();
			std::cout << std::endl;
		}

	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}
	
	try
	{
		std::cout << GRN << "===== Test " << ++nb_test << " =====" << CRESET << std::endl;

		std::cout << YEL << "===== Test constructor form with too hight grade to execute =====" << CRESET << std::endl;

		Form form("test1", 15, 151);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}