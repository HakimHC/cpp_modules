#include <iostream>

#include "Span.hpp"

int main() {

	Span sp(5);

	sp.addNumber(1);
	sp.addNumber(3);
	sp.addNumber(2);

	std::cout << sp.longestSpan() << std::endl;
}
