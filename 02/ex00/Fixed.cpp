#include "Fixed.hpp"

#include <iostream>

	Fixed::Fixed()
	: number(0)
	{
		std::cout << "Default constructor called" << std::endl;
	}

	Fixed::Fixed(Fixed &newFixed)
	{
		std::cout << "Copy constructor called" << std::endl;
		number = newFixed.getRawBits();
	}

	Fixed& Fixed::operator=(const Fixed &newFixed) {
		std::cout << "Copy assignment operator called" << std::endl;
		number = newFixed.getRawBits();
		return *this;
	}

	Fixed::~Fixed() {
		std::cout << "Destructor called" << std::endl;
	}

	int Fixed::getRawBits( void ) const {
		std::cout << "getRawBits member function called" << std::endl;
		return number;
	}

	void Fixed::setRawBits( int const raw ) {
		std::cout << "setRawBits member function called" << std::endl;
		number = raw;
	}
