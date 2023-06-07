#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <string>

class Animal {
	public:
		Animal();
		Animal(Animal& other);
		Animal& operator=(Animal& rhs);
		~Animal();
		virtual void makeSound() const;
		std::string getType(void) const;
	protected:
		std::string type;
};

#endif
