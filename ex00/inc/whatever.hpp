#pragma once
#ifndef __WHATEVER_HPP__
#define __WHATEVER_HPP__

#include <iostream>
#include "colors.hpp"

template <typename T>
void		swap(T &a, T &b);

template <typename T>
T const&	min(T const&a, T const&b);

template <typename T>
T const&	max(T const&a, T const&b);

template <typename T>
void	automate(T a, T b);

#endif // __WHATEVER_HPP__