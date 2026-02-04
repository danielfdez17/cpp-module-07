#include "colors.hpp"
#include "iter.hpp"
#include <iostream>
#include <ctype.h>

const int MAX_LENGTH = 10;

// template <typename T>
// void		swap(T &a, T &b)
// {
// 	T	tmp = a;
// 	a = b;
// 	b = tmp;
// }
// template <typename T>
// T const&	min(T const&a, T const&b)
// {
// 	return a < b ? a : b;
// }
// template <typename T>
// T const&	max(T const&a, T const&b)
// {
// 	return a > b ? a : b;
// }

// template <typename T>
// void	automate(T a, T b)
// {
// 	::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << "\n";
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << "\n";
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << "\n\n";
// }

// template <typename T>
// void	iter(T const *arr, const int len, void (*f)(T const&))
// {
// 	for (int i = 0; i < len; ++i)
// 		f(arr[i]);
// }

// template <typename T>
// void	iter(T *arr, const int len, void (*f)(T &))
// {
// 	for (int i = 0; i < len; ++i)
// 		f(arr[i]);
// }

// template <typename T>
// void	modValue(T &val)
// {
// 	++val *= 2;
// 	// toupper(val);
// }

// template <typename T>
// void	noModValue(T const&val)
// {
// 	std::cout << val << " ";
// }

// template <typename T>
// void	automateRef(T *arr, const int len, void(*f)(T &))
// {
// 	iter(arr, len, f);
// }

// template <typename T>
// void	automateConstRef(T const *arr, const int len, void (*f)(T const&))
// {
// 	iter(arr, len, f);
// 	std::cout << "\n";
// }

int main( void ) {
	std::cout << YELLOW "--------------Template tests--------------\n" RESET;
	automate(2, 3);
	automate(2.0f, 3.5f);
	automate(20.00, 30.50);
	automate("chain1", "chain2");
	automate('3', 'X');
	std::cout << YELLOW "--------------Iter tests--------------\n" RESET;

	int arr[MAX_LENGTH] = {1,2,3,4,5,6,7,8,9,10};
	automateConstRef(arr, MAX_LENGTH, noModValue);
	automateRef(arr, MAX_LENGTH, modValue);
	automateConstRef(arr, MAX_LENGTH, noModValue);
	std::cout << "\n";

	float fArr[MAX_LENGTH] = {1.12f,2.12f,3.12f,4.12f,5.12f,6.12f,7.12f,8.12f,9.12f,10.f};
	automateConstRef(fArr, MAX_LENGTH, noModValue);
	automateRef(fArr, MAX_LENGTH, modValue);
	automateConstRef(fArr, MAX_LENGTH, noModValue);
	std::cout << "\n";

	char cArr[MAX_LENGTH] = {'a','5','!',')','*','^','H','0','<','?'};
	automateConstRef(cArr, MAX_LENGTH, noModValue);
	automateRef(cArr, MAX_LENGTH, modValue);
	automateConstRef(cArr, MAX_LENGTH, noModValue);
	std::cout << "\n";

	// std::string sArr = "aasd523!aG)SDGs+``+*^adHGa023faFsa3<?";
	// automateConstRef(&sArr, sArr.size(), noModValue);
	// automateRef(&sArr, sArr.size(), modValue);
	// automateConstRef(&sArr, sArr.size(), noModValue);
	// std::cout << "\n";
	
	return 0;
}