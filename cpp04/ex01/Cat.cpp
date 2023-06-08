#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"

Cat::Cat()
	:Animal()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(Cat& other)
	:Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = other.type;
	this->brain = new Brain(*(other.brain));
}

Cat& Cat::operator=(Cat& rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
		delete this->brain;
		this->brain = new Brain(*(rhs.brain));
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const {
	std::cout << "meow meow" << std::endl;
}
