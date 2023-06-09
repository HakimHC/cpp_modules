#ifndef __AFORM_HPP__
# define __AFORM_HPP__

# include <exception>
# include <string>
# include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string 	_name;
		bool			_isSigned;
		const int 		_rGradeSign;
		const int 		_rGradeExec;

	public:
		AForm();
		AForm(std::string name, int rGradeSign, int rGradeExec);
		AForm(AForm&);
		virtual ~AForm();
		AForm& 				operator=(AForm& rhs);
		const std::string 		getName() const;
		int 				getRGradeSign() const;
		int 				getRGradeExec() const;
		bool				isSigned() const;
		void				beSigned(Bureaucrat&);
		virtual void			execute(Bureaucrat const& executor) const = 0;

		void				setSign(bool sign);

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
		class FormNotSignedException : public std::exception {
			private:
				std::string _msg;
			public:
				FormNotSignedException();
				virtual ~FormNotSignedException() throw();
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, AForm& obj);

#endif
