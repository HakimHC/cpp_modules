#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

# include <string>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal& other);
		WrongAnimal& operator=(WrongAnimal& rhs);
		virtual ~WrongAnimal();
		void makeSound() const;
		std::string getType(void) const;
	protected:
		std::string type;
};

#endif
