#include <iostream>

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() {
	this->_materias = new AMateria*[MAXMATERIA];
	for (int i = 0; i < MAXMATERIA; i++) {
		this->_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource& other) {
	this->_materias = new AMateria*[MAXMATERIA];
	for (int i = 0; i < MAXMATERIA; i++) {
		this->_materias[i] = other._materias[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(MateriaSource& rhs) {
	if (this != &rhs) {
		delete[] this->_materias;
		this->_materias = new AMateria*[MAXMATERIA];
		for (int i = 0; i < MAXMATERIA; i++) {
			this->_materias[i] = rhs._materias[i]->clone();
		}
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < MAXMATERIA; i++) {
		if (!this->_materias[i]) {
			this->_materias[i] = m;
			return;
		}
	}
	std::cout << "Cannot learn new materia (materia full)" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < MAXMATERIA; i++) {
		if (this->_materias[i]->getType() == type)
			return this->_materias[i]->clone();
	}
	return NULL;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < MAXMATERIA; i++) 
		delete this->_materias[i];
	delete[] this->_materias;
}
