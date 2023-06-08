#include <iostream>

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat()
	:WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat& other)
	:WrongAnimal()
{
	this->type = other.type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat& rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}
