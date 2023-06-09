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
		Form(std::string name, int rGradeSign, int rGradeExec);
		Form(Form&);
		~Form();
		Form& 				operator=(Form& rhs);
		const std::string 		getName();
		bool				isSigned();
		int 				getRGradeSign();
		int 				getRGradeExec();
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

		class FormAlreadySignedException : public std::exception {
			private:
				std::string _msg;
			public:
				FormAlreadySignedException();
				virtual ~FormAlreadySignedException() throw();
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Form& obj);

#endif
