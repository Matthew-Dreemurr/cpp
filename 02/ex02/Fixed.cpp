#include "Fixed.hpp"

#include <cmath>

	Fixed::Fixed()
	: number(0)
	{
		// std::cout << "Default constructor called" << std::endl;
	}

	Fixed::Fixed(const int nb)
	:number(nb << fract)
	{
		// std::cout << "Int constructor called" << std::endl;
	}

	Fixed::Fixed(const float nb)
	{
		number = std::roundf(nb * std::pow(2, fract));
		// std::cout << "Float constructor called" << std::endl;
	}

	Fixed::Fixed(const Fixed &newFixed)
	{
		// std::cout << "Copy constructor called" << std::endl;
		*this = newFixed;
	}

	Fixed& Fixed::operator=(const Fixed &newFixed) {
		// std::cout << "Copy assignment operator called" << std::endl;
		number = newFixed.getRawBits();
		return *this;
	}

	std::ostream& operator<<(std::ostream &os, const Fixed &fixedNumber) {
		os << fixedNumber.toFloat();
		return os;
	}

	bool Fixed::operator<(const Fixed &r) const {
		return this->number < r.number;
	}

	bool Fixed::operator>(const Fixed &r) const {
		return this->number > r.number;
	}

	bool Fixed::operator<=(const Fixed &r) const {
		return this->number <= r.number;
	}

	bool Fixed::operator>=(const Fixed &r) const {
		return this->number >= r.number;
	}

	bool Fixed::operator==(const Fixed &r) const {
		return this->number == r.number;
	}

	bool Fixed::operator!=(const Fixed &r) const {
		return this->number != r.number;
	}

	Fixed Fixed::operator+(const Fixed &r) const {
		return this->number + r.number;
	}

	Fixed Fixed::operator-(const Fixed &r) const {
		return this->number - r.number;
	}

	Fixed Fixed::operator*(const Fixed &r) const {
		return this->toFloat() * r.toFloat();
	}

	Fixed Fixed::operator/(const Fixed &r) const {
		return this->number / r.number;
	}

	Fixed Fixed::operator++(int) {
		Fixed tmp(*this);
		this->number += 1;
		return tmp;
	}

	Fixed Fixed::operator--(int) {
		Fixed tmp(*this);
		this->number -= 1;
		return tmp;
	}

	Fixed& Fixed::operator++() {
		this->number += 1;
		return *this;
	}

	Fixed& Fixed::operator--() {
		this->number -= 1;
		return *this;
	}

	Fixed::~Fixed() {
		// std::cout << "Destructor called" << std::endl;
	}

	int Fixed::getRawBits( void ) const {
		// std::cout << "getRawBits member function called" << std::endl;
		return number;
	}

	void Fixed::setRawBits( int const raw ) {
		// std::cout << "setRawBits member function called" << std::endl;
		number = raw;
	}

	float Fixed::toFloat( void ) const {
		return (float) number / std::pow(2, fract);
	}
	int Fixed::toInt( void ) const {
		return (int) number >> fract;
	}

	Fixed& Fixed::min(Fixed &l, Fixed &r) {
		return (l > r) ? r : l;
	}

	Fixed& Fixed::max(Fixed &l, Fixed &r) {
		return (l < r) ? r : l;
	}

	const Fixed& Fixed::min(const Fixed &l, const Fixed &r) {
		return (l > r) ? r : l;
	}

	const Fixed& Fixed::max(const Fixed &l, const Fixed &r) {
		return (l < r) ? r : l;
	}
