#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::fracBits = 8;

Fixed::Fixed(void)
{
	// std::cout << GREEN "Default constructor called\n" RESET;
	value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << YELLOW "Copy constructor called\n" RESET;
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed& copy)
{
	// std::cout	<< CYAN "Copy assignment operator called\n" RESET;
	value = copy.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	// std::cout << RED "Desstructor called\n" RESET;
}

Fixed::Fixed(const int &value)
{
	// std::cout << GREEN "Int constructor called\n" RESET;
	this->value = value << fracBits;
	floatNumber = toFloat();
}

Fixed::Fixed(const float &floatNumber)
{
	// std::cout << GREEN "Float constructor called\n" RESET;
	this->value = roundf(floatNumber * (1 << fracBits));
	this->floatNumber = floatNumber;
}

int		Fixed::getRawBits(void) const
{
	// std::cout << BLUE << __func__ << " member function called\n" RESET;
	return value;
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)value / (1 << fracBits);
}

int		Fixed::toInt(void) const
{
	return value >> fracBits;
}

// * Comparison operators
bool Fixed::operator>(const Fixed &other) const
{
	return value > other.value;
}

bool Fixed::operator<(const Fixed &other) const
{
	return value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const
{
	return value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return !(*this == other);
}

Fixed fromRawBits(int raw)
{
	Fixed fixed;
	fixed.setRawBits(raw);
	return fixed;
}

// * Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const
{
	return fromRawBits(this->value + other.value);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return fromRawBits(this->value - other.value);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	// Multiply raw fixed-point values and scale result
	long long result = static_cast<long long>(this->value) * other.value;
	return fromRawBits(static_cast<int>(result >> fracBits));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.value == 0)
		return Fixed(0.0f);
	long long result = (static_cast<long long>(this->value) << fracBits) / other.value;
	return fromRawBits(static_cast<int>(result));
}

// * Pre and Post increment/decrement operators
Fixed &Fixed::operator++(void)
{
	++value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	value++;
	return temp;
}

Fixed &Fixed::operator--(void)
{
	--value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	value--;
	return temp;
}

// * Min and Max static member functions
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}