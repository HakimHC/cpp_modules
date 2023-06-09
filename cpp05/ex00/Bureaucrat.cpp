#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	:_name("buro"), _grade(50)
{std::cout << "Default constructor called" << std::endl;}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	:_name(name)
{
	std::cout << "Buro params constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& other)
	:_name(other._name), _grade(other._grade)
{
	std::cout << "Buro copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& rhs) {
	if (this != &rhs) {
		this->_grade = rhs._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Buro destructor called" << std::endl;
}

const std::string Bureaucrat::getName() {
	return this->_name;
}

int Bureaucrat::getGrade() {
	return this->_grade;
}

void Bureaucrat::incgr() {
	if (this->_grade - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade -= 1;
}

void Bureaucrat::decgr() {
	if (this->_grade + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade += 1;
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
	:_msg("Bureaucrat::GradeTooHighException: fatal: grade too high") {}

Bureaucrat::GradeTooLowException::GradeTooLowException()
	:_msg("Bureaucrat::GradeTooLowException: fatal: grade too low") {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return this->_msg.c_str();
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return this->_msg.c_str();
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}


std::ostream& operator<<(std::ostream& os, Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}
