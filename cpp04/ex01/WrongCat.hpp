#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
		WrongCat();
		WrongCat(WrongCat& other);
		WrongCat& operator=(WrongCat& rhs);
		~WrongCat();
};

#endif
