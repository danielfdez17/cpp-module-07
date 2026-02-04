#pragma once
#ifndef __WHATEVER_HPP__
#define __WHATEVER_HPP__

#include <iostream>
#include "colors.hpp"

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

#endif // __WHATEVER_HPP__