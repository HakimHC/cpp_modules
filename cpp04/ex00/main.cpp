#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* w = new WrongAnimal();
	const WrongCat* wc = new WrongCat();

	std::cout << w->getType() << " " << std::endl;
	std::cout << wc->getType() << " " << std::endl;

	w->makeSound();	
	wc->makeSound();	

	delete meta;
	delete i;
	delete j;
	delete w;
	delete wc;
	return 0;
}
