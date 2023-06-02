#include <iostream>

#include "Harl.hpp"

int main() {

	Harl harlos;

	std::cout << "- what a nice day, i hope i dont get a DEBUG log from Harlos" << std::endl << std::endl << "- ";
	harlos.complain("DEBUG");

	std::cout << std::endl << "stfu harlos" << std::endl;

	harlos.complain("INFO");

	std::cout << "whatever im too lazy to keep formatting this convo, just hit me with a warning and an error log" << std::endl;
	harlos.complain("WARNING");
	harlos.complain("ERROR");

	std::cout << "very nice now hit me with the classic CANGREJO complaint" << std::endl;

	harlos.complain("CANGREJO");
}
