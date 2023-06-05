#include <iostream>
#include <cmath>

#include "Fixed.hpp"

int const Fixed::fbits = 8;

Fixed::Fixed()
	:val(0)
{std::cout << "Default constructor called" << std::endl;}

// 10 in binary:	0000 0000 0000 0000 0000 0000 0000 1010
// fixed point:		0000 0000 0000 0000 0000 1010 0000 0000

Fixed::Fixed(int const n) {
	std::cout << "Int constructor called" << std::endl;
	this->val = n << 8;
}

Fixed::Fixed(float const n) {
	std::cout << "Float constructor called" << std::endl;
	float res  = n * 256;
	res = roundf(res);
	this->val = (int) res;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->val = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->val = rhs.getRawBits();
	}
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

int Fixed::toInt( void  ) const {
	return this->val >> this->fbits;
}

float Fixed::toFloat(void) const {
	float res = (float) this->val;
	res /= 256;
	return res;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}
