#include <cctype>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

#include "RPN.hpp"

/* Constructor and destructor */
RPN::RPN() {}
RPN::~RPN() {}

/* Copy constructor */
RPN::RPN(const RPN& other) {
	this->_stack 	= other._stack;
	this->_tokens 	= other._tokens;
}

/* Copy assignment operator */
RPN& RPN::operator=(const RPN& rhs) {
	if (this != &rhs) {
		this->_stack 	= rhs._stack;
		this->_tokens 	= rhs._tokens;
	}
	return *this;
}

/* Static utility functions */
// [...]

static bool isOperator(std::string& token) {
	std::string operators[] = { "+", "-", "*", "/" };

	for (size_t i = 0; i < 4; i++) {
		if (operators[i] == token)
			return true;
	}
	return false;
}

static bool isInt(std::string& token) {
	int signCount = 0;

	for (size_t i = 0; i < token.size(); i++) {
		if (token[i] == '+' || token[i] == '-')
			++signCount;
		else if (!std::isdigit(token[i]))
			return false;
		if (signCount > 1)
			return false;
	}
	if (std::atoi(token.c_str()) == 0 && token != "0")
		return false;
	return true;
}

static void validateToken(std::string& token) {
	if (isOperator(token))
		return;
	if (!isInt(token))
		throw std::runtime_error("fatal: invalid token detected");
}

void printTokens(std::vector<std::string>& tokens) {
	std::cout << "TOKENS: [ ";
		for (std::vector<std::string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
			std::cout << *it;
			std::cout << (it + 1 == tokens.end() ? " ]\n" : ", ");
		}

}

/* Member functions */
void RPN::parse(std::string& s) {
	std::string 		token;
	std::stringstream 	tokenizer(s);
	
	while (std::getline(tokenizer, token, ' ')) {
		if (!token.empty()) {
			validateToken(token);
			this->_tokens.push_back(token);
		}
	}
	/* printTokens(this->_tokens); */
}

void RPN::operate() {
	std::vector<std::string>::iterator 	it;

	int	a;
	int	b;

	for (it = this->_tokens.begin(); it != this->_tokens.end(); it++) {
		if (isOperator(*it)) {
			if (this->_stack.size() < 2)
				throw std::runtime_error("fatal: invalid expression");
			a = this->_stack.top();
			this->_stack.pop();
			b = this->_stack.top();
			this->_stack.pop();
			if (*it == "+")
				this->_stack.push(a + b);
			else if (*it == "-")
				this->_stack.push(b - a);
			else if (*it == "*")
				this->_stack.push(a * b);
			else if (*it == "/") {
				if (a == 0)
					throw std::runtime_error("fatal: division by zero");
				this->_stack.push(b / a);
			}
		}
		else
			this->_stack.push(std::atoi((*it).c_str()));
	}
	if (this->_stack.size() != 1)
		throw std::runtime_error("fatal: invalid expression");
	std::cout << this->_stack.top() << std::endl;
}
