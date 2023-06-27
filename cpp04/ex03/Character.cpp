#include <iostream>

#include "Character.hpp"

Character::Character()
	:_name("default")
{
	this->_inventory = new AMateria*[4];
	for (int i = 0; i < MAX_EQUIP; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(std::string name)
	:_name(name)
{
	this->_inventory = new AMateria*[4];
	for (int i = 0; i < MAX_EQUIP; i++) {
		this->_inventory[i] = NULL;
	}
}

std::string const& Character::getName() const {
	return this->_name;
}

Character::Character(Character& other) {
	this->_name = other._name;
	this->_inventory = new AMateria*[4];
	for (int i = 0; i < MAX_EQUIP; i++) {
		this->_inventory[i] = other._inventory[i]->clone();
	}
}

Character& Character::operator=(Character& rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_inventory = new AMateria*[4];
		for (int i = 0; i < MAX_EQUIP; i++) {
			this->_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	return *this;
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < MAX_EQUIP; i++) {
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		std::cout << "BAD INDEX: bad index range" << std::endl;
	else if (this->_inventory[idx])
		this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
		std::cout << "BAD INDEX: bad index range" << std::endl;
	else if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
	 	std::cout << "BAD INDEX: no item at index " << idx << std::endl;
}

Character::~Character() {
	for (int i = 0; i < MAX_EQUIP; i++)
		delete this->_inventory[i];
	delete[] this->_inventory;
}
