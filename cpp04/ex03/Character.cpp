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
		this->_inventory[i] = other._inventory[i];
	}
}

Character& Character::operator=(Character& rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_inventory = new AMateria*[4];
		for (int i = 0; i < MAX_EQUIP; i++) {
			this->_inventory[i] = rhs._inventory[i];
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

void Character::use(int idx, ICharacter& target) {
	this->_inventory[idx]->use(target);
}

Character::~Character() {}
