#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog()
	:Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog& other)
	:Animal()
{
	this->type = other.type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(Dog& rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "woof woof" << std::endl;
}
