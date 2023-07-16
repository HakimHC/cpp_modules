#include <iostream>

#include "RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "fatal: invalid arguments" << std::endl;
		std::cerr << "usage: ./RPN [expr]" << std::endl;
		return 1;
	}
	RPN obj;
	std::string input = argv[1];
	obj.parse(input);
	return 0;
}
