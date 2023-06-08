#include <iostream>

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->val = 0;
}

Fixed::Fixed(Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->val = other.getRawBits();
}

Fixed& Fixed::operator=(Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->val = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->val;
}

void Fixed::setRawBits(int const raw) {
	this->val = raw;
}
