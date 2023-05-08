#ifndef FIXED_H
#define FIXED_H

class Fixed {
public:
	Fixed();
	Fixed(Fixed &newFixed);
	Fixed& operator=(const Fixed &newFixed);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
private:
	int number;
	const static int fract = 8;
};

Fixed operator+(const Fixed& lhs, const Fixed rhs);

#endif /* FIXED_H */