#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(const int nb);
	Fixed(const float nb);
	Fixed(const Fixed &newFixed);
	Fixed& operator=(const Fixed &newFixed);
	~Fixed();

	bool operator<(const Fixed &r) const;
	bool operator>(const Fixed &r) const;

	bool operator<=(const Fixed &r) const;
	bool operator>=(const Fixed &r) const;

	bool operator==(const Fixed &r) const;
	bool operator!=(const Fixed &r) const;

	Fixed operator+(const Fixed &r) const;
	Fixed operator-(const Fixed &r) const;
	Fixed operator*(const Fixed &r) const;
	Fixed operator/(const Fixed &r) const;

	Fixed operator++(const int r);
	Fixed operator--(const int r);
	Fixed& operator++();
	Fixed& operator--();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

	static Fixed& min(Fixed &l, Fixed &r);
	static Fixed& max(Fixed &l, Fixed &r);
	static const Fixed& min(const Fixed &l, const Fixed &r);
	static const Fixed& max(const Fixed &l, const Fixed &r);
	
private:
	int number;
	const static int fract = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixedNumber);


#endif /* FIXED_H */