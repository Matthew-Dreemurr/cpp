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
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
private:
	int number;
	const static int fract = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixedNumber);


#endif /* FIXED_H */