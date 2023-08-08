#include "Bureaucrat.hpp"
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

		std::cout << YEL << "===== Test copy =====" << CRESET << std::endl;

		Bureaucrat * test_copy = new Bureaucrat(test);

		std::cout << YEL << "===== Test promote =====" << CRESET << std::endl;

		test_copy->promote();
		std::cout << *test_copy << std::endl;

		std::cout << YEL << "===== Test assignation =====" << CRESET << std::endl;

		Bureaucrat test_copy2;
		test_copy2 = *test_copy;

		std::cout << YEL << "===== Test demote =====" << CRESET << std::endl;

		test_copy2.demote();
		std::cout << test_copy2 << std::endl;
		delete test_copy;

	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}

	try {
		std::cout << GRN << "===== Test " << ++nb_test << " =====" << CRESET << std::endl;

		std::cout << YEL << "===== Test constructor with too high grade =====" << CRESET << std::endl;

		Bureaucrat test("Keven", 0);
	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}

	try {
		std::cout << GRN << "===== Test " << ++nb_test << " =====" << CRESET << std::endl;

		std::cout << YEL << "===== Test constructor with too low grade =====" << CRESET << std::endl;	

		Bureaucrat test("Keven", 151);
	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}

	try {
		std::cout << GRN << "===== Test " << ++nb_test << " =====" << CRESET << std::endl;

		std::cout << YEL << "===== Test demote with too high grade =====" << CRESET << std::endl;

		Bureaucrat test("Keven", 150);

		test.demote();

	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}

	try {
		std::cout << GRN << "===== Test " << ++nb_test << " =====" << CRESET << std::endl;

		std::cout << YEL << "===== Test promote with too low grade =====" << CRESET << std::endl;

		Bureaucrat test("Keven", 1);

		test.promote();
	} catch (std::exception & err) {
		std::cout << err.what() << std::endl;
	}

	return 0;
}