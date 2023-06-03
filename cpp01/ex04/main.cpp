#include <iostream>

#include "sed.hpp"

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "fatal: invalid arguments" << std::endl;
		return 1;
	}
	sed(argv[1], argv[2], argv[3]);
}
