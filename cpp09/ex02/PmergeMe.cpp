#include <cctype>
#include <climits>
#include <stdexcept>

#include "PmergeMe.hpp"

/* Default constructor and destructor */
PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

/* Copy constructor and copy assignment operator */
PmergeMe::PmergeMe(const PmergeMe& other):
	_vec(other._vec), _dq(other._dq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	if (this != &rhs) {
		this->_vec = rhs._vec;
		this->_dq = rhs._dq;
	}
	return *this;
}

static void validateArgument(std::string argument) {
	int plusCounter = 0;

	for (size_t i = 0; i < argument.size(); i++) {
		if (argument[i] == '+')
			++plusCounter;
		else if (!std::isdigit(argument[i]))
			throw std::runtime_error("fatal: invalid argument detected (nan)");
		if (plusCounter > 1)
			throw std::runtime_error("fatal: invalid argument detected (nan)");
	}
	long res = std::atol(argument.c_str());
	if (res > INT_MAX || res < 0)
			throw std::runtime_error("fatal: invalid argument detected (not an integer)");
}

/* Member functions */
void PmergeMe::parse(char *arr[]) {
	for (int i = 0; arr[i]; i++) {
		validateArgument(arr[i]);
	}
}
