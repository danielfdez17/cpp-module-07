#include "colors.hpp"
#include "Fixed.hpp"
#include "whatever.hpp"
#include <iostream>

template <typename T>
void		swap(T &a, T &b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}
template <typename T>
T const&	min(T const&a, T const&b)
{
	return a < b ? a : b;
}
template <typename T>
T const&	max(T const&a, T const&b)
{
	return a > b ? a : b;
}

template <typename T>
void	automate(T a, T b)
{
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << "\n";
	std::cout << "min( a, b ) = " << ::min( a, b ) << "\n";
	std::cout << "max( a, b ) = " << ::max( a, b ) << "\n\n";
}

int main( void ) {

	::automate(2, 3);
	::automate(2.0f, 3.5f);
	::automate(20.00, 30.50);
	::automate("chain1", "chain2");
	::automate('3', 'X');
	::automate(Fixed(123), Fixed(7865));
	return 0;
}