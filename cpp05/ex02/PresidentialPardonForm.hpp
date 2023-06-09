#ifndef __PPF_HPP__
# define __PPF_HPP__

# include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	
	private:
		std::string 		_target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string);
		PresidentialPardonForm(PresidentialPardonForm& other);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(PresidentialPardonForm& rhs);

		void 			execute(Bureaucrat const& executor) const;
};

#endif
