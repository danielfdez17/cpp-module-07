#pragma once
#ifndef __FIXED__
#define __FIXED__

#include <iostream>
#include "colors.hpp"

class Fixed
{
private:
	int					value;
	float				floatNumber;
	static const int	fracBits;

public:
	Fixed(void);
	Fixed(const Fixed &copy);
	Fixed & operator=(const Fixed& copy);
	~Fixed(void);

	Fixed(const int &value);
	Fixed(const float &floatNumber);

	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;

	bool 				operator>(const Fixed &other) const;
	bool 				operator<(const Fixed &other) const;
	bool 				operator>=(const Fixed &other) const;
	bool 				operator<=(const Fixed &other) const;
	bool 				operator==(const Fixed &other) const;
	bool 				operator!=(const Fixed &other) const;

	Fixed 				operator+(const Fixed &other) const;
	Fixed 				operator-(const Fixed &other) const;
	Fixed 				operator*(const Fixed &other) const;
	Fixed 				operator/(const Fixed &other) const;

	Fixed 				&operator++(void);	// ? Pre increment
	Fixed 				operator++(int);	// ? Post increment
	Fixed 				&operator--(void);	// ? Pre decrement
	Fixed 				operator--(int);	// ? Post decrement

	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream & operator<<(std::ostream &out, const Fixed &fixed);

#endif // __FIXED__