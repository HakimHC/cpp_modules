#include <iterator>
#include <vector>
#include <algorithm>
#include <map>
#include <list>

#include "easyfind.hpp"

int main() {
	std::cout << "Lets try vectors first: { 1, 2, 3, 4, 5 }" << std::endl;

	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	try {
		std::cout << "ToFind: 4 :: " << *(easyfind(vec, 4)) << std::endl;
		std::cout << "ToFind: 2 :: " << *(easyfind(vec, 2)) << std::endl;
		std::cout << "ToFind: 1 :: " << *(easyfind(vec, 1)) << std::endl;
		std::cout << "ToFind: 9 :: " << *(easyfind(vec, -42)) << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "Now lets try a list (the elements remain the same)" << std::endl;

	std::list<int> head;

	head.push_back(1);
	head.push_back(2);
	head.push_back(3);
	head.push_back(4);
	head.push_back(5);

	try {
		std::cout << "ToFind: 4 :: " << *(easyfind(head, 4)) << std::endl;
		std::cout << "ToFind: 2 :: " << *(easyfind(head, 2)) << std::endl;
		std::cout << "ToFind: 1 :: " << *(easyfind(head, 1)) << std::endl;
		std::cout << "ToFind: 9 :: " << *(easyfind(head, -42)) << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
