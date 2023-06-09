#include "Intern.hpp"

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "utils.hpp"

Intern::Intern()
{std::cout << "Intern default constructor called" << std::endl;}

Intern::~Intern()
{std::cout << "Intern destructor called" << std::endl;}

Intern::Intern(Intern& other)
{std::cout << "Intern copy constructor called" << std::endl;
(void) other;}

Intern& Intern::operator=(Intern& rhs) {
	if (this != &rhs) {
		;
	}
	return *this;
}

AForm* Intern::makeForm(std::string f, std::string target) {

	int totalElements = 3;

	static const std::string forms[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*fn[])(std::string)= {
		&makePPF,
		&makeRRF,
		&makeSCF
	};

	for (int i = 0; i < totalElements; i++) {
		if (forms[i] == f) {
			std::cout << "Intern creates " << f << std::endl;
			return fn[i](target);
		}
	}
	std::cout << "Intern couldn't create " << f << ": invalid form" << std::endl;
	return NULL;
}
