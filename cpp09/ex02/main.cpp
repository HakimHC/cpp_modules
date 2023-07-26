#include <cstdio>
#include <exception>
#include <iostream>

#include "PmergeMe.hpp"

int main(int argc, const char **argv) {
	if (argc == 1) {
		std::cerr << "fatal: invalid arguments" << std::endl;
		std::cerr << "usage: ./PmergeMe [arg1] [arg2] ... [argn]" <<
      std::endl << "(NOTE: arguments must be positive integers)" << std::endl;
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
	
	try {
    std::cout << "Before:\t";
    pm.print(VECTOR);
    pm.sortVector();
    double resVector = pm.trackRunTimeVector();
    double resDeque = pm.trackRunTimeDeque();
    std::cout << "After:\t";
    pm.print(VECTOR);
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : "
      << resVector << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : "
      << resDeque << " us" << std::endl;
	}
  catch (std::exception& e) {
    std::cerr << e.what() << std::endl; 
    return 2;
  }
	return 0;
}
