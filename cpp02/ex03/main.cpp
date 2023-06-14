#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	Fixed a(1);
	Fixed b(2);

	Point p(a, b);
	std::cout << p << std::endl;
}
