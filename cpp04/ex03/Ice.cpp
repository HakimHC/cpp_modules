#include "Ice.hpp"
#include "AMateria.hpp"

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

Ice::~Ice()
{}

AMateria* Ice::clone() const {
	return new Ice();
}
