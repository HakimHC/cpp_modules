#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

#include <iostream>

class Brain {
	public:
		Brain();
		Brain(Brain& other);
		Brain& operator=(Brain& rhs);
		~Brain();

		std::string getIdea(int index);
		void setIdea(std::string idea, int index);

	private:
		std::string *ideas;
};

#endif
