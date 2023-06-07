#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const& name, int grade)
	:name(name), grade(grade)
{std::cout << "Default constructor called" << std::endl;}

Bureaucrat::Bureaucrat(Bureaucrat& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->grade = other.grade;
	this->name = other.name;
}
