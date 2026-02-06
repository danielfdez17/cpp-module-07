#pragma once
#ifndef __ITER_HPP__
#define __ITER_HPP__

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

// todo: typename F
template <typename T>
void	iter(T const *arr, const int len, void (*f)(T const&))
{
	for (int i = 0; i < len; ++i)
		f(arr[i]);
}

// todo: typename F
template <typename T>
void	iter(T *arr, const int len, void (*f)(T &))
{
	for (int i = 0; i < len; ++i)
		f(arr[i]);
}

template <typename T>
void	modValue(T &val)
{
	++val *= 2;
	// toupper(val);
}

template <typename T>
void	noModValue(T const&val)
{
	std::cout << val << " ";
}

// template <typename T, typename F>
// void	automateRef(T *arr, const int len, F *f(T &))
template <typename T>
void	automateRef(T *arr, const int len, void(*f)(T &))
{
	iter(arr, len, f);
}

// template<typename T, typename F>
// void	automateConstRef(T const *arr, const int len, F *f(T const&))
template <typename T>
void	automateConstRef(T const *arr, const int len, void (*f)(T const&))
{
	iter(arr, len, f);
	std::cout << "\n";
}

#endif // __ITER_HPP__
