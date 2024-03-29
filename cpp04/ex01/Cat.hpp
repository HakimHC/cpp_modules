#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
	public:
		Cat();
		Cat(Cat& other);
		Cat& operator=(Cat& rhs);
		~Cat();
		void makeSound() const;
		Brain* getBrain();

	private:
		Brain* brain;
};

#endif
