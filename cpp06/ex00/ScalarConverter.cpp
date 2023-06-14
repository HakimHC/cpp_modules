#include <iostream>

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{std::cout << "ScalarConverter default constructor called" << std::endl;}

ScalarConverter::ScalarConverter(ScalarConverter& other) {
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	(void) other;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& rhs) {
	std::cout << "ScalarConverter assignment operator called" << std::endl;
	if (this != &rhs) {
		// do nothing
	}
	return *this;
}

ScalarConverter::~ScalarConverter()
{std::cout << "ScalarConverter destructor called" << std::endl;}

void ScalarConverter::convert(std::string s) {

	std::cout << s << std::endl;
}
