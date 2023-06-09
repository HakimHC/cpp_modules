#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

AForm* makePPF(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm* makeSCF(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm* makeRRF(std::string target) {
	return new RobotomyRequestForm(target);
}
