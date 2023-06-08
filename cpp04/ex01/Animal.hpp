#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <string>

# include "Brain.hpp"

class Animal {
	public:
		Animal();
		Animal(Animal& other);
		Animal& operator=(Animal& rhs);
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType(void) const;
	protected:
		std::string type;

};

#endif
