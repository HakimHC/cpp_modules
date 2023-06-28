#include <iostream>

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "TestFont.hpp"

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
	TestFont::print("========= SUBJECT MAIN ===========", GREEN);
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

	// ================ MY TESTS =================
	
	TestFont::print("========= MY TESTS ===========", GREEN);
	TestFont::print("========= ERROR HANDLING ===========", GREEN);
	TestFont::print("Lets create a materia source with only ice materias", PURPLE);
	MateriaSource* ms1 = new MateriaSource();
	ms1->learnMateria(new Ice());
	ms1->learnMateria(new Ice());
	ms1->learnMateria(new Ice());
	ms1->learnMateria(new Ice());
	AMateria* a = new Cure();
	TestFont::print("Now lets try to add a 5th materia", PURPLE);
	ms1->learnMateria(a);
	TestFont::print("As expected, you cannot add a 5th materia", PURPLE);
	delete a;
	delete ms1;

	// =======================================================================
	TestFont::print("Now lets use these materias, of course, in an invalid manner", PURPLE);
	AMateria* m1 = new Ice();
	me->equip(m1);
	TestFont::print("Let's use our famous materia at index -4 and at index 172, and lets unequip them aswell", PURPLE);
	me->use(-4, *bob);
	me->use(172, *bob);
	me->unequip(-4);
	me->unequip(172);
	TestFont::print("Lets also equip more than 4 materias", PURPLE);
	AMateria* m3 = new Ice();
	AMateria* m4 = new Cure();
	me->equip(m3);
	me->equip(m4);
	delete m4;
	TestFont::print("Lets try this: let BOB, an innocent NPC, try to equip an already equipped materia", PURPLE);
	bob->equip(m1);

	delete me;
	delete bob;
	delete src;
}
