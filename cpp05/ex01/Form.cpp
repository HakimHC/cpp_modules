#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	:_name("form"), _isSigned(false), _rGradeSign(50), _rGradeExec(20)
{std::cout << "Form default constructor called" << std::endl;}

Form::Form(std::string name, int rGradeSign, int rGradeExec)
	:_name(name), _isSigned(false), _rGradeSign(rGradeSign), _rGradeExec(rGradeExec)
{
	std::cout << "Form params constructor called" << std::endl;
	if (rGradeSign < 1 || rGradeExec < 1)
		throw Form::GradeTooHighException();
	if (rGradeSign > 150 || rGradeExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form& other)
	:_name(other._name), _isSigned(other._isSigned), _rGradeSign(other._rGradeSign), _rGradeExec(other._rGradeExec)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(Form& rhs) {
	if (this != &rhs) {
		this->_isSigned = rhs._isSigned;
	}
	return *this;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

const std::string Form::getName() {
	return this->_name;
}

bool Form::isSigned() {
	return this->_isSigned;
}

int Form::getRGradeExec() {
	return this->_rGradeExec;
}

int Form::getRGradeSign() {
	return this->_rGradeSign;
}

void Form::beSigned(Bureaucrat& b) {
	if (b.getGrade() > this->_rGradeSign)
		throw (Form::GradeTooLowException());
	this->_isSigned = true;
}

Form::GradeTooHighException::GradeTooHighException()
	:_msg("Form::GradeTooHighException: fatal: grade too high") {}

Form::GradeTooLowException::GradeTooLowException()
	:_msg("Form::GradeTooLowException: fatal: grade too low") {}

const char* Form::GradeTooHighException::what() const throw() {
	return this->_msg.c_str();
}

const char* Form::GradeTooLowException::what() const throw() {
	return this->_msg.c_str();
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}
Form::GradeTooHighException::~GradeTooHighException() throw() {}


std::ostream& operator<<(std::ostream& os, Form& obj) {
	os << obj.getName() << ", form" << std::endl;
	os << "Required grade to sign: " << obj.getRGradeSign() << std::endl;
	os << "Required grade to execute: " << obj.getRGradeExec() << std::endl;
	os << (obj.isSigned() ? "Signed" : "Not signed") << std::endl;
	return os;
}
