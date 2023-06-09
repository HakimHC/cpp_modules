#ifndef __UTILS_HPP__
# define __UTILS_HPP__

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

AForm* makePPF(std::string);
AForm* makeSCF(std::string);
AForm* makeRRF(std::string);

#endif
