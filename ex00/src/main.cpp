#include "colors.hpp"
#include "Fixed.hpp"
#include "whatever.hpp"
#include <iostream>

int main( void ) {

	::automate(2, 3);
	::automate(2.0f, 3.5f);
	::automate(20.00, 30.50);
	::automate("chain1", "chain2");
	::automate('3', 'X');
	::automate(Fixed(123), Fixed(7865));
	return 0;
}