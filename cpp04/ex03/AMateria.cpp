#include "AMateria.hpp"

AMateria::AMateria(std::string const& type)
	:_type(type)
{}

AMateria::AMateria()
	:_type("none")
{}

AMateria::AMateria(AMateria& other)
	:_type(other._type)
{}

AMateria& AMateria::operator=(AMateria& rhs)
{
	(void) rhs;
	return *this;
}

std::string const& AMateria::getType() const {
	return this->_type;
}

AMateria::~AMateria()
{}
