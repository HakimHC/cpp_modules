#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"

class Cat: public Animal {
	public:
		Cat();
		Cat(Cat& other);
		Cat& operator=(Cat& rhs);
		~Cat();
		void makeSound() const;
};

#endif
