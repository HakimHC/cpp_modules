#include "Array.hpp"
#include <cstddef>
#include <exception>

int main() {
	Array<int> a(5);

	try {
		std::cout << a[-432] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;
	return 0;
}
