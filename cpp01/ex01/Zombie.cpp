#include <string>
#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie()
{
	return;
}

Zombie::~Zombie()
{
	std::cout << this->name << " died (again)." << std::endl;
	return;
}

void Zombie::set_name(std::string name)
{
	this->name = name;
	return;
}

void Zombie::announce()
{
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}
