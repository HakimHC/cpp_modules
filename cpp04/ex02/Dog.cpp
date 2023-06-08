#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog()
	:Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(Dog& other)
	:Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = other.type;
	this->brain = new Brain(*(other.brain));
}

Dog& Dog::operator=(const Dog& rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
		delete this->brain;
		this->brain = new Brain(*(rhs.brain));
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

void Dog::makeSound() const {
	std::cout << "woof woof" << std::endl;
}

Brain* Dog::getBrain() {
	return this->brain;
}
