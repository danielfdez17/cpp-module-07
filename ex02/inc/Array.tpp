// #include "Array.hpp"
#include <exception>
#include <iostream>

template <typename T>
Array<T>::Array() : arr(NULL), _size(0)
{
	std::cout << BLUE << __func__ << " default constructor called\n" RESET;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	std::cout << BLUE << __func__ << " parameterized constructor called\n" RESET;
	if (n <= 0)
		return ;
	arr = new T[_size];
}

template <typename T>
Array<T>::Array(const Array &copy)
{
	std::cout << BLUE << __func__ << " copy constructor called\n" RESET;
	if (this == &copy)
		return;

	_size = copy._size;
	arr = new T[_size];

	for (long i = 0; i < _size; i++)
		arr[i] = copy.arr[i];
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array &copy)
{
	std::cout << BLUE << __func__ << " assignment operator called\n" RESET;
	if (this == &copy)
		return *this;

	if (arr)
	{
		delete[] arr;
		arr = NULL;
	}

	_size = copy._size;
	arr = new T[_size];

	for (long i = 0; i < _size; i++)
		arr[i] = copy.arr[i];
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << BLUE << __func__ << " destructor called\n" RESET;
	delete[] arr;
	arr = NULL;
	_size = 0;
}

template <typename T>
T	&Array<T>::operator[](int idx)
{
	if (idx < 0 || idx >= _size)
		throw std::exception();
	return arr[idx];
}

template <typename T>
const T	&Array<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= _size)
		throw std::exception();
	return arr[idx];
}

template <typename T>
long	Array<T>::size() const
{
	return _size;
}

