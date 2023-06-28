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
	// ============ SUBJECT =====================
	std::cout << "========= SUBJECT MAIN ===========" << std::endl;
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

	AMateria* m1 = new Ice();
	me->equip(m1);
	bob->equip(m1);
	delete me;

	delete bob;
	delete src;
	// ================ MY TESTS =================
	
	std::cout << "========= MY TESTS ===========" << std::endl;
	std::cout << "========= ERROR HANDLING ===========" << std::endl;
	std::cout << "Lets create a materia source with only ice materias" << std::endl;
	MateriaSource* ms1 = new MateriaSource();
	ms1->learnMateria(new Ice());
	ms1->learnMateria(new Ice());
	ms1->learnMateria(new Ice());
	ms1->learnMateria(new Ice());
	std::cout << "Now lets try to add a 5th materia" << std::endl;
	ms1->learnMateria(new Cure());
	delete ms1;
}
