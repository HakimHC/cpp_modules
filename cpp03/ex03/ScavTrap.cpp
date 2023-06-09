#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <string>

ScavTrap::ScavTrap()
	:ClapTrap()
{
	this->name = "sp";
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string n)
	:ClapTrap(n)
{
	this->name = n;
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& other) 
	:ClapTrap(other.name)
{
	this->hp = other.hp;
	this->ep = other.ep;
	this->ad = other.ad;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->hp > 0 && this->ep) {
		std::cout << "ScavTrap " << this->name <<
			" attacks " << target << ", causing " << this->ad << " points of damage!" <<
			std::endl;
		this->ep--;
	}
}

void ScavTrap::guardGate() {
	if (this->hp > 0 && this->ep) {
		std::cout << this->name << " is now in gate keeper mode!!" << std::endl;
	}
}
