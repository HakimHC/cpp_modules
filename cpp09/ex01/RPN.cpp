#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

RPN::RPN(RPN& other) {
	this->_stack = other._stack;
	this->_tokens = other._tokens;
}

RPN& RPN::operator=(RPN& rhs) {
	if (this != &rhs) {
		this->_stack = rhs._stack;
		this->_tokens = rhs._tokens;
	}
	return *this;
}

void RPN::parse(std::string& s) {
	(void) s;
}
