#include <iostream>
#include <string>

#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "fatal: invalid arguments" << std::endl;
		return 1;
	}
	std::string res = argv[1];
	ScalarConverter::convert(res);
}
