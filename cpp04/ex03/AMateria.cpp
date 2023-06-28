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

void	AMateria::use(ICharacter& target) {
	(void) target;
}

void	AMateria::setState(bool state) {
	this->_state = state;
}

bool	AMateria::getState(void) const {
	return this->_state;
}

AMateria::~AMateria()
{}
