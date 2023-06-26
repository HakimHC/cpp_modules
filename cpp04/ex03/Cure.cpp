#include <iostream>

#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure()
	:AMateria("cure")
{}

Cure::Cure(Cure& other)
	:AMateria(other._type)
{}

Cure& Cure::operator=(Cure& rhs) {
	(void) rhs;
	return *this;
}

Cure::~Cure()
{}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds" << std::endl;
}
