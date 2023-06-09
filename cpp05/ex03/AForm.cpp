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

const std::string AForm::getName() const {
	return this->_name;
}

bool AForm::isSigned() const {
	return this->_isSigned;
}

int AForm::getRGradeExec() const {
	return this->_rGradeExec;
}

int AForm::getRGradeSign() const {
	return this->_rGradeSign;
}

void AForm::setSign(bool sign) {
	this->_isSigned = sign;
}

void AForm::beSigned(Bureaucrat& b) {
	if (b.getGrade() > this->_rGradeSign)
		throw (AForm::GradeTooLowException());
	if (this->_isSigned) {
		std::cout << this->_name << ": form is already signed" << std::endl;
		throw AForm::FormAlreadySignedException();
		return;
	}
	this->_isSigned = true;
}

bool AForm::isExecutable(int grade) const {
	return (grade <= this->_rGradeExec);
}

AForm::GradeTooHighException::GradeTooHighException()
	:_msg("AForm::GradeTooHighException: fatal: grade too high") {}

AForm::GradeTooLowException::GradeTooLowException()
	:_msg("AForm::GradeTooLowException: fatal: grade too low") {}

AForm::FormNotSignedException::FormNotSignedException()
	:_msg("AForm::FormNotSignedException: fatal: form not signed") {}

AForm::FormAlreadySignedException::FormAlreadySignedException()
	:_msg("Form::FormAlreadySignedException: form already signed") {}

const char* AForm::GradeTooHighException::what() const throw() {
	return this->_msg.c_str();
}

const char* AForm::GradeTooLowException::what() const throw() {
	return this->_msg.c_str();
}

const char* AForm::FormNotSignedException::what() const throw() {
	return this->_msg.c_str();
}

const char* AForm::FormAlreadySignedException::what() const throw() {
	return this->_msg.c_str();
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}
AForm::GradeTooHighException::~GradeTooHighException() throw() {}
AForm::FormNotSignedException::~FormNotSignedException() throw() {}
AForm::FormAlreadySignedException::~FormAlreadySignedException() throw() {}


std::ostream& operator<<(std::ostream& os, AForm& obj) {
	os << obj.getName() << ", form" << std::endl;
	os << "Required grade to sign: " << obj.getRGradeSign() << std::endl;
	os << "Required grade to execute: " << obj.getRGradeExec() << std::endl;
	os << (obj.isSigned() ? "Signed" : "Not signed") << std::endl;
	return os;
}
