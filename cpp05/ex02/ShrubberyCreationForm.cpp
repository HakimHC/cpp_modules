#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// CANONICAL MEMBER FUNCTIONS

// ===================================================================================

ShrubberyCreationForm::ShrubberyCreationForm()
	:AForm("SCFform", 145, 137)
{std::cout << "ShrubberyCreationForm default constructor called" << std::endl;}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other)
	:AForm(other.getName(), other.getRGradeSign(), other.getRGradeExec())
{std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& rhs) {
	if (this != &rhs) {
		this->setSign(rhs.isSigned());
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{std::cout << "ShrubberyCreationForm destructor called" << std::endl;}

// ===================================================================================

void ShrubberyCreationForm::execute(Bureaucrat const & executor) {
	if (!this->isSigned())
		throw FormNotSignedException();
	if (this->getRGradeExec() < executor.getGrade())
		throw GradeTooLowException();
	std::cout << "jiji" << std::endl;
}
