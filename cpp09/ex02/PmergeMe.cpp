#include <cctype>
#include <climits>
#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <algorithm>

#include "PmergeMe.hpp"

#define _CHUNK_SIZE 10

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

/* Utilities */
template <typename T>
static bool _isSorted(T& container) {
	typename T::iterator it = container.begin();
	for (; it != container.end() - 1; it++) {
		if (*it > *(it + 1))
			return false;
	}
	return true;
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

template <typename T>
static void insertionSort(T& container, size_t l, size_t r) {
	for (size_t i = l; i < r; i++) {
		size_t j = i;
		while (j > l && container[j] < container[j - 1]) {
			unsigned int tmp = container[j];
			container[j] = container[j - 1];
			container[j - 1] = tmp;
			--j;
		}
	}
}

template <typename T>
static void printContainer(T container) {
	for (typename T::iterator it = container.begin(); it != container.end(); it++) {
		std::cout << *it << (it + 1 == container.end() ? "\n" : " ");
	}
}

static void _mergeVector(std::vector<unsigned int>& vec, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - left;
	std::vector<unsigned int> left_vector;
	std::vector<unsigned int> right_vector;

	for (int i = left; i < mid + 1; i++)
		left_vector.push_back(vec[i]);
	for (int i = mid + 1; i < right + 1; i++)
		right_vector.push_back(vec[i]);

	int left_index = 0;
	int right_index = 0;

	for (int i = left; i < right - left + 1; i++) {
		if (right_index == n2) {
			vec[i] = left_vector[left_index];
			++left_index;
		}
		else if (left_index == n1) {
			vec[i] = right_vector[right_index];
			++right_index;
		}
		else if (right_vector[right_index] > left_vector[left_index]) {
			vec[i] = left_vector[left_index];
			++left_index;
		}
		else {
			vec[i] = right_vector[right_index];
			++right_index;
		}
	}
}

static void _sortVector(std::vector<unsigned int>& vec, int left, int right) {
	/* if (right - left > _CHUNK_SIZE) { */
	if (0) {
		int mid = (left + right) / 2;
		_sortVector(vec, left, mid);
		_sortVector(vec, mid + 1, right);
		_mergeVector(vec, left, mid, right);
		std::cout << "keloke\n";
	}
	else {
		insertionSort(vec, left, right);
	}
}

/* Member functions */
void PmergeMe::parse(const char *arr[]) {
	for (int i = 0; arr[i]; i++) {
		validateArgument(arr[i]);
		this->_vec.push_back(std::atoi(arr[i]));
	}
	this->_dq = std::deque<unsigned int>(this->_vec.begin(), this->_vec.end());
}

void PmergeMe::sortVector() {
	_sortVector(this->_vec, 0, this->_vec.size());
	if (!_isSorted(this->_vec))
		std::runtime_error("fatal: vector is not sorted");
}

void PmergeMe::print(enum containers type) const {
	switch (type) {
		case VECTOR:
			printContainer(this->_vec);
			break;
		case DEQUE:
			printContainer(this->_dq);
			break;
	}
}
