#ifndef __INTERN_HPP__
# define __INTERN_HPP__

# include <string>
# include <iostream>

# include "AForm.hpp"
# include "utils.hpp"

class Intern {
	public:
		Intern();
		Intern(Intern&);
		Intern& operator=(Intern&);
		~Intern();

		AForm* makeForm(std::string, std::string);
};

#endif
