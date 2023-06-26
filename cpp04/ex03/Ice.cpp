#include <iostream>

#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Ice::Ice()
	:AMateria("ice")
{}

Ice::Ice(Ice& other)
	:AMateria(other._type)
{}

Ice& Ice::operator=(Ice& rhs) {
	(void) rhs;
	return *this;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}

Ice::~Ice()
{}

AMateria* Ice::clone() const {
	return new Ice();
}
