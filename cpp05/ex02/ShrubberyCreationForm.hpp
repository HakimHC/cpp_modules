#ifndef __SCF_HPP__
# define __SCF_HPP__

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
	
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(ShrubberyCreationForm& rhs);

		void 			execute(Bureaucrat const& executor);
};

#endif
