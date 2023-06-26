#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MAX_EQUIP 4

class Character : public ICharacter {

	private:
		std::string 	_name;
		AMateria 	**_inventory;
	public:
		Character();
		Character(std::string name);
		Character(Character&);
		Character& operator=(Character&);
		~Character();

		std::string const& getName() const;
		void equip(AMateria *m);
		void use(int idx, ICharacter& target);
};

#endif
