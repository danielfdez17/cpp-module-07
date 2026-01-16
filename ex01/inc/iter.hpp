#pragma once
#ifndef __ITER_HPP__
#define __ITER_HPP__

template <typename T>
void		swap(T &a, T &b);

template <typename T>
T const&	min(T const&a, T const&b);

template <typename T>
T const&	max(T const&a, T const&b);

template <typename T>
void	automate(T a, T b);

template <typename T>
void	iter(T const *arr, const int len, void (*f)(T const&));

template <typename T>
void	iter(T *arr, const int len, void (*f)(T &));

template <typename T>
void	sum_value(T &val);

template <typename T>
void	print_value(T const&val);

template <typename T>
void	automateRef(T *arr, const int len, void(*f)(T &));

template <typename T>
void	automateConstRef(T const *arr, const int len, void (*f)(T const&));

#endif // __ITER_HPP__
