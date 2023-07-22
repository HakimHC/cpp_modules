#include "Intern.hpp"

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

enum e_forms {
	SHRUBBERY,
	ROBOTOMY,
	PRESIDENTIAL
};

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

	static const e_forms idx[] = {
		SHRUBBERY,
		ROBOTOMY,
		PRESIDENTIAL
	};

	for (int i = 0; i < totalElements; i++) {
		if (forms[i] == f) {
			switch (idx[i]) {
				case SHRUBBERY:
					return new ShrubberyCreationForm(target);
				case ROBOTOMY:
					return new RobotomyRequestForm(target);
				case PRESIDENTIAL:
					return new PresidentialPardonForm(target);
			}
		}
	}
	std::cout << "Intern couldn't create " << f << ": invalid form" << std::endl;
	return NULL;
}
