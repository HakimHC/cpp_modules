#ifndef __FORM_HPP__
# define __FORM_HPP__

# include <exception>
# include <string>
# include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string 	_name;
		bool			_isSigned;
		const int 		_rGradeSign;
		const int 		_rGradeExec;

	public:
		Form();
		Form(const std::string, int);
		Form(Form&);
		~Form();
		Form& 				operator=(Form& rhs);
		const std::string 		getName();
		bool				isSigned();
		const int 			getRGradeSign();
		const int 			getRGradeExec();
		void				beSigned(Bureaucrat&);

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

std::ostream& operator<<(std::ostream& os, Form& obj);

#endif
