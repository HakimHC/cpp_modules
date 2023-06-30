#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat()
	:Animal()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat& other)
	:Animal()
{
	this->type = other.type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(Cat& rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "meow meow" << std::endl;
}
