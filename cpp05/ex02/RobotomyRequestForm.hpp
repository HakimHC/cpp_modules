#ifndef __RRF_HPP__
# define __RRF_HPP__

# include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	
	private:
		std::string 		_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string);
		RobotomyRequestForm(RobotomyRequestForm& other);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(RobotomyRequestForm& rhs);

		void 			execute(Bureaucrat const& executor) const;
};

#endif
