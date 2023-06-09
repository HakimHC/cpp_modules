#include "Bureaucrat.hpp"
#include <exception>

int main() {
	std::cout << "========== ==========" << std::endl;
	Bureaucrat b("carlos", 5);

	for (int i = 0; i <  6; i++) {
		std::cout << b << std::endl;
		try {

			b.incgr();
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "========== ==========" << std::endl;

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

	std::cout << "========== ==========" << std::endl;
	std::cout << "Now lets try to construct the buro with invalid values" << std::endl;
	try {
		int grade = -5;
		std::cout << "grade: " << grade << std::endl;
		Bureaucrat b("joaqui", grade);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "========== ==========" << std::endl;
	try {
		int grade = 1000;
		std::cout << "grade: " << grade << std::endl;
		Bureaucrat b("joaqui", grade);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

}
