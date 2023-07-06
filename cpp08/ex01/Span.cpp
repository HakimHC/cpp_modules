#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "Span.hpp"

Span::Span(): _N(0) {}

Span::Span(unsigned int n): _N(n) {}

Span::~Span() {}

Span::Span(Span& other):_N(other._N), _vec(other._vec) {}

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
	std::sort(this->_vec.begin(), this->_vec.end());
	return this->_vec.back() - this->_vec.front();
}

static void printElem(int n) {
	std::cout << n << std::endl;
}

void Span::printVector() {
	std::for_each(this->_vec.begin(), this->_vec.end(), &printElem);
}
