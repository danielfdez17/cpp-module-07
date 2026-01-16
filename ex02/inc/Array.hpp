#pragma once
#ifndef __ARRAY__
#define __ARRAY__

#include "colors.hpp"

template <typename T>
class Array
{
private:
	T		*arr;
	long	_size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &copy);
	Array &operator=(const Array &copy);
	~Array();
	
	T& operator[](int idx);
	const T& operator[](int idx) const;
	long	size() const;
	
};

#include "Array.tpp"

#endif // __ARRAY__