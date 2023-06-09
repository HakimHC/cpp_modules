#ifndef __SCF_HPP__
# define __SCF_HPP__

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
	
	private:
		std::string 		_target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string);
		ShrubberyCreationForm(ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(ShrubberyCreationForm& rhs);

		virtual void 	execute(Bureaucrat const& executor) const;
};

#endif
