#include <exception>
#include <iostream>

#include "PmergeMe.hpp"

int main(int argc, const char **argv) {
	if (argc == 1) {
		std::cerr << "fatal: invalid arguments" << std::endl;
		std::cerr << "usage: ./PmergeMe [arg1] [arg2] ... [argn]" << std::endl;
		return 1;
	}
	PmergeMe pm = PmergeMe();

	try {
		pm.parse(argv + 1);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	
	std::cout << "Before:\t";
	pm.print(VECTOR);
	try {
		pm.sortVector();
	}
	catch (...) {}
	std::cout << "After:\t";
	pm.print(VECTOR);
	return 0;
}
