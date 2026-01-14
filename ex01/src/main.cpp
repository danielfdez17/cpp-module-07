#include "colors.hpp"
// #include "whatever.hpp"
#include <iostream>

const int MAX_LENGTH = 10;

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
void	iter(T const *arr, const int len, void (*f)(T const&))
{
	for (int i = 0; i < len; ++i)
		f(arr[i]);
}

template <typename T>
void	iter(T *arr, const int len, void (*f)(T &))
{
	for (int i = 0; i < len; ++i)
		f(arr[i]);
}

template <typename T>
void	sum_value(T &val)
{
	val++;
}

template <typename T>
void	print_value(T const&val)
{
	std::cout << __func__ << ": " << val << "\n";
}

int main( void ) {
	int a = 2;
	int b = 3;
	std::cout << YELLOW "--------------Template tests--------------\n" RESET;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << YELLOW "--------------Template tests--------------\n" RESET;
	int arr[MAX_LENGTH] = {1,2,3,4,5,6,7,8,9,10};
	iter(arr, MAX_LENGTH, sum_value);
	iter(arr, MAX_LENGTH, print_value);
	return 0;
}