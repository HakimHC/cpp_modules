#include <iostream>

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

int main() {
	AMateria* i = new Ice();
	std::cout << i->getType() << std::endl;

	/* AMateria* b = i->clone(); */
	/* std::cout << b->getType() << std::endl; */

	AMateria* d = new Cure();
	std::cout << d->getType() << std::endl;

	AMateria* f = d->clone();
	std::cout << f->getType() << std::endl;

	delete i;
	/* delete b; */

	Character *a = new Character("juan");
	Character *b = new Character("carlos");
	a->equip(d);
	a->use(0, *b);
}
