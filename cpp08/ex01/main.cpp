#include <exception>
#include <iostream>

#include "Span.hpp"

int main() {
	std::cout << "====== SUBJECT MAIN ======" << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "====== ERROR HANDLING ======" << std::endl;
	Span f = Span((int)1);
	f.addNumber(1);
	std::cout << "Create a span with 1 number, try to add another and try to get its spans" << std::endl;
	try {
		f.addNumber(1);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << f.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << f.shortestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::vector<int> v(1, 100);
		f.addRange(v.begin(), v.end());
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "====== FUNCTIONALITY ======" << std::endl;
	std::cout << "Span with only 0's" << std::endl;
	Span k(100);

	k.addNumber(0);
	k.addNumber(0);
	k.addNumber(0);
	k.addNumber(0);

	std::cout << "Longest span: " << k.longestSpan() << std::endl;
	std::cout << "Shortest span: " << k.shortestSpan() << std::endl;

	std::cout << "Add -1" << std::endl;

	k.addNumber(-1);

	std::cout << "Longest span: " << k.longestSpan() << std::endl;
	std::cout << "Shortest span: " << k.shortestSpan() << std::endl;

	Span s = Span(50 * 1000);

	std::cout << "Add 20.000 numbers, from 0 to 19.999, incrementing 5" << std::endl;
	std::vector<int> vec;
	for (int i = 0; i < 10 * 2000; i += 5)
		vec.push_back(i);
	s.addRange(vec.begin(), vec.end());
	std::cout << "Longest span: " << s.longestSpan() << std::endl;
	std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
}
