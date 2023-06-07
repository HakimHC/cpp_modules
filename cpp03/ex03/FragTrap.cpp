#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap()
:ClapTrap() {
	this->name = "ft";
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string& name)
	:ClapTrap(name)
{
	this->name = name;
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
	std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap& other)
	:ClapTrap(other.name)
{
	this->name = other.name;
	this->hp = other.hp;
	this->ep = other.ep;
	this->ad = other.ad;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap& rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		this->hp = rhs.hp;
		this->ep = rhs.ep;
		this->ad = rhs.ad;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFiveGuys() {
	if (this->hp && this->ep) {
		std::cout << this->name << " just made a high five request!!" << std::endl;
	}
}

void FragTrap::attack(const std::string& target) {
	if (this->hp && this->ep) {
		std::cout << "FragTrap " << this->name << " just attacked " << target << ", dealing " << this->ad << " hitpoints!" << std::endl;
	}
}
