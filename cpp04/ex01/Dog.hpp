#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
	public:
		Dog();
		Dog(Dog& other);
		Dog& operator=(const Dog& rhs);
		virtual ~Dog();
		void makeSound() const;
		Brain* getBrain();

	private:
		Brain* brain;

};

#endif
