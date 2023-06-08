#include "Bureaucrat.hpp"
#include <exception>

int main() {
	Bureaucrat b("carlos", 5);

	for (int i = 0; i <  10; i++) {
		std::cout << b << std::endl;
		try {

			b.incgr();
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	for (int i = 0; i < 149; i++) {
		b.decgr();
	}
	std::cout << b << std::endl;
	try {

		b.decgr();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

}
