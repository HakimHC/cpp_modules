#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

int main()
{
	Animal *animals[10] ;
	int i;

	for (i = 0; i < 5; i++) {
		animals[i] = new Dog();
	}
	for (; i < 10; i++) {
		animals[i] = new Cat();
	}

	for (i = 0; i < 10; i++) {
		delete animals[i];
	}

	Dog* dog = new Dog();
	Dog* dog2 = new Dog(*dog);
	dog->getBrain()->setIdea("hungry", 0);
	*dog2 = *dog;
	std::cout << dog->getBrain()->getIdea(0) << std::endl;
	dog->getBrain()->setIdea("thirsty", 0);
	std::cout << dog->getBrain()->getIdea(0) << std::endl;
	std::cout << dog2->getBrain()->getIdea(0) << std::endl;
	delete dog;
	delete dog2;
	return 0;
}
