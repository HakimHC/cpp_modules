#ifndef __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#define MAXMATERIA 4

class MateriaSource : public IMateriaSource {

	public:
		MateriaSource();
		MateriaSource(MateriaSource&);
		MateriaSource& operator=(MateriaSource&);
		~MateriaSource();

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const&);
	private:
		AMateria**	_materias;
};

#endif
