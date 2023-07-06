#include <iostream>

#include "Span.hpp"

int main() {

	Span sp(5);

	sp.addNumber(1);
	sp.addNumber(9);
	sp.addNumber(2);

	std::cout << sp.longestSpan() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
}
