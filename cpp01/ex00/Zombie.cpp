#include <string>
#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie(std::string n)
{
	this->name = n;
	return;
}

Zombie::~Zombie()
{
	std::cout << this->name << " died (again)." << std::endl;
	return;
}

void Zombie::announce()
{
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}
