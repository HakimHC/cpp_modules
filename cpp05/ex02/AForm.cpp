#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	:_name("form"), _isSigned(false), _rGradeSign(50), _rGradeExec(20)
{std::cout << "AForm default constructor called" << std::endl;}

AForm::AForm(std::string name, int rGradeSign, int rGradeExec)
	:_name(name), _isSigned(false), _rGradeSign(rGradeSign), _rGradeExec(rGradeExec)
{
	std::cout << "AForm params constructor called" << std::endl;
	if (rGradeSign < 1 || rGradeExec < 1)
		throw AForm::GradeTooHighException();
	if (rGradeSign > 150 || rGradeExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm& other)
	:_name(other._name), _isSigned(other._isSigned), _rGradeSign(other._rGradeSign), _rGradeExec(other._rGradeExec)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(AForm& rhs) {
	if (this != &rhs) {
		this->_isSigned = rhs._isSigned;
	}
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

const std::string AForm::getName() {
	return this->_name;
}

bool AForm::isSigned() {
	return this->_isSigned;
}

int AForm::getRGradeExec() {
	return this->_rGradeExec;
}

int AForm::getRGradeSign() {
	return this->_rGradeSign;
}

void AForm::setSign(bool sign) {
	this->_isSigned = sign;
}

void AForm::beSigned(Bureaucrat& b) {
	if (b.getGrade() > this->_rGradeSign)
		throw (AForm::GradeTooLowException());
	this->_isSigned = true;
}

AForm::GradeTooHighException::GradeTooHighException()
	:_msg("AForm::GradeTooHighException: fatal: grade too high") {}

AForm::GradeTooLowException::GradeTooLowException()
	:_msg("AForm::GradeTooLowException: fatal: grade too low") {}

AForm::FormNotSignedException::FormNotSignedException()
	:_msg("AForm::FormNotSignedException: fatal: form not signed") {}

const char* AForm::GradeTooHighException::what() const throw() {
	return this->_msg.c_str();
}

const char* AForm::GradeTooLowException::what() const throw() {
	return this->_msg.c_str();
}

const char* AForm::FormNotSignedException::what() const throw() {
	return this->_msg.c_str();
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}
AForm::GradeTooHighException::~GradeTooHighException() throw() {}
AForm::FormNotSignedException::~FormNotSignedException() throw() {}


std::ostream& operator<<(std::ostream& os, AForm& obj) {
	os << obj.getName() << ", form" << std::endl;
	os << "Required grade to sign: " << obj.getRGradeSign() << std::endl;
	os << "Required grade to execute: " << obj.getRGradeExec() << std::endl;
	os << (obj.isSigned() ? "Signed" : "Not signed") << std::endl;
	return os;
}
