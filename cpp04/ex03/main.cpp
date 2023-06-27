#include <iostream>

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

/* int main() { */
/* 	AMateria* ice = new Ice(); */
/* 	Character a("a"); */

/* 	a.equip(ice); */
/* 	Character b(a); */
/* 	b.use(0, a); */
/* 	a.unequip(0); */
/* 	b.use(0, a); */
/* 	a.use(0, b); */
/* 	Character c("c"); */
/* 	c.equip(ice); */
/* 	c.use(0, a); */
/* 	delete ice; */
/* } */

int main()
{
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;
return 0;
}
