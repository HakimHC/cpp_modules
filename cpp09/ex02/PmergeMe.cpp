#include "PmergeMe.hpp"

#include <algorithm>
#include <cctype>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>

#define _CHUNK_SIZE 7

/* Default constructor and destructor */
PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

/* Copy constructor and copy assignment operator */
PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _dq(other._dq) {}

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
    if (*it > *(it + 1)) return false;
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
    throw std::runtime_error(
        "fatal: invalid argument detected (not an integer)");
}

template <typename T>
static void insertionSort(T& container, size_t l, size_t r) {
  for (size_t i = l; i < r; i++) {
    unsigned int tmp = container[i + 1];
    size_t j  = i  + 1;
    while (j > l && container[j - 1] > tmp) {
      container[j] = container[j - 1];
      --j;
    }
    container[j] = tmp;
  }
}

template <typename T>
static void printContainer(T container) {
  for (typename T::iterator it = container.begin(); it != container.end();
       it++) {
    std::cout << *it << (it + 1 == container.end() ? "\n" : " ");
  }
}

static void _mergeVector(std::vector<unsigned int>& vec, int left, int mid,
                         int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  std::vector<unsigned int> leftVector(n1);
  std::vector<unsigned int> rightVector(n2);

  for (int i = 0; i < n1; i++) leftVector[i] = vec[left + i];
  for (int i = 0; i < n2; i++) rightVector[i] = vec[mid + 1 + i];

  int leftIndex = 0;
  int rightIndex = 0;

  for (int i = left; i < right + 1; i++) {
    if (rightIndex >= n2) {
      vec[i] = leftVector[leftIndex];
      ++leftIndex;
    } else if (leftIndex >= n1) {
      vec[i] = rightVector[rightIndex];
      ++rightIndex;
    } else if (rightVector[rightIndex] > leftVector[leftIndex]) {
      vec[i] = leftVector[leftIndex];
      ++leftIndex;
    } else {
      vec[i] = rightVector[rightIndex];
      ++rightIndex;
    }
  }
}

static void _mergeDeque(std::deque<unsigned int>& dq, int left, int mid,
                         int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  std::deque<unsigned int> leftDeque(n1);
  std::deque<unsigned int> rightDeque(n2);

  for (int i = 0; i < n1; i++) leftDeque[i] = dq[left + i];
  for (int i = 0; i < n2; i++) rightDeque[i] = dq[mid + 1 + i];

  int leftIndex = 0;
  int rightIndex = 0;

  for (int i = left; i < right + 1; i++) {
    if (rightIndex >= n2) {
      dq[i] = leftDeque[leftIndex];
      ++leftIndex;
    } else if (leftIndex >= n1) {
      dq[i] = rightDeque[rightIndex];
      ++rightIndex;
    } else if (rightDeque[rightIndex] > leftDeque[leftIndex]) {
      dq[i] = leftDeque[leftIndex];
      ++leftIndex;
    } else {
      dq[i] = rightDeque[rightIndex];
      ++rightIndex;
    }
  }
}


static void _sortVector(std::vector<unsigned int>& vec, int left, int right) {
  if (right - left > _CHUNK_SIZE) {
    int mid = (left + right) / 2;
    _sortVector(vec, left, mid);
    _sortVector(vec, mid + 1, right);
    _mergeVector(vec, left, mid, right);
  } else {
    insertionSort(vec, left, right);
  }
}

static void _sortDeque(std::deque<unsigned int>& dq, int left, int right) {
  if (right - left > _CHUNK_SIZE) {
    int mid = (left + right) / 2;
    _sortDeque(dq, left, mid);
    _sortDeque(dq, mid + 1, right);
    _mergeDeque(dq, left, mid, right);
  } else {
    insertionSort(dq, left, right);
  }
}

/* Member functions */
void PmergeMe::parse(const char* arr[]) {
  for (int i = 0; arr[i]; i++) {
    validateArgument(arr[i]);
    this->_vec.push_back(std::atoi(arr[i]));
  }
  this->_dq = std::deque<unsigned int>(this->_vec.begin(), this->_vec.end());
}

void PmergeMe::sortVector() {
  _sortVector(this->_vec, 0, this->_vec.size() - 1);
  if (!_isSorted(this->_vec))
    throw std::runtime_error("fatal: vector is not sorted");
}

void PmergeMe::sortDeque() {
  _sortDeque(this->_dq, 0, this->_dq.size() - 1);
  if (!_isSorted(this->_vec))
    throw std::runtime_error("fatal: deque is not sorted");
}

double PmergeMe::trackRunTimeVector() {
  clock_t start = clock();

  this->sortVector();

  clock_t end = clock();

  return double(end - start) / (CLOCKS_PER_SEC / 1000.0);
}

double PmergeMe::trackRunTimeDeque() {
  clock_t start = clock();

  this->sortDeque();

  clock_t end = clock();

  return double(end - start) / (CLOCKS_PER_SEC / 1000.0);
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
