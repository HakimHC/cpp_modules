#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap()
	:ClapTrap("dt_clap_name")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->DiamondTrap::name = "dt";
	this->hp = this->FragTrap::hp;
	this->ep = this->FragTrap::ep;
	this->ad = this->FragTrap::ad;
}

DiamondTrap::DiamondTrap(std::string n)
	:ClapTrap(n + "_clap_name"), ScavTrap(n + "_clap_name"), FragTrap(n + "_clap_name")
{
	std::cout << "DiamondTrap name constructor called" << std::endl;
	this->name = n;
	this->hp = this->FragTrap::hp;
	this->ep = this->ScavTrap::ep;
	this->ad = this->FragTrap::ad;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "I am " << this->name << std::endl;
	std::cout << "My clapname is " << this->ClapTrap::name << std::endl;
}

void DiamondTrap::attack(std::string target) {
	this->ScavTrap::attack(target);
}

/* void DiamondTrap::attack(std::string n) = DiamondTrap::ScavTrap::attack(); */
