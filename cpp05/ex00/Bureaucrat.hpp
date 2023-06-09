#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <exception>
# include <string>
# include <iostream>

class Bureaucrat {
	private:
		const std::string 	_name;
		int 			_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string, int);
		Bureaucrat(Bureaucrat&);
		Bureaucrat& 		operator=(Bureaucrat& rhs);
		~Bureaucrat();
		const std::string 	getName();
		int 			getGrade();
		void 			incrementGrade();
		void 			decrementGrade();

		class GradeTooHighException : public std::exception {
			private:
				std::string _msg;
			public:
				GradeTooHighException();
				virtual ~GradeTooHighException() throw();
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			private:
				std::string _msg;
			public:
				GradeTooLowException();
				virtual ~GradeTooLowException() throw();
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj);

#endif
