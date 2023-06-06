#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	:name(name), hp(10), ep(10), ad(0)
{std::cout << "ClapTrap default constructor called" << std::endl;}

ClapTrap::ClapTrap(ClapTrap& other)
	:name(other.name), hp(other.hp), ep(other.ep), ad(other.ad)
{std::cout << "ClapTrap copy constructor called" << std::endl;}

ClapTrap& ClapTrap::operator=(ClapTrap& rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		this->hp = rhs.hp;
		this->ad = rhs.ad;
		this->ep = rhs.ep;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{std::cout << "ClapTrap destructor called" << std::endl;}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hp > 0 && this->ep) {
		this->hp -= amount;
		std::cout << "ClapTrap " << this->name << " took "
			<< amount << " damage points (HP: " << this->hp << " )" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hp > 0 && this->ep) {
		this->hp += amount;
		std::cout << "ClapTrap " << this->name << " got healed (HP: " << this->hp << " )" << std::endl;
		this->ep--;
	}
}

void ClapTrap::attack(const std::string& target) {
	if (this->hp > 0 && this->ep) {
		std::cout << "ClapTrap " << this->name << " attacks " << target <<
			", causing " << this->ad << " points of damage!" <<
			std::endl;
		this->ep--;
	}
}

int ClapTrap::get_ep() {
	return this->ep;
}
