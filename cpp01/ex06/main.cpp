#include <iostream>

#include "Harl.hpp"

level convert_str(std::string s)
{
	if (s == "DEBUG")
		return DEBUG;
	if (s == "INFO")
		return INFO;
	if (s == "WARNING")
		return WARNING;
	if (s == "ERROR")
		return ERROR;
	return UNDEFINED;
}

int main(int argc, char **argv) {

	Harl harlos;

	if (argc != 2) {
		std::cout << "fatal: invalid argument count" << std::endl;
		return 1;
	}

	harlos.set_level(convert_str(argv[1]));
	if (harlos.get_level() == UNDEFINED) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 2;
	}

	std::cout << "DEBUG: ";
	harlos.complain("DEBUG");

	std::cout << std::endl;

	std::cout << "INFO: ";
	harlos.complain("INFO");

	std::cout << std::endl;

	std::cout << "WARNING: ";
	harlos.complain("WARNING");

	std::cout << std::endl;

	std::cout << "ERROR: ";
	harlos.complain("ERROR");

	std::cout << std::endl;

}
