#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>

class Bureaucrat {
	private:
		std::string const& name;
		int grade;

	public:
		Bureaucrat(std::string const&, int);
		Bureaucrat(Bureaucrat&);
		Bureaucrat& operator=(Bureaucrat& rhs);
		~Bureaucrat();
		std::string const getName();
		int const getGrade();
		void incgr();
		void decgr();
};

#endif
