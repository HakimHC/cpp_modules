#include <iostream>

#include "Harl.hpp"

int main() {

	Harl harlos;

	std::cout << "let's see a debug log" << std::endl;
	harlos.complain("DEBUG");

	std::cout << "very nice, let's see an info log" << std::endl;

	harlos.complain("INFO");

	std::cout << "good, now hit me with a warning log" << std::endl;
	harlos.complain("WARNING");
	std::cout << "good, now hit me with an error log" << std::endl;
	harlos.complain("ERROR");

	std::cout << "very nice now hit me with the classic CANGREJO complaint" << std::endl;

	harlos.complain("CANGREJO");
}
