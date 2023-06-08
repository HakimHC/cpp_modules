#include <iostream>

#include "Animal.hpp"

Animal::Animal() {
	this->type = "Animal";
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal& other) {
	this->type = other.type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(Animal& rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(void) const {
	return this->type;
}

void Animal::makeSound() const {}
