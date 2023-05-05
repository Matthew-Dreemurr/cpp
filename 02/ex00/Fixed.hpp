#ifndef FIXED_H
#define FIXED_H

class Fixed {
public:
	Fixed();
	Fixed(Fixed &newFixed);
	Fixed operator=(Fixed &newFixed);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
private:
	int number;
	const static int fract = 8;
};

#endif /* FIXED_H */