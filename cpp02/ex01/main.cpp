#include <iostream>

#include "Fixed.hpp"

union fi {
	float f;
	unsigned int i;
};

int main( void ) {
	Fixed a(10);
	std::cout << a.toFloat() << std::endl;
	/* fi fi; */
	/* fi.f = -2.24; */
	/* for (int i = 31; i >= 0; i--) { */
	/* 	if (!((fi.i >> i) & 1)) */
	/* 		std::cout << 0; */
	/* 	else */
	/* 	 	std::cout << 1; */
	/* } */
	/* std::cout << std::endl; */
	/* std::cout << (float) fi.i << std::endl; */
}
