#include <cstdlib>

#include <fstream>

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// CANONICAL MEMBER FUNCTIONS

// ===================================================================================

RobotomyRequestForm::RobotomyRequestForm()
	:AForm("RRFform", 72, 45), _target("home")
{std::cout << "RobotomyRequestForm default constructor called" << std::endl;}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:AForm("RRFform", 72, 45), _target(target)
{std::cout << "RobotomyRequestForm target constructor called" << std::endl;}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other)
	:AForm(other.getName(), other.getRGradeSign(), other.getRGradeExec())
{std::cout << "RobotomyRequestForm copy constructor called" << std::endl;}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& rhs) {
	if (this != &rhs) {
		this->setSign(rhs.isSigned());
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{std::cout << "RobotomyRequestForm destructor called" << std::endl;}

// ===================================================================================

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->isSigned())
		throw FormNotSignedException();
	if (!this->isExecutable(executor.getGrade()))
		throw GradeTooLowException();
	std::string msgs[] = {
		" has been robotomized!!",
		" has not been robotomized, robotomy failed...."
	};

	srand(time(0));
	std::cout << this->getName() << msgs[rand() % 2] << std::endl;
}
