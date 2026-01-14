#include "Array.hpp"
#include <exception>

template <typename T>
Array::Array() : _size(0), arr(nullptr)
{

}

template <typename T>
Array::Array(unsigned int n) : _size(n)
{
	arr = new T[_size];
}

template <typename T>
Array::Array(const Array &copy)
{
	if (this == &copy)
		return;

	if (arr)
		delete[] arr;

	_size = copy._size;
	arr = new T[_size];

	for (long i = 0; i < _size; i++)
		arr[i] = copy.arr[i];
}

template <typename T>
Array	&Array::operator=(const Array &copy)
{
	if (this == &copy)
		return *this;

	if (arr)
		delete[] arr;

	_size = copy._size;
	arr = new T[_size];

	for (long i = 0; i < _size; i++)
		arr[i] = copy.arr[i];
	return *this;
}

template <typename T>
Array::~Array()
{
	delete[] arr;
	_size = 0;
}

template <typename T>
T	&Array::operator[](int idx)
{
	if (idx < 0 || idx >= _size)
		throw std::exception("Index is out of bounds!");
	return arr[idx];
}

template <typename T>
const T	&Array::operator[](int idx) const
{
	if (idx < 0 || idx >= _size)
		throw std::exception("Index is out of bounds!");
	return arr[idx];
}

template <typename T>
long	Array::size() const
{
	return _size;
}

