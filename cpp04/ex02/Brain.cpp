#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	this->ideas = new std::string[100];
}

Brain::Brain(Brain& other) {
	std::cout << "Brain copy constructor called" << std::endl;
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(Brain& rhs) {
	if (this != &rhs) {
		delete[] this->ideas;
		this->ideas = new std::string[100];
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
	delete[] this->ideas;
}

std::string Brain::getIdea(int index) {
	return (this->ideas)[index];
}

void Brain::setIdea(std::string idea, int index) {
	(this->ideas)[index] = idea;
}
