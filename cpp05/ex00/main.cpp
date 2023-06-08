#include "Bureaucrat.hpp"
#include <exception>

int main() {
	Bureaucrat b("puta", 5);

	for (int i = 0; i <  10; i++) {
		std::cout << b.getGrade() << std::endl;
		try {

			b.incgr();
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
}
