#include <iostream>
#include <ostream>

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point()
	:_x(Fixed(0)), _y(Fixed(0))
{
	std::cout << "Point default costructor called" << std::endl;
}

Point::Point(Fixed& x, Fixed& y)
	:_x(x), _y(y)
{
	std::cout << "Point params costructor called" << std::endl;
}

Point::Point(Point& other)
	:_x(other._x), _y(other._y)
{
	std::cout << "Point copy costructor called" << std::endl;
}

Point& Point::operator=(Point& rhs) {
	if (this != &rhs) {
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return *this;
}

Point::~Point() {
	std::cout << "Point destructor called" << std::endl;
}

Fixed Point::getX() const {
	return this->_x;
}

Fixed Point::getY() const {
	return this->_y;
}

void Point::setX(Fixed f) {
	this->_x = f;
}

void Point::setY(Fixed f) {
	this->_y = f;
}

std::ostream& operator<<(std::ostream& os, Point& p) {
	os << "X: " << p.getX().toFloat() << " | Y: " << p.getY().toFloat();
	return os;
}
