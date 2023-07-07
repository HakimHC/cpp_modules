#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <functional>

#include "Span.hpp"

Span::Span(): _N(0) {}

Span::Span(unsigned int n): _N(n) {}

Span::~Span() {}

Span::Span(const Span& other):_N(other._N), _vec(other._vec) {}

Span& Span::operator=(Span& rhs) {
	if (this != &rhs) {
		this->_N = rhs._N;
		this->_vec = rhs._vec;
	}
	return *this;
}

void Span::addNumber(int n) {
	if (this->_vec.size() + 1 > this->_N)
		throw std::runtime_error("Cannot add a new element, span is full");
	this->_vec.push_back(n);
}

int Span::longestSpan() {
	if (this->_vec.size() <= 1)
		throw std::runtime_error("No span can be detected");

	std::sort(this->_vec.begin(), this->_vec.end());

	return this->_vec.back() - this->_vec.front();
}

int Span::shortestSpan() {

	if (this->_vec.size() <= 1)
		throw std::runtime_error("No span can be detected");

	std::sort(this->_vec.begin(), this->_vec.end());

	if (this->_vec.size() == 2)
		return this->longestSpan();

	int shortestSpan = this->_vec[1] - this->_vec[0];
	int currSpan = shortestSpan;

	for (std::vector<int>::iterator it = this->_vec.begin() + 1; it != this->_vec.end(); it++) {
		currSpan = *it - *(it - 1);
		if (currSpan < shortestSpan)
			shortestSpan = currSpan;
	}
	return shortestSpan;
}

static void printElem(int n) {
	std::cout << n << std::endl;
}

void Span::printVector() {
	std::for_each(this->_vec.begin(), this->_vec.end(), &printElem);
}

void Span::addRange(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	if ((unsigned int) std::distance(first, last) > this->_N - this->_vec.size())
		throw std::runtime_error("Cannot bulk insert elements");
	for (;first != last; first++)
		this->addNumber(*first);
}
