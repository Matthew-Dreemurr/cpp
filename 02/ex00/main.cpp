#include "Fixed.hpp"
#include <iostream>
	int main( void ) {
// Default constructor calleda
	Fixed a;
// Copy constructor called
// getRawBits member function called
	Fixed b( a );
// Default constructor called
	Fixed c;
// Copy assignment operator called
// getRawBits member function called
	c = b;
// getRawBits member function called
// 0
	std::cout << a.getRawBits() << std::endl;
// getRawBits member function called
// 0
	std::cout << b.getRawBits() << std::endl;
// getRawBits member function called
// 0
	std::cout << c.getRawBits() << std::endl;
// Destructor called
// Destructor called
// Destructor called
	return 0;
}

