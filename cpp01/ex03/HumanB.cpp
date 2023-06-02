#include <iostream>

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: name(name), weapon(NULL) {}

void HumanB::attack()
{
	std::cout << this->name << " attacks with their weapon " << this->weapon->getType() << std::endl;
	return;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
