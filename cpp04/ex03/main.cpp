#include <iostream>

#include "AMateria.hpp"
#include "Ice.hpp"

int main() {
	AMateria* i = new Ice();
	std::cout << i->getType() << std::endl;

	AMateria* b = i->clone();
	std::cout << b->getType() << std::endl;

	delete i;
	delete b;
}
